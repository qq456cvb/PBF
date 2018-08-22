//#version 150
//
//in vec4 aPosCoord;
//in vec4 aColor;
//uniform mat4 uMVPMatrix;
//
//out vec4 vColor;
//
//void main() {
//    vColor = aColor;
//    gl_Position = aPosCoord;
//}
#version 330 core
in vec3 aPos;
in vec3 aColor;
in vec2 aTranslation;

out vec3 vColor;
uniform mat4 uMVPMatrix;

void main() {
    gl_Position = vec4(aPos + vec3(aTranslation, 0), 1.0);
    vColor = aColor;
}


