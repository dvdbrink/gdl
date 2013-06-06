#version 330

uniform mat4 projection;
uniform mat4 world;

in vec4 position;
in vec4 color;
out vec4 ex_Color;

void main(void) {
        gl_Position = projection * world * vec4(position.xy, 0.0f, 1.0f);
        ex_Color = color;
}
