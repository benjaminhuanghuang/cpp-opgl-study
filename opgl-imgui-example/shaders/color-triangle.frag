#version 450 core
//color is an input vertex attribute
layout (location =0) in vec4 color;

//out_color is an output variable that will be sent to the next shader
out vec4 out_color;

void main(){
//...Shader stuffs here

//output a color to the fragment shader through out_color;
out_color=vec4(1.0,0.0,0.0,1.0);
}