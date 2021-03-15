#include <GL/glut.h> ///使用GLUT外掛
#include <stdio.h>
float teapotX=0, teapotY=0;///茶壺的座標
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空
 glPushMatrix();///矩陣備份
    glTranslatef(teapotX, teapotY, 0);///照著座標移動
    glutSolidTeapot(0.3);
 glPopMatrix();///矩陣還原

 glutSwapBuffers(); ///交換2倍的buffers
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
    display();///顯示刷新速度變快
}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT初始設定
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///顯示模式
 glutCreateWindow("week04 mouse"); ///開窗

 ///glutMouseFunc(mouse);
 glutDisplayFunc(display); ///等一下要顯示的函式
 glutMotionFunc(motion);///滑鼠移動的函式
 glutMainLoop(); ///主要迴圈
}
