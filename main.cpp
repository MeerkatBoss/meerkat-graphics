#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

struct vector3f
{
    float x, y, z;
};

GLuint VBO;

static void RenderSceneCB(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3d(0.0, 1.0, 1.0);
    glVertex2d(-1.0, -1.0);
    glVertex2d(0.0, 1.0);
    glVertex2d(1.0, 0.0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argw)
{
    glutInit(&argc, argw);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    int width = 1920;
    int height = 1080;
    glutInitWindowSize(width, height);

    int x = 200;
    int y = 100;
    glutInitWindowPosition(x, y);
    int id = glutCreateWindow("Main");

    GLenum status = glewInit();
    if (status != GLEW_OK)
        return 1;

    GLclampf Red = 0.0f, Green = 0.0f, Blue = 0.0f, Alpha = 1.0f;
    glClearColor(Red, Green, Blue, Alpha);
    // vector3f vertices[3];
    // vertices[0] = {-1.0f, -1.0f, 0.0f};
    // vertices[1] = {1.0f, 0.0f, 0.0f};
    // vertices[2] = {0.0f, 1.0f, 0.0f};
    // glGenBuffers(1, &VBO);
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glutDisplayFunc(RenderSceneCB);
    glutMainLoop();
    return 0;
}