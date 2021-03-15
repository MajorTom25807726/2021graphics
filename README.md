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
