#include "code.h"
float red=1.0f, blue=1.0f,green=1.0f;
double A1=1.0f,A2=1.0f,A3=0.0f,P1=0.0f,P2=1.0f,P3=1.0f;
double ph=0.0f,ah=0.0f,pv=0.0f,av=0.0f,rot=0,tor=0,f6=0,f7=0;
int pl=0,pr=0,pu=0,pd=0,al=0,ar=0,au=0,ad=0,kuu=0;
void changeSize(GLsizei w, GLsizei h)
{
/*w=400;h=400;
glViewport(0, 0, w, h);
glLoadIdentity();*/

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
	glVertex3f(0, -1, 0.0);
	glVertex3f(0, 1, 0.0);
	glEnd();
	//A
	glRotatef(tor, 0.0, 0.0, 1.0);
	glColor3ub(255*A1, 255*A2, 255*A3);
	glBegin(GL_POLYGON);
	glVertex3f(ah+0.5, 0.0+av, 0.0);
	glVertex3f(ah+0.3, -0.4+av, 0.0);
	glVertex3f(ah+0.4, -0.4+av, 0.0);
	glVertex3f(ah+0.5, -0.1+av, 0.0);
	glVertex3f(ah+0.6, -0.4+av, 0.0);
	glVertex3f(ah+0.7, -0.4+av, 0.0);
	glEnd();
	glColor3ub(100, 15, 100);
	glBegin(GL_LINE_LOOP);
	glVertex3f(ah+0.5, 0.0+av, 0.0);
	glVertex3f(ah+0.3, -0.4+av, 0.0);
	glVertex3f(ah+0.4, -0.4+av, 0.0);
	glVertex3f(ah+0.5, -0.1+av, 0.0);
	glVertex3f(ah+0.6, -0.4+av, 0.0);
	glVertex3f(ah+0.7, -0.4+av, 0.0);
	glEnd();
	//палочка посередине
	glColor3ub(255*A1, 255*A2, 255*A3);
	glBegin(GL_POLYGON);
	glVertex3f(ah+0.462, -0.205+av, 0.0);
	glVertex3f(ah+0.538, -0.205+av, 0.0);
	glVertex3f(ah+0.572, -0.295+av, 0.0);
	glVertex3f(ah+0.428, -0.295+av, 0.0);
	glEnd();
	glColor3ub(100, 15, 100);
	glBegin(GL_LINES);
	glVertex3f(ah+0.465, -0.205+av, 0.0);
	glVertex3f(ah+0.535, -0.205+av, 0.0);
	glVertex3f(ah+0.435, -0.295+av, 0.0);
	glVertex3f(ah+0.565, -0.295+av, 0.0);
	glEnd();

	glRotatef(-tor, 0.0, 0.0, 1.0);
 	//P
	glLineWidth(3);
	glColor3ub(255*P1, 255*P2, 255*P3);

	glRotatef(rot, 0.0, 0.0, 1.0);

	glBegin(GL_QUADS);
	glVertex3f(0.1+ph, -0.3+pv, 0.0);
	glVertex3f(0.1+ph, 0.1+pv, 0.0);
	glVertex3f(0.2+ph, 0.1+pv, 0.0);
	glVertex3f(0.2+ph, -0.3+pv, 0.0);

	glVertex3f(0.4+ph, -0.3+pv, 0.0);
	glVertex3f(0.3+ph, -0.3+pv, 0.0);
	glVertex3f(0.3+ph, 0.1+pv, 0.0);
	glVertex3f(0.4+ph, 0.1+pv, 0.0);
	
	glVertex3f(0.1+ph, 0.0+pv, 0.0);
	glVertex3f(0.1+ph, 0.1+pv, 0.0);
	glVertex3f(0.4+ph, 0.1+pv, 0.0);
	glVertex3f(0.3+ph, 0.0+pv, 0.0);
	glEnd();

	//glRotatef(-rot, 0.0, 0.0, 1.0);

	glColor3ub(100, 15, 100);
	
	//glRotatef(rot, 0.0, 0.0, 1.0);

	glBegin(GL_LINE_LOOP);
	glVertex3f(0.1+ph, -0.3+pv, 0.0);
	glVertex3f(0.1+ph, 0.1+pv, 0.0);
	glVertex3f(0.4+ph, 0.1+pv, 0.0);
	glVertex3f(0.4+ph, -0.3+pv, 0.0);
	glVertex3f(0.3+ph, -0.3+pv, 0.0);
	glVertex3f(0.3+ph, 0.0+pv, 0.0);
	glVertex3f(0.2+ph, 0.0+pv, 0.0);
	glVertex3f(0.2+ph, -0.3+pv, 0.0);
	glEnd();
 
	glRotatef(-rot, 0.0, 0.0, 1.0);

	glFlush();
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
	if (key == 27 || key==13){//esc & enter - exit
		exit(0);}
	if(key=='w'){
		pv+=0.1;pu+=1;
	}
	if(key=='a'){
		ph-=0.1;pl+=1;
	}
	if(key=='d'){
		ph+=0.1;pr+=1;
	}
	if(key=='s'){
		pv-=0.1;pd+=1;
	}
	if(key=='i'){
		av+=0.1;au+=1;
	}
	if(key=='j'){
		ah-=0.1;al+=1;
	}
	if(key=='l'){
		ah+=0.1;ar+=1;
	}
	if(key=='k'){
		av-=0.1;ad+=1;
	}
}

