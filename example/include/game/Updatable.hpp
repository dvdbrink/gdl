#ifndef DEMO_UPDATABLE_HPP
#define DEMO_UPDATABLE_HPP

namespace demo
{

class Updatable
{
public:
	virtual ~Updatable() {}
	virtual void update() = 0;
};

}

#endif // DEMO_UPDATABLE_HPP
