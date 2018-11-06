#include "oglwidget.h"
#include <iostream>

OGLWidget::OGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	shoulderRotation = 150;
	elbowRotation  = 150;
	shoulderRotation = map(shoulderRotation, 0, 300, -150, 150);
	elbowRotation    = map(elbowRotation, 0, 300, -150,150);
	//174.78|31.085
	//173.9|40.4692
}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::setViewAngles(float _shoulderRotation, float _elbowRotation)
{

	shoulderRotation = map(_shoulderRotation,0,300,-150,150);
	elbowRotation = map(_elbowRotation, 0, 300, -150, 150);

	this->repaint();
	
	//TODO redraw now?
}

void OGLWidget::initializeGL()
{
	
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);//white
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	//glEnable(GL_LIGHT0);
	//glEnable(GL_LIGHTING);
	//glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	//glEnable(GL_COLOR_MATERIAL);
}

void OGLWidget::draw() {

	std::cout << shoulderRotation << std::endl;
	std::cout << elbowRotation << std::endl;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	
	glPushMatrix();
		glLineWidth(1.0);
		glTranslatef(0.0, 0.0, 0.0);
		setScene();
	glPopMatrix();

	
	glLineWidth(2.0);
	glPointSize(5);

	//shoulder
	glTranslatef(0.0, 0.0, 0.0);
	glRotated(shoulderRotation, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix();
		glBegin(GL_POINTS);
			glColor3f(0.1f, 0.0f, 0.1f);
			glVertex2f(0.0, 0.0);
		glEnd();
			glBegin(GL_LINES);
			glColor3f(0.0, 0.0, 1.0);//blue	
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, 0.3292307692307692);
		glEnd();
		glBegin(GL_POINTS);
			glColor3f(0.1f, 0.0f, 0.1f);
			glVertex2f(0.0, 0.3292307692307692);
		glEnd();
	glPopMatrix();

	//elbow
	glTranslatef(0.0, 0.3292307692307692, 0.0);
	glRotated(elbowRotation, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.0, 0.0);

	glPushMatrix();
		glBegin(GL_LINES);
			glColor3f(0.0f, 1.0f, 0.0f);//green
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.6, 0.0);
		glEnd();
	glPopMatrix();
	
}

void OGLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	OGLWidget::draw();
		
}

/**void OGLWidget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x = GLfloat(width) / height;
	//GLfloat x = 10;
	glFrustum(-x, x, -x, x, 8, 20);
	glMatrixMode(GL_MODELVIEW);
}*/

void OGLWidget::DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle 

		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 

		glVertex2f(x + cx, y + cy);//output vertex 

	}
	glEnd();;
}

void OGLWidget::setScene()
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, 0.9230769230769231);
	glVertex2f(0, -0.9230769230769231);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-0.9230769230769231, 0);
	glVertex2f(0.9230769230769231, 0);
	glEnd();
	DrawCircle(0, 0, 0.9230769230769231, 50);
	DrawCircle(0, 0, 0.2707692307692308, 50);
}

long OGLWidget::map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