void spinDisplay1(void)
{
rot+=0.5;
if(rot>360.0) rot=rot-360.0;

tor+=0.5;
if(tor>360.0) tor=tor-360.0;

glutPostRedisplay();
}
void spinDisplay2(void)
{
rot-=0.5;
if(rot<-360.0) rot=rot+360.0;

tor-=0.5;
if(tor<-360.0) tor=tor+360.0;

glutPostRedisplay();
}
void spinDisplay3(void)
{
rot-=0.5;
if(rot<-360.0) rot=rot+360.0;

tor+=0.5;
if(tor>360.0) tor=tor-360.0;

glutPostRedisplay();
}
void processSpecialKeys(int key, int x, int y) {
	switch(key){
		case GLUT_KEY_F3:
			A1=1.0f,A2=1.0f,A3=0.0f,P1=0.0f,P2=1.0f,P3=1.0f;
			break;
			case GLUT_KEY_F1:
			A1=(rand()%100)/100.;
			A2=(rand()%100)/100.;
			A3=(rand()%100)/100.;
			break;
			case GLUT_KEY_F2:
			P1=(rand()%100)/100.;
			P2=(rand()%100)/100.;
			P3=(rand()%100)/100.;
			break;
			case GLUT_KEY_F4:
			ah=0;
			av=0;
			ph=0;
			pv=0;
			rot=0;tor=0;
			glutDisplayFunc(setka);
			glutIdleFunc(setka);
			break;
			case GLUT_KEY_LEFT:
				ah-=0.1;
				ph-=0.1;
				break;
			case GLUT_KEY_RIGHT:
				ah+=0.1;
				ph+=0.1;
				break;
			case GLUT_KEY_UP:
				av+=0.1;
				pv+=0.1;
				break;
			case GLUT_KEY_DOWN:
				av-=0.1;
				pv-=0.1;
				break;
			case GLUT_KEY_PAGE_UP:
				rot-=10;
				tor-=10;
				break;
			case GLUT_KEY_PAGE_DOWN:
				rot+=10;
				tor+=10;
				break;
				case GLUT_KEY_F9:
		rot-=10;
			break;
			case GLUT_KEY_F10:
		rot+=10;
			break;
			case GLUT_KEY_F11:
		tor-=10;
			break;
			case GLUT_KEY_F12:
		tor+=10;
			break;
			case GLUT_KEY_F6:
				if(kuu){glutIdleFunc(NULL); kuu=0;glutIdleFunc(setka);}
				else{glutIdleFunc(spinDisplay2);kuu++;} 
			break;
			case GLUT_KEY_F7:
				if(kuu){glutIdleFunc(NULL); kuu=0;glutIdleFunc(setka);}
				else{glutIdleFunc(spinDisplay1);kuu++;}
			break;
			case GLUT_KEY_F8:	
				if(kuu){glutIdleFunc(NULL); kuu=0;glutIdleFunc(setka);}
				else{glutIdleFunc(spinDisplay3);kuu++;}
			break;
			;}
} 

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Лабораторна робота № 1. Виконав Андріяш Павло, ПК-14-2");

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glClearColor(0.2,0.35,0.2,0);
	glutDisplayFunc(setka);
	glutIdleFunc(setka);

	glutReshapeFunc(changeSize);


	glutMainLoop();
	return 1;
}