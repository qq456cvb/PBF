//#version 150
//in vec4 vColor;
//out vec4 frag_colour;
//
//void main() {
//  frag_colour = vColor;
//}

#version 330 core
in vec3 vColor;
out vec3 frag_color;
void main() {
    frag_color = vec3(1., 0, 0);
}

