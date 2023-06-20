#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "main.h"
#include "Tool/CommonTool.h"
#include "debugTool/Debug.h"
#include <string>

using namespace DebugFrameWork;
using namespace CommonTool;

using std::string;

#define Length(array,type) (sizeof(array)/sizeof(type))


int main()
{
	Initglfw();
	if (!CreateGLFWwindow() || !LoadGL())
	{
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		ProcessInput(window);//设置回调

		Rander();

		glfwSwapBuffers(window);//交换颜色缓冲
		glfwPollEvents();//调用可用回调
	}
	glfwTerminate();
	return 0;
}

/// <summary>
/// 初始化glfw窗口 opengl的配置
/// </summary>
void Initglfw()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//主版本
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//次版本
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//核心模式
	Log("Init GlFW Success!", Green);
}

/// <summary>
/// 创建窗口并绑定上下文
/// </summary>
bool CreateGLFWwindow()
{
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "learnOpenGL", NULL, NULL);
	if (window == nullptr)
	{
		Log("Failed to create GLFW window!", Red);
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	Log("Create Window Success!", Green);
	return true;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

/// <summary>
/// load opengl function pointers
/// </summary>
bool LoadGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Log("Failed to initialize GLAD", Red);
		return false;
	}
	return true;
}

/// <summary>
/// 设置窗口输入
/// </summary>
/// <param name="windwow"></param>
void ProcessInput(GLFWwindow* windwow)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

#pragma region ====渲染====
void Rander()
{
	ClearWidow();
}

/// <summary>
/// 清空屏幕
/// </summary>
void ClearWidow()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}
#pragma endregion

#pragma region ====着色器====
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";

/// <summary>
/// 创建顶点着色器
/// </summary>
/// <param name="vertexShaderSource"></param>
/// <param name="vertexShaderId"></param>
/// <returns></returns>
bool CreateVertexShader(const char* vertexShaderSource, unsigned int* vertexShaderId = nullptr)
{
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	*vertexShaderId = vertexShader;
	glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		Log("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n", Red);
		Log(infoLog, Red);
		return false;
	}
	return true;
}

/// <summary>
/// 创建片段着色器
/// </summary>
/// <param name="fragmentShaderSource"></param>
/// <param name="fragmentShaderId"></param>
/// <returns></returns>
bool CreateFragmentShader(const char* fragmentShaderSource, unsigned int* fragmentShaderId = nullptr)
{
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	*fragmentShaderId = fragmentShader;
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
	glCompileShader(fragmentShader);

	int success;
	char infoLog[512];
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		Log("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n", Red);
		Log(infoLog, Red);
		return false;
	}
	return true;
}

/// <summary>
/// 创建着色器程序
/// </summary>
/// <param name="shaderProgramId"></param>
/// <param name=""></param>
/// <returns></returns>
bool CreateShaderProgram(unsigned int* shaderProgramId, unsigned int shaderList[])
{
	for (unsigned int i = 0; i < Length(shaderList, unsigned int); i++)
	{


	}
	return false;
}
#pragma endregion