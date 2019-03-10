/*Semestre 2019 - 2
NOMBRE: CORTES BENITEZ YAIR
GRUPO: 02
VISUAL STUDIO 2017
#PRACTICA: 5 (Ejercicio casa)
		PARTE DE UN HUMANOIDE AHORA CON BRAZO QUE SE MUEVE CON LOS SIGUIENTES COMANDOS:
		Hombro: Tecla (H - h)
		Codo: Tecla(C - c)
		Muñeca: Tecla(M - m)
		NOTA: AL MOMETO DE GENERAR LAS PIERNAS Y EL OTRO BRAZO SE MOVIAN JUNTO CON LOS MOVIMIENTOS 
		DEL BRAZO ADAPTADO, NO LOGRÉ ENTENDER POR QUE PASABA ESO. 



*/
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
float angleHom= 0.0f;
float angCodo = 0.0f;
float angMu = 0.0f;
int screenW = 0.0;
int screenH = 0.0;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	glColor3f(0.5, 0.5, 0);
	prisma();
	//Poner Código Aquí.
//CUELLO
	glTranslatef(0, -0.6, 0);
	glScalef(0.8, 0.2, 1);
	glColor3f(1, 0.1, 0);
	prisma();
	glScalef(1.25, 5, 1);
	//TORSO
	glTranslatef(0, -0.9, 0);
	glScalef(1.5, -1.5, 1);
	glColor3f(0.8, 0.5, 0);
	prisma();
	glScalef(0.66, -0.66, 1);
	//HOMBRO
	glTranslatef(0.85, 0.5, 0);
	glRotatef(angleHom, 0, 0, 1);
	glScalef(0.2, 0.5, 1);
	glColor3f(0.2, 0, 0.1);
	prisma();
	glScalef(5, 2, 1);
	//BICEP
	glTranslatef(0.55, 0, 0);
	glScalef(0.9, 0.5, 1);
	glColor3f(0.2, 0.1, 0);
	prisma();
	glScalef(1.11, 2, 1);
	//CODO
	glTranslatef(0.55, 0, 0);
	glRotatef(angCodo, 0, 0, 1);
	glScalef(0.2, 0.5, 1);
	glColor3f(0.7, 0, 0.9);
	prisma();
	glScalef(5, 2, 1);
	//ANTEBRAZO
	glTranslatef(0.45, 0, 0);
	glScalef(0.7, 0.5, 1);
	glColor3f(0, 0.3, 0.6);
	prisma();
	glScalef(1.42, 2, 1);
	//MUÑECA
	glTranslatef(0.45, 0, 0);
	glRotatef(angMu, 0, 1, 0);
	glScalef(0.2, 0.5, 1);
	glColor3f(0, 1, 0.4);
	prisma();
	glScalef(5, 2, 1);
	//PALMA
	glTranslatef(0.30, 0, 0);
	glScalef(0.4, 0.5, 1);
	glColor3f(1, 1, 1);
	prisma();
	glScalef(2.5, 2, 1);
	//PULGAR
	glTranslatef(-0.1, 0.3, 0);
	glScalef(0.1, 0.09, 1);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(10, 14.28, 1);
	//INDICE
	glTranslatef(0.5, -0.05, 0);
	glScalef(0.4, 0.05, 1);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(2.5, 14.28, 1);
	//MEDIO
	glTranslatef(0, -0.15, 0);
	glScalef(0.4, 0.05, 1);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(2.5, 20, 1);
	//ANULAR
	glTranslatef(0, -0.15, 0);
	glScalef(0.4, 0.05, 1);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(2.5, 20, 1);
	//MEÑIQUE
	glTranslatef(-0.03, -0.16, 0);
	glScalef(0.3, 0.05, 1);
	glColor3f(1, 0, 0);
	prisma();
	glScalef(3.33, 20, 1);
	/*PIERNA IZQ
	glTranslatef(-2.8, -1.5, 0);
	glScalef(0.4, -1.5, 1);
	glColor3f(0.8, 1.9, 0);
	prisma();*/ 

		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'H':
			if (angleHom < 90)
				angleHom += 2.0f;
			break;
		case 'h':
			if (angleHom > -45)
				angleHom -= 2.0f;
			break;
		case 'c':
			if (angCodo < 90)
				angCodo += 2.0f;
			break;
		case 'C':
			if (angCodo > 0)
				angCodo -= 2.0f;
			break;
		case 'm':
			if (angMu < 40)
				angMu += 2.0f;
			break;
		case 'M':
			if (angMu > -33)
				angMu -= 2.0f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



