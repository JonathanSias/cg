#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TAMJANELA 500
#define POSJANELA 100

typedef struct Svertices {
	int   nv; // Numero do vertice
	float x;  // Coordenada x do vertice no SRU
	float y;  // Coordenada y do vertice no SRU
} Tvertices;

typedef struct Sarestas {
	int   na; // Numero da aresta
	int   v1; // Numero do primeiro vertice
	int   v2; // Numero do segundo vertice
	float  r; // Percentual de cor RED
	float  g; // Percentual de cor GREEN
	float  b; // Percentual de cor BLUE
	int   ea; // Espessura da aresta 
} Tarestas;

typedef struct Spoligonos {
	int   np; // Numero do poligono
	int   v1; // Numero do v1
	int   v2; // Numero do v2
	int   v3; // Numero do v3
	int   v4; // Numero do v4
	float  r; // Percentual de cor RED
	float  g; // Percentual de cor GREEN
	float  b; // Percentual de cor BLUE
} Tpoligonos;

Tvertices ver[500];
Tarestas  are[500];
Tpoligonos pol[500];
int   i, n, nv, na, np;
float xumin,yumin,xumax,yumax;
int   xdmin,ydmin,xdmax,ydmax;
float xesc, yesc;

//-------------------------------------
void leitura_dados(void) {
	FILE *arq, *arq1, *arq2;
	int k, valor;
	float valorF;
	
	// -------
	arq = fopen("sv2d.ver", "r");
	nv = 0;
	
	while(!feof(arq)) {
		k = fscanf(arq, "%d", &valor);
		ver[nv].nv = valor;
		k = fscanf(arq, "%f", &valorF);
		ver[nv].x = valorF;
		k = fscanf(arq, "%f", &valorF);
		ver[nv].y = valorF;
		nv++; 
	}
	fclose(arq);
	nv--;
	printf("\nnv = %d\n",nv);
	printf("\n NV        x        y\n\n");
	for(k=0; k<nv; k++) 
	  printf("%3d %8.2f %8.2f\n", 
		       ver[k].nv, 
		       ver[k].x, 
		       ver[k].y);
	
	// -----	       
	arq1 = fopen("sv2d.are", "r");  
	na = 0;
	
	while(!feof(arq1)) {
		k = fscanf(arq1, "%d", &valor);
		are[na].na = valor; 
		k = fscanf(arq1, "%d", &valor);
		are[na].v1 = valor;  
		k = fscanf(arq1, "%d", &valor);
		are[na].v2 = valor; 
		k = fscanf(arq1, "%f", &valorF);
		are[na].r = valorF; 
		k = fscanf(arq1, "%f", &valorF);
		are[na].g = valorF; 
		k = fscanf(arq1, "%f", &valorF);
		are[na].b = valorF; 
		k = fscanf(arq1, "%d", &valor);
		are[na].ea = valor; 
		na++;
	}
	fclose(arq1);
	na--;
	printf("\nna = %d\n",na);
	printf("\n na  v1  v2   r   g   b  ea\n\n");
	for(k=0; k<na; k++) 
	  printf("%3d %3d %3d %3.1f %3.1f %3.1f %1d\n", 
		       are[k].na, 
		       are[k].v1, 
		       are[k].v2,
		       are[k].r,
		       are[k].g,
		       are[k].b,
		       are[k].ea); 

		// -----	       
		arq2 = fopen("sv2d.pol", "r");  
		np = 0;
	
		while(!feof(arq2)) {
			k = fscanf(arq2, "%d", &valor);
			pol[np].np = valor; 
			k = fscanf(arq2, "%d", &valor);
			pol[np].v1 = valor;
			k = fscanf(arq2, "%d", &valor);
			pol[np].v2 = valor;
			k = fscanf(arq2, "%d", &valor);
			pol[np].v3 = valor;
			k = fscanf(arq2, "%d", &valor);
			pol[np].v4 = valor;
			k = fscanf(arq2, "%f", &valorF);
			pol[np].r = valorF; 
			k = fscanf(arq2, "%f", &valorF);
			pol[np].g = valorF; 
			k = fscanf(arq2, "%f", &valorF);
			pol[np].b = valorF; 
			np++;
		}
	fclose(arq2);
	np--;
	printf("\nnp = %d\n\n",np);
	for(k=0; k<np; k++) {
	  printf("%3d %3d %3d %3d %3d %3.1f %3.1f %3.1f\n", 
							pol[k].np,
							pol[k].v1,
							pol[k].v2,
							pol[k].v3,
							pol[k].v4,
							pol[k].r, pol[k].g, pol[k].b); 
	 }
}

