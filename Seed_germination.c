#include<stdio.h>
#include<GL/gl.h>
#include<glut.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
char pressed;
float x,y,z;
int flag = 0,f=0;
void *currentfont;
void setFont(void *font)
{
	currentfont = font;
}
void drawstring(float x, float y, float z,const char *string)
{
	char *c;
	int len = (int)strlen(string);
	int i;
	glRasterPos3f(x, y, z);
	for (i = 0; i < len; i++)
	{
		glColor3f(0.0, 0.0, 0.0);
		glutBitmapCharacter(currentfont, string[i]);
	}
}
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   gluOrtho2D(0.0,100.0,0.0,100.0);
}
void init1()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
   	glOrtho(-100.0, 100.0, -100.0, 100.0, -50.0, 50.0);
}

void frontscreen(void)
{
	
	init1();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glClearColor(0, 0, 0, 1.0);

	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,1,1);
	drawstring(-55, 85.0, 0.0,"MANGLORE  INSTITUTE  OF  TECHNOLOGY  AND  ENGINEERING");
	glColor3f(1,1,1);
	drawstring(-20, 75.0, 0.0,"MANGALURU");
	setFont(GLUT_BITMAP_HELVETICA_18);
       glColor3f(0.7, 0, 1);
	drawstring(-40,60, 0.0, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f(0.7, 0, 1);
	drawstring(- 30, 50, 0.0, "COMPUTER GRAPHICS AND VISALIZATION");
	glColor3f(1, 0.5, 0);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	drawstring(30 - 50, 30, 0.0, "A MINI PROJECT ON");
	glColor3f(1, 0, 0);
	drawstring(30 - 50, 20, 0.0, "SEED GERMINATION");
	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1, 0.5, 0);
	drawstring(-80, -20, 0.0, "BY:");
	glColor3f(1,0.4,0.7);
	drawstring(-80, -30, 0.0, "PRAJNA D.Y (4MT17CS076)");
	glColor3f(1,0.4,0.7);
	drawstring(-80, -40, 0.0, "SITHARA PAI (4MT17CS0101)");
	glColor3f(1, 0.5, 0);
	drawstring(40,-20, 0.0, "PROJECT GUIDES:");
	glColor3f(1,0.4,0.7);
	drawstring(40,-30, 0.0, "Ms.SUNITHA N.V");
	glColor3f(1,0.4,0.7);
	drawstring(40, -40, 0.0, "Mrs.JEEVITHA SAMPATH ");
	glColor3f(0.9, 0.6, 0.4);
	drawstring(-20, -60, 0.0, "PRESS 'A' TO START");
	glutSwapBuffers();
	glFlush();
}
void lastscreen(void)
{
	init1();
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,1,1);
	drawstring(-55, 55.0, 0.0,"Thank you");
}

void output(char s[],float a,float b)
{
    int i;
    glRasterPos3f(a,b,0);
    for(i=0;i<strlen(s);i++)
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15,s[i]);
    glFlush();
}

void draw_line(float a1,float b1,float a2,float b2)
{
    glBegin(GL_LINES);
    glVertex2f(a1,b1);
    glVertex2f(a2,b2);
    glEnd();
}
//void draw_rain(float x)
//{
//    glColor3f(1,1,1);
//    glLineWidth(1);
//    int y=100;
//    int k;
//    for(k=0;k<80;k++)
//    {
//    draw_line(x,y-z,x,(y-2)-z);
//    y=y-20;
//    }
//}
void timer_cloud(int t)
{
	x+=0.1;
	if(x==100)
	{
		x=0;
	}
	glutPostRedisplay();
	glutTimerFunc(100,timer_cloud,0);

}

//float y;
void timer_hand(int t)
{
    y-=0.5;
    if(y==-30)
    {
	//return;
	y=-30;
	return;
    }
    else
    {
	glutPostRedisplay();
        glutTimerFunc(100,timer_hand,0);
    }
	
 } 

float yy;
void timer_rain(int t){
       yy-=0.5;
       if(yy==-25)
        {
        	yy=-0.0;
        	timer_rain(yy);
	   //return;
        }
       else
        { 
            glutPostRedisplay();
	    glutTimerFunc(100,timer_rain,0);
          
        }	
 } 
