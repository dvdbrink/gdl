#version 330

uniform mat4 world;
uniform mat4 view;
uniform mat4 projection;

in vec3 position;
in vec2 texCoord;
out vec2 ex_TexCoord;

void main(void) {
    gl_Position = projection * view * world * vec4(position, 1.0f);
    ex_TexCoord = texCoord;
}
