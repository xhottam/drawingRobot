#include "DrawingRobot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DrawingRobot w;
	w.show();
	return a.exec();
}
