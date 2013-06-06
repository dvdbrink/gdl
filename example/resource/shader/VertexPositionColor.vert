#version 330

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

in vec3 position;
in vec4 color;
out vec4 ex_Color;

void main(void) {
    gl_Position = projection * view * world * vec4(position, 1.0f);
    ex_Color = color;
}
