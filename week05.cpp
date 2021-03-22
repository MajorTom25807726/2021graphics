#include <GL/glut.h> ///使用GLUT外掛
#include <stdio.h>
float vx[2000], vy[2000];///準備一堆頂點 等下要畫 介於 -1 ~ +1
int N = 0;///有N個頂點
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空
 glColor3f(0,0,255);
 glBegin(GL_TRIANGLE_FAN);
 for(int i=0;i<N;i++)
 {
     glVertex2f(vx[i], vy[i]);
 }
 glEnd();
 glutSwapBuffers(); ///交換2倍的buffers
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    vx[N] = (x-150)/150.0;///頂點記起來 等下要畫
    vy[N] = -(y-150)/150.0;
    N++;
    display();///顯示刷新速度變快
}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT初始設定
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///顯示模式
 glutCreateWindow("week05 drawing"); ///開窗

 ///glutMouseFunc(mouse);
 glutDisplayFunc(display); ///等一下要顯示的函式
 glutMotionFunc(motion);///滑鼠移動的函式
 glutMainLoop(); ///主要迴圈
}
