#pragma once
#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include "..\Dependencies\freeglut\GL\glut.h"
#include "..\Dependencies\freeglut\GL\freeglut.h"

constexpr auto _PI= 3.14159265;

class OGLWidget : public QOpenGLWidget
{
public:
	
	OGLWidget(QWidget *parent = 0);
	~OGLWidget();
	
	void OGLWidget::setViewAngles(float _shoulderRotation, float _elbowRotation);
	

protected:
	void initializeGL();
	//void resizeGL(int w, int h);
	void paintGL();
private:
	 GLfloat shoulderRotation;
	 GLfloat elbowRotation;

	void OGLWidget::draw();
	void DrawCircle(float cx, float cy, float r, int num_segments);
	void setScene();
	long OGLWidget::map(long x, long in_min, long in_max, long out_min, long out_max);
};

#endif // OGLWIDGET_H
