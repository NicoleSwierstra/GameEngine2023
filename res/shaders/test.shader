#shader vertex
#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
  
out vec3 color; // output a color to the fragment shader

void main()
{
    gl_Position = vec4(aPos, 1.0);
    color = vec3(0.5, 1.5, 0.5); // set ourColor to the input color we got from the vertex data
}       

#shader fragment
#version 330 core
out vec4 out_color;  
in vec3 color;
  
void main()
{
    out_color = vec4(color, 1.0);
}