#include <GL/glut.h> ///使用GLUT外掛
#include <stdio.h>
float vx[2000], vy[2000];///準備一堆頂點 等下要畫 介於 -1 ~ +1
int N = 0;///有N個頂點
float angle = 0;
void hand()
{
    glPushMatrix();
        glScalef(0.5,0.1,0.1);///調成細長的
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display()
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空
     glPushMatrix();///左半身
        glTranslatef(-0.25,0,0);///(3)把正轉動的手臂,掛在肩上
        glRotatef(angle,0,0,1);///(2)轉動
        glTranslatef(-0.25,0,0);///(1)將旋轉中心.放在正中心
        hand();
            glPushMatrix();///備份矩陣
            glTranslatef(-0.25,0,0);///(3)把正轉動的手臂,掛在肩上
            glRotatef(angle,0,0,1);///(2)轉動
            glTranslatef(-0.25,0,0);///(1)將旋轉中心.放在正中心
            hand();
        glPopMatrix();///還原矩陣
    glPopMatrix();

    glPushMatrix();///右半身
        glTranslatef(+0.25,0,0);///(3)把正轉動的手臂,掛在肩上
        glRotatef(-angle,0,0,1);///(2)轉動
        glTranslatef(+0.25,0,0);///(1)將旋轉中心.放在正中心
        hand();
            glPushMatrix();///備份矩陣
            glTranslatef(+0.25,0,0);///(3)把正轉動的手臂,掛在肩上
            glRotatef(-angle,0,0,1);///(2)轉動
            glTranslatef(+0.25,0,0);///(1)將旋轉中心.放在正中心
            hand();
        glPopMatrix();///還原矩陣
    glPopMatrix();
 glutSwapBuffers();///交換2倍的buffers
 angle++;
}
///void mouse(int button, int state, int x, int y)
///{
///}
void motion(int x, int y)
{
    angle++;///只要mouse在motion時,就會增加角度
    display();///顯示刷新速度變快
}
void keyboard(unsigned char key, int x, int y)
{

}
int main(int argc, char ** argv)
{
 glutInit(&argc, argv); ///GLUT初始設定
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///顯示模式
 glutCreateWindow("week05 drawing"); ///開窗

 ///glutMouseFunc(mouse);
 glutIdleFunc(display);
 glutDisplayFunc(display); ///等一下要顯示的函式
 glutMotionFunc(motion);///滑鼠移動的函式
 glutMainLoop(); ///主要迴圈
}
