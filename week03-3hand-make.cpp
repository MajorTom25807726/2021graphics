#include <GL/glut.h> ///�ϥ�GLUT�~��

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///�M��
    glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();
    glutSolidTeapot(0.3); ///��߯���

    glutSwapBuffers(); ///�洫2����buffers
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv); ///GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///��ܼҦ�
    glutCreateWindow("07050135_�����M"); ///�}��

    glutDisplayFunc(display); ///���@�U�n��ܪ��禡

    glutMainLoop(); ///�D�n�j��
}
