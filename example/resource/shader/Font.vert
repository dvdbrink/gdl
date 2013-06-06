#version 330

uniform mat4 world;
uniform mat4 projection;

in vec4 position;
out vec2 texCoord;

void main(void) {
	gl_Position = projection * world * vec4(position.xy, 0.0f, 1.0f);
	texCoord = position.zw;
}
