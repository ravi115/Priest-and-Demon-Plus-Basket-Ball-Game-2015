#include <stdio.h>
#include <stdlib.h>     
#include<math.h>
#include <GL/glut.h>  
#include<string.h>
/******************************************priest with demon game**************************************/



int i;
char str1[30] = "game over";
char str2[30] = "you won";
char a = 10;
int p = -1200, q = 200, r;
int flag_ovr = 0;
/************************************************************************************************************************************/
bool movingh = false;
//GLint window;
//GLint window2;
float xLocation = 0.0f;
float x_pos = 00, y_pos = 00;//modification
//int i;
int nopr = 3;//number of prist on right side
int nodr = 3;//no. of demon on right side
int nopl = 0;//no of priest on left side 
int nodl = 0;//no of demon on left side
int counter = 0;//to count the no of left click

int flag_p1 = 1;
int flag_p2 = 1;
int flag_p3 = 1;
int flag_d1 = 1;
int flag_d2 = 1;
int flag_d3 = 1;
int flag_b = 1;
int flag_bd = 0;
int flag_bp = 0;
int flag_pp = 0;
int flag_dd = 0;
int flag_pd = 0;
int e = -650, d = 300, f = -650;
void mytimer(int v);
void NormalKey(GLubyte key, GLint x, GLint y);
void mytimer1(int v);
void dispover()
{
	glColor3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-600, -200);
	glVertex2f(600, -200);
	glVertex2f(600, 200);
	glVertex2f(-600, 200);
	glEnd();
	if (flag_ovr == 1)
	{
		glColor3f(0, 1, 0);
		glRasterPos2i(-200, 0);
		for (i = 0; i<strlen(str1); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
		}
		flag_b = 0;
		flag_bp = 0;
		flag_pp = 0;
	}
	if (flag_ovr == 2)
	{
		glColor3f(0, 1, 0);
		glRasterPos2i(-200, 0);
		for (i = 0; i<strlen(str2); i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
		}
	}
}
void boat(GLint d, GLint e)// Draw boat 
{
	int i;
	float h = 0, x1 = 0, y1 = 0;
	GLint a, b;
	a = d, b = e;
	glBegin(GL_POLYGON); // outer base
	glColor3f(0.70, 0.025, 0.1);
	glVertex2f(50.0 + a, 250 + b);
	glColor3f(1.0, 0.20, 0.40);
	glVertex2f(80.0 + a, 125.0 + b);
	glColor3f(0.20, 0.50, 0.80);
	glVertex2f(400.0 + a, 125.0 + b);
	glColor3f(0.35, 0.50, 0.70);
	for (i = 0; i < 360; i += 1)// draw top elipse
	{
		h = i*(3.142 / 180);
		x1 = 250 + 200 * cos(h);
		y1 = 250 + 30 * sin(h);
		glVertex2f(x1 + a, y1 + b);
	}
	glEnd();
	glBegin(GL_POLYGON);	// strips on boat
	glColor3f(0, 1, 1);
	glVertex2f(385 + a, 272 + b);
	glColor3f(1, 0, 1);
	glVertex2f(400 + a, 269 + b);
	glColor3f(0, 1, 0);
	glVertex2f(400 + a, 230 + b);
	glColor3f(0, 0, 0);
	glVertex2f(385 + a, 227 + b);
	glEnd();

	glBegin(GL_POLYGON);// strips on boat
	glColor3f(0, 1, 1);
	glVertex2f(285 + a, 280 + b);
	glColor3f(1, 0, 1);
	glVertex2f(300 + a, 279 + b);
	glColor3f(0, 1, 0);
	glVertex2f(300 + a, 221 + b);
	glColor3f(1, 0, 0);
	glVertex2f(285 + a, 220 + b);
	glEnd();

	glBegin(GL_POLYGON);// strips on boat
	glColor3f(1, 0, 1);
	glVertex2f(195 + a, 279 + b);
	glColor3f(1, 0, 0);
	glVertex2f(210 + a, 279 + b);
	glColor3f(1, 0, 1);
	glVertex2f(210 + a, 220 + b);
	glColor3f(1, 1, 0);
	glVertex2f(195 + a, 221 + b);
	glEnd();

	glBegin(GL_POLYGON);// strips on boat
	glColor3f(0, 1, 1);
	glVertex2f(95 + a, 269 + b);
	glColor3f(1, 0, 1);
	glVertex2f(105 + a, 270 + b);
	glColor3f(0, 1, 0);
	glVertex2f(105 + a, 230 + b);
	glColor3f(0, 0, 0);
	glVertex2f(95 + a, 230 + b);
	glEnd();
}

void priest(GLint a, GLint b)// Draw priest 
{
	int i;
	float h, x1, y1;
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.20, 0.40);
	glVertex2f(10.0 + a, 10 + b);
	glColor3f(1.0, 0.20, 0.40);
	glVertex2f(30.0 + a, 30.0 + b);
	glColor3f(1.0, 0.20, 0.40);
	glVertex2f(50.0 + a, 10.0 + b);
	glColor3f(1.0, 0.20, 0.40);
	glVertex2f(30 + a, 0 + b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(23 + a, 2 + b);
	glVertex2d(23 + a, -15 + b);
	glVertex2d(15 + 20 + a, 2 + b);
	glVertex2d(15 + a + 20, -15 + b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(35 + a, -15 + b);
	glVertex2d(60 + a, -15 + b);
	glVertex2d(a, -15 + b);
	glVertex2d(23 + a, -15 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -25 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -35 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -45 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.05, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 25 + 3 * cos(h);
		y1 = b + 20 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.05, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 35 + 3 * cos(h);
		y1 = b + 20 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.9150, 0.970);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + .5 * cos(h);
		y1 = b + 15 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.905, 0.0150, 0.970);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 4 * cos(h);
		y1 = b + 9 + .8 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(a + 5, b - 50);
	glVertex2f(15 + 5 + a, b - 50);
	glVertex2f(a + 5, b - 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(a + 5 + 35, b - 50);
	glVertex2f(50 + 5 + a, b - 100);
	glVertex2f(50 + 5 + a, b - 50);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(55 + a, -15 + b);
	glVertex2d(55 + a, -50 + b);
	glVertex2d(60 + a, -15 + b);
	glVertex2d(55 + a, -50 + b);

	glVertex2d(a + 5, -15 + b);
	glVertex2d(a + 5, -50 + b);
	glVertex2d(a, -15 + b);
	glVertex2d(a + 5, -50 + b);
	glEnd();

}

void demon(GLint a, GLint b) // draw demon only change in face color from priest
{
	int i;
	float h, x1, y1;



	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.20, 0.40);
	glVertex2f(10.0 + a, 10 + b);
	glColor3f(0.0, 0.20, 0.40);
	glVertex2f(30.0 + a, 30.0 + b);
	glColor3f(0.0, 0.20, 0.40);
	glVertex2f(50.0 + a, 10.0 + b);
	glColor3f(0.0, 0.20, 0.40);
	glVertex2f(30 + a, 0 + b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(23 + a, 2 + b);
	glVertex2d(23 + a, -15 + b);
	glVertex2d(15 + 20 + a, 2 + b);
	glVertex2d(15 + a + 20, -15 + b);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(35 + a, -15 + b);
	glVertex2d(60 + a, -15 + b);
	glVertex2d(a, -15 + b);
	glVertex2d(23 + a, -15 + b);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -25 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -35 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 2 * cos(h);
		y1 = b + -45 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.05, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 25 + 3 * cos(h);
		y1 = b + 20 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.05, 0.0150, 0.070);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 35 + 3 * cos(h);
		y1 = b + 20 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.95, 0.9150, 0.970);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + .5 * cos(h);
		y1 = b + 15 + 2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.905, 0.0150, 0.970);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = a + 30 + 4 * cos(h);
		y1 = b + 9 + .8 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(a + 5, b - 50);
	glVertex2f(15 + 5 + a, b - 50);
	glVertex2f(a + 5, b - 100);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(a + 5 + 35, b - 50);
	glVertex2f(50 + 5 + a, b - 100);
	glVertex2f(50 + 5 + a, b - 50);

	glEnd();

	glBegin(GL_LINES);
	glColor3f(1, 0, 1);
	glVertex2d(55 + a, -15 + b);
	glVertex2d(55 + a, -50 + b);
	glVertex2d(60 + a, -15 + b);
	glVertex2d(55 + a, -50 + b);

	glVertex2d(a + 5, -15 + b);
	glVertex2d(a + 5, -50 + b);
	glVertex2d(a, -15 + b);
	glVertex2d(a + 5, -50 + b);
	glEnd();

}

void boatp1(GLint d, GLint e, GLint h)//boat with 1 priest
{
	boat(d, e);
	priest(430 - h, -330);

	glFlush();
}

void boatd1(GLint d, GLint e, GLint h)// boat with 1 demon
{
	boat(d, e);
	demon(620 - h, -330);

	glFlush();
}

void boatp1d1(GLint d, GLint e)//boat with 1 man and 1 demon
{
	boat(d, e);
	priest(430, -330);
	demon(620, -330);
	glFlush();
}
void boatp2(GLint d, GLint e)//boat with 2 man
{
	boat(d, e);
	priest(430, -330);
	priest(620, -330);
	glFlush();
}
void boatd2(GLint d, GLint e)//boat with 2 demon
{
	boat(d, e);
	demon(430, -330);
	demon(620, -330);
	glFlush();
}
static void SpecialKeyFunc(int Key, int p, int q)//translate the boat
{
	switch (Key) {
	case GLUT_KEY_RIGHT:
		if (counter == 2 || counter == 1)
		{
			if (nopl<nodl && nopl != 0)flag_ovr = 1;//right movement of boat
			glutTimerFunc(10, mytimer1, 20);


		}
		break;
	case GLUT_KEY_LEFT:
		if (counter == 2)
		{
			//left movement of boat
			if (d == -430)
			{

			}
			else
			{
				if (nopr<nodr && nopr != 0)flag_ovr = 1;
				glutTimerFunc(10, mytimer, 20);

			}
		}
		break;
	}
}
//modification
void mytimer(int v)			//left movement of boat
{
	x_pos -= 10;
	if (x_pos == -950)
	{
		x_pos += 10;//costant value to stop there
	}

	glutPostRedisplay();
}