// -----------------------------
void envelope_universo(void) {
	int i;
	xumin = xumax = ver[0].x;
	yumin = yumax = ver[0].y;
	for(i=1; i<nv; i++) {
		if(ver[i].x < xumin) xumin = ver[i].x;
		if(ver[i].y < yumin) yumin = ver[i].y;
		if(ver[i].x > xumax) xumax = ver[i].x;
		if(ver[i].y > yumax) yumax = ver[i].y;
	}
	printf("\n\nLIMITES DO UNIVERSO:\n\n");
	printf("xumin = %4.1f\n", xumin);
	printf("xumax = %4.1f\n", xumax);
	printf("yumin = %4.1f\n", yumin);
	printf("yumax = %4.1f\n", yumax);
} 

//------------------------------
void calcula_fator_de_escala(void) {
	xesc = (TAMJANELA-50)/(xumax-xumin);
	yesc = ((TAMJANELA-50)/(yumax-yumin))/((xumax-xumin)/(yumax-yumin));
	printf("\n\nFATORES DE ESCALA SRU->SRD\n\n");
	printf("xesc = %4.1f\n", xesc);
	printf("yesc = %4.1f\n", yesc);
}

//------------------------------
void envelope_dispositivo(void) {
	xdmin = 25;
	ydmin = 25;
	xdmax = TAMJANELA-50;
	ydmax = TAMJANELA-50;
}

//------------------------------
void inicializa(void) {
  leitura_dados();
	envelope_universo();
	calcula_fator_de_escala();
	envelope_dispositivo();
	glClearColor(1, 1, 1, 0); 
}

//------------------------------
void AlteraTamanhoJanela(GLsizei w, GLsizei h) {
	if(h == 0)
		h = 1;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w <= h)
		gluOrtho2D(0, TAMJANELA, 0, TAMJANELA*h/w);
  else
    gluOrtho2D(0, TAMJANELA*w/h, 0, TAMJANELA);
}

//------------------------------
void Desenha(void) {
	int p, a, v, v1, v2, v3, v4;
	int xd1, yd1, xd2, yd2, xd3, yd3, xd4, yd4;
	float xu1, yu1, xu2, yu2, xu3, yu3, xu4, yu4, r, g, b, ea;
	
	glClear(GL_COLOR_BUFFER_BIT);

	// DESENHA POLIGONOS
	for(p=0; p<np; p++) {
		v1 = pol[p].v1;
		v2 = pol[p].v2;
		v3 = pol[p].v3;
		v4 = pol[p].v4;
		r = pol[p].r;
		g = pol[p].g;
		b = pol[p].b;
		xu1 = ver[v1].x;
		yu1 = ver[v1].y;
		xu2 = ver[v2].x;
		yu2 = ver[v2].y;
		xu3 = ver[v3].x;
		yu3 = ver[v3].y;
		xu4 = ver[v4].x;
		yu4 = ver[v4].y;
		xd1 = xdmin + (xu1-xumin) * xesc;
		yd1 = ydmin + (yu1-yumin) * yesc;
		xd2 = xdmin + (xu2-xumin) * xesc;
		yd2 = ydmin + (yu2-yumin) * yesc;
		xd3 = xdmin + (xu3-xumin) * xesc;
		yd3 = ydmin + (yu3-yumin) * yesc;
		xd4 = xdmin + (xu4-xumin) * xesc;
		yd4 = ydmin + (yu4-yumin) * yesc;
		glColor3f(r, g, b);
		glBegin(GL_POLYGON);
			glVertex2i(xd1, yd1);
			glVertex2i(xd2, yd2);
			glVertex2i(xd3, yd3);
			glVertex2i(xd4, yd4);
			glVertex2i(xd1, yd1);
	  glEnd();
	}
	
	// DESENHA ARESTAS
	for(a=0; a<na; a++) {
		v1 = are[a].v1;
		v2 = are[a].v2;
		r = are[a].r;
		g = are[a].g;
		b = are[a].b;
		ea = are[a].ea;
		xu1 = ver[v1].x;
		yu1 = ver[v1].y;
		xu2 = ver[v2].x;
		yu2 = ver[v2].y;
		xd1 = xdmin + (xu1-xumin) * xesc;
		yd1 = ydmin + (yu1-yumin) * yesc;
		xd2 = xdmin + (xu2-xumin) * xesc;
		yd2 = ydmin + (yu2-yumin) * yesc;
		glColor3f(r, g, b);
		glLineWidth(ea);
		glBegin(GL_LINES);
			glVertex2i(xd1, yd1);
			glVertex2i(xd2, yd2);
	  glEnd();
	}
	glFlush();
}

//------------------------------
void SpecialKeys(int key, int x, int y) {
	if(key == GLUT_KEY_END)
	  exit(0);
	glutPostRedisplay();
}

//------------------------------
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(TAMJANELA, TAMJANELA);
  glutInitWindowPosition(POSJANELA, POSJANELA);
  glutCreateWindow("SV2D - Sistema de Visualizacao Bidimensional");
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	inicializa();
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();
	return 0;
}



