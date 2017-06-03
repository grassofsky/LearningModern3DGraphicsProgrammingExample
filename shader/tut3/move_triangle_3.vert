#version 330

layout(location=0) in vec4 position;

out vec4 color;
uniform float fLoopDuration;
uniform float time;

void main()
{
    float fScale = 3.1415927 * 2.0f / fLoopDuration;
    float fCurrTimpeThroughLoop = mod(time, fLoopDuration);

    vec2 offset = vec2(cos(fCurrTimpeThroughLoop*fScale)*0.5f, sin(fCurrTimpeThroughLoop*fScale)*0.5f);
    gl_Position = position+vec4(offset.x, offset.y, 0, 0);
    color = vec4(position.xyz, 1.0);
}