void mytimer1(int v)		//right movement of boat
{
	x_pos += 10;
	if (x_pos == 10)
	{
		x_pos -= 10;
	}
	glutPostRedisplay();
}
void trans2()
{
	if (flag_bp == 2)boatp1(d, e, 0);
	else if (flag_bd == 2)boatd1(d, e, 0);
}

void trans1()//taking left bank of the river
{
	if (flag_pd == 1)boatp1d1(d, e);
	else if (flag_pd == 2)boatp1d1(d, e);
	else if (flag_pp == 1)boatp2(d, e);
	else if (flag_dd == 1)boatd2(d, e);
	else if (flag_pp == 2)boatp2(d, e);
	else if (flag_dd == 2)boatd2(d, e);


}

void boat_at_right_pos(int x, int y)
{

	if (x>75 && x<105 && y<-110 && y>-170)// left pos on boat
	{
		counter--;
		if (flag_pp == 1 || flag_pp == 2)
		{
			flag_pp = 0;
			flag_bp = 1;
			if (flag_p1 == 0)flag_p1 = 1;
			else if (flag_p2 == 0)flag_p2 = 1;
			else if (flag_p3 == 0)flag_p3 = 1;
			nopr++;
		}
		else if (flag_pd == 1 || flag_pd == 2)
		{
			flag_pd = 0;
			flag_bd = 1;
			if (flag_p1 == 0)flag_p1 = 1;
			else if (flag_p2 == 0)flag_p2 = 1;
			else if (flag_p3 == 0)flag_p3 = 1;
			nopr++;
		}
		else if (flag_bp == 1 || flag_bp == 2)
		{
			flag_bp = 0;
			flag_b = 1;
			if (flag_p1 == 0)flag_p1 = 1;
			else if (flag_p2 == 0)flag_p2 = 1;
			else if (flag_p3 == 0)flag_p3 = 1;
			nopr++;
		}
		else if (flag_dd == 1 || flag_dd == 2)
		{
			flag_dd = 0;
			flag_bd = 1;
			if (flag_d1 == 0)flag_d1 = 1;
			else if (flag_d2 == 0)flag_d2 = 1;
			else if (flag_d3 == 0)flag_d3 = 1;
			nodr++;
		}

	}
	if (x>178 && x<202 && y<-110 && y>-170)//right position on the boat
	{

		counter--;
		if (flag_dd == 1 || flag_dd == 2)
		{
			flag_bd = 1;
			flag_dd = 0;
			if (flag_d1 == 0)flag_d1 = 1;
			else if (flag_d2 == 0)flag_d2 = 1;
			else if (flag_d3 == 0)flag_d3 = 1;
			nodr++;
		}
		else if (flag_pd == 1 || flag_pd == 2)
		{
			flag_pd = 0;
			flag_bp = 1;
			if (flag_d1 == 0)flag_d1 = 1;
			else if (flag_d2 == 0)flag_d2 = 1;
			else if (flag_d3 == 0)flag_d3 = 1;
			nodr++;

		}
		else if (flag_bd == 1 || flag_bd == 2)
		{
			flag_bd = 0;
			flag_b = 1;
			if (flag_d1 == 0)flag_d1 = 1;
			else if (flag_d2 == 0)flag_d2 = 1;
			else if (flag_d3 == 0)flag_d3 = 1;
			nodr++;

		}
		else if (flag_pp == 1 || flag_pp == 2)
		{
			flag_pp = 0;
			flag_bp = 1;
			if (flag_p1 == 0)flag_p1 = 1;
			else if (flag_p2 == 0)flag_p2 = 1;
			else if (flag_p3 == 0)flag_p3 = 1;
			nopr++;
		}
	}
}
// boat at left of river

void boat_at_left_pos(int x, int y)
{

	if (x>-405 && x<-375 && y>-170 && y<-110) //left position on the boat
	{
		counter--;
		if (flag_pp == 1 || flag_pp == 2)
		{
			flag_pp = 0;
			flag_bp = 2;
			if (flag_p1 == 0)flag_p1 = 2;
			else if (flag_p2 == 0)flag_p2 = 2;
			else if (flag_p3 == 0)flag_p3 = 2;
			nopl++;
		}
		else if (flag_pd == 1 || flag_pd == 2)
		{
			flag_pd = 0;
			flag_bd = 2;
			if (flag_p1 == 0)flag_p1 = 2;
			else if (flag_p2 == 0)flag_p2 = 2;
			else if (flag_p3 == 0)flag_p3 = 2;
			nopl++;
		}
		else if (flag_bp == 2)
		{
			flag_bp = 0;
			flag_b = 2;
			if (flag_p1 == 0)flag_p1 = 2;
			else if (flag_p2 == 0)flag_p2 = 2;
			else if (flag_p3 == 0)flag_p3 = 2;
			nopl++;
		}
		else if (flag_dd == 1 || flag_dd == 2)
		{
			flag_dd = 0;
			flag_bd = 2;
			if (flag_d1 == 0)flag_d1 = 2;
			else if (flag_d2 == 0)flag_d2 = 2;
			else if (flag_d3 == 0)flag_d3 = 2;
			nodl++;
		}

	}

	if (x>-310 && x<-280 && y>-170 && y<-110)//right  position at boat
	{

		counter--;
		if (flag_dd == 1 || flag_dd == 2)
		{
			flag_bd = 2;
			flag_dd = 0;
			if (flag_d1 == 0)flag_d1 = 2;
			else if (flag_d2 == 0)flag_d2 = 2;
			else if (flag_d3 == 0)flag_d3 = 2;
			nodl++;
		}
		else if (flag_pd == 1 || flag_pd == 2)
		{
			flag_pd = 0;
			flag_bp = 2;
			if (flag_d1 == 0)flag_d1 = 2;
			else if (flag_d2 == 0)flag_d2 = 2;
			else if (flag_d3 == 0)flag_d3 = 2;
			nodl++;

		}
		else if (flag_bd == 2)
		{
			flag_bd = 0;
			flag_b = 2;
			if (flag_d1 == 0)flag_d1 = 2;
			else if (flag_d2 == 0)flag_d2 = 2;
			else if (flag_d3 == 0)flag_d3 = 2;
			nodl++;

		}
		else if (flag_pp == 1 || flag_pp == 2)
		{
			flag_pp = 0;
			flag_bp = 2;
			if (flag_p1 == 0)flag_p1 = 2;
			else if (flag_p2 == 0)flag_p2 = 2;
			else if (flag_p3 == 0)flag_p3 = 2;
			nopl++;
		}
	}
	if (nopl == 3)flag_ovr = 2;
}


/****************************left of river work********************************/

