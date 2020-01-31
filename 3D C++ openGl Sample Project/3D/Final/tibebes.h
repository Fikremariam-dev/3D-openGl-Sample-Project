#include <GL/glut.h>
#include <windows.h>

		int r = 0; int g = 0; int b = 255; int sv = 4;
		float scalex = 0.50; float scaley = 0.65;
		float translatex = 140; float translatey = 110;
        GLfloat xAxisRotation, yAxisRotation, zAxisRotation;

float lightx=5;float lighty=0.0;float lightz=0;


namespace tibebes
{
	class pattern1
	{
        void drawDiamond(float x, float y, float width, float r, float g, float b,float z)
        {
			glBegin(GL_POLYGON);
			glColor3f(r, g, b);
			glVertex3f(x + (width / 2), y,z);
			glVertex3f(x, y + (width / 2),z);
			glVertex3f(x - (width / 2), y,z);
			glVertex3f(x, y - (width / 2),z);
			glEnd();
		}
		void drawUpper(float x, float y, float width, float r,float g,float b,float z)
		{
            glBegin(GL_POLYGON);
			glColor3f(r, g, b);
			glVertex3f(x + (width / 2), y,z);
			glVertex3f(x - (width / 2), y,z);
			glVertex3f(x, y - (width / 2),z);
			glEnd();
			//glutPostRedisplay();
		}
		void drawLower(float x, float y, float width, float r, float g, float b,float z)
		{
			glBegin(GL_POLYGON);
			glColor3f(r, g, b);
			glVertex3f(x + (width / 2), y,z);
			glVertex3f(x - (width / 2), y,z);
			glVertex3f(x, y + (width / 2),z);
			glEnd();
		}
		void drawRectangle(float z)
		{

			glBegin(GL_POLYGON);
            glVertex3f(-3.5, 0.7,z);
			glVertex3f(-3.5, -1.25,z);
			glVertex3f(3.5, -1.25,z);
			glVertex3f(3.5, 0.7,z);
			glEnd();
		}


    public: void patt1()
    {
        glScalef(0.7,0.7,0.7);
        glTranslatef(2,0,0);
        for(float a = -1;a>-3;a-=1)
        {
            for(float i=-2.45;i<3;i+= 2.0)
            {

            drawDiamond(i,-0.8,0.3,0.0,0.0,1.0,a+0.04);
            drawDiamond(i,-0.8,0.4,0.9,0.9,0.9,a+0.03);

            drawDiamond(i,-0.8,0.3,0.0,0.0,1.0,a-0.04);
            drawDiamond(i,-0.8,0.4,0.9,0.9,0.9,a-0.03);

            drawLower(i+0.5,-1.25,0.5,0.9,0.9,0.9,a+0.04);
            drawLower(i-0.5,-1.25,0.5,0.9,0.9,0.9,a+0.04);
            drawLower(i+0.5,-1.25,0.5,0.9,0.9,0.9,a-0.04);
            drawLower(i-0.5,-1.25,0.5,0.9,0.9,0.9,a-0.04);

            drawLower(i,-1.25,1.5,0.0,0.0,1.0,a+0.02);
            drawLower(i,-1.25,1.5,0.0,0.0,1.0,a-0.02);

            drawLower(i,-1.25,1.6,0.9,0.9,0.9,a+0.01);
            drawLower(i,-1.25,1.6,0.9,0.9,0.9,a-0.01);


            drawDiamond(i+1,-0.2,0.5,0.9,0.9,0.9,a+0.04);
            drawDiamond(i+1,-0.2,0.5,0.9,0.9,0.9,a-0.04);
            drawDiamond(i+1,-0.2,1.4,0.0,0.0,1.0,a+0.03);
            drawDiamond(i+1,-0.2,1.4,0.0,0.0,1.0,a-0.03);

            drawDiamond(i+1,-0.2,1.5,0.9,0.9,0.9,a+0.01);
            drawDiamond(i+1,-0.2,1.5,0.9,0.9,0.9,a-0.01);

            drawDiamond(i,0.2,0.3,0.0,0.0,1.0,a+0.04);
            drawDiamond(i,0.2,0.3,0.0,0.0,1.0,a-0.04);
            drawDiamond(i,0.2,0.4,0.9,0.9,0.9,a+0.03);
            drawDiamond(i,0.2,0.4,0.9,0.9,0.9,a-0.03);

            drawUpper(i+0.5,0.7,0.5,0.9,0.9,0.9,a+0.04);
            drawUpper(i-0.5,0.7,0.5,0.9,0.9,0.9,a+0.04);
            drawUpper(i+0.5,0.7,0.5,0.9,0.9,0.9,a-0.04);
            drawUpper(i-0.5,0.7,0.5,0.9,0.9,0.9,a-0.04);


            drawUpper(i,0.7,1.5,0.0,0.0,1.0,a+0.02);
            drawUpper(i,0.7,1.6,0.9,0.9,0.9,a+0.01);
            drawUpper(i,0.7,1.5,0.0,0.0,1.0,a-0.02);
            drawUpper(i,0.7,1.6,0.9,0.9,0.9,a-0.01);
        }
            glColor3ub(r,g,b);
            drawRectangle(a);
        }
            glBegin(GL_QUADS);

            glColor3f(0.1f, 0.5f, 0.5f);
        //right
            glVertex3f(3.5f, 0.7f, -1);
            glVertex3f(3.5f, 0.7f, -2);
            glVertex3f(3.5f, -1.25f, -2);
            glVertex3f(3.5,-1.25,-1);
        //left
            glVertex3f(-3.5f, 0.7f, -1);
            glVertex3f(-3.5f, 0.7f, -2);
            glVertex3f(-3.5f, -1.25f,-2);
            glVertex3f(-3.5f, -1.25f, -1);
        //top
            glVertex3f(-3.5f, 0.7f, -1);
            glVertex3f(-3.5f, 0.7,-2);
            glVertex3f(3.5f, 0.7, -2);
            glVertex3f(3.5f, 0.7f, -1);
        //bottom
            glVertex3f(-3.5f, -1.25f, -1);
            glVertex3f(-3.5f, -1.25,-2);
            glVertex3f(3.5f, -1.25, -2);
            glVertex3f(3.5f, -1.25f, -1);
            glEnd();

		}
	};
	class pattern2
	{

