//
//  ColorShader.cpp
//  Tracking3D
//
//  Created by Neil on 17/10/2017.
//  Copyright © 2017 Neil. All rights reserved.
//

#include "ColorShader.hpp"


bool ColorShader::init()
{
    bool res = true;
    
    const char *uniforms[] = { "uMVPMatrix" };
    int *uniformIds[] = {&mUniformMVPMatrix};
    const int uniformsCount = sizeof(uniforms) / sizeof(uniforms[0]);
    
    const char *attribs[] =    { "aPos", "aColor", "aTranslation" };
    int *attribIds[] = {&mAttribPosCoord, &mAttribColor, &mAttribTranslation };
    const int attribsCount = sizeof(attribs) / sizeof(attribs[0]);
    
    glGenBuffers(3, vbos);
    res &= mProgram.load("shaders/color_render.vert", "shaders/color_render.frag", uniforms, uniformIds, uniformsCount,
                         attribs, attribIds, attribsCount);
    glGenVertexArrays(1, &vao);
    
    return res;
}

void ColorShader::setMVPMatrix(float *mvp)
{
    //Transpose to opengl column-major format
    glUseProgram(mProgram.getId());
    glUniformMatrix4fv(mUniformMVPMatrix, 1, false, mvp);
}

void ColorShader::bindVAO(float r, float res)
{
    vec3 vertices[22];
    vertices[0] = vec3(0, 0, 0);
    for (size_t i = 0; i < res + 1; i++) {
        auto x = r * cos(2 * M_PI / res * i);
        auto y = r * sin(2 * M_PI / res * i);
        vertices[i + 1] = vec3(x, y, 0);
    }
    
    uint32_t indices[20 * 3] = {
        0, 2, 1,
        0, 3, 2,
        0, 4, 3,
        0, 5, 4,
        0, 6, 5,
        0, 7, 6,
        0, 8, 7,
        0, 9, 8,
        0, 10, 9,
        0, 11, 10,
        0, 12, 11,
        0, 13, 12,
        0, 14, 13,
        0, 15, 14,
        0, 16, 15,
        0, 17, 16,
        0, 18, 17,
        0, 19, 18,
        0, 20, 19,
        0, 21, 20
    };
    
    glUseProgram(mProgram.getId());
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbos[0]);
    glBufferData(GL_ARRAY_BUFFER, 22 * 3 * sizeof(float), &vertices[0], GL_STATIC_DRAW);
    glVertexAttribPointer(mAttribPosCoord, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbos[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 60 * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * sizeof(Sphere), NULL, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(mAttribTranslation, 2, GL_FLOAT, GL_FALSE, sizeof(Sphere), NULL);
    
    glBindVertexArray(0);
}

void ColorShader::updateVBO(GLenum mode, float *translation, int prim_count)
{
    glUseProgram(mProgram.getId());
    
    glBindBuffer(GL_ARRAY_BUFFER, vbos[2]);
    glBufferData(GL_ARRAY_BUFFER, MAX_PARTICLES * sizeof(Sphere), NULL, GL_STREAM_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, prim_count * sizeof(Sphere), translation);
    
    glBindVertexArray(vao);
    glEnableVertexAttribArray(mAttribPosCoord);
    glEnableVertexAttribArray(mAttribTranslation);
    glVertexAttribDivisor(mAttribTranslation, 1);
    
    glDrawElementsInstanced(mode, 60, GL_UNSIGNED_INT, NULL, prim_count);
    
    glDisableVertexAttribArray(mAttribPosCoord);
    glDisableVertexAttribArray(mAttribTranslation);
    
    glBindVertexArray(0);
}