void demon_click(int x, int y)
{

	if (x > -700 && x<-670 && y>-230 && y < -170)// demon1 is selected
	{
		counter++;
		flag_d1 = 0;
		flag_b = 0;
		if (nodl == 3 && nodr == 0)//inside p1;
		{
			flag_bd = 2;
			nodl--;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else if (nodr == 0 && nodl == 2)//if region wants
		{
			nodl--;
			flag_bd = 0;
			flag_dd = 2;
		}
		else if (nodr == 1 && nodl == 2)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else if (nodr == 1 && nodl == 1)
		{
			nodl--;
			flag_dd = 2;
			flag_bd = 0;
		}
		else if (nodr == 2 && nodl == 1)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}

	}
	else if (x > -740 && x<-710 && y>-230 && y < -170)// demon2 is selected
	{
		counter++;
		flag_d2 = 0;
		flag_b = 0;
		if (nodl == 3 && nodr == 0)//inside p1;
		{
			flag_bd = 2;
			nodl--;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else if (nodr == 0 && nodl == 2)//if region wants
		{
			nodl--;
			flag_bd = 0;
			flag_dd = 2;
		}

		else if (nodr == 1 && nodl == 2)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else if (nodr == 1 && nodl == 1)
		{
			nodl--;
			flag_dd = 2;
			flag_bd = 0;
		}
		else if (nodr == 2 && nodl == 1)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}

	}


	else if (x > -780 && x<-750 && y>-230 && y < -170)// demon3 is selected
	{

		counter++;
		flag_d3 = 0;
		flag_b = 0;
		if (nodl == 3 && nodr == 0)//inside p1;
		{
			flag_bd = 2;
			nodl--;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else	if (nodr == 0 && nodl == 2)//if region wants
		{
			nodl--;
			flag_bd = 0;
			flag_dd = 2;
		}

		else if (nodr == 1 && nodl == 2)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
		else if (nodr == 1 && nodl == 1)
		{
			nodl--;
			flag_dd = 2;
			flag_bd = 0;
		}
		else if (nodr == 2 && nodl == 1)
		{
			nodl--;
			flag_bd = 2;
			if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
			{
				flag_pd = 2;
				flag_bd = 0;
				flag_bp = 0;
			}
		}
	}
}

void priest_click(int x, int y)
{
	if (x>-650 && x<-620 && y>-160 && y < -100)// priest1 is selected(right most)
	{
		counter++;
		flag_p1 = 0;
		flag_b = 0;
		if (nopl == 3 && nopr == 0)//inside p1;
		{
			flag_bp = 2;
			nopl--;
			if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else	if (nopr == 0 && nopl == 2)//if region wants
		{
			nopl--;
			flag_bp = 0;
			flag_pp = 2;
		}

		else if (nopr == 1 && nopl == 2)
		{
			nopl--;
			flag_bp = 2;

			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else if (nopl == 1 && nopr == 1)
		{
			nopl--;
			flag_pp = 2;
			flag_bp = 0;

		}
		else if (nopr == 2 && nopl == 1)
		{
			nopl--;
			flag_bp = 2;
			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
	}
	else if (x>-690 && x<-660 && y>-160 && y < -100)// priest2 is selected
	{
		counter++;
		flag_p2 = 0;
		flag_b = 0;
		if (nopl == 3 && nopr == 0)//inside p1;
		{
			flag_bp = 2;
			nopl--;
			if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else	if (nopr == 0 && nopl == 2)//if region wants
		{
			nopl--;
			flag_bp = 0;
			flag_pp = 2;
		}

		else if (nopr == 1 && nopl == 2)
		{
			nopl--;
			flag_bp = 2;
			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else if (nopl == 1 && nopr == 1)
		{
			nopl--;
			flag_pp = 2;
			flag_bp = 0;
		}
		else if (nopr == 2 && nopl == 1)
		{
			nopl--;
			flag_bp = 2;
			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
	}
	else if (x>-730 && x<-700 && y>-160 && y < -100)// priest3 is selected
	{
		counter++;
		flag_p3 = 0;
		flag_b = 0;
		if (nopl == 3 && nopr == 0)//inside p1;
		{
			flag_bp = 2;
			nopl--;
			if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else if (nopr == 0 && nopl == 2)//if region wants
		{
			nopl--;
			flag_bp = 0;
			flag_pp = 2;
		}

		else if (nopr == 1 && nopl == 2)
		{
			nopl--;
			flag_bp = 2;
			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
		else if (nopl == 1 && nopr == 1)
		{
			nopl--;
			flag_pp = 2;
			flag_bp = 0;
		}
		else if (nopr == 2 && nopl == 1)
		{
			nopl--;
			flag_bp = 2;
			if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
			{
				flag_pd = 2;
				flag_bp = 0;
				flag_bd = 0;
			}
		}
	}



}
void mouse(int btn, int stat, int x, int y)
{

	x = x - 950;
	y = 440 - y;
	//on left click
	printf("x=%d	y=%d\n", x, y);
	if (counter<2)
	{
		if (btn == GLUT_LEFT_BUTTON && stat == GLUT_DOWN)
		{

			if (x>350 && x<380 && y>-160 && y < -100)// priest1 is selected
			{
				counter++;
				flag_p1 = 0;
				flag_b = 0;
				if (nopr == 3 && nopl == 0)//inside p1;
				{
					flag_bp = 1;
					nopr--;
					if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;

					}
				}

				else if (nopl == 0 && nopr == 2)//if region wants
				{
					nopr--;
					flag_bp = 0;
					flag_pp = 1;
				}

				else if (nopl == 1 && nopr == 2)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}
				else if (nopl == 1 && nopr == 1)
				{
					nopr--;
					flag_pp = 1;
					flag_bp = 0;
				}
				else if (nopl == 2 && nopr == 1)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}

			}

			else if (x>390 && x<420 && y>-160 && y < -100)// priest2 is selected
			{
				counter++;
				flag_p2 = 0;
				flag_b = 0;
				if (nopr == 3 && nopl == 0)//inside p1;
				{
					flag_bp = 1;
					nopr--;
					if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}
				else if (nopl == 0 && nopr == 2)//if region wants
				{
					nopr--;
					flag_bp = 0;
					flag_pp = 1;
				}

				else if (nopl == 1 && nopr == 2)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}
				else if (nopl == 1 && nopr == 1)
				{
					nopr--;
					flag_pp = 1;
					flag_bp = 0;
				}
				else if (nopl == 2 && nopr == 1)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}

			}

			else if (x>430 && x<460 && y>-160 && y < -100)// priest3 is selected
			{
				counter++;
				flag_p3 = 0;
				flag_b = 0;
				if (nopr == 3 && nopl == 0)//inside p1;
				{
					flag_bp = 1;
					nopr--;
					if (nodr == 2 && nodl == 0 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}
				else if (nopl == 0 && nopr == 2)//if region wants
				{
					nopr--;
					flag_bp = 0;
					flag_pp = 1;
				}

				else if (nopl == 1 && nopr == 2)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}
				else if (nopl == 1 && nopr == 1)
				{
					nopr--;
					flag_pp = 1;
					flag_bp = 0;
				}
				else if (nopl == 2 && nopr == 1)
				{
					nopr--;
					flag_bp = 1;
					if (nodl == 0 && nodr == 2 || nodr == 1 && nodl == 1 || nodr == 0 && nodl == 2)
					{
						flag_pd = 1;
						flag_bp = 0;
						flag_bd = 0;
					}
				}

			}


			else if (x >415 && x<445 && y>-230 && y < -170)// demon1 is selected
			{
				counter++;
				flag_d1 = 0;
				flag_b = 0;
				if (nodr == 3 && nodl == 0)//inside p1;
				{
					flag_bd = 1;
					nodr--;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
				else if (nodl == 0 && nodr == 2)//if region wants
				{
					nodr--;
					flag_bd = 0;
					flag_dd = 1;
				}

				else if (nodl == 1 && nodr == 2)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
					}
				}
				else if (nodl == 1 && nodr == 1)
				{
					nodr--;
					flag_dd = 1;
					flag_bd = 0;
				}
				else if (nodl == 2 && nodr == 1)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
					}
				}

			}

			else if (x >462 && x<482 && y>-230 && y < -170)// demon2 is selected
			{
				counter++;
				flag_d2 = 0;
				flag_b = 0;
				if (nodr == 3 && nodl == 0)//inside p1;
				{
					flag_bd = 1;
					nodr--;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
				else if (nodl == 0 && nodr == 2)//if region wants
				{
					nodr--;
					flag_bd = 0;
					flag_dd = 1;
				}

				else if (nodl == 1 && nodr == 2)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
				else if (nodl == 1 && nodr == 1)
				{
					nodr--;
					flag_dd = 1;
					flag_bd = 0;
				}
				else if (nodl == 2 && nodr == 1)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
			}

			else if (x >490 && x<520 && y>-230 && y < -170)// demon3 is selected
			{
				counter++;
				flag_d3 = 0;
				flag_b = 0;
				if (nodr == 3 && nodl == 0)//inside p1;
				{
					flag_bd = 1;
					nodr--;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
				else if (nodl == 0 && nodr == 2)//if region wants
				{
					nodr--;
					flag_bd = 0;
					flag_dd = 1;
				}

				else if (nodl == 1 && nodr == 2)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
				else if (nodl == 1 && nodr == 1)
				{
					nodr--;
					flag_dd = 1;
					flag_bd = 0;
				}
				else if (nodl == 2 && nodr == 1)
				{
					nodr--;
					flag_bd = 1;
					if (nopl == 0 && nopr == 2 || nopr == 1 && nopl == 1 || nopr == 0 && nopl == 2)
					{
						flag_pd = 1;
						flag_bd = 0;
						flag_bp = 0;
					}
				}
			}
		}

	}
	if (btn == GLUT_LEFT_BUTTON && stat == GLUT_UP)
	{

		/*x = x - 950;
		y = 440 - y;*/
		boat_at_right_pos(x, y);//boat is at right side
		boat_at_left_pos(x, y);//boat is at left position
		if (counter<2)
		{
			priest_click(x, y);//priest are on left side of river
			demon_click(x, y);//demon are on left side of river
		}
	}

	glutPostRedisplay();
}

void clouds(float x, float y, float x2, float y2)
{
	int i;
	float h;
	float x1, y1;

	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = x + x2 * cos(h);
		y1 = y + y2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

}
void drawgrass(int a, int b)
{
	float h, x1, y1;
	glColor3f(0.309804, 0.309804, 0.184314);
	glBegin(GL_LINES);
	glVertex2f(-40 + a, 10 + b);
	glVertex2f(-40 + a, 40 + b);
	glVertex2f(-40 + a, 10 + b);
	glVertex2f(-20 + a, 50 + b);
	glVertex2f(-40 + a, 10 + b);
	glVertex2f(-60 + a, 50 + b);
	glVertex2f(-40 + a, 10 + b);
	glVertex2f(10 + a, 50 + b);
	glVertex2f(-40 + a, 10 + b);
	glVertex2f(-90 + a, 50 + b);
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 100; i<200; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = 10 + a + 50 * cos(h);
		y1 = 10 + b + 15 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<95; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = -90 + a + 50 * cos(h);
		y1 = 10 + b + 15 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();
}
void sky()
{
	glColor3f(0.196078, .6, .8);
	glBegin(GL_QUADS);
	glVertex2f(-1600, 800);
	glVertex2f(1600, 800);
	glVertex2f(1600, 200);
	glVertex2f(-1600, 200);
	glEnd();
	glColor3f(0.623529, 0.623529, 0.372549);
	glBegin(GL_QUADS);
	glVertex2f(-1600, 200);
	glVertex2f(1600, 200);
	glVertex2f(1600, -800);
	glVertex2f(-1600, -800);
	glEnd();
}
void river()
{
	glColor3f(0.439216, 0.858824, 0.576471);
	glBegin(GL_POLYGON);
	glVertex2f(0, 100);
	glVertex2f(-1000, -900);
	glVertex2f(1100, -900);
	//glVertex2f(300, 150);
	glVertex2f(150, 200);
	glVertex2f(100, 200);
	glEnd();
	glColor3f(0.4137255, 0.656863, 0.519608);


	glBegin(GL_POLYGON);//thickness of bank of river

	glVertex2f(100, 200);
	glVertex2f(-1000, -900);

	glVertex2f(-990, -900);
	glVertex2f(110, 200);
	glEnd();
	glColor3f(0.4137255, 0.656863, 0.519608);
	glBegin(GL_POLYGON);
	glVertex2f(140, 200);
	glVertex2f(1090, -900);
	glVertex2f(1100, -900);
	glVertex2f(150, 200);
	glEnd();
	glColor3f(1, 0, 0);
	glutSolidSphere(100, 400, 50);

}

void grasspos()
{
	drawgrass(-1500, 50);
	drawgrass(-1500, -50);
	drawgrass(-1500, -150);
	drawgrass(-1500, -300);
	drawgrass(-1500, -450);
	drawgrass(-1500, -650);
	drawgrass(-1500, -800);
	drawgrass(-1350, 80);
	drawgrass(-1400, 20);
	drawgrass(-1400, -75);
	drawgrass(-1400, -200);
	drawgrass(-1350, -135);
	drawgrass(-1400, -350);
	drawgrass(-1400, -500);
	drawgrass(-1400, -700);
	drawgrass(-1450, -400);
	drawgrass(-1470, -575);
	drawgrass(-1300, -750);
	drawgrass(-1300, -530);
	drawgrass(-1350, -600);
	drawgrass(-1300, -450);
	drawgrass(-1300, -380);
	drawgrass(-1350, -300);
	drawgrass(-1300, -220);
	drawgrass(-1300, -100);
	drawgrass(-1200, -350);
	drawgrass(-1250, -270);
	drawgrass(-1200, -550);
	drawgrass(-1200, -790);
	drawgrass(-1250, -650);
	drawgrass(-1150, -300);
	drawgrass(-1150, -450);
	drawgrass(-1150, -700);
	drawgrass(-1000, -450);
	drawgrass(-1060, -540);
	drawgrass(-1080, -620);
	drawgrass(-900, -800);
	drawgrass(-870, -720);
	drawgrass(-800, -650);
	drawgrass(-700, -580);
	drawgrass(-530, -450);
	drawgrass(-500, -350);
	drawgrass(-600, -490);
	drawgrass(-400, -300);
	drawgrass(-360, -250);
	drawgrass(-300, -180);
	drawgrass(-200, -50);
	drawgrass(-170, -105);
	drawgrass(-300, -140);
	drawgrass(-120, 0);
	drawgrass(-70, 40);
	drawgrass(40, 140);
	drawgrass(-940, -540);
	drawgrass(-940, -640);
	drawgrass(-980, -700);
	drawgrass(-1030, -770);
	drawgrass(-1100, -140);
	drawgrass(-1080, -240);
	drawgrass(-1050, -320);
	drawgrass(-1000, -180);
	drawgrass(-950, -280);
	drawgrass(-950, -370);
	drawgrass(-900, -240);
	drawgrass(-850, -440);
	drawgrass(-820, -560);
	drawgrass(-790, -340);
	drawgrass(-700, -470);
	drawgrass(-800, -140);
	drawgrass(-650, -380);
	drawgrass(-800, -240);
	drawgrass(-700, -270);
	drawgrass(-600, -170);
	drawgrass(-570, -240);
	drawgrass(-900, -240);
	drawgrass(-850, -180);
	drawgrass(-920, -140);
	drawgrass(-700, -180);
	drawgrass(-1000, -100);
	drawgrass(-900, -70);
	drawgrass(-800, -50);
	drawgrass(-700, -90);
	drawgrass(-600, -70);
	drawgrass(-500, -210);
	drawgrass(-570, -280);
	drawgrass(-400, -100);
	drawgrass(-500, -140);
	drawgrass(-400, -200);
	drawgrass(-500, -60);
	drawgrass(-300, -20);
	drawgrass(-500, 0);
	drawgrass(-400, -10);
	drawgrass(-600, 30);
	drawgrass(-700, -10);
	drawgrass(-250, 40);
	drawgrass(-900, 0);
	drawgrass(-800, 20);
	drawgrass(-950, 60);
	drawgrass(-850, 90);
	drawgrass(-750, 140);
	drawgrass(-950, 140);
	/************************************right of river**************/
	drawgrass(1070, -790);
	drawgrass(1190, -750);
	drawgrass(1300, -785);
	drawgrass(1420, -740);
	drawgrass(1550, -795);
	drawgrass(1030, -700);
	drawgrass(1190, -670);
	drawgrass(1300, -650);
	drawgrass(1570, -715);
	drawgrass(1430, -675);
	drawgrass(925, -605);
	drawgrass(1540, -635);
	drawgrass(1040, -615);
	drawgrass(1150, -600);
	drawgrass(1270, -585);
	drawgrass(1450, -605);
	drawgrass(870, -525);
	drawgrass(1015, -555);
	drawgrass(1100, -505);
	/********************************grass under the demon***********************************/
	drawgrass(1225, -525);
	drawgrass(1295, -495);
	drawgrass(1400, -535);
	/*********************************************************************************************/
	drawgrass(1500, -515);
	drawgrass(1575, -575);
	drawgrass(780, -445);
	drawgrass(925, -475);
	drawgrass(1025, -455);
	drawgrass(1150, -450);
	drawgrass(1275, -425);
	drawgrass(1375, -445);
	drawgrass(1450, -420);
	drawgrass(1550, -440);
	drawgrass(850, -390);
	drawgrass(950, -405);
	/********************************grass under the priest***********************************/
	drawgrass(1070, -385);
	drawgrass(1165, -345);
	drawgrass(1250, -365);
	/**********************************************************/
	drawgrass(1365, -335);
	drawgrass(1525, -370);
	drawgrass(700, -340);
	drawgrass(830, -305);
	drawgrass(950, -315);
	drawgrass(1100, -300);
	drawgrass(1250, -265);
	drawgrass(1415, -275);
	drawgrass(1570, -305);
	drawgrass(700, -250);
	drawgrass(835, -225);
	drawgrass(1070, -225);
	drawgrass(1175, -205);
	drawgrass(1345, -205);
	drawgrass(1450, -225);
	drawgrass(1575, -205);
	drawgrass(580, -195);
	drawgrass(500, -145);
	drawgrass(690, -135);
	drawgrass(1300, -135);
	drawgrass(1500, -155);
	drawgrass(500, -80);
	drawgrass(640, -75);
	drawgrass(1220, -85);
	drawgrass(1550, -85);
	drawgrass(410, -10);
	drawgrass(580, -20);
	drawgrass(790, -55);
	drawgrass(880, -20);
	drawgrass(1000, -05);
	drawgrass(700, 15);
	drawgrass(470, 40);
	drawgrass(610, 55);
	drawgrass(790, 45);
	drawgrass(950, 80);
	drawgrass(1100, 55);
	drawgrass(1550, 70);
	drawgrass(350, 95);
	drawgrass(490, 130);
	drawgrass(670, 100);
	drawgrass(810, 105);
	drawgrass(1260, 95);
	drawgrass(1570, 125);
	drawgrass(1050, 125);
	drawgrass(1000, 175);
	drawgrass(1130, 150);



}
void tree(int a, int b)
{
	float h, x1, y1;
	glColor3f(0.52, .37, 0.26);
	glBegin(GL_POLYGON);
	glVertex2f(-50 + a, 10 + b);
	glVertex2f(a - 50, -200 + b);
	glVertex2f(a + 50, b - 200);
	glVertex2f(a + 50, b + 10);
	glEnd();
	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = 10 + 300 * cos(h);
		y1 = 10 + 40 * sin(h);
		glVertex2f(x1 + a, y1 + b);
	}
	glEnd();
	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = 10 + 200 * cos(h);
		y1 = 50 + 40 * sin(h);
		glVertex2f(x1 + a, y1 + b);
	}
	glEnd();
	glColor3f(0.137255, 0.556863, 0.137255);
	glBegin(GL_POLYGON);
	for (int i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = 10 + 100 * cos(h);
		y1 = 100 + 40 * sin(h);
		glVertex2f(x1 + a, y1 + b);
	}
	glEnd();

}
void cloud()
{
	glPushMatrix();
	glTranslatef(p, q, r);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.8);
	clouds(-400, 285, 175, 45);
	glBegin(GL_POLYGON);
	clouds(-400, 250, 200, 45);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, .8);
	clouds(200, 500, 150, 45);
	glBegin(GL_POLYGON);
	clouds(200, 470, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 450, 300, 45);
	glBegin(GL_POLYGON);
	clouds(700, 500, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 400, 150, 45);
	glPopMatrix();
}


