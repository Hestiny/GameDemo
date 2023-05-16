#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "main.h"

using namespace std;

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
GLFWwindow* _window = NULL;

int main()
{
	GetglfwWind();
	if (_window == NULL)
		return -1;

	UpdateGLFWwindow();
	return 0;
}

/// <summary>
/// 获取glfw窗口
/// </summary>
/// <returns></returns>
void GetglfwWind()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	_window = glfwCreateWindow(800, 600,
		"demo", NULL, NULL);
	if (_window == NULL)
	{
		cout << "Failed to create GLFW window" << endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(_window);
	glfwSetFramebufferSizeCallback(_window, FrameBufferSizeCallBack);
	//加载glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
	}
}

/// <summary>
/// 跟随窗口调整大小
/// </summary>
/// <param name="window"></param>
/// <param name="w"></param>
/// <param name="h"></param>
void FrameBufferSizeCallBack(GLFWwindow* window, int w, int h)
{
	glViewport(0, 0, w, h);
}

void UpdateGLFWwindow()
{
	while (!glfwWindowShouldClose(_window))
	{
		//输入检测
		ProcessInput(_window);
		//渲染

		//检查调用 交换缓冲
		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
	glfwTerminate();
}

void ProcessInput(GLFWwindow* window)
{
	//如果按下退出则关闭
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}


