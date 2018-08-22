//
//  sphere.hpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef sphere_hpp
#define sphere_hpp

#include <vector>
#include <stdio.h>
#include <glm/glm.hpp>
#include "plane.hpp"
using namespace std;
using namespace glm;


class Sphere {
public:
    Sphere(float r, vec2 pos) {
        this->pos = pos;
        this->v = vec2(0, 0);
        this->r = r;
    }
    
    vec2 pos;
    vec2 v;
    float r;
    
    bool collide(const Plane &plane);
    void respond(const Plane &plane);
};

#endif /* sphere_hpp */
