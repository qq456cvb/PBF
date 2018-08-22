//
//  plane.hpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef plane_hpp
#define plane_hpp

#include <stdio.h>
#include <glm/glm.hpp>
using namespace glm;

class Plane {
    
public:
    Plane(vec2 x, vec2 n) : x(x), n(n) {}
    vec2 x, n;
};

#endif /* plane_hpp */
