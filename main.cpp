#include<windows.h>
#include <GL/glut.h>
#include <math.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);	// Set display window colour to white

	glMatrixMode(GL_PROJECTION);		// Set projection parameters
	gluOrtho2D(0.0, 700.0, 0.0, 700.0);
}

void display()
{
    float theta;
    int i;
	glClear(GL_COLOR_BUFFER_BIT);	// Clear display window
    //Set colour to red
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
	  theta=i*3.142/180;
	  glVertex2f(250+150*cos(theta),250+150*sin(theta));
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
	  theta=i*3.142/180;
	  glVertex2f(300+150*cos(theta),300+150*sin(theta));
	}
	glEnd();

glFlush();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);				// Initalise GLUT
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);	// Set display mode

	glutInitWindowPosition(100, 100);		// Set window position
	glutInitWindowSize(700, 700);			// Set window size
	glutCreateWindow("Half Moon");	// Create display window

	init();					// Execute initialisation procedure
	glutDisplayFunc(display);		// Send graphics to display window
	glutMainLoop();				// Display everything and wait

	return 0;
}

