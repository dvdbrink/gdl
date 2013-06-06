#ifndef DEMO_CROSSHAIR_HPP
#define DEMO_CROSSHAIR_HPP

#include "Renderable.hpp"

#include <gdl/ogl/Program.hpp>
#include <gdl/ogl/Shader.hpp>
#include <gdl/ogl/VertexArray.hpp>
#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/math/Matrix.hpp>

namespace demo
{

class Crosshair : public Renderable
{
public:
	Crosshair();
	virtual void render(const gdl::math::Matrix4f&, const gdl::math::Matrix4f&);
private:
    gdl::math::Matrix4f transform;
    gdl::ogl::Shader vs, fs;
    gdl::ogl::Program program;
    gdl::ogl::VertexBuffer vb;
    gdl::ogl::VertexArray va;
    std::vector<gdl::math::Vector3f> vertices;
};

}

#endif // DEMO_CROSSHAIR_HPP
