#ifndef GDL_OGL_RESOURCE_HPP
#define GDL_OGL_RESOURCE_HPP

#include <gdl/ogl/OpenGL.hpp>

#include <functional>
#include <unordered_map>
#include <stdexcept>

namespace gdl
{
namespace ogl
{

namespace detail
{
    class BaseResource
    {
    protected:
        static std::unordered_map<GLuint, unsigned int> refs;
    };
}

class ResourceException : public std::runtime_error
{
public:
    ResourceException(const std::string& msg) :
        std::runtime_error(msg) {}
};

template <typename T>
class Resource : public detail::BaseResource
{
    typedef std::function<void(GLsizei, GLuint*)> CreateFunc;
    typedef std::function<void(GLsizei, GLuint*)> DeleteFunc;
    typedef std::function<void(GLuint)> DeleteFunc2;

public:
    Resource(CreateFunc&& c, DeleteFunc&& d) :
        _c(std::move(c)),
        _d(std::move(d)),
        _d2(nullptr),
        _id(0)
    {
        create();
    }

    Resource(GLuint id, DeleteFunc2&& d2) :
        _c(nullptr),
        _d(nullptr),
        _d2(std::move(d2)),
        _id(0)
    {
        create(id);
    }

    Resource(const Resource& copy) :
        _c(copy._c),
        _d(copy._d),
        _d2(copy._d2),
        _id(0)
    {
        create();
    }

    virtual ~Resource()
    {
        destroy();
    }

    Resource& operator=(const Resource& copy)
    {
        destroy();
        create(copy._id);
        return *this;
    }

    const GLuint& id() const
    {
        return _id;
    }

private:
    void create()
    {
        if (_c)
        {
            _c(1, &_id);
            refs.insert(std::make_pair(_id, 1));
        }
        else
        {
            throw ResourceException("Unable to create resource: no function set");
        }
    }

    void create(const GLuint& id)
    {
        _id = id;
        if (refs.count(_id) > 0)
        {
            refs[_id]++;
        }
        else
        {
            refs.insert(std::make_pair(_id, 1));
        }
    }

    void destroy()
    {
        if (--refs[_id] == 0)
        {
            if (_d)
            {
                _d(1, &_id);
            }
            else if (_d2)
            {
                _d2(_id);
            }
            else
            {
                throw ResourceException("Unable to delete resource: no function set");
            }
        }
    }

private:
    CreateFunc _c;
    DeleteFunc _d;
    DeleteFunc2 _d2;
    GLuint _id;
};

}
}

#endif // GDL_OGL_RESOURCE_HPP
