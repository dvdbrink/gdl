#version 330

uniform float transparency;
uniform vec4 color;

out vec4 out_Color;

void main(void) {
        out_Color = vec4(color.rgb, transparency);
}
