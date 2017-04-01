#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <ctime>

const float Pi = 3.14159;

//Coordenadas da janela do mundo (Ortho2D)
const float Xmin = -1.0;
const float Xmax = 1.0;
const float Ymin = -1.0;
const float Ymax = 1.0;

using namespace std;

class Shape
{
public:
	Shape() {}
	~Shape() {}
	void DrawCircle(float posX, float posY, float radius, float nPoints);
	void DrawTriangle();
	void DrawGrid();
	void DrawCama();
};
