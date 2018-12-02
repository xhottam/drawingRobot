#pragma once

#include <QtWidgets/QMainWindow>
#include <QFileDialog>
#include "ui_DrawingRobot.h"
#include "QT_Dynamixel.h"
#include <complex>
#include "SerialPort.h"
#include "Dynamixel.h"

static SerialPort *_serial;
static int _handPosition;
static bool _paths;

class DrawingRobot : public QMainWindow
{
	Q_OBJECT

public:
	DrawingRobot(QWidget *parent = Q_NULLPTR);
	bool setMovAbs(int hombro, int codo, bool difference);
	

private:
	Ui::DrawingRobotClass ui;
	QGraphicsScene  *scene = new QGraphicsScene();

	QAction *paint = new QAction();
	QAction *simulate = new QAction();
	QAction *run = new QAction();

	QAction *paintAll = new QAction();
	QAction *simulateAll = new QAction();
	QAction *runAll = new QAction();

	void showBeizer(int index, int row);
	void paintBeizer(int index, int row);
	void paintBeizer(int index);

	void runDegrees(int index, int row);
	void runDegrees(int index);

	void setScene();
	void addSceneEllipse(qreal x, qreal y);

	
public slots:
	void on_fileOpen_clicked();
	void on_actionExit_clicked();
	void on_dynamixelOpen_clicked();
	void action_Paint_clicked();
	void action_Simulate_clicked();
	void action_Run_clicked();
	void action_PaintALL_clicked();
	void action_SimulateALL_clicked();
	void action_RunALL_clicked();
	void on_treeView_clicked();
	void onCustomContextMenu(const QPoint &);
	void onDynamixelReady(bool, SerialPort &,int);
};
