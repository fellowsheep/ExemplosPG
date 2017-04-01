#include "Shapes.h"

void Shape::DrawCircle(float posX, float posY, float radius, float nPoints)
{
	float rd = radius;

	float angle = 0.0;
	float slice = 2 * Pi / nPoints;
	float x, y;

	float xi = posX;
	float yi = posY;

	//Habilitar a cor do círculo
	glColor3f(0, 0, 0);

	//Tamanho do ponto
	glPointSize(5);

	//Espessura da linha
	glLineWidth(3);

	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glBegin(GL_POLYGON);
	while (angle <= 2 * Pi)
	{
		//Sorteia uma cor para o vertice
		float r = rand() % 10 / 10.0;
		float b = rand() % 10 / 10.0;
		float g = rand() % 10 / 10.0;

		glColor3f(r, g, b);

		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	//Para desenhar o contorno
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(0, 0, 0);
	angle = 0.0;
	glBegin(GL_LINE_LOOP);
	while (angle <= 2 * Pi)
	{
		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();

	//Para desenhar os pontos
	//Habilitar o desenho do tipo de primitiva escolhido (ponto, linha, polígono etc)
	glColor3f(1, 0, 1);
	angle = 0.0;
	glBegin(GL_POINTS);
	while (angle <= 2 * Pi)
	{
		//Calcular posicao do ponto em x, y
		x = xi + rd * cos(angle);
		y = yi + rd * sin(angle);
		glVertex2f(x, y);
		//Atualizar o angulo
		angle += slice;
	}
	//Desabilita o desenho do tipo de primitiva
	glEnd();
	
}

void Shape::DrawTriangle()
{
	glPointSize(15);
	glLineWidth(3);

	// Desenha um triângulo no centro da janela
	glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(-0.5,-0.5);
		glColor3f(0,1,0);
		glVertex3f( 0.0, 0.5,0);
		glColor3f(0,0,1);
		glVertex3f( 0.5,-0.5,0);
	glEnd();

	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(-0.5,-0.5);
		glVertex3f( 0.0, 0.5,0);
		glVertex3f( 0.5,-0.5,0);
	glEnd();

	glColor3f(0, 1, 1);
	glBegin(GL_POINTS);
	glVertex2f(-0.5, -0.5);
	glVertex3f(0.0, 0.5, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
}

void Shape::DrawGrid()
{
	glLineWidth(1);

	float xi = Xmin;
	float yi = Ymin;
	float ncells = 40.0;

	float cell = (Xmax - Xmin )/ ncells;
	
	glPointSize(10);
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex2f(Xmin, Ymin);
	glVertex2f(Xmin, Ymax);
	glVertex2f(Xmax, Ymin);
	glVertex2f(Xmax, Ymax);
	glEnd();

	glColor3f(0.8, 0.8, 0.8);
	for (int i = 0; i < ncells; i++)
	{
		for (int j = 0; j < ncells; j++)
		{
			
			glBegin(GL_LINE_LOOP);
			glVertex2f(xi + cell*j, yi + cell*i);
			glVertex2f(xi + cell*(j+1), yi + cell*i);
			glVertex2f(xi + cell*(j + 1), yi + cell*(i+1));
			glVertex2f(xi + cell*j, yi + cell*(i+1));
			glEnd();
		}
	}

}

void Shape::DrawCama()
{
	glLineWidth(2);
	glColor3ub(50, 50, 50);

	glBegin(GL_LINE_LOOP);
	glVertex2f(-0.1, -0.2);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.1, 0.2);
	glVertex2f(-0.1, 0.2);
	glEnd();
	glLineWidth(1);
}
