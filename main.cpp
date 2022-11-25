#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>

void display();

void reshape(int w,int h);

void timer(int);

void circle()
{
    int radius = 2.2;
    double angel;
    for(int i = 0; i <=360; i++)
    {
        angel = (i*3.14)/180;
        glVertex2d(radius*cos(angel), 7+radius*sin(angel));

    }

}

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20109594/20200187");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();

}
float step=0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //right house
    //house body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(9.5,-10);
    glVertex2f(9.5,0);
    glVertex2f(3,0);
    glVertex2f(3,-10);
    glEnd();

    //house head
    glColor3f(0.5f,0.35f,0.05f);
    glBegin(GL_POLYGON);
    glVertex2f(9.5,0 );
    glVertex2f(6,6);
    glVertex2f(3,0);
    glEnd();

    //house door
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(8.5,-10);
    glVertex2f(8.5,-5);
    glVertex2f(6,-5);
    glVertex2f(6,-10);
    glEnd();

    //left house
    //house body
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-9.5,-10);
    glVertex2f(-9.5,0);
    glVertex2f(-3,0);
    glVertex2f(-3,-10);
    glEnd();

    //house head
    glColor3f(0.5f,0.35f,0.05f);
    glBegin(GL_POLYGON);
    glVertex2f(-9.5,0);
    glVertex2f(-6,6);
    glVertex2f(-3,0);
    glEnd();

    //house door
    glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-8.5,-10);
    glVertex2f(-8.5,-5);
    glVertex2f(-6,-5);
    glVertex2f(-6,-10);
    glEnd();

    //moon
    glColor3f(80,80,80);
    glLineWidth(1);
    glBegin(GL_POLYGON);
    circle();
    glEnd();

    //star1
    glBegin (GL_POLYGON);
    glVertex2f(0.0+step,8.3);
    glVertex2f(0.1+step,8.2);
    glVertex2f(0.2+step,8.06);
    glVertex2f(0.1+step,8.1);
    glVertex2f(0.2+step,8.2);
    glVertex2f(0.0+step,8.05);
    glVertex2f(-0.2+step,8.2);
    glVertex2f(-0.1+step,8.1);
    glVertex2f(-0.2+step,8.06);
    glVertex2f(-0.1+step,8.2);
    glEnd();

    //star2
    glBegin (GL_POLYGON);
    glVertex2f(0.0-step,8.3);
    glVertex2f(0.1-step,8.2);
    glVertex2f(0.2-step,8.06);
    glVertex2f(0.1-step,8.1);
    glVertex2f(0.2-step,8.2);
    glVertex2f(0.0-step,8.05);
    glVertex2f(-0.2-step,8.2);
    glVertex2f(-0.1-step,8.1);
    glVertex2f(-0.2-step,8.06);
    glVertex2f(-0.1-step,8.2);
    glEnd();

    //star3
    glBegin (GL_POLYGON);
    glVertex2f(3.0,6.3);
    glVertex2f(3.1,6.2);
    glVertex2f(3.2,6.06);
    glVertex2f(3.1,6.1);
    glVertex2f(3.2,6.2);
    glVertex2f(3.0,6.05);
    glVertex2f(2.8,6.2);
    glVertex2f(2.9,6.1);
    glVertex2f(2.8,6.06);
    glVertex2f(2.9,6.2);
    glEnd();

    //star4
    glBegin (GL_POLYGON);
    glVertex2f(-3.0,6.3);
    glVertex2f(-3.1,6.2);
    glVertex2f(-3.2,6.06);
    glVertex2f(-3.1,6.1);
    glVertex2f(-3.2,6.2);
    glVertex2f(-3.0,6.05);
    glVertex2f(-2.8,6.2);
    glVertex2f(-2.9,6.1);
    glVertex2f(-2.8,6.06);
    glVertex2f(-2.9,6.2);
    glEnd();

    //star5
    glBegin (GL_POLYGON);
    glVertex2f(-3.0,6.3+step);
    glVertex2f(-3.1,6.2+step);
    glVertex2f(-3.2,6.06+step);
    glVertex2f(-3.1,6.1+step);
    glVertex2f(-3.2,6.2+step);
    glVertex2f(-3.0,6.05+step);
    glVertex2f(-2.8,6.2+step);
    glVertex2f(-2.9,6.1+step);
    glVertex2f(-2.8,6.06+step);
    glVertex2f(-2.9,6.2+step);
    glEnd();

    //tree base
    glColor3f(0.5f,0.35f,0.05f);
    glBegin(GL_POLYGON);
    glVertex2f(0.5,-10);
    glVertex2f(0.5,-2 );
    glVertex2f(-0.5,-2);
    glVertex2f(-0.5,-10);
    glEnd();

    //tree head
    glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(2.5,-4);
    glVertex2f(0,3);
    glVertex2f(-2.5,-4);
    glEnd();

    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    step+=0.05;
}
