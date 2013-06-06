#ifndef DEMO_TERRAIN_HPP
#define DEMO_TERRAIN_HPP

#include "Renderable.hpp"

#include <gdl/ogl/Image.hpp>
#include <gdl/ogl/IndexBuffer.hpp>
#include <gdl/ogl/Program.hpp>
#include <gdl/ogl/Shader.hpp>
#include <gdl/ogl/Texture.hpp>
#include <gdl/ogl/VertexBuffer.hpp>
#include <gdl/math/Vector2.hpp>
#include <gdl/ogl/VertexArray.hpp>

namespace demo
{

class Terrain : public Renderable
{
    struct Vertex
    {
        gdl::math::Vector3f position;
        gdl::math::Vector2f texCoords;
    };

public:
	Terrain(unsigned int width, unsigned int height);
	virtual ~Terrain();
	void render(const gdl::math::Matrix4f& view, const gdl::math::Matrix4f& projection);

private:
	void setUpVertices();
	void setUpIndices();

private:
	unsigned int width, height;
    gdl::math::Matrix4f transform;
    gdl::ogl::VertexArray va;
    gdl::ogl::IndexBuffer ib;
    gdl::ogl::VertexBuffer vb;
	std::vector<gdl::Uint16> indices;
    std::vector<Vertex> vertices;
    gdl::ogl::Shader vs, fs;
    gdl::ogl::Program program;
    gdl::ogl::Texture texture;
    gdl::ogl::Image heightmap;
};

}

#endif // DEMO_TERRAIN_HPP
