#include "code.h"
float red=1.0f, blue=1.0f,green=1.0f;
float delta=1./20;
float t=0;
float f(float x){
	if(x>0.2&&x<0.6)
	{
	x*=10;
	return -x*x+8*x-12;
	}	
	if(x<-0.2&&x>-0.6)
	{
    x*=10;  
	return -1*(-(-x)*(-x)+8*(-x)-12);
	}
	else
	{
	return 0;
	}
}
float u(float x, float t)
{
	if(x>0 && (t<8*delta*0.05)){
		glColor3ub(0,0,255);
		glVertex2f(x,f(x+t)/2);
		glColor3ub(0,255,0);
		glVertex2f(x,f(x-t)/2);
	}
	else 
	{
		glColor3f(1,1,1);
		glVertex2f(x,f(x+t)/2);
		glVertex2f(x,f(x-t)/2);
	}
	
	if(x-t>=0)
	{	
		if(x<0){glColor3f(1,1,1);}
		else{glColor3f(1,0,0);};
		return 1./2*(f(x+t)+f(x-t));
	}
	else
	{	
		if(x<0){glColor3f(1,1,1);}
		else{glColor3f(1,0,0);};
		return 1./2*(f(x+t)-f(t-x)); 
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
void setka()
{
	glPushMatrix();
	glScalef(1,0.25,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glLoadIdentity();
	glLineWidth(0);
	glColor3ub(100*red, 100*green, 100*blue);
	//horizontal lines
	
	
	

	for(float q=0.9;q>-1;q-=0.1){
	glBegin(GL_LINES);
	glVertex3f(-1, q, 0.0);
	glVertex3f(1, q, 0.0);
	glEnd();
	}
	//vertical lines
	for(float q=0.9;q>-1;q-=0.1){
	glLineWidth(0);
	glColor3ub(100*red, 100*green, 100*blue);
	glBegin(GL_LINES); 
	glVertex3f(q, -1, 0.0);
	glVertex3f(q, 1, 0.0);
	glEnd();
	}
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
	//дельта т=эль/4а
	//икс от эл до трех эл

glEnd();
glPopMatrix();
	glFlush();
	glutSwapBuffers();
}
void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27 || key==13){//esc & enter - exit
		exit(0);}
	if(key=='1'){
		t+=delta*0.05;
	}
	if(key=='2')
	{
		t-=delta*0.05;
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