/*Semestre 2017 - 2
NOMBRE: YAIR CORTES BENITEZ
GRUPO: 02
PRACTICA: 7 (casa)
SISTEMA SOLAR COMPLETO IMPLEMENTANDO LUZ DIFUSA, LUZ AMBIENTAL Y LUZ ESPECULAR A LOS 
	PLANETAS, ASI COMO SUS RESPECTIVAS LUNAS Y EL ANILLO DE URANO.
*/

#include "Main.h"

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement

int sol = 0;
int mercurio = 0;
int venus = 0;
int tierra = 0;
int marte = 0;
int jupiter = 0;
int saturno = 0;
int urano = 0;
int neptuno = 0;
int luna = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat LuzAmbientalSol[] = { 0.5f, 0.5f, 0.5f, 1.0f };
GLfloat LuzDifusaSol[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LuzEspecularSol[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LuzPosicionSol[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat LuzDifusaMercurio[] = { 0.8f, 1.82f, 0.33f, 1.0f };			
GLfloat LuzEspecularMercurio[] = { 0.2, 1.9, 0.54, 1.0 };
GLfloat MercurioShininess[] = { 30.0 };

GLfloat LuzDifusaVenus[] = { 0.1f, 0.42f, 0.33f, 1.0f };			
GLfloat LuzEspecularVenus[] = { 0.7, 0.0, 1.5, 1.0 };
GLfloat VenusShininess[] = { 30.0 };

GLfloat LuzDifusaTierra[] = { 0.0f, 0.8f, 1.33f, 1.0f };			
GLfloat LuzEspecularTierra[] = { 0.0, 2.5, 0.9, 1.0 };
GLfloat TierraShininess[] = { 45.0 };

GLfloat LuzDifusaMarte[] = { 0.8f, 0.4f, 0.1f, 1.0f };			
GLfloat LuzEspecularMarte[] = { 1.5, 0.0, 0.5, 1.0 };
GLfloat MarteShininess[] = { 45.0 };

GLfloat LuzDifusaJupiter[] = { 1.8f, 1.44f, 0.5f, 1.0f };			
GLfloat LuzEspecularJupiter[] = { 1.5, 0.0, 0.5, 1.0 };
GLfloat JupiterShininess[] = { 45.0 };

GLfloat LuzDifusaSaturno[] = { 0.8f, 1.1f, 0.7f, 1.0f };			
GLfloat LuzEspecularSaturno[] = { 3.0, 0.0, 0.1, 1.0 };
GLfloat SaturnoShininess[] = { 45.0 };

GLfloat LuzDifusaUrano[] = { 0.354f, 0.0f, 0.255f, 1.0f };			
GLfloat LuzEspecularUrano[] = { 0.01, 0.7, 0.7, 1.0 };
GLfloat UranoShininess[] = { 45.0 };

GLfloat LuzDifusaNep[] = { 0.5f, 0.6f, 0.2f, 1.0f };
GLfloat LuzEspecularNep[] = { 1.2f, 1.1f, 1.8f, 1.0f };
GLfloat NepShininess[] = { 50.0 };


GLfloat LuzDifusaLuna[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat LuzEspecularLuna[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat LunaShininess[] = { 50.0 };

GLfloat LuzDifusaAnillo[] = { 0.9f, 0.8f, 0.4f, 1.0f };			// Luna
GLfloat LuzEspecularAnillo[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat AnilloShininess[] = { 50.0 };



void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT0, GL_AMBIENT, LuzAmbientalSol);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LuzDifusaSol);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LuzEspecularSol);
	glEnable(GL_LIGHT0);

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix(); //SISTEMA SOLAR

	glLightfv(GL_LIGHT0, GL_POSITION, LuzPosicionSol);
	glEnable(GL_LIGHTING);

	glPushMatrix(); //sol
	glDisable(GL_LIGHTING);
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(3.5, 20, 25);  //Draw Sun (radio,lineasH,lineasV);
	glEnable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();//Mercurio
	glRotatef(mercurio, 0, 1, 0); //aplicar la rotacion antes de que se mueva el pivote para que gire alrededor del sol (Traslacion)
	glTranslatef(6, 0, 0);
	glRotatef(mercurio, 0, 1, 0);//rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaMercurio);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularMercurio);
	glMaterialfv(GL_FRONT, GL_SHININESS, MercurioShininess);
	glutSolidSphere(0.5, 12, 12);
	glPopMatrix();

	glPushMatrix();//Venus
	glRotatef(venus, 0, 1, 0); //Traslacion
	glTranslatef(9, 0, 0);
	glRotatef(venus, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaVenus);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularVenus);
	glMaterialfv(GL_FRONT, GL_SHININESS, VenusShininess);
	glutSolidSphere(0.8, 12, 12);
	glPopMatrix();

	glPushMatrix();//Tierra
	glRotatef(tierra, 0, 1, 0); //Traslacion
	glTranslatef(10, 0, 0);
	glRotatef(tierra, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaTierra);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularTierra);
	glMaterialfv(GL_FRONT, GL_SHININESS, TierraShininess);
	glutSolidSphere(1, 12, 12);

	glPushMatrix();//Luna
	glRotatef(luna, 0, 1, 0);
	glTranslatef(1.5, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaLuna);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularLuna);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.2, 12, 12);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();//Marte
	glRotatef(marte, 0, 1, 0); //Traslacion
	glTranslatef(11, 0, 0);
	glRotatef(marte, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaMarte);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularMarte);
	glMaterialfv(GL_FRONT, GL_SHININESS, MarteShininess);
	glutSolidSphere(1.3, 12, 12);

	glPushMatrix();//Luna
	glRotatef(luna, 0, 1, 0);
	glTranslatef(1.5, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaLuna);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularLuna);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.2, 12, 12);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//Jupiter
	glRotatef(jupiter, 0, 1, 0); //Traslacion
	glTranslatef(15, 0, 0);
	glRotatef(jupiter, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaJupiter);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularJupiter);
	glMaterialfv(GL_FRONT, GL_SHININESS, JupiterShininess);
	glutSolidSphere(1.7, 12, 12);

	glPushMatrix();//Luna
	glRotatef(luna, 0, 1, 0);
	glTranslatef(2.2, 0.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaLuna);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularLuna);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPushMatrix();//Luna
	glRotatef(luna, 0, 1, 0);
	glTranslatef(2.8, 1.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaLuna);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularLuna);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//Saturno
	glRotatef(saturno, 0, 1, 0); //Traslacion
	glTranslatef(16, 0, 0);
	glRotatef(saturno, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaSaturno);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularSaturno);
	glMaterialfv(GL_FRONT, GL_SHININESS, SaturnoShininess);
	glutSolidSphere(1.4, 12, 12);
	glPushMatrix();//anillo
	glRotatef(45, 1, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaAnillo);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularAnillo);
	glMaterialfv(GL_FRONT, GL_SHININESS, AnilloShininess);
	glutSolidTorus(0.09, 1.5, 50, 50);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//Urano
	glRotatef(urano, 0, 1, 0); //Traslacion
	glTranslatef(18, 0, 0);
	glRotatef(urano, 0, 1, 0); //rota en su propio eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaUrano);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularUrano);
	glMaterialfv(GL_FRONT, GL_SHININESS, UranoShininess);
	glutSolidSphere(1.3, 12, 12);

	glPushMatrix();//Luna
	glRotatef(luna, 0, 1, 0);
	glTranslatef(2.0, 1.5, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaLuna);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularLuna);
	glMaterialfv(GL_FRONT, GL_SHININESS, LunaShininess);
	glutSolidSphere(0.3, 12, 12);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();//neptuno
	glRotatef(neptuno, 0, 1, 0);
	glTranslatef(21, 0, 0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, LuzDifusaNep);
	glMaterialfv(GL_FRONT, GL_SPECULAR, LuzEspecularNep);
	glMaterialfv(GL_FRONT, GL_SHININESS, NepShininess);
	glutSolidSphere(0.8, 30, 20);
	glPopMatrix();
	
	glPopMatrix();

	glutSwapBuffers();
}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{   //movimiento 
		sol = (sol - 5) % 360; //garantiza que el sol regrese al rango
		mercurio = (mercurio - 10) % 360; //si se quiere que gire al otro lado, cambia el signo a +10;
		venus = (venus - 7) % 360;
		tierra = (tierra - 8) % 360;
		marte = (marte - 9) % 360;
		jupiter = (jupiter - 6) % 360;
		saturno = (saturno - 5) % 360;
		urano = (urano - 4) % 360;
		neptuno = (neptuno - 2) % 360;
		luna = (luna + 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}
