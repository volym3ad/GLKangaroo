#include <GL/glut.h>
#include "Point.h"
#include "Object.h"
#include <vector>

using namespace std;

#define windowWidth 800
#define windowHeight 600
#define size 16

Object *object = new Object();

// create vectors of Point's classes

vector<Point*> kangaroo(size);
vector<Point*> glasses(size);

Point *horizontalVector = new Point(2, 0);
Point *verticalVector = new Point(0, 2);

// initialize dots

void initialize() {
    for (int i=0; i<size; i++) {
        kangaroo[i] = new Point();
        glasses[i] = new Point();
    }

    kangaroo[0]->setPoint(150, 500);
    kangaroo[1]->setPoint(150, 300);
    kangaroo[2]->setPoint(350, 300);
    kangaroo[3]->setPoint(150, 550);
    kangaroo[4]->setPoint(100, 500);
    kangaroo[5]->setPoint(150, 330);
    kangaroo[6]->setPoint(150, 270);
    kangaroo[7]->setPoint(120, 300);
    kangaroo[8]->setPoint(250, 300);
    kangaroo[9]->setPoint(400, 300);
    kangaroo[10]->setPoint(400, 150);
    kangaroo[11]->setPoint(250, 150);
    kangaroo[12]->setPoint(325, 225);
    kangaroo[13]->setPoint(175, 225);
    kangaroo[14]->setPoint(150, 50);
    kangaroo[15]->setPoint(500, 50);

    // ---------------------------------

    glasses[0]->setPoint(300, 520);
    glasses[1]->setPoint(300, 530);
    glasses[2]->setPoint(290, 520);
    glasses[3]->setPoint(290, 530);
    glasses[4]->setPoint(283, 520);
    glasses[5]->setPoint(283, 530);
    glasses[6]->setPoint(273, 520);
    glasses[7]->setPoint(273, 530);
    glasses[8]->setPoint(283, 525);
    glasses[9]->setPoint(290, 525);

}

void createGlasses() {

    glColor3f(0.0, 0.0, 0.0);

    object->createQuadObject(glasses[0], glasses[1], glasses[2], glasses[3]);
    object->createQuadObject(glasses[4], glasses[5], glasses[6], glasses[7]);
    object->createLineObject(glasses[8], glasses[9]);
}

void createKangaroo()
{
    glColor3f(1.0, 1.0, 0.0);

    object->createTriangleObject(kangaroo[0], kangaroo[1], kangaroo[2]);
    object->createTriangleObject(kangaroo[0], kangaroo[3], kangaroo[4]);
    object->createTriangleObject(kangaroo[5], kangaroo[6], kangaroo[7]);
    object->createTriangleObject(kangaroo[8], kangaroo[9], kangaroo[10]);
    object->createQuadObject(kangaroo[13], kangaroo[11], kangaroo[8], kangaroo[12]);
    object->createTriangleObject(kangaroo[12], kangaroo[14], kangaroo[15]);

    createGlasses();
}

void transport(double vectX, double vectY)
{
    Point *transportVector = new Point(vectX, vectY);
    for (int i=0; i<16; i++) {
        kangaroo[i] = kangaroo[i]->sum(transportVector);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    createKangaroo();
    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

}

void move(int Key, int x, int y)
{
    switch (Key)
    {
        case GLUT_KEY_RIGHT:
            transport(horizontalVector->x, horizontalVector->y);
            break;
        case GLUT_KEY_LEFT:
            transport(-horizontalVector->x, -horizontalVector->y);
            break;
        case GLUT_KEY_UP:
            transport(verticalVector->x, verticalVector->y);
            break;
        case GLUT_KEY_DOWN:
            transport(-verticalVector->x, -verticalVector->y);
            break;
        default:
            break;
    }
    glutPostRedisplay();

}

void erase() {
    for (int i=0; i<size; i++) {
        delete[] kangaroo[i];
        delete[] glasses[i];
    }
}

int main(int argc, char **argv)
{
    initialize();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("kangaroo");
    glClearColor(0.4, 0.1, 0.4, 1.0);

    glutReshapeFunc(reshape);

    glutSpecialFunc(move);
    glutDisplayFunc(display);
    glutMainLoop();
    
    erase();
}
