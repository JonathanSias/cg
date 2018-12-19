/******************************
* Computação Gráfica
* Tank Race
*
* Jonathan Sias
******************************/
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <iostream>

// tamanho janela
#define XDMAX 800
#define YDMAX 800

// variavel globais movimentaçao
int movex = 0;

//
int yglobal = 0;
int xglobal = 0;
int points = 0;
int velocidade = 20;
int ultrapassados = 0;

//
char texto[30];

// funçao de incialização da janela com cor especificada
void Inicializa(void){
    // seleciona cor do fundo
    glClearColor(0, 0, 0, 0);
    srand(time(NULL));
    //enemy();
}

// modifica dimensões da janela
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    // evita divisão por zero
    if(h == 0){
        h = 1;
    }
    // especifica as dimensões da viewpoet
    glViewport(0, 0, w, h);
    // inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    // estabelece a janela de seleção (left, right, bottom, top)
    if(w <= h){
        gluOrtho2D(0, XDMAX, 0, YDMAX*h/w);
    }else{
        gluOrtho2D(0, XDMAX*w/h, 0, YDMAX);
    }
}

// funçao desenha lados da pista
void sides(int x, int y){
    // 1 left
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(x+0, 0+y);
        glVertex2i(x+100, 0+y);
        glVertex2i(x+100, 100+y);
        glVertex2i(x+0, 100+y);
        glVertex2i(x+0, 0+y);
    glEnd();
    // 1 right
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2i(x+100, 0+y);
        glVertex2i(x+200, 0+y);
        glVertex2i(x+200, 100+y);
        glVertex2i(x+100, 100+y);
        glVertex2i(x+100, 0+y);
    glEnd();
    // 2 left
    glBegin(GL_POLYGON);
        glColor3f(1, 1, 1);
        glVertex2i(x+0, 100+y);
        glVertex2i(x+100, 100+y);
        glVertex2i(x+100, 200+y);
        glVertex2i(x+0, 200+y);
        glVertex2i(x+0, 100+y);
    glEnd();
    // 2 right
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(x+100, 100+y);
        glVertex2i(x+200, 100+y);
        glVertex2i(x+200, 200+y);
        glVertex2i(x+100, 200+y);
        glVertex2i(x+100, 100+y);
    glEnd();

}

// tank jogador
void tank(){
    // tank
    glBegin(GL_POLYGON);
        glColor3f(0.5, 1, 0.2);
        glVertex2i(360+movex, 30);
        glVertex2i(440+movex, 30);
        glVertex2i(440+movex, 130);
        glVertex2i(360+movex, 130);
        glVertex2i(360+movex, 30);
    glEnd();
    //
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(380+movex, 30);
        glVertex2i(420+movex, 30);
        glVertex2i(420+movex, 130);
        glVertex2i(380+movex, 130);
        glVertex2i(380+movex, 30);
    glEnd();
}

// tank inimigo
void enemy(){
    // tank
    glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2i(360+xglobal, 900+yglobal);
        glVertex2i(440+xglobal, 900+yglobal);
        glVertex2i(440+xglobal, 1000+yglobal);
        glVertex2i(360+xglobal, 1000+yglobal);
        glVertex2i(360+xglobal, 900+yglobal);
    glEnd();
    //
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(380+xglobal, 900+yglobal);
        glVertex2i(420+xglobal, 900+yglobal);
        glVertex2i(420+xglobal, 1000+yglobal);
        glVertex2i(380+xglobal, 1000+yglobal);
        glVertex2i(380+xglobal, 900+yglobal);
    glEnd();
    //
    //
    /*glBegin(GL_POLYGON);
        glColor3f(1, 0, 0);
        glVertex2i(360+xglobal, 400+yglobal);
        glVertex2i(440+xglobal, 400+yglobal);
        glVertex2i(440+xglobal, 500+yglobal);
        glVertex2i(360+xglobal, 500+yglobal);
        glVertex2i(360+xglobal, 400+yglobal);
    glEnd();
    //
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 0);
        glVertex2i(380+xglobal, 400+yglobal);
        glVertex2i(420+xglobal, 400+yglobal);
        glVertex2i(420+xglobal, 500+yglobal);
        glVertex2i(380+xglobal, 500+yglobal);
        glVertex2i(380+xglobal, 400+yglobal);
    glEnd();*/
}

