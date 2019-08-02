#version 330 core                                     
layout(location = 0) in vec3 aPos;                 
void main(){                                       
  gl_Position.xyz = aPos;                         
  gl_Position.w = 1.0;      
}                    