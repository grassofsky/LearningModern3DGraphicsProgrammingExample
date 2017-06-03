#version 330

layout(location=0) in vec4 position;

out vec4 color;

void main()
{
gl_Position = position;
color = vec4(position.xyz, 1.0);
}


