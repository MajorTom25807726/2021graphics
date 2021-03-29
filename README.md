# 2021graphics
week03-1
-------
````c
  
///把第1個範例 OprnGL , 拿來亂改
///把第1個Project 變粗黑色 Active
#include <stdio.h>
int main(int argc, char ** argv)
{
    printf("現在的 argc:%d\n", argc);
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]是:%s\n", i ,argv[i]);
    }
}
````
week03-2
-------
````c++
#include <GL/glut.h>


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

            glEnd();

    glutSwapBuffers();
}





int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);

    glutMainLoop();
}
````
week03-3
------
````c++
#include <GL/glut.h> ///使用GLUT外掛

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); ///清空
    glBegin(GL_TRIANGLES);

                glColor3f(1.0f, 0.0f, 0.0f);   glVertex2f(0.0f,   1.0f);
                glColor3f(0.0f, 1.0f, 0.0f);   glVertex2f(0.87f,  -0.5f);
                glColor3f(0.0f, 0.0f, 1.0f);   glVertex2f(-0.87f, -0.5f);

    glEnd();
    glutSolidTeapot(0.3); ///實心茶壺

    glutSwapBuffers(); ///交換2倍的buffers
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv); ///GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); ///顯示模式
    glutCreateWindow("07050135_郭岳霖"); ///開窗

    glutDisplayFunc(display); ///等一下要顯示的函式

    glutMainLoop(); ///主要迴圈
}
````
week04-1
--------
```c++
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

```

week05
------
```cpp
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

```
week06
=====
```cpp
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

```
