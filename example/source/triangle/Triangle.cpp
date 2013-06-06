#include "gdl/sys/Window.hpp"
#include "gdl/ogl/Context.hpp"
#include "gdl/ogl/Color.hpp"
#include "gdl/ogl/Program.hpp"
#include "gdl/ogl/Shader.hpp"
#include "gdl/ogl/VertexArray.hpp"
#include "gdl/ogl/VertexBuffer.hpp"
#include "gdl/math/Vector2.hpp"
#include "gdl/log/Emit.hpp"

using namespace gdl;

int main()
{
    bool running = true;

    sys::Window wnd("Triangle", 0, 0, 800, 600);
    wnd.connect([&](const sys::Closed&){running = false;});

    ogl::Context ctx(wnd.handle());
    ctx.setVerticalSync(true);
    ctx.clearColor(ogl::Color::CornflowerBlue);

    ogl::Shader vs(ogl::Shader::Vertex,
        GLSL(
            in vec2 position;
            in vec4 color;
            out vec4 ex_Color;
            void main(void)
            {
                gl_Position = vec4(position, 0, 1);
                ex_Color = color;
            }
        )
    );
    ogl::Shader fs(ogl::Shader::Fragment,
        GLSL(
            in vec4 ex_Color;
            void main(void)
            {
                gl_FragColor = ex_Color;
            }
        )
    );
    ogl::Program prog(vs, fs);

    struct Vertex
    {
        math::Vector2f position;
        ogl::Color color;
    };

    std::vector<Vertex> vertices = {
        {{-.5f, -.5f}, ogl::Color::Red},
        {{ .5f, -.5f}, ogl::Color::Green},
        {{ .0f,  .5f}, ogl::Color::Blue}
    };

    ogl::VertexBuffer vb;
    vb.data(&vertices.front(), sizeof(Vertex) * vertices.size(), ogl::BufferUsage::Static);

    ogl::VertexArray va;
    va.attribute(vb, {prog.attribute("position"), 2, gl::FLOAT, sizeof(Vertex), 0});
    va.attribute(vb, {prog.attribute("color"), 4, gl::FLOAT, sizeof(Vertex), (const GLvoid*)8});

    while (running)
    {
        wnd.processEvents();

        ctx.clear();

        prog.use();
        va.draw(vb, ogl::PrimitiveType::Triangles, 0, vertices.size());

        ctx.update();
    }
}
