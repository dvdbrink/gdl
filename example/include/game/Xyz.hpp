#ifndef DEMO_XYZ_HPP
#define DEMO_XYZ_HPP

#include "Renderable.hpp"

#include <gdl/ogl/Shader.hpp>
#include <gdl/ogl/Program.hpp>
#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/math/Matrix.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/ogl/VertexArray.hpp>

#include <vector>

namespace demo
{

class Xyz : public Renderable
{
    struct Vertex
    {
        gdl::math::Vector3f position;
        gdl::ogl::Color color;
    };

public:
	Xyz();
	void render(const gdl::math::Matrix4f& view, const gdl::math::Matrix4f& projection);

private:
    gdl::math::Matrix4f transform;
    gdl::ogl::VertexArray va;
    gdl::ogl::Shader vs, fs;
    gdl::ogl::Program program;
    gdl::ogl::VertexBuffer vb;
    std::vector<Vertex> vertices;
};

}

#endif // DEMO_XYZ_HPP
