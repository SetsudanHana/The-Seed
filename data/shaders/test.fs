#version 410

in vec2 textureCoords;

uniform sampler2D sampler;

out vec4 color;

void main() {
	vec4 texel = texture2D( sampler, textureCoords );
	color = texel;
}