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
    //glColor3f(0, 0, 1);
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

    // poligonos preenchidos
    glColor3f(1, 0, 0);//vermelho
    glBegin(GL_POLYGON);
        // poligono 1
        glVertex2i(150, 150);//v4
        glVertex2i(250, 150);//v5
        glVertex2i(250, 250);//v6
        glVertex2i(150, 250);//v7
        glVertex2i(150, 150);//v4
    glEnd();
    glColor3f(0, 1, 0);//verde
    glBegin(GL_POLYGON);
        // poligono 2
        glVertex2i(100, 300);//v3
        glVertex2i(300, 300);//v2
        glVertex2i(200, 350);//v8
        glVertex2i(100, 300);//v3
    glEnd();

    // primeiro quadrado
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        //(x,y)
        glVertex2i(100, 100);//v0
        glVertex2i(300, 100);//v1
        glVertex2i(300, 300);//v2
        glVertex2i(100, 300);//v3
        glVertex2i(100, 100);//v0
    glEnd();
    // triangulo
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2i(100, 300);//v3
        glVertex2i(300, 300);//v2
        glVertex2i(200, 350);//v8
        glVertex2i(100, 300);//v3
    glEnd();
    // segundo quadrado
    glColor3f(0, 0, 0);
    glBegin(GL_LINE_STRIP);
        glVertex2i(150, 150);//v4
        glVertex2i(250, 150);//v5
        glVertex2i(250, 250);//v6
        glVertex2i(150, 250);//v7
        glVertex2i(150, 150);//v4
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
