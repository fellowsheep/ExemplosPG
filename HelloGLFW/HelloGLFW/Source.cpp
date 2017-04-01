//*****************************************************
//
// PrimeiroProjetoOpenGLGLFW
//
// Finalmente, removendo a GLUT da história :D
//
// Adaptado do projeto com GLUT por Rossana B. Queiroz 08/2011
// Última modificação: 03/05/2016
//*****************************************************

#include <cstdlib>
#include <iostream>
#include "Shapes.h" //é a Shapes que está incluindo a glfw!

using namespace std;

Shape shape; //objeto da classe shape

bool drawCircle = false; //flag para habilitar o desenho de círculos (apenas um exemplo)

//Callback de erro 
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

//Callback de teclado
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_C && action == GLFW_PRESS)
	{
		drawCircle = !drawCircle;
	}
}


// Programa Principal 
int main(void)
{
	srand(time(0));

	//Inicialização da janela da aplicação
	GLFWwindow* window;

	//Setando a callback de erro
	glfwSetErrorCallback(error_callback);

	//Inicializando a lib
	if (!glfwInit())
		exit(EXIT_FAILURE);

	//Criando a janela
	window = glfwCreateWindow(640, 480, "HELLO GLFW!! BYE BYE GLUT!!!", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//Colocando a janela criada como sendo o contexto atual
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	//Setando a callback de teclado
	glfwSetKeyCallback(window, key_callback);

	while (!glfwWindowShouldClose(window)) //loop da aplicação :)
	{
		float ratio;
		int width, height;

		//aqui recupera o tamanho atual da janela, para correção do aspect ratio mais tarde
		glfwGetFramebufferSize(window, &width, &height);
		

		//setando a viewport da OpenGL, para ocupar toda a janela da aplicação
		glViewport(0, 0, width, height);

		// Limpa a janela de visualização com a cor branca
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//Setando a matriz de projeção, para definir o Ortho (câmera ortográfica 2D)
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		//Setando a janela do mundo a ser vista (window), a câmera ortográfica 2D
		gluOrtho2D(-1, 1, -1, 1);

		//Trocando para a matriz de modelo
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Mandando desenhar as primitivas (círculo ou triângulo)		
		if (drawCircle)
		{
			shape.DrawCircle(0.0, 0.0, 0.75, 50); //as cores dos vertices vão ser sorteadas a cada frame
		}
		else
		{
			shape.DrawTriangle();
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
