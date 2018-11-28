#include "code.h"
#include <math.h>
// идентификаторы меню
int fillMenu, shrinkMenu, mainMenu, colorMenu;
int kuu;
// статус меню
int menuFlag = 0;	
void display();
void specialKeys();
bool pshe=0;
bool wah=0;
// Определения констант для меню
 #define PI 3.141592653
int light_sample = 0;
#define without	1
#define with	2
double rotate_y=0; 
double rotate_x=0;
void ChangeSize1(int w, int h)    {
glViewport (0.0, 0.0, w, h);

glMatrixMode( GL_PROJECTION );
glLoadIdentity();
gluPerspective( 45.0, w / h, 1.0, 1000.0 );
}         

void ChangeSize(int w, int h) {
	// предотвращение деления на ноль
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	// используем матрицу проекции
	glMatrixMode(GL_PROJECTION);
	// обнуляем матрицу
	glLoadIdentity();
	// установить параметры вьюпорта
	glViewport(0, 0, w, h);
	// установить корректную перспективу
	// gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	// вернуться к матрице проекции
	glMatrixMode(GL_MODELVIEW);
}
void ChangeSize2(int width, int height)    {
  	// Предотвращаем деление на нуль
  	if(height == 0)   height = 1;
 	 // Устанавливаем поле просмотра с размерами окна
    	glViewport(0, 0, width, height);
// Устанавливает матрицу преобразования в режим проецирования
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();

// Устанавливаем размеры перспективы (отсекающего объема)
// (left, right, bottom, top, near, far)
GLfloat aspectRatio = (GLfloat)width / (GLfloat)height;// Для коррекции
const GLfloat nRange = 260; // Размеры отсекающих плоскостей

// Первоначально задали куб, теперь его корректируем
// в зависимости от искажения графического окна
;
 double w = glutGet( GLUT_WINDOW_WIDTH );
    double h = glutGet( GLUT_WINDOW_HEIGHT );
    double ar = w / h;
    gluPerspective( 0, 90, 0.1, 0.2 );  
// Восстанавливает матрицу преобразования в исходный режим вида
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();      
}


