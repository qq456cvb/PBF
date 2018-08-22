//
//  TimeStepper.cpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#include "TimeStepper.hpp"

void TimeStepper::step(Theme &theme, float h) {
    // gravity
    for (auto i = 0; i < theme.spheres.size(); i++) {
        theme.spheres[i].v[1] -= h * 9.8f;
        for (const auto &p : theme.planes) {
            if (theme.spheres[i].collide(p)) {
                theme.spheres[i].respond(p);
            }
        }
        theme.spheres[i].pos += h * theme.spheres[i].v;
    }
}
