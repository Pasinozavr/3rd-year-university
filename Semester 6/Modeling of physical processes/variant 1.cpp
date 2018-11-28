#include "code.h"
#include <math.h>
int a=1;
float t=0, slowmotion=0.2, x1=2./10, x2=6./10, x, delta=(x2-x1)/8*a;

void drawcoordinates()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3ub(100, 100, 100);
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glVertex3f(0, -1, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
}
void drawfringe()
{
	glLineWidth(3);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(0, -1, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
}
void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27 || key==13)
	{
		exit(0);
	}
	if(key=='1')
	{
		t+=delta*slowmotion;
	}
	if(key=='2')
	{
		t-=delta*slowmotion;
	}

}
void changeSize(GLsizei w, GLsizei h)
{
 int left = 0, top = 0;
    int width = w, height = h;

    if (w > h * 4 / 3) // Если экран шире необходимого
    {
        width = h * 4 / 3;
        left = (w - width) / 2;
    }
    else // Наоборот, если экран выше необходимого
    {
        height = w * 3 / 4;
        top = (h - height) / 2;
    }

    glViewport(left, top, width, height);
}
void changecolor()
{
	if(x>0)
	{
		glColor3f(1,0,0);
	}
	else
	{
		glColor3f(1,1,1);
	}
}
float f(float x){
	if(x>=x1 && x<=x2)
	{	
	x*=10;
	return -x*x+8*x-12;
	}	
	if(x<=-x1 && x>=-x2)
	{
	x*=10;
	return (-(-x)*(-x)+8*(-x)-12);
	}
	else
	{
	return 0;
	}
}
float u(float x, float t)
{
	if(x-a*t>=0)
	{
		if(t<4*delta)glColor3f(0,1,0);
		glVertex2f(x,f(x+a*t)/2);
		if(t<4*delta)glColor3f(0,0,1);
		glVertex2f(x,f(x-a*t)/2);
		changecolor();
		return 1./2*(f(x+a*t)+f(x-a*t));
	}
	else
	{
		//glVertex2f(x,f(x+a*t)/2);
		//glVertex2f(x,-f(t-a*x)/2);
		return 1./2*(f(x+a*t)+f(a*t-x)); 
		
	}
}
void modulation()
{
	drawcoordinates();

	glPushMatrix();
	glScalef(1,0.25,1);

	glBegin(GL_POINTS);
	for(x=-1;x<=1;x+=0.0005)
	{
	changecolor();
	glPointSize(3);

	glVertex2f(x,u(x,t));
	
	}
	glEnd();

	glPopMatrix();

	drawfringe();
	glutSwapBuffers();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("u(0,t)=0 -> if x=0 then u=0 - bridge black fringe");

	glutKeyboardFunc(processNormalKeys);


	glClearColor(0.2,0.1,0.2,0);
	glutDisplayFunc(modulation);
	glutIdleFunc(modulation);

	glutReshapeFunc(changeSize);


	glutMainLoop();
	return 1;
}