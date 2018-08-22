//
//  theme.hpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef theme_hpp
#define theme_hpp

#include <stdio.h>
#include <vector>
#include "sphere.hpp"
#include "plane.hpp"

using namespace std;
class Theme {
    
public:
    Theme(const vector<Sphere> &spheres, const vector<Plane> &planes)
        : spheres(spheres), planes(planes) {}
    vector<Sphere> spheres;
    vector<Plane> planes;
};
#endif /* theme_hpp */
