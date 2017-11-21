//proyecto final laboratorio CG

#include "texture.h"
#include "figuras.h"
#include "Camera.h"


int w = 500, h = 500;
int frame=0,time,timebase=0;
int deltaTime = 0;

DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha

CTexture stone;
CTexture mud_creepy;
CTexture port;
CTexture fant;
CTexture creep;
CTexture fant1;

CTexture troom1;
CTexture troom2;
CTexture troom3;
CTexture troom4;
CTexture troom5;
CTexture troom6;

CTexture tree;

CFiguras sky;
CFiguras hey;

int movHombro;
int movDesp;
int movBolsa;
bool play = false;

void arbol()
{
	glPushMatrix();
					glDisable(GL_LIGHTING);
					glEnable( GL_ALPHA_TEST );
					//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
					glAlphaFunc( GL_GREATER, 0.1 );
					//glEnable(GL_BLEND);     // Turn Blending On
					//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
					glBindTexture(GL_TEXTURE_2D, tree.GLindex);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(-45, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
			glPopMatrix();

			glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glBegin(GL_QUADS); //plano
						glColor3f(1.0, 1.0, 1.0);
						glNormal3f( 0.0f, 0.0f, 1.0f);
						glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
						glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
						glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
					glEnd();
					glDisable( GL_ALPHA_TEST );
					//glDisable(GL_BLEND);        // Turn Blending Off
					//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
					glEnable(GL_LIGHTING);
				
			glPopMatrix();
}

			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable ( GL_COLOR_MATERIAL );

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);
    
    text1.LoadBMP("noche.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	text2.LoadBMP("creep.bmp");
	text2.BuildGLTexture();
	text2.ReleaseImage();

	text3.LoadTGA("city/arrow.tga");
	text3.BuildGLTexture();
	text3.ReleaseImage();

	port.LoadTGA("port.tga");
	port.BuildGLTexture();
	port.ReleaseImage();

	fant.LoadTGA("creepy.tga");
	fant.BuildGLTexture();
	fant.ReleaseImage();

	creep.LoadTGA("tunel.tga");
	creep.BuildGLTexture();
	creep.ReleaseImage();

	stone.LoadTGA("ladrillo.tga");
	stone.BuildGLTexture();
	stone.ReleaseImage();

	mud_creepy.LoadTGA("mud.tga");
	mud_creepy.BuildGLTexture();
	mud_creepy.ReleaseImage();

	tree.LoadTGA("arb.tga");
	tree.BuildGLTexture();
	tree.ReleaseImage();

	fant1.LoadTGA("fant.tga");
	fant1.BuildGLTexture();
	fant1.ReleaseImage();

	troom1.LoadTGA("troom1.tga");
	troom1.BuildGLTexture();
	troom1.ReleaseImage();

	troom2.LoadTGA("troom2.tga");
	troom2.BuildGLTexture();
	troom2.ReleaseImage();

	troom3.LoadTGA("troom3.tga");
	troom3.BuildGLTexture();
	troom3.ReleaseImage();

	troom3.LoadTGA("troom3.tga");
	troom3.BuildGLTexture();
	troom3.ReleaseImage();

	troom4.LoadTGA("troom4.tga");
	troom4.BuildGLTexture();
	troom4.ReleaseImage();

	troom5.LoadTGA("troom5.tga");
	troom5.BuildGLTexture();
	troom5.ReleaseImage();

	troom6.LoadTGA("wallsk.tga");
	troom6.BuildGLTexture();
	troom6.ReleaseImage();

	//END NEW//////////////////////////////

	objCamera.Position_Camera(0,-0.5f,10, 0,1.0f,0, 0, 1, 0);

}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
		
	glPushMatrix();
		glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();	

			glPushMatrix(); //caja de escenario
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				sky.skybox(250.0, 250.0, 250.0,text1.GLindex);
				glEnable(GL_LIGHTING);
				glColor3f(1.0,1.0,1.0);
			glPopMatrix();

			glPushMatrix(); //suelo
			glTranslatef(0.0, -15.0, 0.0);
			glDisable(GL_LIGHTING);
			glScalef(150.0, 0.2, 150.0);
			hey.miprisma(mud_creepy.GLindex, 10);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //arbs
				glTranslatef(-10.0, 0.0, 10.5);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.1);
				glScalef(8.0, 11.0, 0.1); //normal situation
				hey.prisma2(tree.GLindex, tree.GLindex);
				glDisable(GL_ALPHA_TEST);
	
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0.0, -15.0, -50.0);
				glPushMatrix(); //castillo almena 1/4
					glTranslatef(-18.5, 15.0, 10.0);
					glDisable(GL_LIGHTING);
					glScalef(10.0, 30.0, 10.0); //normal situation
					hey.miprisma(stone.GLindex, 8);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo almena 2/4
					glTranslatef(18.5, 15.0, 10.0);
					glDisable(GL_LIGHTING);
					glScalef(10.0, 30.0, 10.0); //normal situation
					hey.miprisma(stone.GLindex, 8);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix(); //castillo almena 3/4
				glTranslatef(-18.5, 15.0, -10.0);
				glDisable(GL_LIGHTING);
				glScalef(10.0, 30.0, 10.0); //normal situation
				hey.miprisma(stone.GLindex, 8);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo almena 4/4
				glTranslatef(18.5, 15.0, -10.0);
				glDisable(GL_LIGHTING);
				glScalef(10.0, 30.0, 10.0); //normal situation
				hey.miprisma(stone.GLindex, 8);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix(); //castillo base part1
					glTranslatef(12.0, 12.5, -6.0);
					glDisable(GL_LIGHTING);
					glScalef(16.0, 25.0, 30.0); //normal situation
					hey.miprisma(stone.GLindex, 6);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo base parte 2
				glTranslatef(-12.0, 12.5, -6.0);
				glDisable(GL_LIGHTING);
				glScalef(16.0, 25.0, 30.0); //normal situation
				hey.miprisma(stone.GLindex, 6);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo base parte 3
				glTranslatef(0.0, 25.5, -6.0);
				glDisable(GL_LIGHTING);
				glScalef(25.0, 30.0, 30.0); //normal situation
				hey.miprisma(stone.GLindex, 6);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix(); //castillo entrada 1
					glTranslatef(6.5, 22.5, 10.0);
					glDisable(GL_LIGHTING);
					glScalef(6.0, 50.0, 6.0); //normal situation
					hey.miprisma(stone.GLindex, 4);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo entrada 2
				glTranslatef(-6.5, 22.5, 10.0);
				glDisable(GL_LIGHTING);
				glScalef(6.0, 50.0, 6.0); //normal situation
				hey.miprisma(stone.GLindex, 4);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo PUERTA
					glTranslatef(0.0, 9.0, 9.0);
					glRotatef(movHombro, 1.0, 0.0, 0.0);
					glTranslatef(0.0, -3.0, 0.0);
					glDisable(GL_LIGHTING);
					glScalef(6.0, 10.0, 1.0); //normal situation
					hey.miprisma(port.GLindex, 1);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo PUERTA atrás
					glTranslatef(0.0, 5.0, -15.5);
					//glDisable(GL_LIGHTING);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					glScalef(8.0, 11.0, 0.1); //normal situation
					hey.miprisma(fant1.GLindex, 1);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glDisable(GL_ALPHA_TEST);
					//glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 1
					glTranslatef(18.5, 0.0, 10.0);
					glDisable(GL_LIGHTING);
					//glScalef(15.0, 30.0, 30.0); //normal situation
					hey.cilindro(4.0, 35.0, 40.0, stone.GLindex);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 1 comp
					glTranslatef(18.5, 35.0, 10.0);
					glDisable(GL_LIGHTING);
					//glScalef(15.0, 30.0, 30.0); //normal situation
					hey.cono(10.0, 4.0, 20, stone.GLindex);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix(); //castillo torre 2
					glTranslatef(-18.5, 0.0, 10.0);
					glDisable(GL_LIGHTING);
					//glScalef(15.0, 30.0, 30.0); //normal situation
					hey.cilindro(4.0, 35.0, 40.0, stone.GLindex);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 2 comp
				glTranslatef(-18.5, 35.0, 10.0);
				glDisable(GL_LIGHTING);
				//glScalef(15.0, 30.0, 30.0); //normal situation
				hey.cono(10.0, 4.0, 20, stone.GLindex);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 3
				glTranslatef(18.5, 0.0, -10.0);
				glDisable(GL_LIGHTING);
				//glScalef(15.0, 30.0, 30.0); //normal situation
				hey.cilindro(4.0, 35.0, 40.0, stone.GLindex);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 3 comp
				glTranslatef(18.5, 35.0, -10.0);
				glDisable(GL_LIGHTING);
				//glScalef(15.0, 30.0, 30.0); //normal situation
				hey.cono(10.0, 4.0, 20, stone.GLindex);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 4
				glTranslatef(-18.5, 0.0, -10.0);
				glDisable(GL_LIGHTING);
				//glScalef(15.0, 30.0, 30.0); //normal situation
				hey.cilindro(4.0, 35.0, 40.0, stone.GLindex);
				//hey.castillo(30.0,15.0,30.0,stone.GLindex);
				glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix(); //castillo torre 4 comp
					glTranslatef(-18.5, 35.0, -10.0);
					glDisable(GL_LIGHTING);
					//glScalef(15.0, 30.0, 30.0); //normal situation
					hey.cono(10.0, 4.0, 20, stone.GLindex);
					//hey.castillo(30.0,15.0,30.0,stone.GLindex);
					glEnable(GL_LIGHTING);
				glPopMatrix();



				glPushMatrix(); //hombre dep
					glTranslatef(11.0, 4.8, -18.0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					//glScalef(2.0, 4.0, 0);
					glRotatef(movDesp, 0.0, 1.0, 0.0);
					hey.cilindro(1.5,5.0,20,troom1.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();

				glPushMatrix(); //bolsa
					glTranslatef(6.0, 4.8, -19.0);
					glEnable(GL_ALPHA_TEST);
					glAlphaFunc(GL_GREATER, 0.1);
					//glScalef(2.0, 4.0, 0);
					glRotatef(movBolsa, 0.0, 1.0, 0.0);
					hey.cilindro(1.5, 5.0, 20, troom4.GLindex);
					glDisable(GL_ALPHA_TEST);
				glPopMatrix();

				glPushMatrix(); //rueda
					glTranslatef(10.0, 4.8, -20.5);
					glRotatef(90,0.0,1.0,0.0);
					//glEnable(GL_ALPHA_TEST);
					//glAlphaFunc(GL_GREATER, 0.1);
					glBindTexture(GL_TEXTURE_2D, text2.GLindex);
					//glScalef(2.0, 4.0, 0);
					glRotatef(movBolsa, 1.0, 0.0, 0.0);
					glRotatef(90, 0.0,0.0,1.0);
					hey.torus(5.0, 4.5, 20, 20);
					glRotatef(90, 0.0,0.0,1.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					glRotatef(180, 0.0, 0.0, 1.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					glRotatef(60, 1.0, 0.0, 0.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					glRotatef(-180, 0.0, 0.0, 0.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					glRotatef(45, 1.0, 0.0, 0.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					glRotatef(180, 0.0, 0.0, 1.0);
					hey.cilindro(0.3, 4.4, 20, text2.GLindex);
					//glDisable(GL_ALPHA_TEST);
				glPopMatrix();

				glPushMatrix();//pared fondo 
					glTranslatef(10.0, 4.8, -20.8);
					glDisable(GL_LIGHTING);
					glScalef(13.0,12.0,0.1);
					hey.miprisma(troom3.GLindex, 1);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(16.7, 2.0, -5.0);
					glScalef(6.3, 5.0, 0.1);
					glDisable(GL_LIGHTING);
					glRotatef(90,1.0,0.0,0.0);
					hey.miprisma(troom6.GLindex, 2);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(16.7, 7.0, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(6.3, 5.0, 0.1);
					glRotatef(90, 1.0, 0.0, 0.0);
					hey.miprisma(troom6.GLindex, 1);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(4.2, 4.9, -6.8);
					glDisable(GL_LIGHTING);
					glScalef(0.01, 10.5, 27.5);
					hey.miprisma(troom6.GLindex, 6);
					glEnable(GL_LIGHTING);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(16.7, 14.5, -5.0);
					glDisable(GL_LIGHTING);
					glScalef(6.3, 10.0, 0.1);
					glRotatef(90, 1.0, 0.0, 0.0);
					hey.miprisma(troom6.GLindex, 2);
					glEnable(GL_LIGHTING);
				glPopMatrix();


				glPushMatrix();
				glTranslatef(13.5, 5.3, -10.0);
				glDisable(GL_LIGHTING);
				glScalef(0.01, 11.5, 10.0);
				hey.miprisma(troom6.GLindex, 6);
				glEnable(GL_LIGHTING);
				glPopMatrix();

			glPopMatrix();


			




		glPopMatrix(); 

	glPopMatrix();

	glutSwapBuffers ( );

}

void animacion()
{
	
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime() obtiene los frames per sec
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 50) {
		movDesp = (movDesp + 1);
		movBolsa = (movBolsa - 2);
		movHombro = (movHombro + 1);
		if (movHombro > 100) {
				movHombro = (movHombro - 0.1);
				dwLastUpdateTime = dwCurrentTime;
		}
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 270.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {

		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.1 );
			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.1));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'r':
			if (movHombro < 60.0)
				movHombro -= 0.2f;
			break;

		case 'R':
			if (movHombro < 60.0)
				movHombro += 0.2f;
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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
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
  glutInitWindowSize  (2000, 2000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Jerarquia"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );


  glutMainLoop        ( );          // 

  return 0;
}
