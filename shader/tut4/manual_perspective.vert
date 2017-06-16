#version 330

layout(location=0) in vec4 position;
layout(location=1) in vec4 color;

smooth out vec4 outColor;

uniform vec2 offset;
uniform float fNear;
uniform float fFar;
uniform float xfrustumScale;
uniform float yfrustumScale;

void main()
{
    vec4 cameraPos = position + vec4(offset.x, offset.y, 0.0f, 0.0f);
    vec4 clipPos;
    clipPos.x = cameraPos.x*xfrustumScale;
    clipPos.y = cameraPos.y*yfrustumScale;

    clipPos.z = cameraPos.z*(fNear+fFar)/(fNear-fFar);
    clipPos.z = clipPos.z + 2.0f*fNear*fFar/(fNear-fFar);

    clipPos.w = -cameraPos.z;


    clipPos.z = 0.0; // In the example the z is out of the range [-1,1]

    gl_Position = clipPos;
    outColor = color;
}


