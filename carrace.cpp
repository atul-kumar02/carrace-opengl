#include "GL/freeglut.h"
#include "GL/gl.h"
#include "iostream"
#include "math.h"
#include "GL/glut.h"
using namespace std;
float y[4][2]={-44,-19,-12,13,20,45,52,77};
float yk[11][2]={20,40,70,95,130,150,180,210,240,260,300,340,375,400,425,445,485,500,535,550,570,585};
float yk2[11][2]={20,40,70,95,130,150,180,210,240,260,300,340,375,400,425,445,485,500,535,550,570,585};
GLint flag=0,font=0,count,score,level;
GLint p=-6,q=-36;
void initk(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}
//=======================defination of drawBitmapText function===========================
void drawBitmapText(const char *string,float xk,float yk,float zk) 
{  
    const char *c;
    glRasterPos3f(xk, yk,zk);

    for (c=string; *c != '\0'; c++) 
    {
        if(font==0) glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
        else if(font==1) glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}
void display(void)
{   glClear(GL_COLOR_BUFFER_BIT);
    //boundary......................................
    glColor3f(0.0,1.0,1.0);
    glBegin(GL_LINE_STRIP);
        glVertex2f(-15.0, -50.0);
        glVertex2f(15.0, -50.0);
        glVertex2f(15.0, 50.0);
        glVertex2f(-15.0, 50.0);
        glVertex2f(-15.0, -50.0);
    glEnd();
//other vehicles............................................
glColor3f(0,0,1);
    glRectf(3,yk[0][0],9,yk[0][1]);//1a
    glRectf(-9,yk[1][0],-3,yk[1][1]);//2a
    glRectf(-9,yk[2][0],-3,yk[2][1]);//1b
    glRectf(3,yk[3][0],9,yk[3][1]);//2b
    glRectf(-9,yk[4][0],-3,yk[4][1]);//1c
    glRectf(3,yk[5][0],9,yk[5][1]);//2c
    glRectf(-9,yk[6][0],-3,yk[6][1]);//1d
    glRectf(3,yk[7][0],9,yk[7][1]);//2d
    glRectf(3,yk[8][0],9,yk[8][1]);//1d
    glRectf(3,yk[9][0],9,yk[9][1]);//2d
    glRectf(-9,yk[10][0],-3,yk[10][1]);//2d
 
//road divider...............................
glColor3f(1.0,1.0,1.0);
for(int i=0;i<4;i++)
{
    glRectf(-1,y[i][0],1,y[i][1]);
}
glColor3f(1.0,0,0);
    glRectf(-17,-45,-16,50);
    glRectf(16,-45,17,50);
    glEnd();
glColor3f(0,1,1);
    glRectf(-20.0,-50.0,20.0,-45.0);
//my car........................................
glColor3f(1,1,0);
    glPushMatrix();
    glRectf(p-4,q-6,p+4,q+6);
    glEnd();
    glPopMatrix();
glEnd();
glColor3f(0,1,0);
    font=1;
    drawBitmapText("score",-28,48,0);
    int s1,s2,s3,s4;
    s1 = score/1000;s2 =(score/100)%10;s3=(score%100)/10;s4=score%10;
    char a[5]={s1+48,s2+48,s3+48,s4+48};
    glColor3f(0,1,0);
    drawBitmapText(a,-28,45,0);
    
    drawBitmapText("ATULKUMAR",18,47,0);
    font=0;
    if(flag!=0)
    { 
     //===========GAME OVER==================================
    glColor3f(0.2,0.5,0.5);
    glRectf(-22,-7,22,7);
    glColor3f(0,0,0);
    drawBitmapText("GAME OVER !!",-10,1,0);
    drawBitmapText("Press 'r' To Restart The Game ",-18,-5,0);
    //=======================================================
    glutIdleFunc(NULL);
    }
glutSwapBuffers();
}
void transDisplay(void)
{  for(int i=0;i<4;i++)
       {  
             y[i][0]-=0.3;
              y[i][1]-=0.3;
if(y[i][1]<=-45)
{y[i][0]=57;y[i][1]=82;
glRectf(-1,y[i][0],1,y[i][1]);  
}
 }  
    if(flag==0&&level==1)
     {
       for(int i=0;i<11;i++)
       {  
             yk[i][0]-=1.1;
              yk[i][1]-=1.1;
	
        }        
     } 
 if(flag==0&&level==2)
     {
       for(int i=0;i<11;i++)
       {  
             yk[i][0]-=1.2;
              yk[i][1]-=1.2;
	
        }        
     } 
       if(yk[0][0]<=-600) { yk[0][0]=yk2[0][0];yk[0][1]=yk2[0][1];
yk[1][0]=yk2[1][0];yk[1][1]=yk2[1][1];yk[2][0]=yk2[2][0];yk[2][1]=yk2[2][1];yk[3][0]=yk2[3][0];yk[3][1]=yk2[3][1];
yk[4][0]=yk2[4][0];yk[4][1]=yk2[4][1];yk[5][0]=yk2[5][0];yk[5][1]=yk2[5][1];yk[6][0]=yk2[6][0];yk[6][1]=yk2[6][1];
 yk[7][0]=yk2[7][0];yk[7][1]=yk2[7][1];yk[8][0]=yk2[8][0];yk[8][1]=yk2[8][1];yk[9][0]=yk2[9][0];yk[9][1]=yk2[9][1];yk[10][0]=yk2[10][0];yk[10][1]=yk2[10][1];}

for(int i=0;i<11;i++)
    {
        if((q+6>=yk[i][0])&&(q+6<=yk[i][1]))//condition for collision 
        {  
           if((i==0||i==3||i==5||i==7||i==8||i==9))
           {
	      if(((p-3<=3) &&(p+3>=3))||((p-3<=9) &&(p+3>=9)))
 	       {flag=1;break;}
           }
           else if((i==1||i==2||i==4||i==6||i==10||i==10))
           {
               if(((p-3<=-3) &&(p+3>=-3))||((p-3<=-9) &&(p+3>=-9)))
 	       {flag=1;break;}
           }
           else flag=0;
        }
    }        
if(count%10==0) score++; 
glutPostRedisplay();
}
void restart(void)
{
        if(flag!=0)
        {  for(int i=0;i<11;i++)
           {
              for(int j=0;j<2;j++)
              {
                 yk[i][j]=yk2[i][j];
              }
            }
            p=-6;q=-36,score=0;
flag=0;
        } 
        else  glutIdleFunc(transDisplay); 

        glutPostRedisplay();  
}


void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-30.0, 30.0, -50.0, 50.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}
void keyboard(unsigned char key, int xk, int yk)
{
   
    if(key=='w') {if((q<45)&&(flag==0))q+=3;glutPostRedisplay();}
    if(key=='s') {if((q>-36)&&(flag==0))q-=3;glutPostRedisplay();}
    if(key=='d') {if((p<6)&&(flag==0))p+=6;glutPostRedisplay();}
    if(key=='a') {if((p>-6)&&(flag==0))p-=6;glutPostRedisplay();}
if(key=='1') {if(flag==0)level=1;glutPostRedisplay();}
if(key=='2') {if(flag==0)level=2;glutPostRedisplay();}
    if(key=='r')
    {  glutIdleFunc(restart);}
    if(key=='p'){glutIdleFunc(NULL);}

}


int main(int argc, char** argv)
{  
     glutInit(&argc, argv); 
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     glutInitWindowSize(500, 600);
     glutInitWindowPosition(200, 100);
     glutCreateWindow("CAR RACING...");
     initk();
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     
     glutMainLoop();
     return 0;
}
