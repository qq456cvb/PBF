//
//  TimeStepper.hpp
//  Simulation
//
//  Created by Neil on 2018/8/21.
//  Copyright © 2018 Neil. All rights reserved.
//

#ifndef TimeStepper_hpp
#define TimeStepper_hpp

#include <stdio.h>
#include "theme.hpp"
#include <vector>
using namespace std;
using namespace glm;

class TimeStepper {
    
public:
    void step(Theme &theme, float h);
};

#endif /* TimeStepper_hpp */
