#ifndef DEMO_RENDERABLE_H
#define DEMO_RENDERABLE_H

#include <gdl/math/Matrix.hpp>

namespace demo
{

class Renderable
{
public:
        virtual ~Renderable() {}
        virtual void render(const gdl::math::Matrix4f& view, const gdl::math::Matrix4f& projection) = 0;
};

}

#endif // DEMO_RENDERABLE_H
