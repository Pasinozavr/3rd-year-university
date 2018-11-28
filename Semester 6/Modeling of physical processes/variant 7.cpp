#include "code.h"
#include <math.h>
float red=1.0f, blue=1.0f,green=1.0f;
float t = 0;
float a = 3;
float f0 = 2;
float c = 0;
int k = 1;
float delta = (0.5 - 0.1)*0.2 / (8 * a);
float fix(float x)
{
	return 3 * x;
}
float fit(float t) { return -3 ; }
float u(float x, float t)
{
	glColor3f(1, 0, 0);
	if (x - a*t>0.5) { return 0; }
	if (x + a*t<0.1) { return 0; }
	if (x - a*t<0.1 && x + a*t>0.5) { return 4* ((0.5 - 0.1) / (2 * a))*fit(t); }
	if (0.1<x - a*t && x - a*t<0.5 && x + a*t>0.5) {  return  4 * fit(t)*((0.5 - (x - a*t)) / (2 * a)); }
	if (0.1<x + a*t&&x + a*t<0.5&&x - a*t<0.1) {return  4 * (x + a*t - 0.1)*fit(t) / (2 * a); }
	if (x - a*t>0.1 && x + a*t<0.5) { return 4 * t*fit(t); }
	
}
float u1(float x, float t)
{
	glColor3f(1, 0.5, 0);
	//if (x <= 0.1-16*c) { return 0; }
	if (x >=  0.1-2*t-c && x<=0.5-2*t-c) { return (((-0.8*x)/ ((0.5 + 2 * t + c) - (0.1 + 2 * t + c))) + 0.2)-6*t; }
	if (x >=  0.1-2*t-c) { return 4 * -0.2; }
	

}
float u2(float x, float t)
{
	glColor3f(1, 0.5, 0);
	//if (x <=  0.1+ 16 * c) { return 0; }
	if (x >= 0.1+ 2*t+c && x <= 0.5+2*t+c) { return (((0.8*x) /(0.4) - 0.2))-6*t ; }
	if (x >= 0.1+ 2*t + c) { return 4 * 0.2; }


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

		
		glColor3f(1, 1, 1);
		glVertex2f(q,u1(q,t));
		glColor3f(1, 1, 1);
		glVertex2f(q, u2(q, t));
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