        void draw(float q,float w,float e,float r,float t,float u,float rr,float d)
        {
            glColor3ub(r,g,b);
            int ii = 0;
            while(ii<6)
            {
                glLineWidth(7.0f);
                glBegin(GL_LINES);

                glVertex3f(q,w,d);
                glVertex3f(e,r,d);

                glVertex3f(e,rr,d);
                glVertex3f(t,u,d);
                glEnd();

                q=q+0.09;w=w+0.058;e=e+0.09;r=r+0.058;rr=rr-0.058;t=t+0.09;u=u-0.058;
                ii++;
            }

        }
        void draw2(float x1 ,float y1 ,float y2,float sx, float sy,int x,float d)
        {
            int i=0;

            while(i<4)
            {
                if (x==0)
                    x1=x1-0.1;
                else
                    x1=x1+0.1;

                y1=y1-0.0643;y2=y2+0.0643;
                i++;
                glColor3ub(r,g,b);
                glBegin(GL_LINES);

                glVertex3f(sx,y1,d);
                glVertex3f(x1,sy,d);

                glVertex3f(x1,sy,d);
                glVertex3f(sx,y2,d);
                glEnd();

            }

        }
        public :void patt2()
        {

            glColor3ub(255,0,0);
            for(float a = -1;a>-2;a-=0.5)
            {
            glBegin(GL_LINES);
            float ix = 0.1; float ix1 = 0.4; float iyy = 0.52; float iy = 0.41;
                    for (int i = 0; i < 2; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {
                            glVertex3f(ix, iyy,a);
                            glVertex3f(0.25f, iy,a);
                            glVertex3f(0.25f, iy,a);
                            glVertex3f(ix1, iyy,a);
                            ix -= 0.15; ix1 += 0.15;
                            if (iy < 0)
                                iy += 0.09;
                            else
                                iy -= 0.09;
                        }
                        iyy = -0.63; iy = -0.55; ix = 0.1; ix1 = 0.4;
                    }
                    float jx = -0.5; float jy = 0.23; float jyy = 0.52; float jxx = -0.95;
                    //drawing corner lines
                    for (int j = 0; j < 4; j++)
                    {
                        for (int i = 0; i < 3; i++)
                        {
                            glVertex3f(jx, jyy,a);
                            glVertex3f(jxx, jy,a);//jy += 0.10;jx -= 0.15;
                            if (j == 0 || j == 1) jx -= 0.15; else jx += 0.15;
                            if (j == 0 || j == 2) jy += 0.10; else jy -= 0.10;
                        }
                        if (j == 0) jx = -0.5; else jx = 1.0;
                        if (j == 1) jxx = 1.45f;
                        if (j == 0 || j == 2) { jy = -0.35; jyy = -0.63; }
                        else { jy = 0.23; jyy = 0.52; }
                    }
                    glEnd();
                    glColor3ub(230, 230, 230);




        //drawing top and bottom straight lines

            glVertex3f(-1.0f, 0.5f, a);
            glVertex3f(1.5f, 0.55f, a);

            glVertex3f(-1.0f, -0.63f,a);
            glVertex3f(1.5f, -0.63f, a);

            glEnd();
            glColor3ub(0,255,0);
            }

            glBegin(GL_QUADS);

            glColor3f(0.1f, 0.5f, 0.5f);
        //right
            glVertex3f(1.5f, 0.55f, -1);
            glVertex3f(1.5f, 0.55f, -1.5);
            glVertex3f(1.5f, -0.63f, -1.5);
            glVertex3f(1.5,-0.63,-1);
        //left
            glVertex3f(-1.0f, 0.5f, -1);
            glVertex3f(-1.0f, 0.5f, -1.5);
            glVertex3f(-1.0f, -0.63f,-1.5);
            glVertex3f(-1.0f, -0.63f, -1);
        //top
            glVertex3f(-1.0f, 0.5f, -1);
            glVertex3f(-1.0f, 0.5,-1.5);
            glVertex3f(1.5f, 0.55, -1.5);
            glVertex3f(1.5f, 0.55f, -1);
        //bottom
            glVertex3f(-1.0f, -0.63f, -1);
            glVertex3f(-1.0f, -0.63,-1.5);
            glVertex3f(1.5f, -0.63, -1.5);
            glVertex3f(1.5f, -0.63f, -1);

            glVertex3f(-1.0f, 0.5f, -1.25);
            glVertex3f(1.5f, 0.55f, -1.25);
            glVertex3f(1.5f, -0.63f, -1.25);
            glVertex3f(-1.0f, -0.63f,-1.25);
            glEnd();

            glColor3ub(0,0,255);
            draw(-0.35,-0.06,-0.8,0.23, -0.35,0.52,0.23,-1);
            draw(0.85,-0.06,0.4,0.23,0.85,0.52,0.23,-1);
            draw(-0.35,-0.64,-0.8,-0.35, -0.35,-0.06,-0.35,-1);
            draw(0.85,-0.64,0.4,-0.35,0.85,-0.06,-0.35,-1);

            draw(-0.35,-0.06,-0.8,0.23, -0.35,0.52,0.23,-1.5);
            draw(0.85,-0.06,0.4,0.23,0.85,0.52,0.23,-1.5);
            draw(-0.35,-0.64,-0.8,-0.35, -0.35,-0.06,-0.35,-1.5);
            draw(0.85,-0.64,0.4,-0.35,0.85,-0.06,-0.35,-1.5);

            //drawing the centre diamond shaped polygon
            glColor3f(1.0f, 1.0f, 1.0f);//white
            glBegin(GL_QUADS);
            for(float i = -1;i>-2;i-=0.5)
            {
                glVertex3f(0.25f, 0.23f, i);
                glVertex3f(-0.2f, -0.06f, i);
                glVertex3f(0.25f, -0.35f, i);
                glVertex3f(0.7f, -0.06f, i);
            }
            glEnd();

        //drawing the inner polygons of the centre diamond shape
            float x = -0.1, y = -0.2857,yy = 0.1644;
            int i = 0;
            while(i < 4)
            {
                glColor3f(0.0f, 0.0f, 0.0f);//Black
                glLineWidth(5.0f);
                    //glPushMatrix();
                glBegin(GL_LINES);
                for(float i = -1;i>-2;i-=0.5)
                {

                    glVertex3f(x, -0.06f,i+0.01);
                    glVertex3f(0.25f, y,i+0.01);

                    glVertex3f(0.5-x, -0.06f,i+0.01);
                    glVertex3f(0.25f, yy, i+0.01);

                    glVertex3f(x, -0.06f,i+0.01);
                    glVertex3f(0.25f, yy,i+0.01);

                    glVertex3f(0.25f, y,i+0.01);
                    glVertex3f(0.5-x, -0.06f,i+0.01);


                    glVertex3f(x, -0.06f,i-0.01);
                    glVertex3f(0.25f, y,i-0.01);

                    glVertex3f(0.5-x, -0.06f,i-0.01);
                    glVertex3f(0.25f, yy, i-0.01);

                    glVertex3f(x, -0.06f,i-0.01);
                    glVertex3f(0.25f, yy,i-0.01);

                    glVertex3f(0.25f, y,i-0.01);
                    glVertex3f(0.5-x, -0.06f,i-0.01);
                }
                glEnd();
                x= x+0.1;
                y=y+0.0643;yy=yy-0.0643;
                i++;
            }

            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
            glBegin(GL_TRIANGLES);

        //Left and Right triangles
            for(float i = -1;i>-2;i-=0.5)
            {
                glVertex3f(-0.95f, 0.23f, i);
                glVertex3f(-0.50f, -0.06f,i);
                glVertex3f(-0.95f, -0.35f,i);

                glVertex3f(1.45f, 0.23f,i);
                glVertex3f(1.0f, -0.06f,i);
                glVertex3f(1.45f, -0.35f,i);
            }
            glEnd();

            draw2(-0.50,0.23,-0.35,-0.95,-0.06,0,-1.01);
            draw2(1.0,0.23,-0.35,1.45,-0.06,1,-1.01);
            draw2(-0.50,0.23,-0.35,-0.95,-0.06,0,-0.99);
            draw2(1.0,0.23,-0.35,1.45,-0.06,1,-0.99);

            draw2(-0.50,0.23,-0.35,-0.95,-0.06,0,-1.5+0.01);
            draw2(1.0,0.23,-0.35,1.45,-0.06,1,-1.5+0.01);
            draw2(-0.50,0.23,-0.35,-0.95,-0.06,0,-1.5-0.01);
            draw2(1.0,0.23,-0.35,1.45,-0.06,1,-1.5-0.01);

        }
	};
    class pattern3
    {
        int const SIDE_INC = 5;
        int const ROMB_TO_ZIG = 0.8;
        public: void  patt3()
        {
            glScaled(0.1,0.1,0.1);
            glTranslated(-5,-9,0);
                for(float a = -5;a>-16;a-=10)
            {
                glLineWidth(5);
            for(int j=-1;j<=4;j++)
            {
                glColor3f(0.36, 0.29, 0.25);
                glColor3ub(r,g,b);
                //left zikzak

                for(int i = 0;i <= 5;i++)
                {
                    glBegin(GL_LINES);
                    glVertex3f(2+SIDE_INC*j,0+4*i,a);
                    glVertex3f(0+SIDE_INC*j,2+4*i,a);
                    glVertex3f(0+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2+SIDE_INC*j,4+4*i,a);
                    glEnd();
                }



                //right zikzak
                glBegin(GL_LINES);
                for(int i = 0;i <= 5;i++)
                {
                    glVertex3f(2.5+SIDE_INC*j,0+4*i,a);
                    glVertex3f(4.5+SIDE_INC*j,2+4*i,a);
                    glVertex3f(4.5+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2.5+SIDE_INC*j,4+4*i,a);
                }

            glEnd();

                //inner box
                 glBegin(GL_LINES);
                for(int i = 0;i <= 5;i++)
                {
                    glVertex3f(2.25+SIDE_INC*j,0+4*i,a);
                    glVertex3f(0.25+SIDE_INC*j,2+4*i,a);
                    glVertex3f(0.25+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2.25+SIDE_INC*j,4+4*i,a);
                    glVertex3f(2.25+SIDE_INC*j,4+4*i,a);
                    glVertex3f(4.25+SIDE_INC*j,2+4*i,a);
                    glVertex3f(4.25+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2.25+SIDE_INC*j,0+4*i,a);
                }

                glEnd();

                glBegin(GL_LINES);
                for(int i = -1;i <= 5;i++)
                {
                    glVertex3f(4.75+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2.75+SIDE_INC*j,4+4*i,a);
                    glVertex3f(2.75+SIDE_INC*j,4+4*i,a);
                    glVertex3f(4.75+SIDE_INC*j,6+4*i,a);
                    glVertex3f(4.75+SIDE_INC*j,6+4*i,a);
                    glVertex3f(6.75+SIDE_INC*j,4+4*i,a);
                    glVertex3f(6.75+SIDE_INC*j,4+4*i,a);
                    glVertex3f(4.75+SIDE_INC*j,2+4*i,a);
                }

                glEnd();

                for(int i = 0;i <= 5;i++)
                {
                    glBegin(GL_POLYGON);
                    glVertex3f(2.25+SIDE_INC*j,0.5+4*i,a);
                    glVertex3f(0.75+SIDE_INC*j,2+4*i,a);
                    glVertex3f(2.25+SIDE_INC*j,3.5+4*i,a);
                    glVertex3f(3.75+SIDE_INC*j,2+4*i,a);
                    glEnd();
                }

                 for(int i = -1;i <= 5;i++)
                {
                    glBegin(GL_POLYGON);
                    glVertex3f(4.75+SIDE_INC*j,2.5+4*i,a);
                    glVertex3f(3.25+SIDE_INC*j,4+4*i,a);
                    glVertex3f(4.75+SIDE_INC*j,5.5+4*i,a);
                    glVertex3f(6.25+SIDE_INC*j,4+4*i,a);
                    glEnd();
                }

                  glColor3f(0.65, 0.67, 0.60);
                //right zikzak
                glLineWidth(2);
                glBegin(GL_LINES);
                for(int i = -1;i <= 5;i++)
                {
                    glVertex3f(1.5+SIDE_INC*j,1.25+4*i,a);
                    glVertex3f(3.0+SIDE_INC*j,2.75+4*i,a);
                    glVertex3f(1.5+SIDE_INC*j,2.75+4*i,a);
                    glVertex3f(3.0+SIDE_INC*j,1.25+4*i,a);
                }
                glEnd();

                glLineWidth(15);
                glBegin(GL_LINES);
                for(int i = -1;i <= 5;i++)
                {
                    glVertex3f(4.0+SIDE_INC*j,3.25+4*i,a);
                    glVertex3f(5.5+SIDE_INC*j,4.75+4*i,a);
                    glVertex3f(4.0+SIDE_INC*j,4.75+4*i,a);
                    glVertex3f(5.5+SIDE_INC*j,3.25+4*i,a);
                }
                glEnd();

                glLineWidth(5);

            }

        }
    }
};

