#include <GL/glut.h> ///�ϥ�GLUT�~��
#include <stdio.h>
float vx[2000], vy[2000];///�ǳƤ@�ﳻ�I ���U�n�e ���� -1 ~ +1
int N = 0;///��N�ӳ��I
float angle = 0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///�զ��Ӫ���
        glutSolidCube(1);///���
    glPopMatrix();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///�M��
     glPushMatrix();///���b��
        glTranslatef(-0.25,0,0);///(3)�⥿��ʪ����u,���b�ӤW
        glRotatef(angle,0,0,1);///(2)���
        glTranslatef(-0.25,0,0);///(1)�N���त��.��b������
        hand();
            glPushMatrix();///�ƥ��x�}
            glTranslatef(-0.25,0,0);///(3)�⥿��ʪ����u,���b�ӤW
            glRotatef(angle,0,0,1);///(2)���
            glTranslatef(-0.25,0,0);///(1)�N���त��.��b������
            hand();
        glPopMatrix();///�٭�x�}
    glPopMatrix();

    glPushMatrix();///�k�b��
        glTranslatef(+0.25,0,0);///(3)�⥿��ʪ����u,���b�ӤW
        glRotatef(-angle,0,0,1);///(2)���
        glTranslatef(+0.25,0,0);///(1)�N���त��.��b������
        hand();
            glPushMatrix();///�ƥ��x�}
            glTranslatef(+0.25,0,0);///(3)�⥿��ʪ����u,���b�ӤW
            glRotatef(-angle,0,0,1);///(2)���
            glTranslatef(+0.25,0,0);///(1)�N���त��.��b������
            hand();
        glPopMatrix();///�٭�x�}
    glPopMatrix();
 glutSwapBuffers();///�洫2����buffers
 angle++;
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    angle++;///�u�nmouse�bmotion��,�N�|�W�[����
    display();///��ܨ�s�t���ܧ�
}
void keyboard(unsigned char key, int x, int y)
{

}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT��l�]�w
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///��ܼҦ�
 glutCreateWindow("week05 drawing"); ///�}��

 ///glutMouseFunc(mouse);
 glutIdleFunc(display);
 glutDisplayFunc(display); ///���@�U�n��ܪ��禡
 glutMotionFunc(motion);///�ƹ����ʪ��禡
 glutMainLoop(); ///�D�n�j��
}