void mytimer5(int v)
{
	p += 10;
	if (p >= 1200)p = -1200;
	glutTimerFunc(80, mytimer5, 20);
	glutPostRedisplay();
}
void drawtriangle(int g, int h, int i, int j, int k, int l)
{
	glColor3f(.647059, 0.364706, .264706);
	glBegin(GL_TRIANGLES);
	glVertex2f(g, h);
	glVertex2f(i, j);
	glVertex2f(k, l);
	glEnd();
}
void drawtree()
{
	tree(950, -150);
	tree(1350, 0);
	tree(-1250, 0);

}
void drawmountain()
{
	int h, x1, y1, i;
	glColor3f(.647059, 0.364706, .264706);
	drawtriangle(-1000, 100, -1800, 100, -1400, 600);
	drawtriangle(-1200, 200, -600, 200, -900, 500);
	drawtriangle(-800, 100, 00, 100, -400, 600);
	drawtriangle(-300, 200, 100, 200, -100, 400);
	drawtriangle(150, 200, 450, 200, 300, 400);
	drawgrass(250, 150);
	drawtriangle(190, 150, 1000, 150, 470, 400);
	drawtriangle(700, 200, 1400, 200, 1000, 600);
	drawtriangle(1100, 150, 1700, 150, 1400, 500);


}

void display1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0, 0, 0, 1);
	sky();
	river();
	cloud();
	tree(-1100, 400);
	tree(700, 400);

	drawmountain();
	grasspos();
	drawtree();
	GLint h = 450, k = 60;
	// priest on right position
	if (flag_p1 == 1)priest(1000, -300);
	if (flag_p2 == 1)priest(1080, -300);
	if (flag_p3 == 1)priest(1160, -300);
	// priest at left position
	if (flag_p1 == 2)priest(-1000, -300);
	if (flag_p2 == 2)priest(-1080, -300);
	if (flag_p3 == 2)priest(-1160, -300);
	// demon at right position
	if (flag_d1 == 1)demon(1140, -450);
	if (flag_d2 == 1)demon(1220, -450);
	if (flag_d3 == 1)demon(1300, -450);
	//demon at left position
	if (flag_d1 == 2)demon(-1100, -450);
	if (flag_d2 == 2)demon(-1180, -450);
	if (flag_d3 == 2)demon(-1260, -450);
	//boat
	if (flag_b == 1)boat(d, e);
	else if (flag_b == 2)boat(f, e);
	if (flag_bp == 1)boatp1(d, e, 0);
	if (flag_bd == 1)boatd1(d, e, 0);
	glMatrixMode(GL_MODELVIEW);//modification
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_pos, y_pos, 0);//translation of boat
	trans1();
	trans2();
	glPopMatrix();
	if (flag_ovr == 1 || flag_ovr == 2)dispover();
	glutSwapBuffers();//modification	
	glFlush();
}





/******************************************basketball game**************************************/