    class pattern4
    {


    void draw_inner_Lines(float x,float y,float x1,float x2)
    {
        glBegin(GL_LINES);
        glColor3ub(r,g,b);
        for(float a = -1;a>-2;a-=0.65)
        {
            glVertex3f(x,y,a+0.02);
            glVertex3f(x1,x2,a+0.02);


            glVertex3f(x,y,a-0.04);
            glVertex3f(x1,x2,a-0.04);
        }
        glEnd();

    }
    void leftAndRight()
    {
        for(float a = -1;a>-2;a-=0.65)
        {
             glColor3f(0.1f, 0.5f, 0.5f);
            glBegin(GL_QUADS);
            glVertex3f(-0.425,0.9,a-0.01);
            glVertex3f(0.225,0.9,a-0.01);
            glVertex3f(0.225,-0.9,a-0.01);
            glVertex3f(-0.425,-0.9,a-0.01);
            glEnd();

            float down = 0,width = -0.3;

            for(int i = 0; i<3;i++)
            {
                for(int i = 0; i<3;i++)
                {
                glBegin(GL_QUADS);

                glColor3ub(202,185,90);
                glVertex3f(0.0+width,0.7-down,a-0.02);
                glVertex3f(0.1+width,0.5-down,a-0.02);
                glVertex3f(0.0+width,0.3-down,a-0.02);
                glVertex3f(-0.1+width,0.5-down,a-0.02);


                glVertex3f(0.0+width,0.7-down,a);
                glVertex3f(0.1+width,0.5-down,a);
                glVertex3f(0.0+width,0.3-down,a);
                glVertex3f(-0.1+width,0.5-down,a);

                glEnd();
                glLineWidth(2);
                draw_inner_Lines(0.0+width,0.7-down-0.03,0.1+width-0.018,0.5-down);
                draw_inner_Lines(0.0+width,0.3-down+0.03,-0.1+width+0.018,0.5-down);
                draw_inner_Lines(0.1+width-0.018,0.5-down,0.0+width,0.3-down+0.03);
                draw_inner_Lines(-0.1+width+0.018,0.5-down,0.0+width,0.7-down-0.03);


                draw_inner_Lines(0.0+width,0.7-down-0.06,0.1+width-0.036,0.5-down);
                draw_inner_Lines(0.0+width,0.3-down+0.06,-0.1+width+0.036,0.5-down);
                draw_inner_Lines(0.1+width-0.036,0.5-down,0.0+width,0.3-down+0.06);
                draw_inner_Lines(-0.1+width+0.036,0.5-down,0.0+width,0.7-down-0.06);

                glColor3f(0,0.5,0);
                glBegin(GL_QUADS);
                glVertex3f(0.0+width,0.7-down-0.10,a-0.03);
                glVertex3f(0.1+width-0.06,0.5-down,a-0.03);
                glVertex3f(0.0+width,0.3-down+0.10,a-0.03);
                glVertex3f(-0.1+width+0.06,0.5-down,a-0.03);

                glVertex3f(0.0+width,0.7-down-0.10,a+0.01);
                glVertex3f(0.1+width-0.06,0.5-down,a+0.01);
                glVertex3f(0.0+width,0.3-down+0.10,a+0.01);
                glVertex3f(-0.1+width+0.06,0.5-down,a+0.01);

                glEnd();
                //
                down += 0.5;
                }

                width += 0.2;
                down = 0;
            }


        }


    }


public : void patt4()
{
        glTranslatef(0.0,0.0,3);
        glRotated(90,0,0,1);
        for(float a = -1;a>-2;a-=0.65)
        {

        glColor3ub(0,0,255);
        glBegin(GL_QUADS);
        glVertex3f(-0.425,0.9,a-0.01);
        glVertex3f(0.225,0.9,a-0.01);
        glVertex3f(0.225,-0.9,a-0.01);
        glVertex3f(-0.425,-0.9,a-0.01);
        glEnd();

        float down = 0,width = -0.3;

        for(int i = 0; i<3;i++)
        {
            for(int i = 0; i<3;i++)
            {
            glBegin(GL_QUADS);

            glColor3ub(202,185,90);
            glVertex3f(0.0+width,0.7-down,a-0.02);
            glVertex3f(0.1+width,0.5-down,a-0.02);
            glVertex3f(0.0+width,0.3-down,a-0.02);
            glVertex3f(-0.1+width,0.5-down,a-0.02);

            glVertex3f(0.0+width,0.7-down,a);
            glVertex3f(0.1+width,0.5-down,a);
            glVertex3f(0.0+width,0.3-down,a);
            glVertex3f(-0.1+width,0.5-down,a);

            glEnd();
            glLineWidth(2);
            draw_inner_Lines(0.0+width,0.7-down-0.03,0.1+width-0.018,0.5-down);
            draw_inner_Lines(0.0+width,0.3-down+0.03,-0.1+width+0.018,0.5-down);
            draw_inner_Lines(0.1+width-0.018,0.5-down,0.0+width,0.3-down+0.03);
            draw_inner_Lines(-0.1+width+0.018,0.5-down,0.0+width,0.7-down-0.03);

            draw_inner_Lines(0.0+width,0.7-down-0.06,0.1+width-0.036,0.5-down);
            draw_inner_Lines(0.0+width,0.3-down+0.06,-0.1+width+0.036,0.5-down);
            draw_inner_Lines(0.1+width-0.036,0.5-down,0.0+width,0.3-down+0.06);
            draw_inner_Lines(-0.1+width+0.036,0.5-down,0.0+width,0.7-down-0.06);

            glColor3f(0,0.5,0);
            glBegin(GL_QUADS);
            glVertex3f(0.0+width,0.7-down-0.10,a-0.03);
            glVertex3f(0.1+width-0.06,0.5-down,a-0.03);
            glVertex3f(0.0+width,0.3-down+0.10,a-0.03);
            glVertex3f(-0.1+width+0.06,0.5-down,a-0.03);

            glVertex3f(0.0+width,0.7-down-0.10,a+0.01);
            glVertex3f(0.1+width-0.06,0.5-down,a+0.01);
            glVertex3f(0.0+width,0.3-down+0.10,a+0.01);
            glVertex3f(-0.1+width+0.06,0.5-down,a+0.01);

            glEnd();
            //
            down += 0.5;
            }

            width += 0.2;
            down = 0;
        }


    }
    glRotatef(90,0.0,1.0,0.0);
    glTranslatef(1.45,0,1.24);
    leftAndRight();
    //-------


        }
    };
}
