#ifndef DEMO_DEMO_HPP
#define DEMO_DEMO_HPP

#include "Camera.hpp"
#include "Crosshair.hpp"
#include "Terrain.hpp"
#include "Updatable.hpp"
#include "Xyz.hpp"
#include "Renderable.hpp"

#include <gdl/gui/Text.hpp>
#include <gdl/ogl/Context.hpp>
#include <gdl/sys/Window.hpp>
#include <gdl/gui/Container.hpp>
#include <gdl/gui/Console.hpp>

#include <chrono>
#include <vector>

namespace demo
{

class Game
{
public:
	Game(const std::string& title, int left, int top, unsigned int width, unsigned int height);
	virtual ~Game();

	virtual void run();

private:
	virtual void handleInput();
	virtual void update();
	virtual void render();

private:
	bool running;

    gdl::sys::Window window;
    gdl::ogl::Context context;

	Camera camera;
	Xyz xyz;
	Terrain terrain;
	Crosshair crosshair;

	std::vector<Updatable*> updatables;
    std::vector<Renderable*> renderables;

	std::chrono::high_resolution_clock::time_point previousTime;
	int numberOfFrames;
};

}

#endif // DEMO_DEMO_HPP
