#shader vertex
#version 330 core
layout (location = 0) in vec4 aPos;
// layout (location = 1) in vec4 aColor;
in vec4 aColor;
// layout (location = 1) in vec2 texCrood;
// out vec2 v_TexCrood;
// uniform mat4 u_MVP;
uniform mat4 u_RM;
// uniform mat4 u_MVPM;
out vec4 vColor;

void main() {
    // gl_Position = aPos;
    // gl_Position = u_MVP*aPos;
    // gl_Position = u_RM*u_MVP*aPos;
    gl_Position = u_RM*aPos;
    vColor = aColor;
    // v_TexCrood = texCrood;
}



#shader fragment
#version 330 core
in vec4 vColor;
// uniform sampler2D u_Texture;
// uniform float u_time;
// uniform float u_r;
// uniform float u_g;
// uniform float u_b;
// in vec2 v_TexCrood;
out vec4 color;
void main()
{
    // vec4 texColor = texture(u_Texture, v_TexCrood);
    // vec3 circle = vec3(0.5, 0.5, 0.3);
    // vec2 div = vec2(480.0,480.0);
    // vec2 cl = gl_FragCoord.xy / div;
    // vec2 ncl = fract(cl);

    // float d = length(cl-circle.xy) - circle.z;
    // d = smoothstep(0.0,0.01, d);

    // vec4 tl = vec4(1.0, 0.0, 0.0, 1.0);
    // vec4 tr = vec4(0.8, 0.8, 0.0, 0.5);

    // vec4 bl = vec4(0.8, 0.8, 0.0, 0.5);
    // vec4 br = vec4(0.7, 0.1, 0.0, 1.0);

    // vec4 top = mix(tl, tr, cl.x);
    // vec4 bottom = mix(bl, br, cl.x);

    // vec4 c1 = mix(bottom, top, cl.y);

    // float cx = (sin(cl.x-u_time)+1.0)/2.0;
    // float cy = (sin(cl.y-u_time)+1.0)/2.0;
    // float c = (sin((cl.x * 40.0) - u_time * 2.0) + 1.0) / 2.0;
    // vec4 c2 = vec4(cl.x,1.0,1.0,1.0);
    // vec4 c3 = vec4(d,d,d, 1.0);
    // color = vec4(cl,1.0,1.0);
    color =vColor;
    // color = vec4(1.0f);
    // color = vec4(texColor);
}