#include <GL/glut.h>


void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(-5, 5, -5, 5); 
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT); //

    // Draw points
    glPointSize(5.0);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glBegin(GL_POINTS);
        glVertex2f(-4.0, 4.0);
        glVertex2f(-3.0, 4.0);
        glVertex2f(-2.0, 4.0);
    glEnd();

    // Draw lines
    glColor3f(0.0, 1.0, 0.0); // Green color
    glBegin(GL_LINES);
        glVertex2f(-4.0, 3.0);
        glVertex2f(-2.0, 3.0);
    glEnd();

    // Draw triangles
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glBegin(GL_TRIANGLES);
        glVertex2f(-4.0, 2.0);
        glVertex2f(-3.0, 2.0);
        glVertex2f(-3.5, 3.0);
    glEnd();

    // Draw quads
    glColor3f(1.0, 0.0, 1.0); // Magenta color
    glBegin(GL_QUADS);
        glVertex2f(-4.0, 1.0);
        glVertex2f(-2.0, 1.0);
        glVertex2f(-2.0, 0.0);
        glVertex2f(-4.0, 0.0);
    glEnd();

    // Draw polygon
    glColor3f(0.5, 0.5, 0.5); // Gray color
    glBegin(GL_POLYGON);
        glVertex2f(-4.0, -1.0);
        glVertex2f(-3.0, -1.0);
        glVertex2f(-3.0, -2.0);
        glVertex2f(-4.0, -2.0);
    glEnd();

    glFlush(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("OpenGL Output Primitives"); 
    init(); 
    glutDisplayFunc(display); 
    glutMainLoop(); 
    return 0;
}
