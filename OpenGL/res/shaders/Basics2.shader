#shader vertex
#version 330 core
layout (location = 0) in vec4 aPos;
// layout (location = 1) in vec4 aColor;
// in vec4 aColor;
// layout (location = 1) in vec2 texCrood;
// out vec2 v_TexCrood;
// uniform mat4 u_MVP;
// uniform mat4 u_RM;
// uniform mat4 u_MVPM;
// out vec4 vColor;

void main() {
    gl_Position = aPos;
    // gl_Position = u_MVP*aPos;
    // gl_Position = u_RM*u_MVP*aPos;
    // gl_Position = u_RM*aPos;
    // vColor = aColor;
    // v_TexCrood = texCrood;
}



#shader fragment
#version 330 core
// in vec4 vColor;
// uniform sampler2D u_Texture;
// uniform float u_time;
// uniform vec2 u_resolution;
// uniform float u_r;
// uniform float u_g;
// uniform float u_b;
// in vec2 v_TexCrood;
out vec4 color;
void main()
{
//     vec4 texColor = texture(u_Texture, v_TexCrood);
//     vec3 circle = vec3(0.5, 0.5, 0.3);
//     vec2 div = vec2(480.0,480.0);
//     vec2 cl = gl_FragCoord.xy / div;
//     vec2 ncl = fract(cl);

//     float d = length(cl-circle.xy) - circle.z;
//     d = smoothstep(0.0,0.01, d);

//     vec4 tl = vec4(1.0, 0.0, 0.0, 1.0);
//     vec4 tr = vec4(0.8, 0.8, 0.0, 0.5);

//     vec4 bl = vec4(0.8, 0.8, 0.0, 0.5);
//     vec4 br = vec4(0.7, 0.1, 0.0, 1.0);

//     vec4 top = mix(tl, tr, cl.x);
//     vec4 bottom = mix(bl, br, cl.x);

//     vec4 c1 = mix(bottom, top, cl.y);

//     float cx = (sin(cl.x-u_time)+1.0)/2.0;
//     float cy = (sin(cl.y-u_time)+1.0)/2.0;
//     float c = (sin((cl.x * 40.0) - u_time * 2.0) + 1.0) / 2.0;
//     vec4 c2 = vec4(cl.x,1.0,1.0,1.0);
//     vec4 c3 = vec4(d,d,d, 1.0);
//     color = vec4(cl,1.0,1.0);
       // color =vColor;
       color = vec4(1.0f,1.0f,0.0f,1.0f);
//     color = vec4(texColor);
}

// #ifdef GL_ES
// precision mediump float;
// #endif

// uniform vec2 u_resolution;
// uniform float u_time;

// vec2 ani(vec2 st,float a){
//     int x;
//     if(int(floor(u_time))%2==0)
//         a=0.;
//     else if (!(int(floor(u_time))%2==0))
//         a=1.;
        
//     if(a==0.){
//     st.x += step(1., mod(st.y,2.0)) *u_time*2.;
// 	st.x-=u_time*1.;
//     }
//     if(a==1.){
//     st.y += step(1., mod(st.x,2.0)) *u_time*2.;
// 	st.y-=u_time*1.;
//     }
//     return st;
    
// }

// vec2 brickTile(vec2 _st, float _zoom){
//     _st *= _zoom;
		
//     Here is where the offset is happening
//     _st=ani(_st, u_time );
//     _st.x += step(1., mod(_st.y,2.0)) * u_time;
//     return fract(_st);
// }

// float box(vec2 _st, vec2 _size){
//     _size = vec2(0.5)-_size*0.5;
//     vec2 uv = smoothstep(_size,_size+vec2(1e-4),_st);
//     uv *= smoothstep(_size,_size+vec2(1e-4),vec2(1.0)-_st);
//     return uv.x*uv.y;
// }

// void main(void){
//     vec2 st = gl_FragCoord.xy/u_resolution.xy;
//     vec3 color = vec3(0.);

//     st /= vec2(2.15,0.65)/1.5;

//     Apply the brick tiling
//     st = brickTile(st,50.0);

//     color = vec3(box(st,vec2(0.380,0.450)),1.0,1.);

//     Uncomment to see the space coordinates
//     color = vec3(st,0.0);

//     gl_FragColor = vec4(color,1.0);
// }


    // if(arr[i]>=7&&arr[i<=14])
    