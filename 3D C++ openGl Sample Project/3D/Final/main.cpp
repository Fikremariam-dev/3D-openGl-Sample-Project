#include <GL\glut.h>
#include "tibebes.h"
#include <iostream>



using namespace std;
using namespace tibebes;

pattern1 p1;
pattern2 p2;
pattern3 p3;
pattern4 p4;

int pattern = 1;
int autoRotate =1;

void initialize(void)
{

    glClearColor(0,0,0,0);
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING); //Enable lighting
	glEnable(GL_LIGHT0); //Enable light #0
}

void transformation(int val)
{
    if(autoRotate==1)
    {
        xAxisRotation += 0.2;
        glutTimerFunc(25,transformation,0);
        glutPostRedisplay();

    }

}

void writeText(char *string, float x, float y)
{
	char *c;
	glRasterPos3f(x, y,0);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void handleMouse(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON)
	{
		if ((360 <= x && x <= 477) && (y <= 638 && y >= 585))
			pattern = 1;
		else if ((511 <= x && x <= 629) && (y <= 638 && y >= 585))
			pattern = 2;
		else if ((661 <= x && x <= 780) && (y <= 638 && y >= 585))
			pattern = 3;
		else if ((812 <= x && x <= 930) && (y <= 638 && y >= 585))
			pattern = 4;
		else if ((963 <= x && x <= 1079) && (y <= 638 && y >= 585))
			pattern = 5;
		else if ((419 <= x && x <= 496) && (y <= 61 && y >= 8))
		{
			r = 0; g = 0; b = 255;
		}
		else if ((510 <= x && x <= 587) && (y <= 61 && y >= 8))
		{
			r = 170; g = 85; b = 0;
		}
		else if ((601 <= x && x <= 677) && (y <= 61 && y >= 8))
		{
			r = 1; g = 255; b = 0;
		}
		else if ((690 <= x && x <= 768) && (y <= 61 && y >= 8))

		{
			r = 232; g = 232; b = 67;
		}
		else if ((781 <= x && x <= 858) && (y <= 61 && y >= 8))
		{
			r =255; g = 0; b = 0;
		}
		else if ((872 <= x && x <= 950) && (y <= 61 && y >= 8))
		{
			r = 170; g = 85; b = 255;
		}
		else if ((962 <= x && x <= 1039) && (y <= 61 && y >= 8))
		{
			r = 255; g = 170; b = 127;
		}
		glutPostRedisplay();
	}
}

void specialInput(int key,int x,int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        xAxisRotation += 0.5;
        break;
    case GLUT_KEY_DOWN:
        xAxisRotation -= 0.5;
        break;
    case GLUT_KEY_LEFT:
        yAxisRotation -= 0.5;
        break;
    case GLUT_KEY_RIGHT:
        yAxisRotation += 0.5;

    }
    glutPostRedisplay();
}

void pressedKey(unsigned char key, int x, int y) {
	if (key == 's')
	{
        lightz -= 0.05;
	}
	if (key == 'w') {

        lightz += 0.05;
	}
	if(key == 'p')
    {
        if(autoRotate == 0){
                autoRotate =1;
            glutTimerFunc(25,transformation,0);
            return;
        }

        else
            autoRotate = 0;
    }
	glutPostRedisplay();
}



void color()
{
    int aj = 255;

	float x = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i == 1) glColor3ub(170,85,0);
		if (i == 2) glColor3ub(0,255,0);
		if (i == 3) glColor3ub(232, 232, 67);
		if (i == 4) glColor3ub(255,0,0);
		if (i == 5) glColor3ub(170,85,255);
		if (i == 6) glColor3ub(255,170,127);
		glBegin(GL_QUADS);
		glVertex3f(-0.3+x, 0.98,0);
		glVertex3f(-0.3+x, 0.815,0);
		glVertex3f(-0.17+x, 0.815,0);
		glVertex3f(-0.17+x, 0.98,0);
		glEnd();
		x = x + 0.15;
	}
}


