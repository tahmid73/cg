#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat weidth){
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+weidth, y);
	glVertex2i(x+weidth, y+height);
	glVertex2i(x, y+height);
	glEnd();
}
void drawSquare(GLfloat x, GLfloat y, GLfloat height){
	drawQuads(x, y, height, height);	
}

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
//glBegin(GL_LINES);
//glColor3ub (255, 0, 0);
//glVertex2i(100, 200);
//glVertex2i(100, 300);
//glVertex2i(150, 300);
//glVertex2i(320, 480);
//glEnd();
glBegin(GL_LINES);
glColor3ub(255, 255, 255);
glColor3ub (255, 255, 0);
glVertex2i(0, 240);
glVertex2i(640, 240);
glVertex2i(320, 0);
glVertex2i(320, 480);
//glVertex2i(160, 400);
//glVertex2i(260, 400);
glEnd();
glBegin(GL_TRIANGLES);
glColor3ub (0, 255, 0);
glVertex2i(620, 120);
glVertex2i(500, 220);
glVertex2i(500, 20);
glColor3ub (0, 0, 255);
glVertex2i(500, 220);
glVertex2i(500, 20);
glVertex2i(380, 120);

glEnd();

glBegin(GL_LINES);
glColor3ub(255, 0, 0);
//F
glVertex2i(380,280);
glVertex2i(380,420);
glVertex2i(380,420);
glVertex2i(480,420);
glVertex2i(380,350);
glVertex2i(480,350);
//H
glVertex2i(110,120);
glVertex2i(210,120);
glVertex2i(110,190);
glVertex2i(110,50);
glVertex2i(210,190);
glVertex2i(210,50);
glEnd();

glBegin(GL_TRIANGLES);
glColor3ub(0, 255, 255);
glVertex2i(160,360);
glVertex2i(210,410);
glVertex2i(110, 410);
glColor3ub(255, 0, 255);
glVertex2i(160,360);
glVertex2i(210,310);
glVertex2i(110,310);
glEnd();

//glBegin(GL_QUADS);
//glVertex2i(440,120);
//glVertex2i(440,220);
//glVertex2i(340,220);
//glVertex2i(340,120);
//glVertex2i(390,120);


glEnd();
drawQuads(360,50 , 100,90);
drawSquare(100,100,100);
glFlush ();
}



void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