// escrever texto na tela
void escreveTexto(int posx, int posy, char ns[20])
{
    glRasterPos2i (posx, posy);
    char *p= (char*) ns;
    while (*p!= '\0')
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}

// desenha asfalto
// chama tank jogador
// chama tank inimigos
void Desenha(void){
    glClear(GL_COLOR_BUFFER_BIT);
    // asfalto
    glBegin(GL_POLYGON);
        glColor3f(0.4, 0.4, 0.4);
        glVertex2i(0, 0);
        glVertex2i(800, 0);
        glVertex2i(800, 800);
        glVertex2i(0, 800);
    glEnd();
    //
    // chama a funçao que desenha os lados da pista
    for (int i = 0; i < 800; i+=200) {
        sides(0,i);
        sides(600,i);
    }
    // chama tank
    tank();
    // chama inimigo
    enemy();

    // texto
    glColor3f(1, 0, 0);
    strcpy(texto, "TANK RACE");
    escreveTexto(650,650,texto);
    strcpy(texto, "PONTOS: ");
    char aux[30];
    sprintf(aux, "%d", points);
    strcat(texto, aux);
    escreveTexto(650,630,texto);
    //strcpy(texto, "");
    //escreveTexto(20,20,texto);

    glFlush();
    glutSwapBuffers();
}

void Teclado(int tecla, int xmouse, int ymouse){
    switch (tecla) {
        // esquerda
        case GLUT_KEY_LEFT:
          //
          if (movex >= 0) {
              movex -= 100;
          }
          break;
        // direita
        case GLUT_KEY_RIGHT:
          //
          if (movex <= 0) {
              movex += 100;
          }
          break;
    }
    glutPostRedisplay();
}

// posicao inimigo
// randomize
void eposition(){
    //
    int random;
    int sinal;
    random = (rand()%101);
    sinal = (rand()%2);
    if (sinal == 0) {
        xglobal = random;
    }else {
        xglobal = -random;
    }
}

// movimentaçao inimigo
void moveinimigo(int p){
    //yglobal -= 5;
    /*if (((360) >= (570+yglobal)) && ((420+xglobal) <= (440+movex)) && ((900+yglobal) <= (130)) && ((100+xglobal) >= (30))) {
        //printf("XXXXXXXX\n");
    }
    if (((900+yglobal) <= (130)) && ((100+xglobal) >= (30))) {
        printf("YYYYYYYY\n");
    }
    if(((570+yglobal) < (300))&&((570+yglobal) >= (250))&&((290+xglobal) >= (250+movex))&&((300+xglobal) <= (300+movex))){
        printf("STOPPP\n");
    }*/
    //yglobal -= 5;

    if((((360+xglobal) >= (360+movex)) && ((360+xglobal) <= (440+movex)) || ((440+xglobal) >= (360+movex)) && ((440+xglobal) <= (440+movex))) && ((900+yglobal) <= (130)) && ((900+yglobal) >= (30))){
        //printf("MORREU\n");
        glColor3f(1, 0, 0);
        strcpy(texto, "GAME OVER");
        escreveTexto(400,400,texto);
    }else{
         yglobal -= 5;
    }

    if (yglobal >= -100) {
        eposition();
    }
    if (yglobal <= -1000) {
        yglobal = 0;
        points++;
        ultrapassados++;
        if (ultrapassados == 5) {
            velocidade--;
            ultrapassados = 0;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(velocidade, moveinimigo, 1);
}

// sair [Esc]
void Teclado2(unsigned char tecla, int xmouse, int ymouse){
  switch (tecla) {
    // [Esc]
    case 27:
        exit(0);
        break;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(XDMAX, YDMAX);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("TANK RACE");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutSpecialFunc(Teclado);
    glutKeyboardFunc(Teclado2);
    glutTimerFunc(velocidade, moveinimigo, 1);
    Inicializa();
    glutMainLoop();
    return 0;
}
