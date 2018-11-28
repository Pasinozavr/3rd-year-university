#include "code.h"
#include <math.h>
float red=1.0f, blue=1.0f,green=1.0f;
float t = 0;
float a = 2;
float f0 = 2;
float c = 0;
int k = 1;
float l=1,x1=-l/10,x2=l/10,delta = (x2-x1)*0.2 / (8 * a);
float fix(float x)
{
	if(x>=x1&&x<=x2)
	{
		x*=10;
	return cos(3.14*x/2);
	}
	else{return 0;}
}
float fit(float t) { return -3 ; }
float u(float x, float t)
{
	
	if(t<4/0.2*delta){glColor3f(1,1,1);
	glVertex2f(x,fix(x+a*t)/2);
	glVertex2f(x,fix(x-a*t)/2);}
	glColor3f(1, 0, 0);
	return 1./2*(fix(x+a*t)+fix(x-a*t));
	
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
void setka()
{
	glPushMatrix();
	glScalef(1,0.25,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glLineWidth(0);
	glColor3ub(100*red, 100*green, 100*blue);
	
	//cordinates
	glLineWidth(0);
	glColor3ub(200, 200, 100);
	glBegin(GL_LINES);
	glVertex3f(-1, 0, 0.0);
	glVertex3f(1, 0, 0.0);
	glLineWidth(3);
	glVertex3f(0, -1, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
	glLineWidth(1);
	glPointSize(2);
	glBegin(GL_POINTS);
	glColor3ub(255, 0, 0);
for(float q=-1;q<=1;q+=0.0005)
	{

		
		
		glColor3ub(255, 0, 0);
		glVertex2f(q,u(q,t));
		}


glEnd();
glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27 || key==13){//esc & enter - exit
		exit(0);}
	if(key=='1'){
		t+=delta*1;
		c += (0.5 - 0.1)*0.2 / (8 * a);
		k++;
	}
	if(key=='2')
	{
		t-=delta*1;
		c -= (0.5 - 0.1)*0.2 / (8 * a);
	}

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Волновое уравнение");

	glutKeyboardFunc(processNormalKeys);
	//glutSpecialFunc(processSpecialKeys);

	glClearColor(0.2,0.35,0.2,0);
	glutDisplayFunc(setka);
	glutIdleFunc(setka);

	glutReshapeFunc(changeSize);


	glutMainLoop();
	return 1;
}