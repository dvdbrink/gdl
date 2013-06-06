#version 330

uniform mat4 world;

in vec3 position;
out vec4 ex_Color;

void main(void) {
    gl_Position = world * vec4(position, 1.0f);
    ex_Color = vec4(0);
}
