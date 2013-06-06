#include "Game.hpp"

#include <gdl/log/Emit.hpp>
#include <gdl/math/Vector2.hpp>
#include <gdl/ogl/Color.hpp>
#include <gdl/gui/Viewport.hpp>
#include <gdl/gui/Rectangle.hpp>
#include <gdl/gui/Button.hpp>
#include <gdl/gui/Label.hpp>
#include <gdl/ogl/FrameBuffer.hpp>

#include <sstream>
#include <thread>
#include <memory>

namespace demo
{

Game::Game(const std::string& title, int left, int top, unsigned int width, unsigned int height) :
	running(false),
	window(title, left, top, width, height),
    context(window.handle()),
	camera(window, width, height),
	terrain(128, 128),
	numberOfFrames(0)
{
	updatables.push_back(&camera);

    renderables.push_back(&xyz);
    renderables.push_back(&crosshair);
    renderables.push_back(&terrain);

    window.connect([&](const gdl::sys::Closed&){running = false;});

    window.setMouseVisible(false);
    context.clearColor(gdl::ogl::Color::CornflowerBlue);
}

Game::~Game() {}

void Game::run()
{
	previousTime = std::chrono::high_resolution_clock::now();

    gdl::ogl::Shader vs(gdl::ogl::Shader::Vertex,
        GLSL(
            uniform mat4 transform;
            uniform mat4 view;
            uniform mat4 projection;

            in vec2 position;

            void main(void)
            {
                gl_Position = projection * view * transform * vec4(position, 0, 1);
            }
        )
    );
    gdl::ogl::Shader fs(gdl::ogl::Shader::Fragment,
        GLSL(
            void main(void)
            {
                gl_FragColor = vec4(1, 0, 0, 1);
            }
        )
    );
    gdl::ogl::Program prog(vs, fs);

    std::vector<gdl::math::Vector2f> vertices = {
        {-.5f, -.5f},
        { .5f, -.5f},
        { .0f,  .5f}
    };

    gdl::ogl::VertexBuffer vb;
    vb.data(&vertices.front(), sizeof(vertices), gdl::ogl::BufferUsage::Static);

    gdl::ogl::VertexArray va;
    va.attribute(vb, {prog.attribute("position"), 2, gdl::gl::FLOAT, 0, 0});

    gdl::math::Matrix4f transform;

	running = true;
	while (running)
	{
		handleInput();
        update();

        context.clear();
		render();

//        prog.use();
//        prog.uniform("transform", transform);
//        prog.uniform("view", camera.view);
//        prog.uniform("projection", camera.projection);
//        va.draw(vb, gdl::ogl::PrimitiveType::Triangles, 0, 3);

        context.update();

        numberOfFrames++;
	}
}

void Game::handleInput()
{
	window.processEvents();
}

void Game::update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	auto elapsedTime = currentTime - previousTime;

	if (elapsedTime > std::chrono::seconds(1))
	{
		std::ostringstream oss;
		oss << (1000.0/double(numberOfFrames)) << " ms/frame | " << numberOfFrames << "fps";
		window.setTitle(oss.str());
		numberOfFrames = 0;
		previousTime = currentTime;
	}

	for (auto it = begin(updatables); it != end(updatables); ++it)
	{
		(*it)->update();
	}
}

void Game::render()
{
//    context.clear();

	for (auto it = begin(renderables); it != end(renderables); ++it)
	{
		(*it)->render(camera.view, camera.projection);
	}

//    context.update();

//	numberOfFrames++;
}

}
