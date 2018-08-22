//
//  sphere.cpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#include "sphere.hpp"
#include <iostream>

bool Sphere::collide(const Plane &plane) {
    float dist = - dot(plane.x - pos, plane.n) / plane.n.length();
//    vec2 n = dot(plane.x - pos, plane.n) * plane.n / dot(plane.n, plane.n);
    if (dist < r && dot(v, plane.n) < 0) {
        return true;
    }
    return false;
}

void Sphere::respond(const Plane &plane) {
    float cor = 0.75f;
    float I_ratio = (1. + cor) / 2.;
    auto n_unit = normalize(plane.n);
    v -= 2 * I_ratio * dot(v, n_unit) * n_unit;
}
