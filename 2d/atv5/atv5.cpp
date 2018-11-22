///////////////////
// Jonathan Sias //
///////////////////
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#include <cmath>

#define TAMJANELA 600

using namespace std;

void Inicializa(void) {
	glClearColor(1, 1, 1, 0);
}

void pontosCirc(int x, int y, int x1, int y1, int flag)
{
	if (flag == 0) {
		glBegin(GL_POINTS);
	}else{
		if (flag == 1) {
			glBegin(GL_POLYGON);
		}else{
			cout << "ACHOU ERRADO OTÁRIO !" << endl;
			exit(-1);
		}
	}

    glVertex2i(x1+x, y1+y);
    glVertex2i(x1+y, y1+x);
    glVertex2i(x1+y, y1-x);
    glVertex2i(x1+x, y1-y);
    glVertex2i(x1-x, y1-y);
    glVertex2i(x1-y, y1-x);
    glVertex2i(x1-y, y1+x);
    glVertex2i(x1-x, y1+y);
  glEnd();
}

void desenhaCirc(int raio, int x1, int y1, int flag)
{
  int x, y;
  float d;
  x = 0;
  y = raio;
  d = 5./4-raio;
  pontosCirc(x, y, x1, y1, flag);
  while(y > x)
  {
    if(d < 0)
      d = d + 2*x + 3;
    else {
       d = d + 2*(x-y) + 5;
       y = y-1;
      }
    x = x + 1;
    pontosCirc(x, y, x1, y1, flag);
  }
}

void Desenha(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  // cabeça
  // poligono
  glColor3f(1, 1, 1);
  desenhaCirc(130, 300, 300, 1);// raio, xc, yc, flag
  // linha
  glColor3f(0, 0, 0);
  desenhaCirc(130, 300, 300, 0);// raio, xc, yc, flag

  // orelha direita
  // poligono
  glColor3f(0, 0, 0);
  desenhaCirc(80, 400, 430, 1);// raio, xc, yc, flag
  // linha
  glColor3f(0, 0, 0);
  desenhaCirc(80, 400, 430, 0);// raio, xc, yc, flag

  // orelha esquerda
  // poligono
  glColor3f(0, 0, 0);
  desenhaCirc(80, 200, 430, 1);// raio, xc, yc, flag
  // linha
  glColor3f(0, 0, 0);
  desenhaCirc(80, 200, 430, 0);// raio, xc, yc, flag

  // olho esquerdo
  // poligono
  desenhaCirc(20, 250, 325, 0);// raio, xc, yc, flag
  // linha
  desenhaCirc(20, 250, 325, 0);// raio, xc, yc, flag

  // olho direito
  // poligono
  desenhaCirc(20, 350, 325, 0);// raio, xc, yc, flag
  // linha
  desenhaCirc(20, 350, 325, 0);// raio, xc, yc, flag

  // olho pequeno esquerdo
  // poligono
  desenhaCirc(8, 250, 325, 1);// raio, xc, yc, flag
  // linha
  desenhaCirc(8, 250, 325, 0);// raio, xc, yc, flag

  // olho pequeno direito
  // poligono
  desenhaCirc(8, 350, 325, 1);// raio, xc, yc, flag
  // linha
  desenhaCirc(8, 350, 325, 0);// raio, xc, yc, flag

  // nariz
  // poligono
  desenhaCirc(20, 300, 275, 1);// raio, xc, yc, flag
  // linha
  desenhaCirc(20, 300, 275, 0);// raio, xc, yc, flag

  // poligonos
  // cabelo
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  	glVertex2i(400, 430);
	glVertex2i(300, 350);
	glVertex2i(200, 430);
  glEnd();
  // boca
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  	glVertex2i(270, 200);
	glVertex2i(330, 200);
	glVertex2i(355, 230);
	glVertex2i(245, 230);
  glEnd();

  // esquerda
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  	glVertex2i(200, 430);
	glVertex2i(170, 300);
	glVertex2i(225, 300);
  glEnd();
  // direita
  glColor3f(0, 0, 0);
  glBegin(GL_POLYGON);
  	glVertex2i(400, 430);
	glVertex2i(375, 300);
	glVertex2i(430, 300);
  glEnd();

  // rugas
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  	glVertex2i(300, 310);
	glVertex2i(245, 295);
  glEnd();
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  	glVertex2i(300, 310);
	glVertex2i(345, 295);
  glEnd();

  // covinhas
  // direita
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
	  glVertex2i(355, 230);
	  glVertex2i(380, 260);
  glEnd();
  // esquerda
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
	glVertex2i(245, 230);
	glVertex2i(220, 260);
  glEnd();

  // lingua
  glColor3f(1, 0, 0);
  glBegin(GL_POLYGON);
  	glVertex2i(270, 200);
	glVertex2i(330, 200);
	glVertex2i(315, 220);
	glVertex2i(285, 220);
  glEnd();
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  	glVertex2i(285, 220);
	glVertex2i(295, 210);
  glEnd();
  // covinhas menores
  // direita
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
  	glVertex2i(380, 260);
	glVertex2i(370, 270);
  glEnd();
  glBegin(GL_LINE_STRIP);
  	glVertex2i(380, 260);
	glVertex2i(390, 250);
  glEnd();
  // esquerda
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
	glVertex2i(220, 260);
	glVertex2i(230, 270);
  glEnd();
  glColor3f(0, 0, 0);
  glBegin(GL_LINE_STRIP);
	glVertex2i(220, 260);
	glVertex2i(210, 250);
  glEnd();

  glFlush();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	if(h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		gluOrtho2D(0, TAMJANELA, 0, TAMJANELA*h/w);
	else
		gluOrtho2D(0, TAMJANELA*w/h, 0, TAMJANELA);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(TAMJANELA, TAMJANELA);
	glutInitWindowPosition(100,100);
	glutCreateWindow("OpenGL: Circunferencias");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	Inicializa();
	glutMainLoop();
	return 0;
}
