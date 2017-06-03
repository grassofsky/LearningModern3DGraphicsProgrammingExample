#version 330

layout(location=0) in vec4 position;
layout(location=1) in vec4 color;

smooth out vec4 outColor;

uniform vec2 offset;
uniform float fNear;
uniform float fFar;
uniform float frustumScale;

void main()
{
    vec4 cameraPos = position + vec4(offset.x, offset.y, 0, 0);
    vec4 clipPos;
    clipPos.xy = cameraPos.xy*frustumScale;

    clipPos.z = cameraPos.z*(fNear+fFar)/(fNear-fFar);
    clipPos.z += 2*fNear*fFar/(fNear-fFar);

    clipPos.w = -cameraPos.z;

    gl_Position = clipPos;
    outColor = color;
}


