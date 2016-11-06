// Include section
#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <string>
#include <math.h>
// Need Math Defines before cmath to use Math constants
#define _USE_MATH_DEFINES
#include <cmath>

static int radius = 30;

// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei winWidth = 800, winHeight = 600;

// Initialize method
void init(void)
{
	// Get and display your OpenGL version
	const GLubyte *Vstr;
	Vstr = glGetString(GL_VERSION);
	fprintf(stderr, "Your OpenGL version is %s\n", Vstr);

	// White color window
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Projection on World Coordinates
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, -(GLdouble)winHeight / 2, (GLdouble)winHeight / 2);
}
void otherCode()
{
	// Your other code here
}
// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);

	// Set graphic objects color to Red or change for your choice
	glColor3f(1.0, 0.0, 0.0);
	//Generate 24x24 bitmap unique image
	GLubyte bitShape2[72] = {
    0xff, 0xff, 0xff,
    0x03, 0x00, 0xc0,
    0xa5, 0x5a, 0xa5,
    0x89, 0x5a, 0x91,
    0x91, 0x5a, 0x89,
    0x25, 0x5a, 0xa4,
    0x45, 0x5a, 0xa2,
    0x95, 0x00, 0xa9,
    0x15, 0xff, 0xa8,
    0x55, 0xa5, 0xaa,
    0x55, 0xe7, 0xaa,
    0x55, 0x99, 0xaa,
    0x55, 0xdb, 0xaa,
    0x55, 0xc3, 0xaa,
    0x55, 0xbd, 0xa8,
    0x15, 0xff, 0xa8,
    0x95, 0x00, 0xa1,
    0x45, 0x5a, 0xa2,
    0x25, 0x5a, 0xa4,
    0x91, 0x5a, 0x89,
    0x89, 0x5a, 0x91,
    0xa5, 0x5a, 0xa5,
    0x03, 0x00, 0xc0,
    0xff, 0xff, 0xff
  };

	// Needed for reading from memory. 1 indicates byte alignment
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	// Center the bitmap image
	glRasterPos2i(-200, 200);
	// Display the image of size 24x24
	// x and y offsets of 24, 12.
	glBitmap(24.0, 24.0, 0.0, 0.0, 24.0, 12.0, bitShape2);

  // Create black rectangles

  // Define to Arrays to hold vertex points
  int blackRectA1[] = { -400, -300 };
  int blackRectA2[] = { -300, 100 };
  int blackRectB1[] = { -270, -300 };
  int blackRectB2[] = { -240, -160 };
  int blackRectC1[] = { -240, -100 };
  int blackRectC2[] = { -50, -50 };
  int blackRectD1[] = { 160, -280 };
  int blackRectD2[] = { 250, 280 };

  // Change color to black
  glColor3f(0.0, 0.0, 0.0);

  // Draw rectangles
  glRectiv(blackRectA1, blackRectA2);
  glRectiv(blackRectB1, blackRectB2);
  glRectiv(blackRectC1, blackRectC2);
  glRectiv(blackRectD1, blackRectD2);

	glPushMatrix();
	//Set Drawing Color - Will Remain this color until otherwise specified
	glColor3f(0.2, 0.3, 0.5);  //Some type of blue
	//Draw Circle
	glBegin(GL_POLYGON);
	  for(double i = 0; i < 2 * M_PI; i += M_PI / 12)
			glVertex3f(-270 + cos(i) * radius, -130 + sin(i) * radius, 0.0);
	glEnd();
	//Draw Circle
  glPopMatrix();


  std::string s = "Modern Art Designed by Eric Sabelhaus";

  glColor3d(1.0, 0.0, 0.0);
  glRasterPos2d(-240, -165);
  for (std::string::iterator i = s.begin(); i != s.end(); ++i) {
    char c = *i;
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
  }

  GLuint regHex;
  GLdouble theta;
  GLint x, y, k;

  // Sets up a hexagon starting at 10,10 with a size of "60"
  regHex = glGenLists(1);  //  Get an identifier for the display list.
  glNewList(regHex, GL_COMPILE);
  glBegin(GL_POLYGON);
  for (k = 0; k < 6; k++) {
    // M_PI is C++ Constant for PI
    theta = 2*M_PI * k / 6.0;
    x = 10 + 60 * cos(theta);
    y = 10 + 60 * sin(theta);
    glVertex2i(x, y);
  }
  glEnd();
  glEndList();

  // Must call this to display the Hex graphic
  glCallList(regHex);

  glRasterPos2d(-300, -74);

  GLubyte bitShape1[72] = {
    0xff, 0xff, 0xff,
    0x03, 0x00, 0xc0,
    0xa5, 0x5a, 0xa5,
    0x89, 0x5a, 0x91,
    0x91, 0x5a, 0x89,
    0x25, 0x5a, 0xa4,
    0x45, 0x5a, 0xa2,
    0x95, 0x00, 0xa9,
    0x15, 0xff, 0xa8,
    0x55, 0xa5, 0xaa,
    0x55, 0xe7, 0xaa,
    0x55, 0x99, 0xaa,
    0x55, 0xdb, 0xaa,
    0x55, 0xc3, 0xaa,
    0x55, 0xbd, 0xa8,
    0x15, 0xff, 0xa8,
    0x95, 0x00, 0xa1,
    0x45, 0x5a, 0xa2,
    0x25, 0x5a, 0xa4,
    0x91, 0x5a, 0x89,
    0x89, 0x5a, 0x91,
    0xa5, 0x5a, 0xa5,
    0x03, 0x00, 0xc0,
    0xff, 0xff, 0xff
  };

  glBitmap(24.0, 24.0, 0.0, 0.0, 24.0, 12.0, bitShape1);

  // Create blue rectangle

  glColor3d(0.251, 0.878, 0.816);

  int blueRectA1[] = { -300, -50 };
  int blueRectA2[] = { -180, 160 };

  glRectiv(blueRectA1, blueRectA2);

	// Execute OpenGL functions
	glFlush();
}

// Windows redraw function
void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(GLdouble)winWidth / 2, (GLdouble)winWidth / 2, -(GLdouble)winHeight / 2, (GLdouble)winHeight / 2);
	glClear(GL_COLOR_BUFFER_BIT);
}
// Main function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Set initial Window position
	glutInitWindowPosition(100, 100);
	// Set Window Size
	glutInitWindowSize(winWidth, winHeight);
	// Set Window Title
	glutCreateWindow("Eric Sabelhaus – Homework 2");
	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
  return 0;
}
