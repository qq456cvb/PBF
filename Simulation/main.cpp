//
//  main.cpp
//  Simulation
//
//  Created by Neil on 2018/8/19.
//  Copyright © 2018 Neil. All rights reserved.
//

#include <iostream>
#include "ColorShader.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "common/shader.hpp"
using namespace std;
#include <vector>
#include <unistd.h>
#include <glm/glm.hpp>
#include "sphere.hpp"
#include "TimeStepper.hpp"

int main(int argc, const char * argv[]) {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        return 1;
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 640, "Simulator", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);
    
    int height, width;
    glfwGetFramebufferSize(window, &width, &height);
    
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();
    
    glClearColor(0, 0, 0, 1.0);
    float mvp[16] = {1.f, 0, 0, 0, 0, 1.f, 0, 0, 0, 0, 1.f, 0, 0, 0, 0, 1.f};
    
    auto shader = new ColorShader();
    vector<Sphere> spheres;
    float r = 0.02f;
    int res = 20;
    int num_spheres = 40;
    for (size_t i = 0; i < num_spheres; i++) {
        float center[] = {-0.9f + i * 1.8f / num_spheres, -0.9f +  i * 1.8f / num_spheres};
        spheres.push_back(Sphere(r, vec2(center[0], center[1])));
    }
    vector<Plane> planes;
    planes.emplace_back(vec2(0, -1.f), vec2(0, 1.f));
    
    shader->bindVAO(r, res);
    TimeStepper stepper;
    Theme theme(spheres, planes);
    while(!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        shader->setMVPMatrix(mvp);
        shader->updateVBO(GL_TRIANGLES, (float*)&theme.spheres[0], num_spheres);
//        color[0] -= (cnt++) / 1000.0;
        stepper.step(theme, 0.01f);
        usleep(10);
        // put the stuff we've been drawing onto the display
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    delete shader;
    return 0;
}
