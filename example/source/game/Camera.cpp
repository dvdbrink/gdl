#include "Camera.hpp"

#include <gdl/ogl/OpenGL.hpp>
#include <gdl/log/Emit.hpp>
#include <gdl/math/Vector3.hpp>
#include <gdl/math/Quaternion.hpp>

namespace demo
{

Camera::Camera(gdl::sys::Window& window, float width, float height) :
	position({.0f, .5f, 1.0f}),
	direction(gdl::math::Vector3f{.0f, .5f, .0f} - position),
	up({.0f, 1.0f, .0f}),
	translationSpeed(0.5f),
	rotationSpeed(0.5f),
	lookAround(false)
{
    direction = gdl::math::normal(direction);
	createLookAt();
    projection = gdl::math::perspective(60.0f, width/height, 0.1f, 200.0f);

    window.connect([&](const gdl::sys::Mouse::ButtonPressed& e)
	{
        if (!lookAround && e.button == gdl::sys::Mouse::Button::Right)
		{
			lookAround = true;
		}
	});

    window.connect([&](const gdl::sys::Mouse::ButtonReleased& e)
	{
        if (lookAround && e.button == gdl::sys::Mouse::Button::Right)
		{
			lookAround = false;
		}
	});

    window.connect([&](const gdl::sys::Mouse::Motion& e)
	{
		if (lookAround)
		{
			float yawAngle = -rotationSpeed * (e.x - previousMouseX);
			float pitchAngle = rotationSpeed * (e.y - previousMouseY);

            gdl::math::Quaternion rotation;
            rotation = gdl::math::rotate(rotation, yawAngle, up);
            rotation = gdl::math::rotate(rotation, pitchAngle, gdl::math::cross(up, direction));
			direction = rotation * direction;
		}

		previousMouseX = e.x;
		previousMouseY = e.y;
	});

    window.connect([&](const gdl::sys::Keyboard::KeyPressed& e)
    {
        handleKeyboard(e.key);
    });

    window.connect([&](const gdl::sys::Keyboard::KeyPressedRepeat& e)
    {
        handleKeyboard(e.key);
    });
}

Camera::~Camera()
{
}

void Camera::update()
{
	createLookAt();
}

void Camera::handleKeyboard(const gdl::sys::Keyboard::Key& key)
{
	switch(key)
	{
        case gdl::sys::Keyboard::Key::W:
		{
			position += direction * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::S:
		{
			position -= direction * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::A:
		{
            position += gdl::math::cross(up, direction) * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::D:
		{
            position -= gdl::math::cross(up, direction) * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::Up:
		{
			position += up * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::Down:
		{
			position -= up * translationSpeed;
			break;
		}
        case gdl::sys::Keyboard::Key::Q:
		{
			position = gdl::math::Vector3f{.0f, .0f, 1.0f};
			direction = gdl::math::Vector3f{.0f, .0f, .0f} - position;
            direction = gdl::math::normal(direction);
			up = gdl::math::Vector3f{.0f, 1.0f, .0f};
			break;
		}
		default: break;
	}
}

void Camera::createLookAt()
{
    view = gdl::math::lookAt(position, direction + position, up);
}

}
