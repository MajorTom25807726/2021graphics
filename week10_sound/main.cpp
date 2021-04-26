#include <windows.h>
#include <GL/glut.h>
#include "CMP3_MCI.h"
CMP3_MCI mp3;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
void keyboard(unsigned char key , int x, int y)///TODO2
{
    if(key == '1') PlaySound("Journey - Separate Ways (Worlds Apart) (Official Video - 1983).wav", NULL, SND_ASYNC);
    if(key == '2') PlaySound("re.wav", NULL, SND_ASYNC);
    if(key == '3') PlaySound("mi.wav", NULL, SND_ASYNC);
}
void mouse(int button, int state, int x,int y)
{
    if(state == GLUT_DOWN) PlaySound("do.wav", NULL, SND_ASYNC);
}
int main(int argc, char **argv)
{
    mp3.Load("music.mp3");
    mp3.Play();
    glutInit( &argc, argv);
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 sound");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);///TODO2
    glutMouseFunc(mouse);///TODO4
    glutMainLoop();
}
