#include <GL/glut.h> ///�ϥ�GLUT�~��
#include <stdio.h>
float teapotX=0, teapotY=0;///�������y��
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///�M��
 glPushMatrix();///�x�}�ƥ�
    glTranslatef(teapotX, teapotY, 0);///�ӵۮy�в���
    glutSolidTeapot(0.3);
 glPopMatrix();///�x�}�٭�

 glutSwapBuffers(); ///�洫2����buffers
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
    display();///��ܨ�s�t���ܧ�
}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT��l�]�w
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///��ܼҦ�
 glutCreateWindow("week04 mouse"); ///�}��

 ///glutMouseFunc(mouse);
 glutDisplayFunc(display); ///���@�U�n��ܪ��禡
 glutMotionFunc(motion);///�ƹ����ʪ��禡
 glutMainLoop(); ///�D�n�j��
}
