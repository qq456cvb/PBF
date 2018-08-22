//
//  ColorShader.hpp
//  Tracking3D
//
//  Created by Neil on 17/10/2017.
//  Copyright © 2017 Neil. All rights reserved.
//

#ifndef ColorShader_hpp
#define ColorShader_hpp

#include "ShaderProgram.hpp"
#include <glm/glm.hpp>
#include "sphere.hpp"

#include <stdio.h>
using namespace glm;

#define MAX_PARTICLES 10000

class ColorShader
{
public:
    ColorShader() {
        init();
    }
    ~ColorShader() {
        free();
    }
    
    bool init();
    void free() {mProgram.free();}
    
    //mvp is in normal opencv row-major order
    void setMVPMatrix(float *mvp);
    
    void bindVAO(float r, float res);
    void updateVBO(GLenum mode, float *translation, int prim_count);
    GLuint vbos[3];
    GLuint vao;
    ShaderProgram mProgram;
protected:
    
    int mUniformMVPMatrix;
    int mAttribPosCoord;
    int mAttribColor;
    int mAttribTranslation;
    
};
#endif /* ColorShader_hpp */