void init()
{
    glClearColor(0.3, 0.3, 0.3, 1.0);
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
}
void init_l()
{
    float light0_diffuse[] = {0.4, 0.7, 0.2};
    float light0_direction[] = {0.0, 0.0, 1.0, 0.0};

    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
}
void pov1(){
	rotate_y -= 5;
	//glutPostRedisplay();
}
void pov2(){
	 rotate_y += 5;
	// glutPostRedisplay();
}
void pov3(){
	rotate_x += 5;
	//glutPostRedisplay();
}
void pov4(){
	rotate_x -= 5;
	//glutPostRedisplay();
}
void display(){
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  //glLoadIdentity();
 // установка источников света
  
  if (light_sample == 0)
      {
            // ничего
            GLfloat light0_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light0_direction[] = {0.0, 0.0, -5.0, 0.0};
            glEnable(GL_LIGHT0);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
            glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
      }
   if (light_sample == 1)
      {
            // направленный источник света
            GLfloat light0_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light0_direction[] = {0.0, 0.0, -1.0, 0.0};
            glEnable(GL_LIGHT0);
            glLightfv(GL_LIGHT0, GL_DIFFUSE, light0_diffuse);
            glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);
      }
      if (light_sample == 2)
      {
            // точечный источник света
            // убывание интенсивности с расстоянием
            // отключено (по умолчанию)
            GLfloat light1_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light1_position[] = {0.0, 0.0, -1.0, 1.0};
            glEnable(GL_LIGHT1);
            glLightfv(GL_LIGHT1, GL_DIFFUSE, light1_diffuse);
            glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
      }
      if (light_sample == 3)
      {
            // точечный источник света
            // убывание интенсивности с расстоянием
            // задано функцией f(d) = 1.0 / (0.4 * d * d + 0.2 * d)
            GLfloat light2_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light2_position[] = {0.0, 0.0, -1.0, 1.0};
            glEnable(GL_LIGHT2);
            glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
            glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
            glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.0);
            glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.2);
            glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.4);
      }
      if (light_sample == 4)
      {
            // прожектор
            // убывание интенсивности с расстоянием
            // отключено (по умолчанию)
            // половина угла при вершине 30 градусов
            // направление на центр плоскости
            GLfloat light3_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light3_position[] = {-2.0, 0.0, -2.0, 1.0};
            GLfloat light3_spot_direction[] = {2.0, 0.0, 2.0};
            glEnable(GL_LIGHT3);
            glLightfv(GL_LIGHT3, GL_DIFFUSE, light3_diffuse);
            glLightfv(GL_LIGHT3, GL_POSITION, light3_position);
            glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30);
            glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light3_spot_direction);
      }
      if (light_sample == 5)
      {
            // прожектор
            // убывание интенсивности с расстоянием
            // отключено (по умолчанию)
            // половина угла при вершине 30 градусов
            // направление на центр плоскости
            // включен рассчет убывания интенсивности для прожектора
            GLfloat light4_diffuse[] = {0.4, 0.7, 0.2};
            GLfloat light4_position[] = {0.0, 0.0, -1.0, 1.0};
            GLfloat light4_spot_direction[] = {0.0, 0.0, 1.0};
            glEnable(GL_LIGHT4);
            glLightfv(GL_LIGHT4, GL_DIFFUSE, light4_diffuse);
            glLightfv(GL_LIGHT4, GL_POSITION, light4_position);
            glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30);
            glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light4_spot_direction);
            glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 15.0);
      }
      if (light_sample == 6)
      {
            // несколько источников света
            GLfloat light5_diffuse[] = {1.0, 0.0, 0.0};
            GLfloat light5_position[] = {0.5 * cos(0.0), 0.5 * sin(0.0), 1.0, 1.0};
            glEnable(GL_LIGHT5);
            glLightfv(GL_LIGHT5, GL_DIFFUSE, light5_diffuse);
            glLightfv(GL_LIGHT5, GL_POSITION, light5_position);
            glLightf(GL_LIGHT5, GL_CONSTANT_ATTENUATION, 0.0);
            glLightf(GL_LIGHT5, GL_LINEAR_ATTENUATION, 0.4);
            glLightf(GL_LIGHT5, GL_QUADRATIC_ATTENUATION, 0.8);
            GLfloat light6_diffuse[] = {0.0, 1.0, 0.0};
            GLfloat light6_position[] = {0.5 * cos(2 * PI / 3), 0.5 * sin(2 * PI / 3), 1.0, 1.0};
            glEnable(GL_LIGHT6);
            glLightfv(GL_LIGHT6, GL_DIFFUSE, light6_diffuse);
            glLightfv(GL_LIGHT6, GL_POSITION, light6_position); 
            glLightf(GL_LIGHT6, GL_CONSTANT_ATTENUATION, 0.0);
            glLightf(GL_LIGHT6, GL_LINEAR_ATTENUATION, 0.4);
            glLightf(GL_LIGHT6, GL_QUADRATIC_ATTENUATION, 0.8);
            GLfloat light7_diffuse[] = {0.0, 0.0, -1.0};
            GLfloat light7_position[] = {0.5 * cos(4 * PI / 3), 0.5 * sin(4 * PI / 3), 1.0, 1.0};
            glEnable(GL_LIGHT7);
            glLightfv(GL_LIGHT7, GL_DIFFUSE, light7_diffuse);
            glLightfv(GL_LIGHT7, GL_POSITION, light7_position); 
            glLightf(GL_LIGHT7, GL_CONSTANT_ATTENUATION, 0.0);
            glLightf(GL_LIGHT7, GL_LINEAR_ATTENUATION, 0.4);
            glLightf(GL_LIGHT7, GL_QUADRATIC_ATTENUATION, 0.8);
      }
 glPushMatrix();
  
 glColor3f( 0.0, 1.0, 0.0 );    
 glBegin(GL_LINES);
 glVertex3f(  -1, 0, 0 ); 
 glVertex3f(  1, 0, 0 ); 
 glEnd();

 glColor3f( 0.0, 0.0, 1.0 );    
 glBegin(GL_LINES);
 glVertex3f(  0, -1,0 ); 
 glVertex3f(  0, 1, 0 ); 
 glEnd();

  glColor3f( 1.0, 0.0, 0.0 );    
 glBegin(GL_LINES);
 glVertex3f(  0, 0, 0 ); 
 glVertex3f(  0, 0, 1 ); 
 glEnd();
 
  glRotatef(rotate_x/1,1,0,1);
  glRotatef(rotate_y/1, 0.0, 1.0, 1 );

 
  glBegin(GL_QUADS);
 //фронт
  glNormal3f(0,0,1);
  glColor3f( 1.0, 1.0, 0.0 );    
  glVertex3f(  -0.35, 0.0, 0.2 ); 
  glVertex3f(  -0.35, 0.5, 0.2 );
  glVertex3f(  -0.15, 0.5, 0.2 );
  glVertex3f(  -0.15, 0, 0.2 );
      
  glVertex3f(  -0.35,  0.5, 0.2 ); 
  glVertex3f(  -0.20,  0.7, 0.2 );    
  glVertex3f(  0.20,  0.7, 0.2 );    
  glVertex3f(  0.35,  0.5, 0.2 );      
    
  glVertex3f( 0.15,  0.0, 0.2 );      
  glVertex3f( 0.15,  0.5, 0.2 );
  glVertex3f( 0.35,  0.5, 0.2 );
  glVertex3f( 0.35,  0, 0.2 );
  glEnd();
 
  //задняя стенка
  glBegin(GL_QUADS);
  glColor3f( 0.0, 1.0, 1.0 );    
  glVertex3f(  -0.35, 0.0, 0.0 ); 
  glVertex3f(  -0.35, 0.5, 0.0 );
  glVertex3f(  -0.15, 0.5, 0.0 );
  glVertex3f(  -0.15, 0, 0.0 );
      
  glVertex3f(  -0.35,  0.5, 0.0 );    
  glVertex3f(  -0.20,  0.7, 0.0 );    
  glVertex3f(  0.20,  0.7, 0.0 );    
  glVertex3f(  0.35,  0.5, 0.0 );      
    
  glVertex3f( 0.15,  0.0, 0.0 );      
  glVertex3f( 0.15,  0.5, 0.0 );
  glVertex3f( 0.35,  0.5, 0.0 );
  glVertex3f( 0.35,  0, 0.0 );

  glNormal3f(-1,0,0);
  //боковые
  glColor3f( 0.17, 0.55, 0.45 );    
  glVertex3f(  -0.35, 0.0, 0.0 );
  glVertex3f(  -0.35, 0.5, 0.0 );
  glVertex3f(  -0.35, 0.5, 0.2 ); 
  glVertex3f(  -0.35, 0.0, 0.2 ); 
      
  glVertex3f(  -0.35, 0.5, 0.0 );
  glVertex3f(  -0.20, 0.7, 0.0 );
  glVertex3f(  -0.20, 0.7, 0.2 ); 
  glVertex3f(  -0.35, 0.5, 0.2 );

  glVertex3f(  0.35, 0.0, 0.0 );
  glVertex3f(  0.35, 0.5, 0.0 );
  glVertex3f(  0.35, 0.5, 0.2 ); 
  glVertex3f(  0.35, 0.0, 0.2 ); 
      
  glVertex3f(  0.35, 0.5, 0.0 );
  glVertex3f(  0.20, 0.7, 0.0 );
  glVertex3f(  0.20, 0.7, 0.2 ); 
  glVertex3f(  0.35, 0.5, 0.2 );
  glNormal3f(0,-1,0);
  //верх
  glNormal3f(0,1,0);
  glColor3f( 0.50, 0.50, 0.9 );    
  glVertex3f(  0.20,  0.7, 0.0 );    
  glVertex3f(  0.20,  0.7, 0.2 ); 
  glVertex3f(  -0.20,  0.7, 0.2 );   
  glVertex3f(  -0.20,  0.7, 0.0 );    
  
  //низ
  glNormal3f(0,-1,0);
  glColor3f( 0.15, 0.16, 0.8 );    
  glVertex3f(  0.15,  0.0, 0.0 );    
  glVertex3f(  0.15,  0.0, 0.2 ); 
  glVertex3f(  0.35,  0.0, 0.2 );   
  glVertex3f(  0.35,  0.0, 0.0 );    
  glNormal3f(0,1,0);
    glVertex3f(  -0.15,  0.0, 0.0 );    
  glVertex3f(  -0.15,  0.0, 0.2 ); 
  glVertex3f(  -0.35,  0.0, 0.2 );   
  glVertex3f(  -0.35,  0.0, 0.0 );  
  
  //внутри
  glNormal3f(-1,0,0);
  glColor3f( 0.64, 0.63, 0.12 );    
  glVertex3f(  -0.15, 0.0, 0.0 ); 
  glVertex3f(  -0.15, 0.5, 0.0 );
  glVertex3f(  -0.15, 0.5, 0.2 ); 
  glVertex3f(  -0.15, 0.0, 0.2 ); 
      glNormal3f(-1,0,0);
  glVertex3f(  0.15, 0.0, 0.0 ); 
  glVertex3f(  0.15, 0.5, 0.0 );
  glVertex3f(  0.15, 0.5, 0.2 ); 
  glVertex3f(  0.15, 0.0, 0.2 ); 
  glNormal3f(0,-1,0);
   glColor3f( 0.45, 0.34, 0.76 );    
  glVertex3f(  -0.15, 0.5, 0.0 );
  glVertex3f(  -0.35, 0.5, 0.2 );
  glVertex3f(  0.35, 0.5, 0.2 );  
  glVertex3f(  0.15, 0.5, 0.0 ); 
   glEnd();

   
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
//glPushMatrix();
glTranslated(0, 0, 0);
glRotatef( 30, 0.0, 0.0, 1 ); 
//glRotatef(-10,0,0,1);
glTranslated(0, 0, 0);
//glPopMatrix();
glPopMatrix();
   /*
   glPushMatrix();
    
 
  glRotatef( rotate_x, 1.0, 0.0, 0.5 );
  glRotatef( rotate_y, 0.0, 1.0, 0.5 );
  
 
   glRotatef( -30, 1.0, 0.0, 0.1 ); 
  glRotatef( -rotate_x, 1.0, 0.0, 0.5 );
  glRotatef( -rotate_y, 0.0, 1.0, 0.5 );
    glPopMatrix();*/
 // отключение источников света
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHT1);
      glDisable(GL_LIGHT2);
      glDisable(GL_LIGHT3);
      glDisable(GL_LIGHT4);
      glDisable(GL_LIGHT5);
      glDisable(GL_LIGHT6);
      glDisable(GL_LIGHT7);
  glutSwapBuffers();
 
}
void specialKeys( int key, int x, int y ) {
 
  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT){
     rotate_y -= 5;
	 glutPostRedisplay();
	 
  }
  //  Left arrow - decrease rotation by 5 degree
   if (key == GLUT_KEY_LEFT){
   rotate_y += 5;
   glutPostRedisplay();
  }
 
   if (key == GLUT_KEY_UP){
   rotate_x += 5;
   glutPostRedisplay();
  }
 
   if (key == GLUT_KEY_DOWN){
rotate_x -= 5;
glutPostRedisplay();
  }
 
  //  Request display update
  
 
}
void processNormalKeys( unsigned char key, int x, int y ) {
  //  Right arrow - increase rotation by 5 degree
  if (key == 27 || key==15)
    exit(0);
	if(pshe==true){  
	  if (key == '1') light_sample = 1;
      if (key == '2') light_sample = 2;
      if (key == '3') light_sample = 3;
      if (key == '4') light_sample = 4;
      if (key == '5') light_sample = 6;
	  if (key == '0') light_sample = 0;
	    glutPostRedisplay();
	}
     
}
void processMenuStatus(int status, int x, int y) {
	if (status == GLUT_MENU_IN_USE)
		{menuFlag = 1;
	}
	else{
		menuFlag = 0;}
}
void processMainMenu(int option) {
 switch(option){
 case without:
	 pshe=false;
	 wah=false;
	  glClearColor(0.3, 0.3, 0.3, 1.0);
    glDisable(GL_LIGHTING);
    //glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
	 glutPostRedisplay();
	 break;

 case with:
	 pshe=true;
	 wah=true;
	  glClearColor(0.3, 0.3, 0.3, 1.0);
    glEnable(GL_LIGHTING);
    glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    glEnable(GL_NORMALIZE);
	 glutPostRedisplay();
	 break;
 }
	//ничего здесь не делаем
	//все действия для подменю
}
void createPopupMenus() {
	mainMenu = glutCreateMenu(processMainMenu);
	glutAddMenuEntry("Без освещения", without);
	glutAddMenuEntry("С освещением", with);
	// прикрепить меню к правой кнопке
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//статус активности меню
	glutMenuStatusFunc(processMenuStatus);
}
int main(int argc, char* argv[]){
  pshe=false;
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutCreateWindow("Litera's lighting");
  glEnable(GL_DEPTH_TEST);
  if(wah){
	  init();}
  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(processNormalKeys);
  glutReshapeFunc(ChangeSize);
  createPopupMenus();
  glutMainLoop();
  return 0;
}