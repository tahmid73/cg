#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>


void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width);
void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);
//background
glBegin(GL_POLYGON);
glColor3ub(255, 255, 0);
glVertex2d(150, 18);
glVertex2d(470,18);
glVertex2d(602,150);
glVertex2d(602,281);
glVertex2d(470,413);
glVertex2d(150,413);
glVertex2d(18, 281);
glVertex2d(18, 150);
glEnd();


//outline
glBegin(GL_LINES);
glColor3ub(0, 0, 0);
glVertex2d(150, 18);
glVertex2d(470,18);
glVertex2d(470,18);
glVertex2d(602,150);
glVertex2d(602,150);
glVertex2d(602,281);
glVertex2d(602,281);
glVertex2d(470,413);
glVertex2d(470,413);
glVertex2d(150,413);
glVertex2d(150,413);
glVertex2d(18, 281);
glVertex2d(18, 281);
glVertex2d(18, 150);
glVertex2d(18, 150);
glVertex2d(150, 18);
glEnd();

//batman logo
glBegin(GL_POLYGON);
glVertex2d(564, 169);
glVertex2d(564, 262);
glVertex2d(423, 375);
glVertex2d(366, 300);
glVertex2d(310, 375);
glVertex2d(254, 300);
glVertex2d(197, 375);
glVertex2d(56, 262);
glVertex2d(56, 169);
glEnd();

glBegin(GL_TRIANGLES);
glVertex2d(56, 169);
glVertex2d(188, 169);
glVertex2d(188, 74);
glVertex2d(433, 169);
glVertex2d(564, 169);
glVertex2d(433, 74);
glEnd();

drawQuads(263, 74, 95, 96);
drawQuads(187, 75, 19, 19);
drawQuads(188, 150, 19, 19);
drawQuads(244, 150, 19, 19);
drawQuads(263, 54, 20, 20);
drawQuads(339, 54, 20, 20);
drawQuads(357, 150, 19, 19);
drawQuads(414, 150, 19, 19);
drawQuads(414, 74, 19, 19);
glFlush ();

}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}



void drawQuads(GLfloat x, GLfloat y, GLfloat height,GLfloat width){
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x+width, y);
	glVertex2i(x+width, y+height);
	glVertex2i(x, y+height);
	glEnd();
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
