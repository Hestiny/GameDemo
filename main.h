#pragma once

GLFWwindow* window;
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void Initglfw();
bool CreateGLFWwindow();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
bool LoadGL();
void ProcessInput(GLFWwindow* windwow);

void Rander();
void ClearWidow();
bool CreateVertexShader(const char*, unsigned int*);