#define pi 3.141592654
#define g 10
float Xn, Yn, Xnn, Ynn;
float angle;
int w = 10;
float del_t;
int cloudmomvent = -1200;
float xdist, ydist, rxy;
char str[40] = "BASKET HERE!!";
char string1[60] = "Welcome ";
char string2[40];
char str3[30] = "Remainig Ball : = ";
char str4[15] = "Game Over";
char str5[2];//to display value of n
char str6[10] = "Score : ";
char str7[20] = "Best Score : ";
char str8[10];
char str9[20];//to display the value of score;
char str10[20] = "Your Score :-->";
char str11[20] = "-RESTART-";
char str12[10] = "MENU";
char str13[10] = "QUIT";
char str14[15] = "Nice Basket";
char str15[20] = "Yeah";
char str16[20] = "Ooops Missed";
int noc = 5;
int n;
int score;
int rtheta = 75;//rotation of ball
int x_heli = 1400, y_heli = -500;//variable for helicopter translator
float h, x, y/*, p, q*/;
float X[100], Y[100];
int t, u;
float y_dec, x_dec;
float velocity = 105;
float tof;
float x_direction = 0, y_direction = 0;
//int a = -100;
int x_t = -1225, y_t = 420;
int x_t1 = 220, y_t1 = 600;
int b_x = 400, b_y = 150;
int theta = 0, theta1 = 0;
int flag_tr = 0;//flag for trajectory
int flag_clr = 0;//different color of ball
int flag_er = 1;//flag for bal
//int flag_ovr = 0;//flag for game over conditons
int flag_goal = 0;//flag to display type of goal whenever a goal has to be done

void basketcourt()
{
	glColor3f(.33, 0.33, 0.33);
	glBegin(GL_POLYGON);
	glVertex2f(-970, 0);
	glVertex2f(1100, 0);
	glVertex2f(1100, -40);
	glVertex2f(-970, -40);
	glEnd();
	//glColor3f(.55,0.55,0.55);
	glBegin(GL_POLYGON);
	glVertex2f(-970, 0);
	glVertex2f(-1300, -150);
	glVertex2f(-1300, -190);
	glVertex2f(-970, -40);
	glEnd();
	//glColor3f(.55,0.55,0.55);
	glBegin(GL_POLYGON);
	glVertex2f(1100, 0);
	glVertex2f(1300, -150);
	glVertex2f(1300, -190);
	glVertex2f(1100, -40);
	glEnd();

	glLineWidth(20);//relling of the pipe over the wall
	glColor3f(1, .6, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-1300, -55);
	glVertex2f(-970, 105);
	glVertex2f(1100, 105);
	glVertex2f(1300, -55);
	glEnd();

	glLineStipple(2, 0x000F);
	glEnable(GL_LINE_STIPPLE);
	glColor3f(.9, .6, .2);//lines above the waLL,	,
	glLineWidth(2);
	glBegin(GL_LINES);
	for (int i = 0; i<120; i += 1)
	{
		glVertex2f(-1300, -50 - (i + 2));
		glVertex2f(-970, 100 - i);
		glVertex2f(-970, 100 - i);
		glVertex2f(1100, 100 - i);
		glVertex2f(1100, 100 - i);
		glVertex2f(1300, -50 - (i + 2));
	}
	glEnd();
	glLineStipple(0, 0xFFFF);
	glEnable(GL_LINE_STIPPLE);

	glColor3f(.22, .22, .22);
	glBegin(GL_POLYGON);
	glVertex2f(-970, -40);
	glVertex2f(1100, -40);
	glVertex2f(1100, -200);
	glVertex2f(-970, -200);
	glEnd();

	glColor3f(.22, .22, .22);
	glBegin(GL_POLYGON);
	glVertex2f(-970, -40);
	glVertex2f(-1300, -190);
	glVertex2f(-1300, -400);
	glVertex2f(-970, -200);
	glEnd();

	glColor3f(.22, .22, .22);
	glBegin(GL_POLYGON);
	glVertex2f(1100, -40);
	glVertex2f(1300, -190);
	glVertex2f(1300, -350);
	glVertex2f(1100, -200);
	glEnd();
	glColor3f(0, .31, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1300, -675);
	glVertex2f(-1300, -400);
	glVertex2f(-970, -200);
	glVertex2f(1100, -200);
	glVertex2f(1300, -350);
	glVertex2f(1300, -675);
	glEnd();

	glColor3f(0, 0.2, 0.3);//base floor
	glBegin(GL_POLYGON);
	glVertex2f(-1210, -580);
	glVertex2f(-790, -250);
	glVertex2f(1000, -250);
	glVertex2f(1300, -580);
	glEnd();

	glColor3f(1, 1, 1);//base floor lines
	glBegin(GL_LINES);
	glVertex2f(-1210, -580);
	glVertex2f(-790, -250);
	glVertex2f(-790, -250);
	glVertex2f(1000, -250);
	glVertex2f(1000, -250);
	glVertex2f(1300, -580);
	glVertex2f(1300, -580);
	glVertex2f(-1210, -580);
	glVertex2f(100, -250);
	glVertex2f(100, -580);
	glEnd();

	glColor3f(1, 1, 1);//base center circle
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 100 + 90 * cos(h);
		y = -400 + 70 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
}
void ball1()
{
	if (flag_clr == 0)glColor3f(1, .5, 0);
	else if (flag_clr == 1)glColor3f(.6, .3, .4);
	else if (flag_clr == 2)glColor3f(.4, .6, .3);
	else if (flag_clr == 3)glColor3f(0, .5, .6);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	if (t<100 && u<100)glTranslatef(X[u], Y[t], 0);
	else  glTranslatef(x_dec, y_dec, 0);
	//else glTranslatef(b_x,b_y,0);
	glRotatef(rtheta, 1, 1, 0);
	glutSolidSphere(80.0, 40.0, 120.0);//drawing of sphare
	if (flag_clr == 0)glColor3f(.8, .8, .8);
	else if (flag_clr == 1)glColor3f(.6, .6, .6);
	else if (flag_clr == 2)glColor3f(.6, .8, .56);
	else if (flag_clr == 3)glColor3f(.6, .7, 0);
	glLineWidth(1);
	glutWireSphere(80, 20, 10);
	glPopMatrix();
	//glutPostRedisplay();
	glFlush();
}

