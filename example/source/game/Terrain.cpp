#include "Terrain.hpp"

#include <gdl/log/Emit.hpp>

namespace demo
{

Terrain::Terrain(unsigned int width, unsigned int height) :
    width(width), height(height),
    vs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Vertex, "resource/shader/VertexPositionTexture.vert")),
    fs(gdl::ogl::Shader::fromFile(gdl::ogl::Shader::Fragment, "resource/shader/VertexPositionTexture.frag")),
    program(vs, fs),
    texture(gdl::ogl::Image{"resource/texture/paper.jpg"}),
    heightmap("resource/texture/heightmap.bmp")
{
    texture.setWrapping(gdl::ogl::Wrapping::Repeat, gdl::ogl::Wrapping::Repeat);
    texture.setFilter(gdl::ogl::Filter::Linear, gdl::ogl::Filter::LinearMipmapLinear);
	texture.generateMipMaps();

	setUpVertices();
	setUpIndices();

    va.attribute(vb, gdl::ogl::Attribute{program.attribute("position"), 3, gdl::gl::FLOAT, sizeof(Vertex), 0});
    va.attribute(vb, gdl::ogl::Attribute{program.attribute("texCoord"), 2, gdl::gl::FLOAT, sizeof(Vertex), (const GLvoid*)12});
}

Terrain::~Terrain() {}

void Terrain::render(const gdl::math::Matrix4f& view, const gdl::math::Matrix4f& projection)
{
    program.use();

    program.uniform("world", transform);
    program.uniform("view", view);
    program.uniform("projection", projection);

    texture.bind();
    va.draw(vb, ib, gdl::ogl::PrimitiveType::Triangles, gdl::gl::UNSIGNED_SHORT, indices.size());
	texture.unbind();
}

void Terrain::setUpVertices()
{
    vertices.clear();
	for (unsigned int y = 0; y < height; y++)
	{
		for (unsigned int x = 0; x < width; x++)
		{
			float height = heightmap.getPixels()[(x + y * width) * heightmap.getChannels()] / 5.0f;
			vertices.push_back({{static_cast<float>(x), height, static_cast<float>(y)}, {x / 30.0f, y / 30.0f}});
		}
	}
    vb.data(&vertices.front(), sizeof(Vertex) * vertices.size(), gdl::ogl::BufferUsage::Static);
}

void Terrain::setUpIndices()
{
    indices.clear();
	for (unsigned int y = 0; y < height-1; y++)
	{
		for (unsigned int x = 0; x < width-1; x++)
		{
			unsigned short topLeft = x + y * width;
			unsigned short topRight = (x+1) + y * width;
			unsigned short lowerLeft = x + (y+1) * width;
			unsigned short lowerRight = (x+1) + (y+1) * width;

			indices.push_back(topLeft);
			indices.push_back(lowerLeft);
			indices.push_back(lowerRight);

			indices.push_back(lowerRight);
			indices.push_back(topRight);
			indices.push_back(topLeft);
		}
	}
    ib.data(&indices.front(), sizeof(gdl::Uint16) * indices.size(), gdl::ogl::BufferUsage::Static);
}

}
