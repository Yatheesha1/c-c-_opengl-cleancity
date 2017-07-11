//g++ 'manwalk.cpp' -lGL -lGLU -lglut
 
#include <GL/glut.h>
#include <math.h>
#include <unistd.h>
GLfloat a;
int seq=0;

int flag=0;

void Printtext(float r,float g,float b,const char *string,int x,int y)
{
	glColor3f(r,g,b);
	glRasterPos2f(x,y);
    while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void start()
{
   Printtext(.9,.5,.5,"WELCOME",-50,0); 
   Printtext(0.9,0.5,0.5,"CG MINI PROJECT",-90,-30); 
   Printtext(0.9,0.5,0.5,"________________",-90,-60);
   Printtext(0.9,0.5,0.5,"CLEAN CITY",-60,-90);   
   Printtext(.9,.5,.5,"ISHAHATH,THALHATH",-120,-120);
   glutPostRedisplay();
   glutSwapBuffers();
}

void end()
{
   glClearColor(0,0,0,1);
   Printtext(.9,.5,.5,"MESSAGE:",-50,0);
   Printtext(0.9,0.5,0.5,"KEEP THE CITY CLEAN",-120,-30);  
   glutPostRedisplay();
   glutSwapBuffers();
}

void DrawCircle(float cx, float cy, float r) 
{ 
	int num_segments=360,degree=360;
	glBegin(GL_POLYGON);
	for(int i = 0; i < degree; i++) 
	{ 
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 
	} 
	glEnd(); 
}

void sun()
{
  glColor3f(0.992,0.721,0.075);
  DrawCircle(-100, 250, 30) ;
}

void dust()
{
  glColor3f(0.5019,0.0,0.0);
  glBegin(GL_POLYGON);
  glVertex2f(-450,-270);
  glVertex2f(-450,-240);
  glVertex2f(-400,-230);
  glVertex2f(-400,-250);
  glEnd();
}

void tree()
{
  glColor3f(0.5019,0.0,0.0);
  glBegin(GL_POLYGON);//stem
  glVertex2f(-180,-110);
  glVertex2f(-180,-160);
  glVertex2f(-200,-160);
  glVertex2f(-200,-110);
  glEnd();

  glColor3f(0.0,0.5,0.0);
  DrawCircle(-210,-100,25);//leaf
  DrawCircle(-170,-100,25);
  DrawCircle(-200,-60,30);
  DrawCircle(-180,-60,30);
  DrawCircle(-190,-35,20);
}

void draw_tree()
{
  glPushMatrix();
  glTranslated(50,-80,0);
  glScaled(1.5,1.5,0);
  tree();
  glPopMatrix();
	
  glPushMatrix();
  glTranslated(300,100,0);
  tree();
  glPopMatrix();
  
  glPushMatrix();
  glTranslated(100,200,0);
  glScaled(0.9,0.9,0);
  tree();
  glPopMatrix();
}

void man()
{
	glPushMatrix();
    glTranslatef(a,0,0);	
	int y=200;
	
	if(flag==1)
	{
	glPushMatrix();
    glTranslated(23,-225,0);
    glRotatef(90, 0, 0, 1);
	glTranslated(-23,225,0);
    }
	 
	glColor3f(0.98,0.89,0.535);//face
	glBegin(GL_POLYGON);
	glVertex2f(22,4-y);
	glVertex2f(21,8-y);
	glVertex2f(20,8-y);
	glVertex2f(18,10-y);
	glVertex2f(21,13-y);
	glVertex2f(18,13-y);
	glVertex2f(18,14-y);
	glVertex2f(17,14-y);
	glVertex2f(17.5,14.5-y);
	glVertex2f(16,15-y);
	glVertex2f(20,20-y);
	glVertex2f(30,20-y);
	glVertex2f(30,8-y);
	glVertex2f(28,7-y);
	glVertex2f(28,5-y);
	glEnd();
	
	glColor3f(0,0,0);//hair
	glBegin(GL_POLYGON);
	glVertex2f(20,20-y);
	glVertex2f(28.5,18-y);
	glVertex2f(27,15-y);
	glVertex2f(30,20-y);
	glVertex2f(30,15-y);
	glVertex2f(32,14-y);
	glVertex2f(34,15-y);
	glVertex2f(22,25-y);
	glVertex2f(20,23-y);
	glEnd();

	glPointSize(3.5-y);//eye
	glColor3f(0,0,0);
	glBegin(GL_POINTS);
	glVertex2f(19,16.5-y);
	glEnd();

	glLineWidth(1.5);//eye brow
	glColor3f(0,0,0);	
	glBegin(GL_LINE_STRIP);
	glVertex2f(20,19-y);
	glVertex2f(21.5,18.5-y);
	glVertex2f(22,18-y);
	glEnd();

	glColor3f(0,0.969,0.996);//shirt
	glBegin(GL_POLYGON);
	glVertex2f(21,3.5-y);
	glVertex2f(28,5-y);
	glVertex2f(29,-25-y);
	glVertex2f(17,-25-y);
	glVertex2f(20,0-y);
	glVertex2f(21,1-y);
	glEnd();

	glLineWidth(0.5);//mouth
	glColor3f(0,0,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(18,11.5-y);
	glVertex2f(19,10.5-y);
	glVertex2f(20,10-y);
	glEnd();
	
	glColor3f(0,0.969,0.996);//shirt	
	glBegin(GL_TRIANGLES);	
	glVertex2f(23,2-y);
	glVertex2f(31,-10-y);
	glVertex2f(27,-12-y);
	glEnd();	
	
	glLineWidth(0.5);
	glColor3f(0,0,0);//handblack
	glBegin(GL_LINE_LOOP);
	glVertex2f(23,2-y);
	glVertex2f(27,-12-y);
	glVertex2f(31,-10-y);
	glEnd();

	glColor3f(0.98,0.89,0.535);//hand
	glBegin(GL_POLYGON);
	glVertex2f(27.5,-11.5-y);
	glVertex2f(28,-13.5-y);
	glVertex2f(19,-19-y);
	glVertex2f(20,-21.5-y);
	glVertex2f(22.5,-21.5-y);
	glVertex2f(22,-19.5-y);
	glVertex2f(32,-15-y);
	glVertex2f(31,-10.5-y);
	glEnd();
	
	if(flag==1)
	 glPopMatrix();
		
	glColor3f(0.98,0.89,0.535);//leg1
	glBegin(GL_POLYGON);
	glVertex2f(21.5,-40-y);
	glVertex2f(26,-40-y);
	glVertex2f(26.5,-50-y);
	glVertex2f(23,-50-y);
	glEnd();

	glColor3f(1,1,1);//sock
	glBegin(GL_POLYGON);
	glVertex2f(23,-50-y);
	glVertex2f(26.5,-50-y);
	glVertex2f(27,-59-y);
	glVertex2f(18,-60-y);
	glVertex2f(17.5,-59.5-y);
	glVertex2f(17.5,-58-y);
	glVertex2f(21,-58-y);
	glVertex2f(23,-57-y);
	glVertex2f(23,-50-y);
	glEnd();
	
	glColor3f(1,0,0);//short
	glBegin(GL_POLYGON);
	glVertex2f(18,-25-y);
	glVertex2f(20,-40-y);
	glVertex2f(26,-40-y);
	glVertex2f(28,-25-y);
	glEnd();
	glPopMatrix();
}

void path()
{
	glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(-550,-300);
    glVertex2f(-550,-200);
    glVertex2f(550,-200);
    glVertex2f(550,-300);
    glEnd(); 
}

void sky()
{
  glColor3f(0.0,0.9,0.9);
  glBegin(GL_POLYGON);
  glVertex2f(-550,100);
  glVertex2f(-550,350);
  glVertex2f(550,350);
  glVertex2f(550,100);
  glEnd();
}
void mountain()
{
  glColor3f(0.588,0.565,0.6);
  glBegin(GL_POLYGON);
  glVertex2f(-530,100);
  glVertex2f(-250,300);
  glVertex2f(0,100);
  glVertex2f(250,300);
  glVertex2f(520,100);
  glEnd();
}



void land()
{
	glColor3f(0,1,0);
    glBegin(GL_POLYGON);
    glVertex2f(-550,-350);
    glVertex2f(-550,-300);
    glVertex2f(550,-300);
    glVertex2f(550,-350);
    glEnd(); 
    
    glBegin(GL_POLYGON);
    glVertex2f(-550,-200);
    glVertex2f(-550,100);
    glVertex2f(550,100);
    glVertex2f(550,-200);
    glEnd(); 
}

void displayfst()
{
  glClear(GL_COLOR_BUFFER_BIT);
  if(seq==0)
  {
   start();
   seq=1;
   sleep(3);
  }
  if(seq==1)
  {
    path();
    if(a<-215)
      flag=1;
    
    if(a<-222)
      flag=2;  
      
    if(flag!=2)
      dust();
      
    a=a-0.5;  
    land();
    sky();
    mountain();
    sun();
    glPushMatrix();
    glTranslatef(a,-20,0);
    man();
    glPopMatrix();
    draw_tree();
    if(a<-300)
      seq=2;
  }
  if(seq==2) 
  {
	end();
  }
  glutPostRedisplay();
  glutSwapBuffers();
}

void myinit()
{
glClearColor(0,0,0,1);
glPointSize(1.0);
gluOrtho2D(-550.0,550.0,-350.0,350.0);
}

int main(int argc,char** argv)
{

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("MANWALK");
	myinit();
	glutDisplayFunc(displayfst);
	glutMainLoop();
	return 0;
}
