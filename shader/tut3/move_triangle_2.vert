#version 330

layout(location=0) in vec4 position;

out vec4 color;
uniform vec2 offset;

void main()
{
    gl_Position = position+vec4(offset.x, offset.y, 0, 0);
    color = vec4(position.xyz, 1.0);
}


