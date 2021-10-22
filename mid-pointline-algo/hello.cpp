#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int x1, y1, x2, y2;

void midPointLine(void)
{
    int dX=x2-x1;
    int dY=y2-y1;
    int steps=max(dX,dY);
    int pointx=x1,pointy=y1;
    int pointyPre=y1;
    int pk=0;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2i(x1,y1);


    for(int i=0;i<steps+1;i++)
    {
        if(i==0)
        {
            pointx=x1;
            pointy=y1;
            pk=2*dY-dX;
            glVertex2i(x1,y1);
            continue;
        }
         else if(pk>0)
        {
            pointx=pointx+1;
            pointyPre=pointy;
            pointy=pointy+1;
            pk=pk+(2*dY)-2*dX*(pointy-pointyPre);
            glVertex2i(x1,y1);
        }
        else
        {
             pointx=pointx+1;
             pointyPre=pointy;
             pk=pk+(2*dY)-2*dX*(pointy-pointyPre);
             glVertex2i(x1,y1);
        }
        glVertex2i(pointx+i*10,pointy+i*10);
        cout<<"(x:"<<pointx<<",y:"<<pointy<<" )"<<endl;
    }
    glEnd();

    glFlush();

 }

 void init(void)
 {
 glClearColor (1.0, 1.0, 1.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,640.0,480.0,0.0);
}
  int main(int argc, char** argv)
{

    cout<<"Enter the Initial Points:" ;
    cin>>x1>>y1;
    cout<<"Enter the Final Points:";
    cin>>x2>>y2;

 glutInit(&argc, argv);
 glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize (960, 540);
 glutInitWindowPosition (960, 540);
 glutCreateWindow ("Mid Point Line Algorithm");
 init ();
 glutDisplayFunc(midPointLine);
 glutMainLoop();
 return 0;
 }
