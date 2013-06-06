#ifndef DEMO_CAMERA_HPP
#define DEMO_CAMERA_HPP

#include <gdl/sys/Keyboard.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/math/Vector3.hpp>
#include <gdl/sys/Window.hpp>

#include "Updatable.hpp"

namespace demo
{

class Camera : public Updatable
{
public:
    Camera(gdl::sys::Window&, float width, float height);
	virtual ~Camera();
	virtual void update();
private:
    virtual void handleKeyboard(const gdl::sys::Keyboard::Key&);
	virtual void createLookAt();
public:
	gdl::math::Matrix4f view;
	gdl::math::Matrix4f projection;
private:
	gdl::math::Vector3f position;
	gdl::math::Vector3f direction;
	gdl::math::Vector3f up;
	float translationSpeed;
	float rotationSpeed;
	int previousMouseX;
	int previousMouseY;
	bool lookAround;
};

}

#endif // DEMO_CAMERA_HPP
