#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/glu.h>
#include "SupportClass.h"

using namespace std;

/* Mèo CODING */

float orthorLeft = -5;
float orthorRight = 5;
float orthorBot = -5;
float orthorTop = 5;

int currentWidth = 600;
int currentHeight = 600;

float currentRed = 0;
float currentBlue = 0;
float currentGreen = 0;

/*Hàm vẽ hình vuông*/
void DrawSquare(float x,float y,float size = 1) {
    glColor3ub(rand() % 256,rand() % 256,rand() % 256);
    glBegin(GL_POLYGON);
        glVertex2f(x - size / 2, y - size / 2);
        glVertex2f(x + size / 2, y - size / 2);
        glVertex2f(x + size / 2, y + size / 2);
        glVertex2f(x - size / 2, y + size / 2);
    glEnd();
    glColor3f(currentRed,currentGreen,currentBlue);
}

void myReshape(int w,int h) {
    currentWidth = w;
    currentHeight = h;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        orthorBot = orthorBot * h / w;
        orthorTop = orthorTop * h / w;
    } else {
        orthorLeft = orthorLeft * w / h;
        orthorRight = orthorRight * w / h;
    }
    gluOrtho2D(orthorLeft,orthorRight,orthorBot,orthorTop);
    glutPostRedisplay();
}


Point2D ScreenPositionToOrthor(int x,int y) {
    Point2D rt;
    rt.x = orthorLeft + (orthorRight - orthorLeft) / currentWidth * x;
    rt.y = orthorTop - (orthorTop - orthorBot) / currentHeight * y;
    return rt;
}

void myMouseEvent(int button,int state,int x,int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        Point2D pos = ScreenPositionToOrthor(x,y);
        DrawSquare(pos.x,pos.y,rand() % 3 + 1);
    }
    glutPostRedisplay();
}

void myDisplay() {
    glFlush();
}

int main(int argc,char* argv[]) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(currentWidth,currentHeight);
    glutCreateWindow("Mouse CLICK");
    glutDisplayFunc(myDisplay);
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glEnd();
    glFlush();
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouseEvent);
    glColor3f(currentRed,currentBlue,currentGreen);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(orthorLeft,orthorRight,orthorBot,orthorTop);
    glutMainLoop();
}