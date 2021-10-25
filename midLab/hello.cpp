#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>



void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glPointSize(5.0);

glBegin(GL_QUADS);
glColor3ub(0, 0, 255);
glVertex2i(320, 0);
glVertex2i(380, 185);
glVertex2i(320, 225);
glVertex2i(283, 113);
glVertex2i(380, 185);
glVertex2i(320, 225);
glVertex2i(505, 225);
glVertex2i(563, 185);
glVertex2i(505, 225);
glVertex2i(430, 225);
glVertex2i(340, 300);
glVertex2i(415, 300);
glVertex2i(340, 300);
glVertex2i(415, 300);
glVertex2i(475, 480);
glVertex2i(375, 405);
glVertex2i(260, 185);
glVertex2i(273, 225);
glVertex2i(130, 225);
glVertex2i(70, 185);

glVertex2i(315, 360);
glVertex2i(165, 480);
glVertex2i(185, 405);
glVertex2i(290, 330);
glEnd();

glColor3ub(255, 0, 0);
glBegin(GL_POLYGON);
glVertex2i(220, 295);
glVertex2i(165, 250);
glVertex2i(235, 250);
glVertex2i(260, 185);
glVertex2i(285, 250);
glVertex2i(355, 250);
glVertex2i(300, 295);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(220, 295);
glVertex2i(200, 365);
glVertex2i(280, 295);

glVertex2i(300, 295);
glVertex2i(315, 360);
glVertex2i(235, 295);

glEnd();
glFlush ();

}


void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 640.0, 480.0, 0.0);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (640, 480);
glutInitWindowPosition (100, 150);
glutCreateWindow ("Star in star");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
