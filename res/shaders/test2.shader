#shader vertex
#version 330 core

layout(location = 0) in vec4 v_position;
layout(location = 1) in vec3 v_normal;
layout(location = 2) in vec2 v_texCoords;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 trans;

out vec2 coords;
out vec3 norm;

void main() {
	gl_Position = proj * view * trans * vec4(v_position.xyz, 1.0f);
	coords = v_texCoords;
	norm = normalize(v_normal);
};

#shader fragment
#version 330 core

in vec2 coords;
in vec3 norm;

out vec4 color;

void main() {
	color = vec4(1 - coords.x, coords.x, coords.y, 1.0f);
};