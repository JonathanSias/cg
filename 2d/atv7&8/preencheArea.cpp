#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>

#define TAMJANELA 500
#define POSJANELA 100

using namespace std;

void inicializa(void)
{

  glClearColor(1, 1, 1, 0);

}

// HERMITE
void curvaHermite (float k, float ang1, float ang4,
                   int p1x, int p1y, int p4x, int p4y)
{

	int px, py, xmin, xmax, ymin, ymax, i;
	float max, r1x, r1y, r4x, r4y, t, xp1, xp4, xr1, xr4;

	if (p1x > p4x)
		{
			xmin = p4x;
			xmax = p1x;
		}
	else
		{
			xmin = p1x;
			xmax = p4x;
		}

	if (p1y > p4y)
		{
			ymin = p4y;
			ymax = p1y;
		}
	else
		{
			ymin = p1y;
			ymax = p4y;
		}

	if (xmax - xmin > ymax - ymin)
		max = xmax - xmin;
	else
		max = ymax - ymin;

	ang1 = (M_PI*ang1)/180;
	ang4 = (M_PI*ang4)/180;

	r1x = k * cos(ang1);
	r1y = k * sin(ang1);
	r4x = k * cos(ang4);
	r4y = k * sin(ang4);

	glBegin(GL_LINE_STRIP);

	for(i=0; i<=max; i++)
		{
			t = i/max;

			xp1 = 2*t*t*t - 3*t*t + 1;
			xp4 = - 2*t*t*t + 3*t*t;

			xr1 = t*t*t - 2*t*t + t;
			xr4 = t*t*t - t*t;

			px = xp1 * p1x + xp4 * p4x + xr1 * r1x + xr4 * r4x;
			py = xp1 * p1y + xp4 * p4y + xr1 * r1y + xr4 * r4y;


				glVertex2i(px,py);

		}

	glEnd();

}

void preencheArea(int x, int y, float rf, float gf, float bf, float rp, float gp, float bp)
{

    int i;
    unsigned char pixel[4];

    glReadPixels(x, y, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
    glColor3f(rp, gp, bp);

    if((int)pixel[0] == rf*255 && (int)pixel[1] == gf*255 && (int)pixel[2] == bf*255)
      {
        glBegin(GL_POINTS);
          glVertex2i(x, y);
        glEnd();
        preencheArea(x+1,y  ,rf,gf,bf,rp,gp,bp);
        preencheArea(x  ,y+1,rf,gf,bf,rp,gp,bp);
        preencheArea(x-1,y  ,rf,gf,bf,rp,gp,bp);
        preencheArea(x  ,y-1,rf,gf,bf,rp,gp,bp);
      }

}

void desenhaQuadrado(int x1, int y1, int x3, int y3, int r, int g, int b, int esp)
{

  glColor3f(r, g, b);
  glLineWidth(esp);

  glBegin(GL_LINE_STRIP);
    glVertex2i(x1, y1);
    glVertex2i(x1+x3, y1);
    glVertex2i(x1+x3, y3);
    glVertex2i(x1, y3);
    glVertex2i(x1, y1);
  glEnd();

}

void Desenha(void)
{

  glClear(GL_COLOR_BUFFER_BIT);

  // DESENHA CURVA
  glColor3f(0, 0, 0);
  glLineWidth(4);
  // raio, ang1, ang2, x1, y1, x2, y2
  // cabeça fora
  curvaHermite(300, 110, 360, 110, 170, 248, 352);
  curvaHermite(315, 360, 255, 248, 352, 385, 172);
  // orelha esquerda
  curvaHermite(360, 225, 35, 150, 318, 50, 440);
  curvaHermite(345, 35, 210, 50, 440, 150, 318);
  // orelha direita
  curvaHermite(350, 150, 330, 350, 318, 448, 440);
  curvaHermite(335, 328, 145, 448, 440, 350, 318);
  // rosto esq/dir
  curvaHermite(200, 110, -40, 152, 191, 248, 338);
  curvaHermite(200, 400, 250, 248, 338, 340, 191);
  // bochechas
  curvaHermite(300, 190, 340, 152, 191, 205, 55);
  curvaHermite(300, 355, 205, 340, 191, 292, 55);
  // queixo
  curvaHermite(310, 310, 50, 180, 82, 318, 82);
  // boca
  curvaHermite(250, 300, 60, 190, 102, 308, 102);
  curvaHermite(260, -60, 60, 155, 142, 345, 142);
  // covinhas esq/dir
  curvaHermite(120, 55, 150, 140, 130, 173, 143);
  curvaHermite(48, 15, 280, 325, 142, 360, 130);
  // lingua
  curvaHermite(100, 50, 150, 210, 70, 258, 68);
  curvaHermite(100, 40, 120, 249, 71, 280, 80);
  // nariz
  curvaHermite(130, 90, 270, 202, 150, 292, 150);
  curvaHermite(130, 270, 90, 202, 150, 292, 153);
  // ruga
  curvaHermite(80, 90, 270, 200, 180, 298, 180);
  // olhos
  // esquerdo
  curvaHermite(300, 90, 270, 196, 230, 238, 230);
  curvaHermite(182, 270, 90, 196, 230, 238, 250);
  // direito
  curvaHermite(300, 90, 270, 255, 230, 290, 230);
  curvaHermite(150, 270, 90, 255, 230, 290, 240);
  // pupilas
  curvaHermite(90, 140, 270, 220, 195, 233, 220);
  curvaHermite(90, 65, 270, 255, 220, 275, 195);

  // PREENCHIMENTO
  // x, y, rf, gf, bf, rp, gp, bp
  // orelhas esq/dir
  preencheArea(100, 400, 1, 1, 1, 0, 0, 0);
  preencheArea(400, 400, 1, 1, 1, 0, 0, 0);
  // cabelo esq/dir/cima
  preencheArea(130, 250, 1, 1, 1, 0, 0, 0);
  preencheArea(360, 250, 1, 1, 1, 0, 0, 0);
  preencheArea(248, 340, 1, 1, 1, 0, 0, 0);
  // nariz
  preencheArea(250, 150, 1, 1, 1, 0, 0, 0);
  // boca
  preencheArea(250, 80, 1, 1, 1, 0, 0, 0);
  // olhos esq/dir
  preencheArea(225, 210, 1, 1, 1, 0, 0, 0);
  preencheArea(270, 210, 1, 1, 1, 0, 0, 0);
  // lingua
  preencheArea(240, 60, 1, 1, 1, 1, 0, 0);
  // rosto
  preencheArea(250, 300, 1, 1, 1, 1, 0.9, 0.8);

  glFlush();
  glutSwapBuffers();

}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{

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

//------------------------------
int main(int argc, char **argv)
{

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(TAMJANELA, TAMJANELA);
  glutInitWindowPosition(POSJANELA, POSJANELA);
  glutCreateWindow("Preenche Area");
  inicializa();
  glutDisplayFunc(Desenha);
  glutReshapeFunc(AlteraTamanhoJanela);
  glutMainLoop();
  return 0;

}
