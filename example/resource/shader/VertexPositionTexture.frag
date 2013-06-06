#version 330

in vec2 ex_TexCoord;
out vec4 out_Color;

uniform sampler2D tex;

void main(void) {
	out_Color = texture(tex, ex_TexCoord);
}