void msg(char * st)//to display how fine you basket
{
	glColor3f(0.93, 0.16, 0.96);
	glRasterPos2i(-500, 250);
	for (int i = 0; i<strlen(st); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}

	glFlush();
}
void basket()
{

	glColor3f(0.858824, 0.858824, 0.439216);//POLL
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(-970, 260);
	glVertex2f(-970, -390);
	glVertex2f(-950, -430);
	glVertex2f(-930, -390);
	glVertex2f(-930, 260);
	glVertex2f(-950, 260);
	glVertex2f(-950, -350);
	glVertex2f(-950, -430);
	glVertex2f(-950, 220);
	glEnd();

	glColor3f(0.137255, 0.556863, 0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(-855, -300);
	glVertex2f(-680, -332);
	glVertex2f(-710, -430);
	glVertex2f(-1030, -440);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = -700 + 70 * cos(h);
		y = -380 + 50 * sin(h);//changes now
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1, 1, 1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(-855, -300);
	glVertex2f(-680, -332);
	glVertex2f(-680, -332);
	glVertex2f(-710, -430);
	glVertex2f(-710, -430);
	glVertex2f(-1030, -440);
	glVertex2f(-1030, -440);
	glVertex2f(-855, -300);
	glEnd();

	// this the other side of the basket base

	glColor3f(0.137255, 0.556863, 0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(1045, -300);
	glVertex2f(845, -332);
	glVertex2f(855, -430);
	glVertex2f(1170, -440);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 850 + 70 * cos(h);
		y = -380 + 50 * sin(h);//changes now
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1, 1, 1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(1045, -300);
	glVertex2f(845, -332);
	glVertex2f(845, -332);
	glVertex2f(855, -430);
	glVertex2f(855, -430);
	glVertex2f(1170, -440);
	glVertex2f(1170, -440);
	glVertex2f(1045, -300);
	glEnd();



	glBegin(GL_POLYGON);//front side of the poll which is attached with basket board
	glColor3f(0, 0, 1);
	glVertex2f(-930, 260);
	glVertex2f(-700, 260);
	glVertex2f(-700, 220);
	glVertex2f(-950, 220);
	glEnd();

	//below code for basket board

	glColor3f(0.77, 0.77, 0.77);
	glBegin(GL_POLYGON);//board where the basket attached
	glVertex3f(-850, 450, 200);
	glVertex3f(-630, 420, -200);//changes 200 to 300
	glVertex3f(-630, 220, -400);//changes -80 to -900
	glVertex3f(-850, 200, 400);
	glEnd();

	glColor3f(0.90, 0.91, 0.98);
	glBegin(GL_POLYGON);//board where the basket attached of side line from each side of the board
	glVertex3f(-840, 440, 200);
	glVertex3f(-635, 410, -200);//changes 200 to 300
	glVertex3f(-635, 230, -400);//changes -80 to -900
	glVertex3f(-840, 210, 400);
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);//code for hook1
	glVertex3f(-720, 280, 200);
	glVertex3f(-700, 280, -200);//changes 200 to 300
	glVertex3f(-700, 250, -400);//changes -80 to -900
	glVertex3f(-720, 250, 400);
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);//lines through the hing into board
	glVertex2f(-780, 360);
	glVertex2f(-660, 340);//changes 200 to 300
	glVertex2f(-660, 340);//changes -80 to -900
	glVertex2f(-660, 250);
	glVertex2f(-660, 250);
	glVertex2f(-780, 240);
	glVertex2f(-780, 240);
	glVertex2f(-780, 360);
	glEnd();

	if (flag_goal == 1)// to display how fine you have basketed
		msg(str14);
	else if (flag_goal == 2)
		msg(str15);
	else if (flag_goal == 3)
		msg(str16);
	glColor3f(1, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<180; i += 1)//basket upper ring degree angle
	{
		h = i*(3.142 / 180);
		p = -620 + 110 * cos(h);
		q = 230 + 40 * sin(h);
		x = -620 + 100 * cos(h);
		y = 230 + 30 * sin(h);
		glVertex2f(p, q);
		glVertex2f(x, y);
	}
	glEnd();
	glLineWidth(1.5);
	glBegin(GL_LINE_STRIP);//1st lines between the upper ring and lower ring from front side
	for (int i = 0; i <= 180; i += 14)
	{
		h = i*(3.142 / 180);
		x = -620 + 110 * cos(h);
		y = 230 + 30 * sin(h);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		glColor3f(0, 0, .41);
		glVertex2f(x, y);
		glColor3f(1, 1, 1);
		glVertex2f(p, q);

	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (int i = 0; i<180; i += 1)//lower ring of basket back side
	{
		h = i*(3.142 / 180);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		x = -620 + 100 * cos(h);
		y = 50 + 30 * sin(h);
		glVertex2f(x, y);
		glVertex2f(p, q);

	}
	glEnd();

	//below code calculate the trajectory
	if (flag_tr == 1)
	{
		if (flag_clr == 0)glColor3f(1, .5, 0);
		else if (flag_clr == 1)glColor3f(.6, .3, .4);
		else if (flag_clr == 2)glColor3f(.4, .6, .3);
		else if (flag_clr == 3)glColor3f(0, .5, .6);
		glPointSize(2);
		glBegin(GL_POINTS);
		for (int i = 0; i<100; i++)
			glVertex2f(X[i], Y[i]);
		glEnd();
	}


	if (flag_er == 1 || flag_er == 2)
	{
		ball1();//function to draw the ball

	}


	glColor3f(1, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i<360; i += 1)//basket upper ring degree angle
	{
		h = i*(3.142 / 180);
		p = -620 + 110 * cos(h);
		q = 230 + 40 * sin(h);
		x = -620 + 100 * cos(h);
		y = 230 + 30 * sin(h);
		glVertex2f(p, q);
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i <= 360; i += 18)//2nd lines between the upper ring and lower ring from back side
	{
		h = i*(3.142 / 180);
		x = -620 + 110 * cos(h);
		y = 230 + 30 * sin(h);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		glColor3f(0, 0, .61);
		glVertex2f(x, y);
		glColor3f(1, 1, 1);
		glVertex2f(p, q);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (int i = 180; i<360; i += 1)//lower ring of basket
	{
		h = i*(3.142 / 180);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		x = -620 + 100 * cos(h);
		y = 50 + 30 * sin(h);
		glVertex2f(x, y);
		glVertex2f(p, q);

	}
	glEnd();
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);//code for hook2
	glVertex3f(-720, 260, 200);
	glVertex3f(-700, 260, 200);//changes 200 to 300
	glVertex3f(-690, 250, -300);//changes -80 to -900
	glVertex3f(-710, 240, 380);
	glEnd();



	glColor3f(1, .4, .5);
	glRasterPos2i(-830, 400);
	int k = 4, a = 15;//to decrement the value of x and y in x,y direction
	for (int i = 0; i<strlen(str); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
		glRasterPos2i(-830 + a, 400 - k);
		k += 3;
		a += 15;
	}
}


void calcu(float Xnn, float Ynn, float theta)
{
	int i;
	tof = 2 * velocity*sin(theta) / g;
	del_t = tof / 100;//time of flight at each point of x and y irrespective to trajectory
	float temp = 0;//variable to calculate time of flight at each point
	for (i = 0; i<100; i++)//this will go in timer func
	{
		x_direction = Xnn + velocity*cos(theta)*temp;//x-initial point + initial velocity * cos(theta) *time of flight at each point
		y_direction = Ynn + velocity*sin(theta)*temp - ((g*temp*temp) / 2);
		X[i] = x_direction;
		Y[i] = y_direction;
		temp += del_t;
		printf("the value of x[100]=%d and y[100]=%d\n\t", X[i], Y[i]);
	}
	x_dec = X[99];
	y_dec = Y[99];
	flag_tr = 1;
	for (i = 0; i<100; i++)
		printf("%f %f\n", X[i], Y[i]);
}
void displayname()
{
	glLineWidth(2);
	glColor3f(1, 1, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1250, 673);
	glVertex2f(-900, 673);
	glVertex2f(-900, 620);
	glVertex2f(-1250, 620);
	glEnd();

	glColor3f(.56, .0, 0);
	glRasterPos2i(-1200, 635);
	for (int i = 0; i<strlen(str1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string1[i]);
	}
	glColor3f(05, .56, 0);
	glRasterPos2i(-1040, 635);
	for (int i = 0; i<strlen(str2); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string2[i]);
	}

	glPopMatrix();
}
void displayboard()
{
	glColor3f(0, .66, .66);//background color of scoreboard and ball
	glBegin(GL_POLYGON);
	glVertex2f(535, 675);
	glVertex2f(1340, 675);
	glVertex2f(1340, 625);
	glVertex2f(535, 625);
	glEnd();

	glColor3f(.0, .0, .66);//score board
	glBegin(GL_POLYGON);
	glVertex2f(810, 670);
	glVertex2f(1000, 670);
	glVertex2f(1000, 630);
	glVertex2f(810, 630);
	glEnd();


	glColor3f(.66, .66, .66);//remaining ball
	glBegin(GL_POLYGON);
	glVertex2f(550, 670);
	glVertex2f(800, 670);
	glVertex2f(800, 630);
	glVertex2f(550, 630);
	glEnd();

	glColor3f(.66, .66, .66);//best score
	glBegin(GL_POLYGON);
	glVertex2f(1010, 670);
	glVertex2f(1330, 670);
	glVertex2f(1330, 630);
	glVertex2f(1010, 630);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2i(570, 640);
	for (int i = 0; i<strlen(str3); i++)//function to write ball
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str3[i]);
	}
	n = noc;
	_itoa_s(n, str5, 10);//converting 10 into ascii of it
	glColor3f(1, 1, 1);
	glRasterPos2i(750, 640);
	for (int i = 0; i<strlen(str5); i++)//printing value of remainig ballinto the box
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str5[i]);
	}
	glColor3f(1, 1, 1);
	glRasterPos2i(820, 640);
	for (int i = 0; i<strlen(str6); i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str6[i]);
	}
	_itoa_s(score, str9, 10);
	glColor3f(1, 1, 0);
	glRasterPos2i(920, 640);
	for (int i = 0; i<strlen(str9); i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str9[i]);
	}

	glColor3f(1, 1, 1);
	glRasterPos2i(1020, 640);
	for (int i = 0; i<strlen(str7); i++)//print best score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str7[i]);
	}
	if (n == 0)
	{
		_itoa_s(score, str9, 10);
		glColor3f(1, 0, 0);
		glRasterPos2i(1160, 640);
		for (int i = 0; i<strlen(str9); i++)//print score
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str9[i]);
		}
	}


}
void dispgameover()
{
	glBegin(GL_POLYGON);
	glColor3f(0.62352, 0.372549, 0.623529);
	glVertex2f(-500, -500);
	glColor3f(0.62352, 0.372549, 0.623529);
	glVertex2f(600, -500);
	glColor3f(0.42352, 0.272549, 0.423529);
	glVertex2f(600, 300);
	glColor3f(0.42352, 0.272549, 0.423529);
	glVertex2f(-500, 300);
	glEnd();
	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 50 + 300 * cos(h);
		y = -100 + 300 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
	glPushMatrix();
	glTranslatef(-180, 30, 0);
	glutSolidTorus(10, 15, 4, 3);
	glPopMatrix();
	glColor3f(.6, .9, 1);
	glRasterPos2i(-50, 30);
	for (int i = 0; i<strlen(str10); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str10[i]);
	}
	glColor3f(.9, .2, 0);//sqaure for displaying score
	glBegin(GL_LINE_LOOP);
	glVertex2f(-150, 5);
	glVertex2f(300, 5);
	glVertex2f(300, -100);
	glVertex2f(-150, -100);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2i(40, -55);
	for (int i = 0; i<strlen(str9); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[i]);
	}

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-120, -150);
	glVertex2f(260, -150);
	glVertex2f(260, -280);
	glVertex2f(-120, -280);
	glEnd();

	glColor3f(.8, .5, .9);//for restert
	glBegin(GL_LINE_LOOP);
	glVertex2f(-120, -150);
	glVertex2f(260, -150);
	glVertex2f(260, -280);
	glVertex2f(-120, -280);
	glEnd();

	glColor3f(.8, .5, .9);
	glRasterPos2i(-20, -225);
	for (int i = 0; i<strlen(str11); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[i]);
	}

	glColor3f(.4, .9, .3);//for menu
	glBegin(GL_LINE_LOOP);
	glVertex2f(-480, -300);
	glVertex2f(-220, -300);
	glVertex2f(-220, -400);
	glVertex2f(-480, -400);
	glEnd();

	glColor3f(.4, .9, .3);
	glRasterPos2i(-400, -350);
	for (int i = 0; i<strlen(str12); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str12[i]);
	}

	glColor3f(.4, .9, .3);//for quit
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, -300);
	glVertex2f(580, -300);
	glVertex2f(580, -400);
	glVertex2f(350, -400);
	glEnd();

	glColor3f(.4, .9, .3);
	glRasterPos2i(430, -350);
	for (int i = 0; i<strlen(str13); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str13[i]);
	}



}

