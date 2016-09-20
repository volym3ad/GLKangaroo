#ifndef OPENGLAPPLICATION_OBJECT_H
#define OPENGLAPPLICATION_OBJECT_H

#include <GL/gl.h>
#include "Point.h"

class Object {
public:
    Object() {}

    void createLineObject(Point *class1, Point *class2) {
        glBegin(GL_LINES);
        glVertex2d(class1->x, class1->y);
        glVertex2d(class2->x, class2->y);
        glEnd();
    }

    void createTriangleObject(Point *class1, Point *class2, Point *class3) {
        glBegin(GL_TRIANGLES);
        glVertex2d(class1->x, class1->y);
        glVertex2d(class2->x, class2->y);
        glVertex2d(class3->x, class3->y);
        glEnd();
    }

    void createQuadObject(Point *class1, Point *class2, Point *class3, Point *class4) {
        glBegin(GL_QUAD_STRIP);
        glVertex2d(class1->x, class1->y);
        glVertex2d(class2->x, class2->y);
        glVertex2d(class3->x, class3->y);
        glVertex2d(class4->x, class4->y);
        glEnd();
    }
};

#endif //OPENGLAPPLICATION_OBJECT_H
