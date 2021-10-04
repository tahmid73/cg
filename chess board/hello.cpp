#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void drawSquare(GLfloat x, GLfloat y, GLfloat height);

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);

glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2i(450, 450);
glVertex2i(0, 450);
glVertex2i(451, 0);
glVertex2i(451, 450);
glVertex2i(0, 0);
glVertex2i(451, 0);
glEnd();

int point=0,i=0,j=0,count=0;


for(i=0;i<=400;i+=50){
	for (j=0;j<=400;j+=50){
		if(count%2==0){
			glColor3ub(255,255,255);
			drawSquare(j,i,50);
			count++;
		}
		else{
			glColor3ub(0, 0, 0);
			drawSquare(j,i,50);
			count++;
		}
	}
}

glFlush ();

}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}


//drawquads
void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width){
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+width, y);
	glVertex2i(x+width, y+height);
	glVertex2i(x, y+height);
	glEnd();
}
//draw square
void drawSquare(GLfloat x, GLfloat y, GLfloat height){
	drawQuads(x, y, height, height);	
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
