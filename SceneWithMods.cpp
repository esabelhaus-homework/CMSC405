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
#include <cmath>
#include <iostream>

// Need Math Defines before cmath to use Math constants
#define _USE_MATH_DEFINES

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// used for cin and cout
using namespace std;

static int radius = 30;

static float triangleTranslate = 27.9f;
static float hexy = .5f;
static float age = 27.9f;
static int rando = 100;


// Global Variable Section
// List all of your global variables, stuctures and other definition here
// Window display size
GLsizei winWidth = 800, winHeight = 600;

class Pt2D {
public:
	GLfloat x, y;
};

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


void translatePolygon(Pt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty)
{
	GLint k;
	// translate each vertex
	for (k = 0; k < nVerts; k++) {
		verts[k].x = verts[k].x + tx;
		verts[k].y = verts[k].y + ty;
	}
}

// Generate the Graphics
void displayFcn(void)
{
	// Clear display window.
	glClear(GL_COLOR_BUFFER_BIT);

	// Set graphic objects color to Red or change for your choice
	glColor3f(1.0, 0.0, 0.0);
	//Generate 24x24 bitmap unique image
	// unique image is of a turtle on a pyramid
	GLubyte bitShape[72] = {
	0xff, 0xff, 0xff, 0x03, 0x00, 0xc0, 0xa5, 0x5a, 0xa5, 0x89, 0x5a, 0x91,
	0x91, 0x5a, 0x89, 0x25, 0x5a, 0xa4, 0x45, 0x5a, 0xa2, 0x95, 0x00, 0xa9,
	0x15, 0xff, 0xa8, 0x55, 0xa5, 0xaa, 0x55, 0xe7, 0xaa, 0x55, 0x99, 0xaa,
	0x55, 0xdb, 0xaa, 0x55, 0xc3, 0xaa, 0x55, 0xbd, 0xa8, 0x15, 0xff, 0xa8,
	0x95, 0x00, 0xa1, 0x45, 0x5a, 0xa2, 0x25, 0x5a, 0xa4, 0x91, 0x5a, 0x89,
	0x89, 0x5a, 0x91, 0xa5, 0x5a, 0xa5, 0x03, 0x00, 0xc0, 0xff, 0xff, 0xff
	};

	// Needed for reading from memory. 1 indicates byte alignment
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// set position of raster within the coordinate plane
	glRasterPos2i(-200, 200);
	// Display the image of size 24x24
	// x and y offsets of 24, 12.
	glBitmap(24.0, 24.0, 0.0, 0.0, 24.0, 12.0, bitShape);

	// Draw lines
	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	  glVertex2i(100, 100);
	  glVertex2i(-100, -100);
	glEnd();

	glLineWidth(2.5);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	  glVertex2i(100, -100);
	  glVertex2i(-100, 100);
	glEnd();

	// Create black rectangles

	// arrays to hold vertex points of rectangles
	int blackRectA1[] = { -400, -300 };
	int blackRectA2[] = { -300, 100 };
	int blackRectB1[] = { -270, -300 };
	int blackRectB2[] = { -240, -160 };
	int blackRectC1[] = { -240, -100 };
	int blackRectC2[] = { -50, -50 };
	int blackRectD1[] = { 160, -280 };
	int blackRectD2[] = { 250, 280 };

	// change color to black
	glColor3f(0.0, 0.0, 0.0);

	// draw rectangles
	glRectiv(blackRectA1, blackRectA2);
	glRectiv(blackRectB1, blackRectB2);
	glRectiv(blackRectC1, blackRectC2);
	glRectiv(blackRectD1, blackRectD2);


	//set color to steel blue
	glColor3f(0.275, 0.510, 0.706);

	// draw circle
	glPushMatrix();
	glBegin(GL_POLYGON);
	  for (double i = 0; i < 2 * M_PI; i += M_PI / 12)
		  glVertex3f(-270 + cos(i) * radius, -130 + sin(i) * radius, 0.0);
	glEnd();
	glPopMatrix();


	// add text to scene
	std::string s = "Modern Art Designed by Eric Sabelhaus";
	// set color to red
	glColor3d(1.0, 0.0, 0.0);
	// set position of raster within the coordinate plane
	glRasterPos2i(-240, -165);
	for (std::string::iterator i = s.begin(); i != s.end(); ++i) {
		char c = *i;
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
	}

	// create instance variables for hexagon
	GLuint regHex;
	GLdouble theta;
	GLint x, y, k;

	// Sets up a hexagon starting at 300,-200 with a size of "60"
	regHex = glGenLists(1);  //  Get an identifier for the display list.
	glNewList(regHex, GL_COMPILE);
	glBegin(GL_POLYGON);
	for (k = 0; k < 6; k++) {
		// M_PI is C++ Constant for PI
		theta = 2 * M_PI * k / 6.0;
		x = 340 + 60 * cos(theta);
		y = -200 + 60 * sin(theta);
		glVertex2i(x, y);
	}
	glEnd();
	glEndList();

	// Must call this to display the Hex graphic
	glCallList(regHex);

	// set position of raster within the coordinate plane
	glRasterPos2i(-300, -74);
	glBitmap(24.0, 24.0, 0.0, 0.0, 24.0, 12.0, bitShape);

	// Create blue rectangle

	glColor3d(0.251, 0.878, 0.816);

	int blueRectA1[] = { -300, -50 };
	int blueRectA2[] = { -180, 160 };

	glRectiv(blueRectA1, blueRectA2);


	//Draw fish
	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	  for (double i = 0; i < 2 * M_PI; i += M_PI / 12)
		  glVertex3f(-70 + cos(i) * radius, -260 + sin(i) * radius, 0.0);
	glEnd();
	glPopMatrix();

	glBegin(GL_POLYGON);
	  glColor3f(0.0, 1.0, 0.0);
	  glVertex2i(-70, -230);
	  glVertex2i(-70, -290);
	  glVertex2i(-200, -260);
	glEnd();

	glBegin(GL_POLYGON);
	  glColor3f(0.0, 1.0, 0.0);
	  glVertex2i(-230, -230);
	  glVertex2i(-230, -290);
	  glVertex2i(-180, -260);
  glEnd();

  // Draw objects before and after rotations
	glColor3f(1.0, 0.0, 0.0);
  glRecti(0, 0, 75, 150);

	glPushMatrix();
	glColor3f(0.275, 0.510, 0.706);
	glRotatef(age, 0.0f, 0.0f, 1.0f);
	glRecti(0, 0, 75, 150);
	glPopMatrix();


  // translating triangle
	glPushMatrix();
	// Create the struct values for holding x,y values
	Pt2D myverts[3];
	myverts[0].x = -270;
	myverts[0].y = -130;
	myverts[1].x = -270;
	myverts[1].y = -150;
	myverts[2].x = -230;
	myverts[2].y = -140;

	glTranslatef(-120.0, -120.0, 1.0);

	glBegin(GL_TRIANGLES);
		glColor3f(0.0, 1.0, 0.0);
		for (k = 0; k < 3; k++) {
			glVertex2i(myverts[k].x, myverts[k].y);
		}
	glEnd();

  glPopMatrix();


  // hexagon scaling
  glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	GLuint regHexScaling;
	// Sets up a hexagon starting at 300,-200 with a size of "60"
	regHexScaling = glGenLists(1);  //  Get an identifier for the display list.
	glNewList(regHexScaling, GL_COMPILE);
	glBegin(GL_POLYGON);
	for (k = 0; k < 6; k++) {
		// M_PI is C++ Constant for PI
		theta = 2 * M_PI * k / 6.0;
		x = 200 + 30 * cos(theta);
		y = -100 + 30 * sin(theta);
		glVertex2i(x, y);
	}
	glEnd();
	glEndList();

  // scale the hexagon between -1.7 and 1.7, default is .5
	glScalef(hexy, hexy, 1.0f);
	// Must call this to display the Hex graphic
  glCallList(regHexScaling);
  glPopMatrix();

	// perform transformations on at least four of the objects

	// At least one object must allow a rotation - Done

	// At least one object must allow scaling -

	// At least one must allow translation. -

	// At least one of the objects must allow a combination of transformations. -

	// You must constraint the user on the bounds of the transformations. set hard limits - do this last

	// Execute OpenGL functions
	glFlush();
}

void whatSizesToUse() {
  // accept the amount of translation for the bitmap from 1
	cout << "where do we translate the triangle to?" << endl;
	cout << "Enter a float: ";
	cin >> triangleTranslate;

  // accept an integer for scaling up the hexagon
	cout << "how big is the hexagon" << endl;
	cout << "Enter an float between -1.7 and 1.7: ";
	cin >> hexy;

  // accept a float for how much to rotate the rectangle
	cout << "how old are you?" << endl;
	cout << "Enter a float: ";
	cin >> age;
	cout << "Rotating " << age << " degrees" << endl;

  // accept an amont for coordinates
	cout << "pick a number" << endl;
	cout << "Enter an integer: ";
  cin >> rando;
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
	glutCreateWindow("Eric Sabelhaus - Homework 4");

  // determine input values
	//whatSizesToUse();

	// Initialize
	init();
	// Display function call
	glutDisplayFunc(displayFcn);
	// Window reshape call
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
	return 0;
}