void MyInterface(void)
{
     glMatrixMode(GL_MODELVIEW);
    // clear the drawing buffer.
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0,0.0,-2);
//-------------------------------------Interface------------------------------------------------
    glScalef(1.35,0.725,1);
    glColor3ub(69, 78, 202);
    writeText("colors", -0.4, 0.9);
    glColor3ub(0, 138, 0);
	writeText("5th", 0.65, -0.87);
	writeText("Tibebe", 0.65, -0.94);

	writeText("4th", 0.4, -0.87);
	writeText("Tibebe", 0.4, -0.94);

	writeText("3rd", 0.15, -0.87);
	writeText("Tibebe", 0.15, -0.94);

	writeText("Hemen", -0.1, -0.87);
	writeText("Tibebe", -0.1, -0.94);

	writeText("1st", -0.35, -0.87);
	writeText("Tibebe", -0.35, -0.94);
    		//pattern List

    writeText("Tibebes", -0.5, -0.75);


    color();

    writeText("Description", -0.9, 0.9);
    glColor3ub(0,0,255);
    glLineWidth(1);
    glBegin(GL_LINES);
    glVertex3f(-1.0,0.87,0);
    glVertex3f(-0.505,0.87,0);

    glVertex3f(-0.505,0.87,0);
    glVertex3f(-0.505,-1.0,0);

    glEnd();

    if (pattern == 1)
    {

        writeText("Tibeb", -0.95, 0.8 );
        glColor3f(0,0,0);

        writeText("At the top and bottom of the", -0.995, 0.63 );
        writeText("pattern there are three consecutive ", -0.995, 0.56 );
        writeText("triangle shapes which have diamond", -0.995, 0.49 );
        writeText("shapes inside them.", -0.995, 0.42 );
        writeText("at the centre of the pattern there", -0.995, 0.35 );
        writeText("are 3 diamond shapes which have", -0.995, 0.28 );
        writeText("smaller diamonds on top of them", -0.995, 0.21 );


    }



    	if (pattern == 2)
    {

        writeText("Hemen Tibeb", -0.95, 0.8 );
        glColor3f(0,0,0);
        writeText("Handwoven by traditional weavers.", -0.995, 0.70 );
        writeText("At the centre of the pattern there", -0.995, 0.63 );
        writeText("is a diamond shape which is open ", -0.995, 0.56 );
        writeText("at the top and bottom vertex and", -0.995, 0.49 );
        writeText("branches out to make two adjacent ", -0.995, 0.42 );
        writeText("lines. In the centre diamond Shape", -0.995, 0.35 );
        writeText("there are 4 diamonds inside one", -0.995, 0.28 );
        writeText("another. There are two diamond ", -0.995, 0.21 );
        writeText("stacked vertically which meet at ", -0.995, 0.14 );
        writeText("the vertex from the left and right ", -0.995, 0.07 );
        writeText("of the centre diamond. They have ", -0.995, 0.0 );
        writeText("little square patterns inside of them.", -0.995, -0.07 );


    }
        if (pattern == 3)
        {
             glColor3f(0,0,0);
        writeText("There are six consecutive ", -0.995, 0.63 );
        writeText("rhombuses diagonally and they are", -0.995, 0.56 );
        writeText("repeated downwards by altering the ",-0.995, 0.49 );
        writeText("Xaxis to the left and right as they", -0.995, 0.42 );
        writeText("progress downwards. each polygon", -0.995, 0.35 );
        writeText("has an inner square polygon and ", -0.995, 0.28 );
        writeText("an X shaped sign over the inner ", -0.995, 0.21 );
        writeText("polygon ", -0.995, 0.14 );
        }

        	if (pattern == 4)
    {

        writeText("Tibeb", -0.95, 0.8 );
        glColor3f(0,0,0);
        writeText("", -0.995, 0.70 );
        writeText("There are there consecutive ", -0.995, 0.63 );
        writeText("Rhombuses and they have two ", -0.995, 0.56 );
        writeText("polygons one in the other and ", -0.995, 0.49 );
        writeText("inside them there is a rhombus.", -0.995, 0.42 );
        writeText("This rhombus contains cross over it.", -0.995, 0.35 );

    }


	glColor3f(0, 255, 0);
	float x = 0;
	for (int i = 0; i < 5; i++)
	{
		glBegin(GL_QUADS);
		glVertex3f(-0.40+ x, -0.97, 0);
		glVertex3f(-0.40+ x, -0.8 ,0);
		glVertex3f(-0.20+ x, -0.8 ,0);
		glVertex3f(-0.20+ x, -0.97 ,0);
		glEnd();
		x = x + 0.25;
	}

    	glColor3f(1.9, 1.9, 1.9);