void mytimer3(int v)
{
	y_dec -= 24;
	printf("y new vai %f ,%f", y_dec, x_dec);
	if (y_dec <= -400)
	{
		flag_goal = 0;
		flag_er = 0;
		flag_er = 2;
		u = 0; t = 0, rtheta = 75;
		flag_tr = 0;
		if (noc<1)flag_ovr = 1;
	}
	if (y_dec >= -400)
		glutTimerFunc(50, mytimer1, 20);
	glutPostRedisplay();
}
void mytimer2(int v)
{
	u += 2;
	t += 2;
	if (u == 100 && t == 100)
	{
		if (X[99]>-660 && X[99]<-560)
		{
			flag_goal = 1;
			score += 200;
		}
		else if (X[99]>-560 && X[99]<-510 || X[99]<-660 && X[99]>-730)
		{
			flag_goal = 2;
			score += 100;
		}
		else if (X[99]>-510 || X[99]<-730)
		{
			flag_goal = 3;
			score += 0;
		}

		glutTimerFunc(50, mytimer1, 20);
	}
	rtheta += 5;
	if (rtheta>720)rtheta = 360;
	if (u <= 100)
		glutTimerFunc(50, mytimer, 20);
	glutPostRedisplay();
}
/*void clouds(float x, float y, float x2, float y2)
{
	int i;
	float h;
	float x1, y1;
	glColor3f(1, 1, .85644);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = x + x2 * cos(h);
		y1 = y + y2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

}*/
/*void cloud()
{
	glPushMatrix();
	glTranslatef(cloudmomvent, 0, 0);

	glBegin(GL_POLYGON);
	clouds(-400, 585, 175, 45);
	glBegin(GL_POLYGON);
	clouds(-400, 550, 200, 45);
	glBegin(GL_POLYGON);
	clouds(200, 500, 150, 45);
	glBegin(GL_POLYGON);
	clouds(200, 470, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 450, 300, 45);
	glBegin(GL_POLYGON);
	clouds(700, 500, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 400, 150, 45);
	glPopMatrix();
}*/
void cloudtimer(int v)
{
	cloudmomvent += 10;
	if (cloudmomvent >= 1200)cloudmomvent = -1200;
	glutTimerFunc(120, cloudtimer, 20);
	glutPostRedisplay();
}

void fan2()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(900, 680);
	glColor3f(1, 1, 1);
	glVertex2f(800, 740);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(-280, 680);
	glColor3f(1, 1, 1);
	glVertex2f(-380, 740);
	glEnd();
	//main fan
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(-280, 540);
	glColor3f(1, 1, 1);
	glVertex2f(-330, 480);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(900, 540);
	glColor3f(1, 1, 1);
	glVertex2f(800, 480);
	glEnd();
	glColor3f(.7, .7, .7);//main fan
	glBegin(GL_POLYGON);
	glVertex2f(220, 600);
	glVertex2f(235, 630);
	glVertex2f(205, 570);
	glEnd();

}
void fan()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_heli, y_heli, 0);
	glScalef(.25, .25, .25);
	glRotated(180, 0, 1, 0);

	glTranslated(x_t, y_t, 0);
	glRotated(theta1, 0, 0, 1);
	glTranslated(-(x_t), -(y_t), 0);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-1490, 600);
	glColor3f(1, 1, 1);
	glVertex2f(-1485, 550);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-940, 600);
	glColor3f(1, 1, 1);
	glVertex2f(-915, 550);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-940, 240);
	glColor3f(1, 1, 1);
	glVertex2f(-915, 190);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-1490, 240);
	glColor3f(1, 1, 1);
	glVertex2f(-1485, 190);
	glEnd();
	glPopMatrix();
}

void helicopter()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_heli, y_heli, 0);
	glScalef(.25, .25, .25);
	glRotated(180, 0, 1, 0);

	glColor3f(0.13, .37, .31);
	glBegin(GL_POLYGON);
	glVertex2f(500, -2);
	glVertex2f(500, 502);
	glVertex2f(-100, 502);
	glVertex2f(-300, 270);
	glVertex2f(-1300, 420);
	glVertex2f(-1300, 350);
	glVertex2f(-200, -2);
	glVertex2f(500, -2);
	glEnd();
	glLineWidth(2);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1200, 380);
	glVertex2f(-300, 180);
	glVertex2f(-300, 180);
	glVertex2f(200, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.7, .7, .7);
	for (int i = 90; i > -90; i--)
	{
		h = i*(3.142 / 180);
		x = 500 + 150 * cos(h);
		y = 250 + 252 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.13, .37, .31);
	for (int i = 0; i >= -90; i--)
	{
		h = i*(3.142 / 180);
		x = 500 + 150 * cos(h);
		y = 250 + 252 * sin(h);
		glVertex2f(x, y);
	}
	glVertex2f(500, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(325, 500);
	glColor3f(0, 0, 0);
	glVertex2f(125, 500);
	glColor3f(1, 1, 1);
	glVertex2f(125, 575);
	glColor3f(0, 0, 0);
	glVertex2f(325, 575);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(325, 525);
	glColor3f(0, 1, 0);
	glVertex2f(350, 525);
	glColor3f(1, 0, 0);
	glVertex2f(350, 550);
	glColor3f(0, 1, 0);
	glVertex2f(325, 550);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(205, 575);
	glColor3f(1, 1, 0);
	glVertex2f(205, 600);
	glColor3f(1, 0, 0);
	glVertex2f(245, 600);
	glColor3f(0, 1, 1);
	glVertex2f(245, 575);
	glEnd();

	glColor3f(.6, .2, .6);
	glBegin(GL_POLYGON);
	glVertex2f(-1200, 345);
	glVertex2f(-1250, 345);
	glVertex2f(-1250, 450);
	glVertex2f(-1200, 450);
	glEnd();





	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	glVertex2f(75, 0);
	glColor3f(1, 1, 1);
	glVertex2f(75, -250);
	glColor3f(1, 1, 1);
	glVertex2f(400, -250);
	glColor3f(1, 1, 1);
	glVertex2f(400, 0);
	glColor3f(1, 1, 1);
	glVertex2f(450, 0);
	glColor3f(1, 1, 1);
	glVertex2f(450, -250);
	glColor3f(1, 1, 1);
	glVertex2f(550, -150);
	glColor3f(1, 1, 1);
	glVertex2f(550, -175);
	glColor3f(1, 1, 1);
	glVertex2f(450, -300);
	glColor3f(1, 1, 1);
	glVertex2f(0, -300);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -150);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -125);
	glColor3f(1, 1, 1);
	glVertex2f(25, -250);
	glColor3f(1, 1, 1);
	glVertex2f(25, 0);
	glEnd();


	glColor3f(.8, .8, .8);
	glBegin(GL_POLYGON);
	glVertex2f(a + 500, 375);
	glVertex2f(a + 475, 425);
	glVertex2f(a + 300, 425);
	glVertex2f(a + 300, 50);
	glVertex2f(a + 500, 50);
	glVertex2f(a + 500, 375);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(a + 450, 350);
	glColor3f(0, 0, 0);
	glVertex2f(a + 450, 225);
	glColor3f(0, 0, 0);
	glVertex2f(a + 350, 225);
	glColor3f(0, 0, 0);
	glVertex2f(a + 350, 350);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex2f(a + 325, 150);
	glColor3f(0, 1, 0);
	glVertex2f(a + 400, 150);
	glColor3f(0, 0, 0);
	glVertex2f(a + 400, 125);
	glColor3f(1, 0, 0);
	glVertex2f(a + 360, 125);
	glColor3f(0, 1, 0);
	glVertex2f(a + 360, 140);
	glColor3f(0, 0, 0);
	glVertex2f(a + 325, 140);
	glColor3f(0, 0, 1);
	glVertex2f(a + 325, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.6, .6, .5);
	glVertex2f(a + 250, 350);
	glVertex2f(a + 50, 350);
	glVertex2f(a + 50, 225);
	glVertex2f(a + 250, 225);
	glEnd();

	glColor3f(.7, .3, .5);
	glBegin(GL_POLYGON);
	glVertex2f(a + 220, 330);
	glVertex2f(a + 70, 330);
	glVertex2f(a + 70, 245);
	glVertex2f(a + 220, 245);
	glEnd();

	glTranslated(x_t1, y_t1, 0);
	glRotated(theta, 0, 1, 0);
	glTranslated(-(x_t1), -(y_t1), 0);
	fan2();
	glPopMatrix();
	fan();

}

void helitimer(int v)
{
	x_heli -= 20;
	if (x_heli<-1400)x_heli = 1200;
	y_heli += 20;
	if (y_heli>380)y_heli = 380;
	theta += 150;
	if (theta>360)theta = 0;
	theta1 += 60;
	if (theta1>360)theta1 = 0;

	glutTimerFunc(105, helitimer, 20);
	glutPostRedisplay();

}

void display2()
{
	glClearColor(0.22, 0.69, 0.87, 0.1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cloud();//draw sky
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	helicopter();//fn to draw helicopter
	glPopMatrix();
	basketcourt();
	basket();//function to design basket platform
	displayname();//function to display player name
	displayboard();//function to display score remaining ball e.t.c
	if (flag_ovr == 1)dispgameover();

	glutSwapBuffers();
	//disp1();
	glFlush();
}
void mykey(unsigned char key, int x, int y)
{
	if (key == 27)exit(0);
}
void move(int x, int y)
{
	Ynn = 495 - y;
	Xnn = x - 675;
	xdist = Xnn - 675;//distance of base from left partof the windows to the now present postion of x value
	ydist = Ynn - Yn;//this is the distance between mouse click yn and move ynn
	rxy = (ydist / xdist);//ratio of perpendicular/base
	angle = atan(rxy);//{tan(Q)=y/x; so atan(y/x)=angle}
	angle = angle*(300 / 3.142);//changing in radian to degree
	printf("xdist=%f\tydist=%f\tangle=%f\n", xdist, ydist, angle);
	printf("xnn=%f,ynn=%f", Ynn, Xnn, Yn, Xn);
	if (flag_er == 1 || flag_er == 2)
	{
		calcu(Xn, Yn, angle);
	}
	glFlush();
}
void mymouse(int btn, int state, int x, int y)
{
	Yn = 495 - y;
	Xn = x - 675;
	printf("y_dec[100]=%f", y_dec);
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		printf("xn=%f\tyn=%f\n", Xn, Yn);
		if (flag_er == 1 || flag_er == 2)
			glutTimerFunc(90, mytimer, 20);
		if (Xn>-100 && Xn<100 && Yn>0 && Yn<500)
			noc -= 1;//decreamenting number of ball every click
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (Xn>-65 && Xn<140 && Yn>-30 && Yn<35)
			printf("hii");
		else if (Xn>-265 && Xn<-125 && Yn>-100 && Yn<-45){}
		else if (Xn>195 && Xn<320 && Yn>-100 && Yn<-45)
			exit(0);
	}
	glutPostRedisplay();
}
void menu(int d)
{
	switch (d)
	{
	case 1: flag_clr = 1;
		break;
	case 2: flag_clr = 2;
		break;
	case 3: flag_clr = 3;
		break;
	case 4:flag_clr = 0;
	}
	glutPostRedisplay();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-675, 675, -675, 675, -675, 675);
	glMatrixMode(GL_MODELVIEW);
}






