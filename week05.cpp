#include <GL/glut.h> ///�ϥ�GLUT�~��
#include <stdio.h>
float vx[2000], vy[2000];///�ǳƤ@�ﳻ�I ���U�n�e ���� -1 ~ +1
int N = 0;///��N�ӳ��I
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///�M��
 glColor3f(0,0,255);
 glBegin(GL_TRIANGLE_FAN);
 for(int i=0;i<N;i++)
 {
     glVertex2f(vx[i], vy[i]);
 }
 glEnd();
 glutSwapBuffers(); ///�洫2����buffers
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    vx[N] = (x-150)/150.0;///���I�O�_�� ���U�n�e
    vy[N] = -(y-150)/150.0;
    N++;
    display();///��ܨ�s�t���ܧ�
}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT��l�]�w
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///��ܼҦ�
 glutCreateWindow("week05 drawing"); ///�}��

 ///glutMouseFunc(mouse);
 glutDisplayFunc(display); ///���@�U�n��ܪ��禡
 glutMotionFunc(motion);///�ƹ����ʪ��禡
 glutMainLoop(); ///�D�n�j��
}
