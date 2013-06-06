#ifndef GDL_SINGLETON_HPP
#define GDL_SINGLETON_HPP

#include <memory>

namespace gdl
{

template<typename T>
class Singleton
{
public:
	static T& get()
	{
		if (instance.get() == nullptr)
		{
			instance = std::make_shared<T>();
		}
		return *instance;
	}
private:
	Singleton() {}
	~Singleton() {}
	static std::shared_ptr<T> instance;
};

template<typename T>
std::shared_ptr<T> Singleton<T>::instance = nullptr;

}

#endif // GDL_SINGLETON_HPP
