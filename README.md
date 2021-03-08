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