/*****************************help for priest*************************************/
/*****************************help for basketball*************************************/
/*******************************credits page*******************************************/
char stri8[] = "RNS Institute of Technology";
char stri9[] = "PROJECT:    Priest With Demon    And    Basket Ball Game";
char stri13[] = "_________";
char name1[] = "KUMAR ANUBHAW";
char name2[] = "KUMAR VAIBHAW";
char name3[] = "RAVI RANJAN KUMAR";
void display_string(int x, int y, char *string, int font)
{
	int len, i;
	//glColor3f(0.6, 0.9, 0.2);
	glColor3f(0.6, 0.1, 0.2);
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		if (font == 1)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
		if (font == 2)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
		if (font == 3)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
		if (font == 4)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
	}

}
void display4(void)
{



	glClearColor(1.0, .5, 0.685, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	display_string(-400, 700, stri8, 1);
	display_string(-550, 600, stri9, 1);
	display_string(-200, 450, "CREDITS", 1);
	display_string(-200, 440, stri13, 1);
	display_string(-300, 200, name1, 1);
	display_string(-300, 00, name2, 1);
	display_string(-300, -200, name3, 1);
	glFlush();
}
void fpage3(void)
{
	display4();
	/*if (flag == 1)
	{
	display2();
	}*/
	glFlush();
}
/*************************control for priest*********************************************/
/*************************control for priest*********************************************/
//char str[] = "RNS Institute of Technology";
//char str1[] = "PROJECT :    Priest With Demon    And    Basket Ball Game";
//char stri13[] = "__________";
char boat1[] = "TO MOVE BOAT";
char control1[] = "Left Move-----------------------------------------------Left Arrow Key";
char control2[] = "Right Move----------------------------------------------Right Arrow Key";
char boat2[] = "BOAT AT RIGHT POSITION";
char priest2[] = "TO LOAD UNLOAD PRIEST";
char control3[] = "Load And Unload-----------------------------------------Mouse Left Button";
char demon2[] = "TO LOAD UNLOAD DEMON";
char control4[] = "Load And Unlaod-----------------------------------------Mouse Left Button";
char boat3[] = "BOAT AT LEFT POSITION";
char priest1[] = "TO LOAD UNLOAD PRIEST";
char control5[] = "Load And Unload-----------------------------------------Mouse Right Button";
char demon1[] = "TO LOAD UNLOAD DEMON";
char control6[] = "Load And Unlaod-----------------------------------------Mouse Right Button";
void display(void)
{



	glClearColor(1.0, .5, 0.685, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	display_string(-400, 700, stri8, 1);
	display_string(-450, 600, stri9, 1);
	display_string(0, 450, "CONTROLS", 1);
	display_string(0, 440, stri13, 1);
	display_string(-700, 300, boat1, 2);
	display_string(-700, 250, control1, 2);
	display_string(-700, 200, control2, 2);
	display_string(-200, 100, boat2, 2);
	display_string(-700, 0, priest2, 2);
	display_string(-700, -50, control3, 2);
	display_string(-700, -150, demon2, 2);

	display_string(-700, -200, control4, 2);
	display_string(-200, -300, boat3, 2);
	display_string(-700, -400, priest1, 2);

	display_string(-700, -450, control5, 2);
	display_string(-700, -550, demon1, 2);

	display_string(-700, -600, control6, 2);

	
	glFlush();
}
void fpage1(void)
{
	display();
	/*if (flag == 1)
	{
	display2();
	}*/
	glFlush();
}
/*****************************main page************************************/
//char str8[] = "RNS Institute of Technology";
//char str9[] = "Priest and Demon";
char stri10[] = "Basket Ball";
char stri11[] = "______________";
char stri12[] = "_________";
char name[] = "PROJECT :    Priest With Demon    And    Basket Ball Game";
char menu5[50] = "1.PLAY GAME";
char menu1[] = "2.CONTROLS";
char menu2[] = "3.HELP";
char menu3[] = "4.CREDITS";
char menu4[] = "5.QUIT";
void polygon(int x, int y, int a, int b)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + a, y);
	glVertex2f(x + a, y + b);
	glVertex2f(x, y + b);
	glEnd();
}
void polygon1(int x, int y, int a, int b)
{
	glColor3f(1.0, .5, 0.685);
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + a, y);
	glVertex2f(x + a, y + b);
	glVertex2f(x, y + b);
	glEnd();
}
void mouse1(int btn, int state, int x, int y)
{

	x = x - 300;
	y = 400 - y;
	printf("x=%d,y=%d", x, y);
 /*****************side button creation**********************************/ 
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (x > -100 && x<60 && y>65 && y < 100)
		{
			polygon(-1200, 140, 320, 60);
			display_string(-1200, 150, menu5, 1);
		}
		if (x > -100 && x<45 && y>20 && y <50)
		{
			polygon(-1200, 30, 320, 60);
			display_string(-1200, 50, menu1, 1);
		}
		if (x > -100 && x<-25 && y>-30 && y <-5)
		{
			polygon(-1200, -65, 190, 60);
			display_string(-1200, -50, menu2, 1);
		}
		if (x > -100 && x<40 && y>-75 && y <-50)
		{
			polygon(-1200, -165, 270, 60);
			display_string(-1200, -150, menu3, 1);
		}
		if (x > -110 && x<-20 && y>-130 && y <-110)
		{
			polygon(-1200, -265, 190, 60);
			display_string(-1200, -250, menu4, 1);
		}



		/************************left side button elimination******************************************/

		if (x > 890 && x<1065 && y>65 && y < 100)
		{
			polygon(800, 140, 320, 60);
			display_string(800, 150, menu5, 1);
		}
		if (x > 890 && x<1065 && y>20 && y <50)
		{
			polygon(800, 30, 320, 60);
			display_string(800, 50, menu1, 1);
		}
		if (x > 890 && x<1000 && y>-30 && y <-5)
		{
			polygon(800, -65, 190, 60);
			display_string(800, -50, menu2, 1);
		}
		if (x > 890 && x<1050 && y>-75 && y <-50)
		{
			polygon(800, -165, 270, 60);
			display_string(800, -150, menu3, 1);
		}
		if (x > 890 && x<1000 && y>-130 && y <-110)
		{
			polygon(800, -265, 190, 60);
			display_string(800, -250, menu4, 1);
		}
	}
	/******************************right side buttom creation************************************/
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (x > -100 && x<60 && y>65 && y < 100)
		{

			polygon1(-1200, 140, 320, 60);
			display_string(-1200, 150, menu5, 1);
			display1();
		}
		if (x > -100 && x<45 && y>20 && y <50)
		{

			polygon1(-1200, 30, 320, 60);
			display_string(-1200, 50, menu1, 1);
			fpage1();// control page
		}
		if (x > -100 && x<-25 && y>-30 && y <-5)
		{

			polygon1(-1200, -65, 190, 60);
			display_string(-1200, -50, menu2, 1);
			//fpage2();//help page
		}
		if (x > -100 && x<40 && y>-75 && y <-50)
		{

			polygon1(-1200, -165, 270, 60);
			display_string(-1200, -150, menu3, 1);
			fpage3();//credit page
		}
		if (x > -110 && x<-20 && y>-130 && y <-110)
		{

			polygon1(-1200, -265, 190, 60);
			display_string(-1200, -250, menu4, 1);
			exit(0);
		}


		/***************************right side buttom eliminition****************************************/
		if (x > 890 && x<1065 && y>65 && y < 100)
		{

			polygon1(800, 140, 320, 60);
			display_string(800, 150, menu5, 1);
			display2();// basket ball fun
		}
		if (x > 890 && x<1065 && y>20 && y <50)
		{

			polygon1(800, 30, 320, 60);
			display_string(800, 50, menu1, 1);
			//fpage4();//contro for basket
		}
		if (x > 890 && x<1000 && y>-30 && y <-5)
		{

			polygon1(800, -65, 190, 60);
			display_string(800, -50, menu2, 1);
			//fpage5();//help basket
		}
		if (x > 890 && x<1050 && y>-75 && y <-50)
		{

			polygon1(800, -165, 270, 60);
			display_string(800, -150, menu3, 1);
			fpage3();//credits
		}
		if (x > 890 && x<1000 && y>-130 && y <-110)
		{

			polygon1(800, -265, 190, 60);
			display_string(800, -250, menu4, 1);
			exit(0);
		}




	}

}
			

void display3(void)
{



	glClearColor(1.0, .5, 0.685, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	display_string(-400, 700, stri8, 1);
	display_string(-450, 600, name, 1);
	display_string(0, 450, "MENU", 1);
	display_string(-1200, 300, stri9, 1);
	display_string(-1200, 280, stri11, 1);
	display_string(800, 300, stri10, 1);
	display_string(800, 280, stri12, 1);
	display_string(-1200, 150, menu5, 1);
	display_string(-1200, 50, menu1, 1);
	display_string(-1200, -50, menu2, 1);
	display_string(-1200, -150, menu3, 1);
	display_string(-1200, -250, menu4, 1);
	display_string(800, 150, menu5, 1);
	display_string(800, 50, menu1, 1);
	display_string(800, -50, menu2, 1);
	display_string(800, -150, menu3, 1);
	display_string(800, -250, menu4, 1);
	glFlush();
}
void disp5(void)
{

	display3();

	glFlush();
}
void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w>h)
		gluOrtho2D(-800 * (GLfloat)w / (GLfloat)h, 800 * (GLfloat)w / (GLfloat)h, -800, 800);
	else
		gluOrtho2D(-800, 800, -800 * (GLfloat)h / (GLfloat)w, 800 * (GLfloat)h / (GLfloat)w);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1600, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("print");
	glutReshapeFunc(myreshape);

	glutDisplayFunc(disp5);
	glutMouseFunc(mouse1);
	glutMainLoop();
	return 1;
}
