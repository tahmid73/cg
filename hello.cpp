#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1416

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void drawSquare(GLfloat x, GLfloat y, GLfloat height);
void sideBars();

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
glColor3ub(169, 23, 23);
drawFilledCircle(960,561,550);
glColor3ub(0, 0, 0);
drawQuads(891, 670, 410, 136);
sideBars();
glFlush ();
}



void myInit (void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1920.0, 1080.0, 0.0);
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (960, 540);
glutInitWindowPosition (960, 540);
glutCreateWindow ("");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();

}

void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 50; 	
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width){
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+width, y);
	glVertex2i(x+width, y+height);
	glVertex2i(x, y+height);
	glEnd();
}
void drawSquare(GLfloat x, GLfloat y, GLfloat height){
	drawQuads(x, y, height, height);	
}

void sideBars(){
	glBegin(GL_QUADS);
	//1st one from left
	glVertex2i(586,985);
	glVertex2i(895,936);
	glVertex2i(891,972);
	glVertex2i(610, 1012);
	//2nd one
	glVertex2i(699,1039);
	glVertex2i(1374,949);
	glVertex2i(1339,1000);
	glVertex2i(720, 1071);
	//4th one going down one 
	glVertex2i(1134,1005);
	glVertex2i(1015,1080);
	glVertex2i(1116,1080);
	glVertex2i(1224,991);
	
	glVertex2i(1024,984);
	glVertex2i(1374,949);
	glVertex2i(1339,1000);
	glVertex2i(1014, 1021);
	glEnd();

}