//top and left
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, 1.0f,0);glVertex3f(1.0f, 1.0f,0);
	glVertex3f(1.0f, 0.8f,0);glVertex3f(-0.5f, 0.8f,0);
	glVertex3f(-0.5f, -0.6f,0);glVertex3f(-1.0f, -0.6f,0);
	glEnd();

//bottom
    glBegin(GL_POLYGON);
    glVertex3f(-1.0f, -0.6f,0);glVertex3f(1.0f, -0.6f,0);
    glVertex3f(1.0f, -1.0f,0);glVertex3f(-1.0f, -1.0f,0);

	glEnd();
//right
    glBegin(GL_POLYGON);
    glVertex3f(1.0f, 0.8f,0);glVertex3f(0.95f, 0.8f,0);
	glVertex3f(0.95f, -0.6f,0);glVertex3f(1.0f, -0.6f,0);
    glEnd();




    glLoadIdentity();


    glScalef(1,1,1);
    glTranslatef(0.0,0.0,-8.5);
    glRotatef(xAxisRotation,1.0,0.0,0.0);
    glRotatef(yAxisRotation,0.0,1.0,0.0);
    glRotatef(zAxisRotation,0.0,0.0,1.0);


	//Ambient light
	GLfloat AColor[] = {0.7f, 0.7f, 0.7f, 1.0f}; //Colour and intensity of background light
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AColor);

	//Positioned light
	GLfloat L0Colour[] = {1.0f, 1.0f, 1.0f, 1.0f}; //Colour and intensity of positioned light
	GLfloat L0Position[] = {lightx, lighty, lightz, 1.0f};//position of the light
	glLightfv(GL_LIGHT0, GL_DIFFUSE, L0Colour);
	glLightfv(GL_LIGHT0, GL_POSITION, L0Position);



	if (pattern == 1)
    {
       // writeText("Hemen Tibeb Handwoven by traditional weavers", -0.9, 0.8 );

        p1.patt1();
    }

	else if (pattern == 2)
    {
        glLineWidth(5);
        p2.patt2();
    }
	else if (pattern == 3)
		p3.patt3();
    else if (pattern == 4)
    {
        lightx =0;lighty=0;lightz = 0;
        p4.patt4();
    }


    glutSwapBuffers();
}


void ResizeWindow(int x, int y)
{
    if (y == 0 || x == 0) return;  //Nothing is visible then, Hence return
    glMatrixMode(GL_PROJECTION);    //Set a new projection matrix
    glLoadIdentity();
    //Angle of view:40 degrees
    //Near clipping plane distance: 0.5
    //Far clipping plane distance: 20.0

    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
    glutReshapeWindow(1200,650);
}


int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(1150, 650);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    initialize();
    glutDisplayFunc(MyInterface);
    glutReshapeFunc(ResizeWindow);
    glutTimerFunc(25,transformation,0);
    glutSpecialFunc(specialInput);
    glutKeyboardFunc(pressedKey);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}





