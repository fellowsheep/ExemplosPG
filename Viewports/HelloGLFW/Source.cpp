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

#define NVIEWPORTS 1  //vai gerar NVIEWPORTS x NVIEWPORTS, na verdade

using namespace std;

Shape shape; //objeto da classe shape

bool drawCircle = false; //flag para habilitar o desenho de círculos (apenas um exemplo)


//Protótipos de algumas funções (para não se preocupar com a ordem)
void ajustaCamera2D(int width, int height);


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

//Callback de redimensionamento
void reshape(GLFWwindow* window, int width, int height)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (height == 0)
		height = 1;

	ajustaCamera2D(width,height);

}

void ajustaCamera2D(int width, int height)
{
	//Ativa a matriz de projeção --> conceitos mais tarde!!
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width < height) //altura menor que largura
	{
		float aspecto = (float)height / width; //proporcao altura/largura 
		gluOrtho2D(Xmin, Xmax, Ymin*aspecto, Ymax*aspecto); //corrige a proporção na largura
	}
	else {
		float aspecto = (float)width / height; //proporcao largura/altura
		gluOrtho2D(Xmin*aspecto, Xmax*aspecto, Ymin, Ymax); //corrige a proporção na altura

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

	//Setando a callback de reshape
	glfwSetFramebufferSizeCallback(window, reshape);

	int width, height;
	float ratio;

	ajustaCamera2D(640, 480);

	while (!glfwWindowShouldClose(window)) //loop da aplicação :)
	{	

		//aqui recupera o tamanho atual da janela
		glfwGetFramebufferSize(window, &width, &height);

		// Limpa a janela de visualização com a cor branca
		glClearColor(1, 1, 1, 0);
		glClear(GL_COLOR_BUFFER_BIT);

		//seta a matriz de modelo 
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();


		for (int i = 0; i<NVIEWPORTS; i++) 
		{
			for (int j = 0; j<NVIEWPORTS; j++)
			{
				// Define a viewport
				glViewport(j*width/(float)NVIEWPORTS, i*height / (float)NVIEWPORTS, width / (float)NVIEWPORTS, height / (float)NVIEWPORTS);

				// Chamando as rotinas de desenho                        
				shape.DrawGrid();
				glPointSize(10);
				glColor3f(1, 0, 0);
				glBegin(GL_POINTS);
				glVertex2f(0, 0);
				glEnd();
				//shape.DrawTriangle();
				glPushMatrix();
				glTranslatef(-0.2, 0.4, 0);	
				glPushMatrix();
				glRotatef(90.0, 0, 0, 1);		
				shape.DrawCama();
				glPopMatrix();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(-0.2, 0.1, 0);
				glPushMatrix();
				glRotatef(90.0, 0, 0, 1);
				shape.DrawCama();
				glPopMatrix();
				glPopMatrix();
			}
		}

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);

	return 0;
}