void sun(){
	  //sun
   glColor3f(1.0,0.9,0.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(40,90,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(13,100,100);
   glPopMatrix();	
}

void grass(){
	
	  //grass
   glColor3f(0.,0.3,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2i(5,47);
   glVertex2i(6,47);
   glVertex2i(3,70);
   glEnd();
  
   glBegin(GL_TRIANGLES);
   glVertex2i(6,47);
   glVertex2i(8,47);
   glVertex2i(5,79);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(10,30);
   glVertex2i(12,30);
   glVertex2i(7,65);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(12,30);
   glVertex2i(14,30);
   glVertex2i(9,75);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(14,30);
   glVertex2i(17,30);
   glVertex2i(17,75);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(17,30);
   glVertex2i(18,30);
   glVertex2i(19,63);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(18,30);
   glVertex2i(20,30);
   glVertex2i(23,75);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(22,30);
   glVertex2i(25,30);
   glVertex2i(27,60);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(25,30);
   glVertex2i(27,30);
   glVertex2i(30,55);
   glEnd();

   //bush1
   glColor3f(0.0,0.7,0.0);
   glPushMatrix();
   glTranslatef(2,35,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(10,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(5,43,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(13,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(9,37,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(15,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(5,35,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(11,100,100);
   glPopMatrix();

   //bush2
   glColor3f(0.0,0.7,0.0);
   glPushMatrix();
   glTranslatef(23,35,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(14,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(26,43,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(15,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(30,37,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(13,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(23,35,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(11,100,100);
   glPopMatrix();

	glColor3f(0.,0.3,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2i(84,30);
   glVertex2i(87,30);
   glVertex2i(82,47);
   glEnd();

   glBegin(GL_TRIANGLES);
   glVertex2i(87,30);
   glVertex2i(89,30);
   glVertex2i(85,57);
   glEnd();
   
   glBegin(GL_TRIANGLES);
   glVertex2i(89,30);
   glVertex2i(92,30);
   glVertex2i(90,49);
   glEnd();
 
   glBegin(GL_TRIANGLES);
   glVertex2i(92,30);
   glVertex2i(94,30);
   glVertex2i(96,50);
   glEnd();	
}
void tree()
{
	   //tree
   glColor3f(0.36,0.25,0.2);
   glBegin(GL_POLYGON);
   glVertex2i(97,60);
   glVertex2i(95,80);
   glVertex2i(100,80);
   glVertex2i(100,30);
   glVertex2i(95,30);
   glEnd();
   //glColor3f(0.0,0.8,0.1);
   glBegin(GL_TRIANGLES);
   glVertex2i(80,30);
   glVertex2i(96,30);
   glVertex2i(96,34);
   glEnd();
 
   glColor3f(0.0,0.7,0.0);
   glPushMatrix();
   glTranslatef(90,80,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(17,100,100);
   glPopMatrix();
   
   //glColor3f(0.0,0.8,0.1);
   glPushMatrix();
   glTranslatef(96,84,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(17,100,100);
   glPopMatrix();
   
  //glColor3f(0.0,0.6,0.2);
   glPushMatrix();
   glTranslatef(93,89,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(13,100,100);
   glPopMatrix();
   
  // glColor3f(0.0,0.7,0.3);
   glPushMatrix();
   glTranslatef(97,95,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(16,100,100);
   glPopMatrix();
   
  // glColor3f(0.0,0.8,0.0);
   glPushMatrix();
   glTranslatef(85,85,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(18,100,100);
   glPopMatrix();

   //glColor3f(0.0,0.8,0.1);
   glPushMatrix();
   glTranslatef(95,73,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(16,100,100);
   glPopMatrix();
}
void scene1()
{
	init();
   //background
   glColor3f(0.75,1.0,0.9);
   glBegin(GL_POLYGON);
   glVertex2i(0,30);
   glVertex2i(100,30);
   glVertex2i(100,100);
   glVertex2i(0,100);
   glEnd();


  	glColor3f(0.8,0.3,0.1);
   glBegin(GL_POLYGON);
   glVertex2i(0,0);
   glVertex2i(100,0);
	glColor3f(0.4,0.5,0.1);	
   glVertex2i(100,30);
   glVertex2i(0,30);
   glEnd();

	sun();
	grass();
 	tree();

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(1.5,y,0);
   
   //hand
   glColor3f(1.0,0.6,0.3);
   glColor3f(1.0,0.6,0.3);
glBegin(GL_POLYGON);
glVertex2i(63,60);
glVertex2i(72,64);
glVertex2i(72,72);
glVertex2i(61,65);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(56,54);
glVertex2i(63,60);
glVertex2i(61,65);
glVertex2i(54,63);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(50,57);
glVertex2i(55,61);
glVertex2i(54,63);
glVertex2i(50,59);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(51,52);
glVertex2i(51,58);
glVertex2i(50,59.5);
glVertex2i(50,52);
glEnd();
glBegin(GL_POLYGON);
glVertex2i(52,50);
glVertex2i(51,52);
glVertex2i(50,52);
glVertex2i(51,50);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(54.5,61);
glVertex2i(54,56);
glVertex2i(56,56);
glVertex2i(55,61);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(55,57);
glVertex2i(55.5,54);
glVertex2i(56,55);
glVertex2i(56,57);
glEnd();

glBegin(GL_POLYGON);
glVertex2i(56,55);
glVertex2i(55,54);
glVertex2i(58,54.5);
glVertex2i(56,60);
glEnd();


glBegin(GL_POLYGON);
glVertex2i(55,58);
glVertex2i(53,53);
glVertex2i(54,52);
glVertex2i(56,57);
glEnd();

   //seed
   glColor3f(0.4,0.7,0.1);
   glPushMatrix();
   glTranslatef(52,49,0);    
   glScalef(0.3,0.9,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();
   
   glPushMatrix();
   glTranslatef(52.5,51,0);    
   glScalef(0.3,0.5,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();
   
   glPushMatrix();
   glTranslatef(52.5,47,0);    
   glScalef(0.3,0.5,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();
 
   glPopMatrix();
      glColor3f(1.0,1.0,1.0);
	output("Press 'B' to go to next scene",75,15);
   glFlush();
}


void scene2()
{
	init();
   //background
   glColor3f(0.75,1.0,0.9);
   glBegin(GL_POLYGON);
   glVertex2i(0,30);
   glVertex2i(100,30);
   glColor3f(0.1,0.1,0.5);
   glVertex2i(100,100);
   glVertex2i(0,100);
   glEnd();
   
	glColor3f(0.8,0.3,0.1);
   glBegin(GL_POLYGON);
   glVertex2i(0,0);
   glVertex2i(100,0);
	glColor3f(0.4,0.5,0.1);	
   glVertex2i(100,30);
   glVertex2i(0,30);
   glEnd();
   
      glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(x,1.5,0);
   
   //cloud     
   glColor3f(0.8,0.95,0.9);
   glPushMatrix();	
   glTranslatef(10,90,0);	
   glScalef(0.3,0.5,0);
   glutSolidSphere(11,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(12,93,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(9,100,100);
   glPopMatrix();	

   glPushMatrix();	
   glTranslatef(13,90,0);	
   glScalef(0.3,0.5,0);	
   glutSolidSphere(12,100,100);
   glPopMatrix();	

   glPushMatrix();	
   glTranslatef(15,89,0);
   glScalef(0.3,0.5,0);	
   glutSolidSphere(12,100,100);
   glPopMatrix();
	
   glPushMatrix();	
   glTranslatef(12,91,0);
   glScalef(0.3,0.5,0);		
   glutSolidSphere(10,100,100);
   glPopMatrix();
        
   glPushMatrix();	
   glTranslatef(8,91,0);
   glScalef(0.9,0.6,0);		
   glutSolidSphere(5,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(17,89,0);
   glScalef(0.9,0.6,0);		
   glutSolidSphere(5,100,100);
   glPopMatrix();
    
   glPushMatrix();	
   glTranslatef(25,90,0);
   glScalef(0.8,0.5,0);		
   glutSolidSphere(4,100,100);
   glPopMatrix();

   //glColor3f(1.0,1.0,1.0);
   glPushMatrix();	
   glTranslatef(50,90,0);	
   glScalef(0.3,0.5,0);
   glutSolidSphere(13,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(51,93,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(10,100,100);
   glPopMatrix();	

   glPushMatrix();	
   glTranslatef(53,90,0);	
   glScalef(0.3,0.5,0);	
   glutSolidSphere(12,100,100);
   glPopMatrix();	

   glPushMatrix();	
   glTranslatef(55,89,0);
   glScalef(0.3,0.5,0);	
   glutSolidSphere(12,100,100);
   glPopMatrix();
	
   glPushMatrix();	
   glTranslatef(56,91,0);
   glScalef(0.3,0.5,0);		
   glutSolidSphere(10,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(47,89,0);
   glScalef(0.9,0.6,0);		
   glutSolidSphere(5,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(57,91,0);
   glScalef(0.9,0.6,0);		
   glutSolidSphere(5,100,100);
   glPopMatrix();

   glPushMatrix();	
   glTranslatef(65,88,0);
   glScalef(0.9,0.4,0);		
   glutSolidSphere(4,100,100);
   glPopMatrix();
   			
   glPopMatrix();

  	 grass();
  	 tree();

   //seedroots
  glColor3f(0.9,0.7,0.5);
   glLineWidth(3);
   draw_line(57,18,61,14);
	draw_line(57.2,16,53,14);
	draw_line(57.3,12,59,10);
	draw_line(57.3,11,55,9.5);
  
   glBegin(GL_TRIANGLES);
   glVertex2i(57,19);
   glVertex2i(58,20);
   glVertex2f(57.5,8);
   glEnd();

   //seed
   glColor3f(0.4,0.7,0.1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glPushMatrix();
   glTranslatef(57,22,0);    
   glScalef(0.3,0.9,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(57.5,24,0);    
   glScalef(0.3,0.5,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();
  
   glPushMatrix();
   glTranslatef(57.5,20,0);    
   glScalef(0.3,0.5,0);
   glutSolidSphere(5,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(1.5,yy,0);

   //rain fall
   glColor3f(0.0,0.0,1.0);
   glLineWidth(3);
   draw_line(1,100,1,90);
   draw_line(2,100,2,90);
    draw_line(1,85,1,80);
  draw_line(4,95,4,87);
  draw_line(3,84,3,75);
   draw_line(6,100,6,90);
   draw_line(8,70,8,56);
   draw_line(10,100,10,90);
   	draw_line(13,70,13,55);
	draw_line(15,90,15,85);
	draw_line(16,80,16,70);
   draw_line(18,80,18,60);
	draw_line(21,100,21,85);
	draw_line(22.5,100,22.5,80);
  draw_line(24,70,24,60);
	draw_line(26,100,26,90);
	draw_line(28,100,28,95);
	draw_line(30,80,30,55);
	draw_line(32,65,32,60);
	draw_line(33,95,33,80);
	draw_line(35,90,35,70);
  draw_line(38,100,38,90);
  draw_line(39.5,95,39.5,85);
   draw_line(41,80,41,85);
   draw_line(43,90,43,75);
	draw_line(45,70,45,60);
   draw_line(47,100,47,85);
	draw_line(50,80,50,60);
	draw_line(53,90,53,75);
   draw_line(55,100,55,90);
   draw_line(56,85,56,75);
   draw_line(58,85,58,60);
	draw_line(60,90,60,70);
	draw_line(62,75,62,63);
	draw_line(64,75,64,65);
	draw_line(65,100,65,85);
	draw_line(67,80,67,75);
	draw_line(66,70,66,63);
	draw_line(69,90,69,75);
  draw_line(72,100,72,90);
   draw_line(74,95,74,80);
   draw_line(75,85,75,83);
   draw_line(76.5,87,76.5,75);
   draw_line(75,85,75,60);
	draw_line(77,75,77,65);
draw_line(79,73,79,68);
draw_line(80,100,80,90);
draw_line(83,85,83,60);
draw_line(82,90,82,75);
draw_line(85,95,85,80);
draw_line(86,85,86,70);
draw_line(87,100,87,85);
draw_line(89,78,89,60);
  draw_line(91,100,91,80);
  draw_line(93,95,93,75);
draw_line(95,87,95,68);
 draw_line(97,80,97,65);
 draw_line(98,85,98,70);
 draw_line(99,90,99,85);
  glColor3f(0.0,0.0,1.0);
   glLineWidth(2);
 	draw_line(2,90,2,85);
 		draw_line(2.5,75,2.5,65);
 	draw_line(3,80,3,60);
 	draw_line(5,90,5,70);
   draw_line(7,90,7,75);
draw_line(9,100,9,85);
 draw_line(12,85,12,65);
   draw_line(14,100,14,80);
	draw_line(17,90,17,75);
  draw_line(19,80,19,65);
  draw_line(23,90,23,70);
   draw_line(27,70,27,55);
draw_line(28,100,28,85);
draw_line(30,77,30,62);
  draw_line(32,90,32,70);
 draw_line(34,100,34,80);
   draw_line(36,70,36,55);
   draw_line(39,90,39,75);
	draw_line(42,100,42,80);
  	draw_line(44,70,44,55);
  	draw_line(46,90,46,70);
 	draw_line(48,100,48,85);
   draw_line(52,70,52,60);
	draw_line(54,85,54,70);
	draw_line(56,95,56,80);
	draw_line(59,75,59,60);
 
   draw_line(63,100,63,90);
   draw_line(66,95,66,80);
draw_line(68,75,68,60);
   draw_line(71,80,71,65);
  draw_line(73,100,73,85);
   draw_line(76,90,76,75);
	draw_line(78,85,78,60);
draw_line(81,95,81,75);
draw_line(83,100,83,90);
	draw_line(86,80,86,65);
   draw_line(90,90,90,75);
  draw_line(94,85,94,75);
  draw_line(96,70,96,60);
 draw_line(98,100,98,90);			
   glPopMatrix();
// 	int x=10,k;
//   for(k=0;k<50;k++)
//   {
//    draw_rain(x);
//    x=x+15;
//   }
   //rain
      glColor3f(1.0,1.0,1.0);
   	output("Press 'C' to go to next scene",75,15);
  
   glFlush();
}
void scene3(){
		init();
		 //background
   glColor3f(0.75,1.0,0.9);
   glBegin(GL_POLYGON);
   glVertex2i(0,30);
   glVertex2i(100,30);
   glVertex2i(100,100);
      //glColor3f(0.1,0.1,0.5);
   glVertex2i(0,100);
   glEnd();
   
	glColor3f(0.8,0.3,0.1);
   glBegin(GL_POLYGON);
   glVertex2i(0,0);
   glVertex2i(100,0);
	glColor3f(0.4,0.5,0.1);	
   glVertex2i(100,30);
   glVertex2i(0,30);
   glEnd();
   
   sun();
   grass();
   tree();
   
   //small plant stems 
      glColor3f(0.0,0.7,0.0);
      glPushMatrix();
    glTranslatef(61.25,39.3,0.0);
    glScalef(0.26,2.0,0.0);
    glutSolidSphere(5,100,100);
    glPopMatrix();
    
    glColor3f(0.75,1.0,0.9);
     glPushMatrix();
    glTranslatef(62.21,39.8,0.0);
    glScalef(0.4,2.0,0.0);
    glutSolidSphere(5,100,100);
    glPopMatrix();
    
    glColor3f(0.0,0.7,0.0);
    glPushMatrix();
    glTranslatef(62,37.3,0.0);
    glRotatef(53.0,0.4,0.4, -0.5); 
    glScalef(0.2,2.0,0.0);
    glutSolidSphere(1.5,100,100);
    glPopMatrix();
    
    glLineWidth(5);
     draw_line(60,39,57,42);
     
      glPushMatrix();
    glTranslatef(63,38.3,0.0);
    glRotatef(51.0,0.3,0.4, -0.4); 
    glScalef(1.0,1.5,0.0);
    glutSolidSphere(1.5,100,100);
    glPopMatrix();
    
     glPushMatrix();
    glTranslatef(57.5,41.8,0.0);
   glRotatef(150.0,0.0,0.0,-0.15); 
    glScalef(0.8,1.5,0.0);
    glutSolidSphere(1.5,100,100);
    glPopMatrix();
    
     glLineWidth(5);
     draw_line(60.2,44,62,46);
     
     glPushMatrix();
    glTranslatef(62,46.3,0.0);
   glRotatef(53.0,0.3,0.4,-0.4); 
    glScalef(0.9,1.5,0.0);
    glutSolidSphere(1.1,100,100);
    glPopMatrix();
    
    //root
        glColor3f(0.9,0.7,0.5);
   glLineWidth(3);
   draw_line(62,28,65,24);
    draw_line(64,25,64.5,23);
	draw_line(61.8,27,58,23);
	  draw_line(62,23,64.5,20);
	draw_line(61.6,21,57,17);
	draw_line(60.2,20.2,58.5,16);
	draw_line(61.5,20.5,64.5,17);
	draw_line(61.5,29.5,59.5,27);
	draw_line(59.4,27,57,25);

   glBegin(GL_TRIANGLES);
   glVertex2i(61.0,30);
   glVertex2i(62.7,30);
   glVertex2f(61.7,18);
   glEnd();
    
     glColor3f(1.0,1.0,1.0);
   	output("Press 'D' to go to next scene",75,15);
   glFlush();
}
void scene4()
{	
		init();
	 //background
   glColor3f(0.75,1.0,0.9);
   glBegin(GL_POLYGON);
   glVertex2i(0,30);
   glVertex2i(100,30);
   glVertex2i(100,100);
      //glColor3f(0.1,0.1,0.5);
   glVertex2i(0,100);
   glEnd();
   
	glColor3f(0.8,0.3,0.1);
   glBegin(GL_POLYGON);
   glVertex2i(0,0);
   glVertex2i(100,0);
	glColor3f(0.4,0.5,0.1);	
   glVertex2i(100,30);
   glVertex2i(0,30);
   glEnd();

	sun();
	grass();
	tree();
	
	   //roots
     glColor3f(0.9,0.7,0.5);
   glLineWidth(3);
   draw_line(61,28,64,24);
    draw_line(63,25,63.5,23);
	draw_line(60.8,27,57,23);
	  draw_line(61,23,63.5,20);
	draw_line(60.6,21,56,17);
	draw_line(60.6,27,57.5,20);
	draw_line(59.2,20.2,57.5,16);
	draw_line(60.5,20.5,63.5,17);
		draw_line(60.5,29.5,58.5,27);
		draw_line(58.4,27,56,25);

   glBegin(GL_TRIANGLES);
   glVertex2i(60.0,28.5);
   glVertex2i(61.7,30);
   glVertex2f(60.7,18);
   glEnd();
	
	glColor3f(0.6,0.4,0.0);
    glBegin(GL_TRIANGLES);
   glVertex2i(57.2,46);
   glVertex2i(59,46);
   glVertex2f(57,47.5);
   glEnd();
   
    glColor3f(0.0,0.7,0.0);
      glPushMatrix();
    glTranslatef(60,43.9,0.0);
    glScalef(0.26,2.6,0.0);
    glutSolidSphere(6,100,100);
    glPopMatrix();
    
     glColor3f(0.0,0.7,0.0);
      glPushMatrix();
    glTranslatef(60,48.3,0.0);
    glScalef(0.26,2.6,0.0);
    glutSolidSphere(6,100,100);
    glPopMatrix();
    
     glColor3f(0.75,1.0,0.9);
     glPushMatrix();
    glTranslatef(61.4,45.1,0.0);
    glScalef(0.3,2.5,0.0);
    glutSolidSphere(6,100,100);
    glPopMatrix();
    
      glColor3f(0.75,1.0,0.9);
     glPushMatrix();
    glTranslatef(61.1,49.4,0.0);
    glScalef(0.37,2.6,0.0);
    glutSolidSphere(6,100,100);
    glPopMatrix();
    
    //leaf
    
       glColor3f(0.0,0.7,0.0);
   glPushMatrix();
   glTranslatef(61.7,37.5,0.0);
   glRotatef(53.0,0.4,0.4, -0.5);
   glScalef(0.2,2.0,0.0);
   glutSolidSphere(1.5,100,100);
   glPopMatrix();
   
   glPushMatrix();
   glTranslatef(64.5,38.5,0.0);
   glRotatef(60.0,0.1,0.1, -0.4);
  glScalef(0.6,1.1,0.0);
   glutSolidSphere(3.8,100,100);
   glPopMatrix();
	
	 glLineWidth(5);
	draw_line(59,38,56,40);
	
   glPushMatrix();
   glTranslatef(55.3,41.4,0.0);
   glRotatef(150.0,0.0,0.0,-0.15);
   glScalef(0.8,1.5,0.0);
   glutSolidSphere(2.5,100,100);
   glPopMatrix();
   
   glLineWidth(5);
	draw_line(59,43,64,50);
   
   glPushMatrix();
   glTranslatef(63,48,0.0);
   glRotatef(53.0,0.1,0.3,-0.4);
   glScalef(0.8,1.2,0.0);
   glutSolidSphere(2.5,100,100);
   glPopMatrix();

	glLineWidth(5);
	draw_line(59.5,44,63,44.3);
   glPushMatrix();
   glTranslatef(62.5,44.6,0.0);
   glRotatef(55.0,0.1,0.1,-0.4);
   glScalef(0.8,2.0,0.0);
   glutSolidSphere(1.0,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(61,64.5,0.0);
   glRotatef(53.0,0.3,0.4,-0.4);
   glScalef(0.9,1.9,0.0);
   glutSolidSphere(1.0,100,100);
   glPopMatrix();
  
   glPushMatrix();
   glTranslatef(58.5,64.5,0.0);
   glRotatef(150.0,0.0,0.0,-0.15);
   glScalef(0.9,1.9,0.0);
   glutSolidSphere(1.0,100,100);
   glPopMatrix();
   
   glLineWidth(5);
	draw_line(59,59,60,61);
  glPushMatrix();
   glTranslatef(60.8,61,0.0);
   glRotatef(53.0,0.3,0.4,-0.4);
   glScalef(0.9,1.6,0.0);
   glutSolidSphere(1.0,100,100);
   glPopMatrix(); 
   
   glLineWidth(5);
	draw_line(58.6,54.1,56,57.5);
   
      glPushMatrix();
   glTranslatef(56.4,57.7,0.0);
   glRotatef(150.0,0.0,0.0,-0.15);
   glScalef(0.9,1.9,0.0);
   glutSolidSphere(1.2,100,100);
   glPopMatrix();

 glLineWidth(5);
   draw_line(59,46,55,50);
 
   glPushMatrix();
   glTranslatef(56,50,0.0);
   glRotatef(150.0,0.0,0.0,-0.15);
   glScalef(0.9,1.9,0.0);
   glutSolidSphere(1.5,100,100);
   glPopMatrix();
   
    //flower
    glColor3f(0.0,0.7,0.0);
	 glLineWidth(5);
   draw_line(59,50,61,55);

   glColor3f(1.0,0.0,0.0);
   glPushMatrix();
   glTranslatef(60,54,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(3.0,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(61.5,53.3,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(3.2,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(61.7,55,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(3.0,100,100);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(60.7,52.8,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(3.3,100,100);
   glPopMatrix();
 
   glPushMatrix();
   glTranslatef(60.8,55.6,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(3.0,100,100);
   glPopMatrix();

   glColor3f(0.45,0.29,0.7);
   glPushMatrix();
   glTranslatef(61,54,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(2.8,100,100);
   glPopMatrix();
   
   glColor3f(1.0,1.0,0.);
   glPushMatrix();
   glTranslatef(61,54,0);
   glScalef(0.3,0.5,0);
   glutSolidSphere(2.0,100,100);
   glPopMatrix();
   
   
      glColor3f(1.0,1.0,1.0);
   	output("Press 'Q' to go to next scene",75,15);
   glFlush();	
}
void keyboard(unsigned char key, int x, int y)
{
    if(key=='a' || key=='A')
    {
    	f=1;
         timer_hand(0);
        glutPostRedisplay();
    }
   if(key=='b' || key=='B')
    {
    	f=2;
        timer_cloud(0);
         timer_rain(0);
        glutPostRedisplay();
    }
    if(key=='c' || key=='C')
    {
    	f=3;
        glutPostRedisplay();
    }
    
        if(key=='d' || key=='D')
    {
    	f=4;
        glutPostRedisplay();
    }
         if(key=='e' || key=='E')
    {
    	f=5;
        glutPostRedisplay();
    }
     if(key=='q' || key=='Q')
    {
        exit(0);
    }
}
void display(void)
 {
 	   glClear(GL_COLOR_BUFFER_BIT);
    if(f==0)
     {
       	frontscreen();
        glutPostRedisplay();
     }
     if(f==1)
     {
        scene1();
        glutPostRedisplay();
     }
     if(f==2)
     {
        scene2();
        glutPostRedisplay();
     }
     if(f==3)
     {
         scene3();
         glutPostRedisplay();
     }
     if(f==4)
     {
         scene4();
         glutPostRedisplay();
     }
      if(f==5)
     {
        lastscreen();
         glutPostRedisplay();
     }
     glFlush();
     glutSwapBuffers();
 }
 
int main(int argc,char **argv)
{
   printf("project");
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(1355,698);
   glutInitWindowPosition(0,0);
   glutCreateWindow("seed germination");
   glutDisplayFunc(display);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
