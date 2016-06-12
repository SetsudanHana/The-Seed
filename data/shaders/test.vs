#version 410
layout(location = 0) in vec2 vertexPosition;
layout(location = 1) in vec2 vertexTexture;

uniform mat4 matrix;
uniform mat4 modelMatrix;

out vec2 textureCoords;

void main() {
	vec4 transformed = modelMatrix * vec4(vertexPosition.x, vertexPosition.y, 0.0, 1.0);
	textureCoords = vertexTexture;
	gl_Position = matrix * vec4(transformed.xyz, 1.0);
}