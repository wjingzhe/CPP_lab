/*
When creating your project, uncheck OWL,
uncheck Class Library, select Static
instead of Dynamic and change the target
model to Console from GUI.
Also link glut.lib to your project once its done.
*/

#include <windows.h>
#include <gl/gl.h>     // The GL Header File
#include <gl/glut.h>   // The GL Utility Toolkit (Glut) Header

float	rtri;						// Angle For The Triangle
float	rquad;						// Angle For The Quad


void init ( GLvoid )     // Create Some Everyday Functions
{

   glShadeModel(GL_SMOOTH);						// Enable Smooth Shading
   glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
   glClearDepth(1.0f);				 			// Depth Buffer Setup
   glEnable(GL_DEPTH_TEST);						// Enables Depth Testing
   glDepthFunc(GL_LEQUAL);				 		// The Type Of Depth Testing To Do
   glEnable ( GL_COLOR_MATERIAL );
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display ( void )   // Create The Display Function
{
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
   glLoadIdentity();				       		// Reset The Current Modelview Matrix
   glPushMatrix();
   glTranslatef(-1.5f,0.0f,-6.0f);			      	// Move Left 1.5 Units And Into The Screen 6.0
   glRotatef(rtri,0.0f,1.0f,0.0f);				// Rotate The Triangle On The Y axis
	glBegin(GL_TRIANGLES);				      	// Drawing Using Triangles
		glColor3f(1.0f,0.0f,0.0f);		      	// Set The Color To Red
		glVertex3f( 0.0f, 1.0f, 0.0f);		      	// Top
		glColor3f(0.0f,1.0f,0.0f);		      	// Set The Color To Green
		glVertex3f(-1.0f,-1.0f, 0.0f);		      	// Bottom Left
		glColor3f(0.0f,0.0f,1.0f);		       	// Set The Color To Blue
		glVertex3f( 1.0f,-1.0f, 0.0f);		      	// Bottom Right
	glEnd();						// Finished Drawing The Triangle
    glPopMatrix();  //在此恢复矩阵，这样才不会影响正方形的旋转


    //glLoadIdentity();					// Reset The Current Modelview Matrix
    //平移与平移，旋转与旋转之间是会相互影响的!!!
    glTranslatef(1.5f,0.0f,-6.0f);				// Move Right 1.5 Units And Into The Screen 6.0
	glRotatef(rquad,0.0f,1.0f,0.0f);			// Rotate The Quad On The X axis
	glColor3f(0.5f,0.5f,1.0f);		    		// Set The Color To Blue One Time Only
	glBegin(GL_QUADS);				   	// Draw A Quad
		glVertex3f(-1.0f, 1.0f, 0.0f);					// Top Left
		glVertex3f( 1.0f, 1.0f, 0.0f);					// Top Right
		glVertex3f( 1.0f,-1.0f, 0.0f);					// Bottom Right
		glVertex3f(-1.0f,-1.0f, 0.0f);					// Bottom Left
	glEnd();								// Done Drawing The Quad
    //glPopMatrix();
  
   rtri+=0.2f;						// Increase The Rotation Variable For The Triangle ( NEW )
	rquad-=0.15f;				       	// Decrease The Rotation Variable For The Quad     ( NEW )
    //printf("\n%f:",rtri);

    glutSwapBuffers ( );
  // Swap The Buffers To Not Be Left With A Clear Screen
}

void reshape ( int w, int h )   // Create The Reshape Function (the viewport)
{
  glViewport( 0, 0, w, h );
  glMatrixMode(GL_PROJECTION);  // Select The Projection Matrix
  glLoadIdentity( );                // Reset The Projection Matrix
  if ( h==0 )  // Calculate The Aspect Ratio Of The Window
     gluPerspective( 80, ( float ) w, 1.0, 5000.0 );
  else
     gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );
  glMatrixMode( GL_MODELVIEW );  // Select The Model View Matrix
  glLoadIdentity ( );    // Reset The Model View Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
  switch ( key ) {
    case 27:        // When Escape Is Pressed...
      exit ( 0 );   // Exit The Program
      break;        // Ready For Next Case
    default:        // Now Wrap It Up
      break;
  }
}

void arrow_keys (int a_keys, int x, int y )  // Create Special Function (required for arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
      glutFullScreen( ); // Go Into Full Screen Mode
      break;
    case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
      glutReshapeWindow( 500, 500 ); // Go Into A 500 By 500 Window
      break;
    default:
      break;
  }
}

int main ( int argc, char** argv )   // Create Main Function For Bringing It All Together
{
  glutInit( &argc, argv ); // Erm Just Write It =)
  init();
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE ); // Display Mode
  glutInitWindowSize( 500, 500 ); // If glutFullScreen wasn't called this is the window size
  glutCreateWindow( "NeHe's OpenGL Framework" ); // Window Title (argv[0] for current directory as title)
  glutFullScreen( );          // Put Into Full Screen
  glutDisplayFunc( display );  // Matching Earlier Functions To Their Counterparts
  glutReshapeFunc( reshape );
  glutKeyboardFunc( keyboard );
  glutSpecialFunc ( arrow_keys );
  glutIdleFunc( display );
  glutMainLoop( );          // Initialize The Main Loop
}

