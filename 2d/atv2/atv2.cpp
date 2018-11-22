///////////////////
// Jonathan Sias //
///////////////////

//#include <iostream>
//#include <cstdlib>
// openGL bibliotecas
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define XDMAX 400
#define YDMAX 400

using namespace std;

// funçao de incialização da janela com cor especificada
void Inicializa(void){
    // seleciona cor do fundo
    glClearColor(1, 1, 1, 0);
}
// função que desenha na tela
void Desenha(void){
    // limpa a janela com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);
    // especifica que a cor corrente é branca
    glColor3f(0, 0, 1);
    //glPointSize(5);
    glLineWidth(3);
    // desenha quatro pontos brancos
    /*glBegin(GL_LINES);
        glVertex2i(100, 100);//P0
        glVertex2i(300, 100);//P1

        glVertex2i(300, 100);//P1
        glVertex2i(300, 300);//P2

        glVertex2i(300, 300);//P2
        glVertex2i(100, 300);//P3

        glVertex2i(100, 300);//P3
        glVertex2i(100, 100);//P0
        //glVertex2i(290, 10);
        //glVertex2i(290, 290);
        //glVertex2i(10, 290);
    glEnd();*/
    glBegin(GL_POLYGON);
        // poligono 1
        glVertex2i(50,250);
        glVertex2i(250,250);
        glVertex2i(250,350);
        glVertex2i(50,350);
    glEnd();

    glBegin(GL_POLYGON);
        // poligono 2
        glVertex2i(100,200);
        glVertex2i(150,200);
        glVertex2i(150,250);
        glVertex2i(100,250);
    glEnd();

    glBegin(GL_POLYGON);
        // poligono 3
        glVertex2i(50,50);
        glVertex2i(150,50);
        glVertex2i(150,200);
        glVertex2i(100,200);
        glVertex2i(50,150);
    glEnd();

    glBegin(GL_POLYGON);
        // poligono 4
        glVertex2i(150,100);
        glVertex2i(200,100);
        glVertex2i(200,200);
        glVertex2i(150,150);
    glEnd();

    glBegin(GL_POLYGON);
        // poligono 5
        glVertex2i(200,100);
        glVertex2i(250,150);
        glVertex2i(250,250);
        glVertex2i(200,250);
    glEnd();

    glBegin(GL_POLYGON);
        // poligono 6
        glVertex2i(250,150);
        glVertex2i(300,200);
        glVertex2i(300,250);
        glVertex2i(250,300);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        //(x,y)
        glVertex2i(50, 50);//v0
        glVertex2i(150,50);//v1
        glVertex2i(150, 100);//v2
        glVertex2i(200, 100);//v3
        glVertex2i(300, 200);//v4
        glVertex2i(300, 250);//v5
        glVertex2i(250, 300);//v6
        glVertex2i(250, 350);//v7
        glVertex2i(50, 350);//v8
        glVertex2i(50, 250);//v9
        glVertex2i(100, 250);//v10
        glVertex2i(100, 200);//v11
        glVertex2i(50, 150);//v12
        glVertex2i(50, 50);//v0
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2i(150, 150);
        glVertex2i(200, 200);
        glVertex2i(200, 250);
        glVertex2i(150, 250);
        glVertex2i(150, 150);
    glEnd();

    // executa os comandos OpenGL
    glFlush();
}

//
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

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(XDMAX, YDMAX);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atividade Prática 2");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();

    return 0;
}
