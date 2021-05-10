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
week08
------

```cpp
 ////畫出圖形
#include <opencv/highgui.h>
int main()
{
    IplImage * img = cvLoadImage("0412.jpg");
    cvShowImage("week08", img);
    cvWaitKey(0);
}
```
week08-1
-----
```cpp
 ////把圖貼在茶壺上
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
    IplImage * img = cvLoadImage("0412.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08 texture");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}
```
week08-2
------
```cpp
////合併背景與茶壺
#include <opencv/highgui.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
void init()
{
    IplImage * img = cvLoadImage("0412.jpg"); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
}   ///最後一行最難/最重要, 所貼圖影像的資料都設定好
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glBegin(GL_POLYGON);
            glTexCoord2f(0, 1); glVertex3f(-1,-1,0);
            glTexCoord2f(1, 1); glVertex3f(+1,-1,0);
            glTexCoord2f(1, 0); glVertex3f(+1,+1,0);
            glTexCoord2f(0, 0); glVertex3f(-1,+1,0);
        glEnd();
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08 texture");

    init();

    glutDisplayFunc(display);
    glutMainLoop();
}
```
week10 music
----
```cpp
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

```
week10 light
------
```cpp
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week10 light");


    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutDisplayFunc(display);
    glutMainLoop();
}

```
week11
---
```cpp
///打光的陣列
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week11");
    ///打光的設定
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutDisplayFunc(display);
    glutMainLoop();
}
```
```cpp
////有打光轉向的模型
#include "glm.h"
GLMmodel* pmodel = NULL;

void drawmodel(void)
{///使用範例的程式
    if(!pmodel)
    {
        pmodel = glmReadOBJ("data/al.obj");
        if(!pmodel) exit(0);
        glmUnitize(pmodel);
        glmFacetNormals(pmodel);
        glmVertexNormals(pmodel, 90.0);
    }

    glmDraw(pmodel, GLM_SMOOTH | GLM_MATERIAL);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(180, 0,1,0);
        drawmodel();///使用範例的程式
    glPopMatrix();
    glutSwapBuffers();
}
```
week12
---
```cpp
///上周打光複習
#include <GL/glut.h>
#include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 all in");

    glutDisplayFunc( display );

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    glutMainLoop();
}
```
week12_glm
---
```cpp
#include <GL/glut.h>
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
	return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12 all in");

    glutDisplayFunc( display );

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
    myTexture("Diffuse.jpg");glutMainLoop();
}
```
week12_gundam
---
[前往程式碼區](https://gist.github.com/MajorTom25807726/ffa7dc320c5c44b1c656adaa526fb6c9) 請點擊連結
