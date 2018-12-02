#include "DrawingRobot.h"
#include "QStandardItemModel"
#include "svg.h"
#include "oglwidget.h"
#include <iostream>


DrawingRobot::DrawingRobot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	_serial = new SerialPort();
	_paths = false;

	ui.graphicsView->scale(0.5, -0.5);	
	
	//
	paint->setText(QString("Paint"));
	connect(paint, SIGNAL(triggered()), this, SLOT(action_Paint_clicked()));
	//simulate->setEnabled(false);
	simulate->setText(QString("Simulate"));
	connect(simulate, SIGNAL(triggered()), this, SLOT(action_Simulate_clicked()));
	//run->setEnabled(false);
	run->setText(QString("Run"));
	connect(run, SIGNAL(triggered()), this, SLOT(action_Run_clicked()));
	
	//paintAll->setEnabled(false);
	paintAll->setText(QString("PaintALL"));
	connect(paintAll, SIGNAL(triggered()), this, SLOT(action_PaintALL_clicked()));
	//simulateAll->setEnabled(false);
	simulateAll->setText(QString("SimulateALL"));
	connect(simulateAll, SIGNAL(triggered()), this, SLOT(action_SimulateALL_clicked()));
	//runAll->setEnabled(false);
	runAll->setText(QString("RunALL"));
	connect(runAll, SIGNAL(triggered()), this, SLOT(action_RunALL_clicked()));
	
	//ui.treeView->hide();
	ui.treeView->setContextMenuPolicy(Qt::CustomContextMenu);

	//ui.listWidget->hide();
	//ui.listWidget_2->hide();
	//ui.listWidget_3->hide();

	connect(ui.fileOpen, SIGNAL(triggered()),this, SLOT(on_fileOpen_clicked()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(on_actionExit_clicked()));
	connect(ui.dynamixelOpen, SIGNAL(triggered()), this, SLOT(on_dynamixelOpen_clicked()));

	//connect(ui.treeView, SIGNAL(clicked(QModelIndex)), SLOT(on_treeView_clicked()));
	connect(ui.treeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));

	

}

void DrawingRobot::on_treeView_clicked() {
	QModelIndex index = ui.treeView->currentIndex();
	if (index.parent().isValid()) {
		TRACE(<< "path : index " << index.parent().row() << " child:row " << index.row() << " child:column " << index.column() << std::endl);	
		showBeizer(index.parent().row(), index.row());
	}else {
		TRACE(<< "meando fuera del tiesto" << std::endl);
	}
}

void DrawingRobot::onCustomContextMenu(const QPoint &point) {	
	
	QMenu *menu = new QMenu;
	QModelIndex index = ui.treeView->indexAt(point);

	menu->addAction(paint);
	menu->addAction(paintAll);
	menu->addAction(simulate);
	menu->addAction(simulateAll);
	menu->addAction(run);	
	menu->addAction(runAll);	


	if (index.row() == -1 && index.column() == -1) {
		paint->setEnabled(false);
		simulate->setEnabled(false);
		run->setEnabled(false);
		(_paths)?paintAll->setEnabled(true):paintAll->setEnabled(false);
		(_paths)?simulateAll->setEnabled(true):simulateAll->setEnabled(false);
		(_serial->_connect)?runAll->setEnabled(true): runAll->setEnabled(false);
	}else {
		(_paths)?paint->setEnabled(true):paint->setEnabled(false);
		(_paths)?simulate->setEnabled(true): simulate->setEnabled(false);
		(_serial->_connect)?run->setEnabled(true): run->setEnabled(false);
		paintAll->setEnabled(false);
		simulateAll->setEnabled(false);
		runAll->setEnabled(false);
	}
	

	
	menu->exec(QCursor::pos());
}

void DrawingRobot::onDynamixelReady(bool connected, SerialPort &serial,int handPosition)
{
	std::cout << "onDynamixelReady" << std::endl;
	if (connected) {
		_serial = &serial;
		_handPosition = handPosition;
		//int moving = dynamixel.dxl_read_byte(_serial, 1, Dynamixel::AXM_MOVING);
		//dynamixel.readControlTable(_serial, 1);		
	}
	
}


void DrawingRobot::showBeizer(int index, int row)
{
	ui.listWidget->clear();
	ui.listWidget_2->clear();
	ui.listWidget_3->clear();
	

	auto it = svg::_paths.paths.begin();
	std::advance(it, index);

	auto _it = (it._Ptr->_Myval._beizer.begin());
    std::advance(_it, row);

	for (auto __it = _it._Ptr->_Myval.coordinates.begin(); __it != _it._Ptr->_Myval.coordinates.end(); __it++) {
		for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
			QListWidgetItem *child = new QListWidgetItem(QString("%1|%2").arg(___it._Ptr->_Myval.x).arg(___it._Ptr->_Myval.y));
			ui.listWidget->addItem(child);
		}
	}
	for (auto __it = _it._Ptr->_Myval.degrees.begin(); __it != _it._Ptr->_Myval.degrees.end(); __it++) {
		for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
			QListWidgetItem *child = new QListWidgetItem(QString("%1|%2").arg(___it._Ptr->_Myval.x).arg(___it._Ptr->_Myval.y));
			ui.listWidget_2->addItem(child);
		}
	}

	for (auto __it = _it._Ptr->_Myval.angles.begin(); __it != _it._Ptr->_Myval.angles.end(); __it++) {
		for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
			QListWidgetItem *child = new QListWidgetItem(QString("%1|%2").arg(___it._Ptr->_Myval.x).arg(___it._Ptr->_Myval.y));
			ui.listWidget_3->addItem(child);
		}
	}

	//ui.listWidget->show();
	//ui.listWidget_2->show();
	//ui.listWidget_3->show();


}

void DrawingRobot::action_Paint_clicked()
{
	QModelIndex index = ui.treeView->currentIndex();
	if (index.parent().isValid()) {
		TRACE(<< "path : index " << index.parent().row() << " child:row " << index.row() << " child:column " << index.column() << std::endl);
		paintBeizer(index.parent().row(), index.row());
	}
	else {
		TRACE(<< "path : index " << index.row() << std::endl);
		paintBeizer(index.row());
	}

}

void DrawingRobot::action_Simulate_clicked()
{
	QModelIndex index = ui.treeView->currentIndex();
	if (index.parent().isValid()) {
		TRACE(<< "path : index " << index.parent().row() << " child:row " << index.row() << " child:column " << index.column() << std::endl);
		
		auto it = svg::_paths.paths.begin();
		std::advance(it, index.parent().row());

		auto _it = (it._Ptr->_Myval._beizer.begin());
		std::advance(_it, index.row());

		for (auto __it = _it._Ptr->_Myval.angles.begin(); __it != _it._Ptr->_Myval.angles.end(); __it++) {
			for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
				ui.openGLWidget->setViewAngles(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y);
				Sleep(8);
			}
		}

		
	}
	else {
		TRACE(<< "path : index " << index.row() << std::endl);
		
		auto it = svg::_paths.paths.begin();
		std::advance(it, index.row());
	
		for (auto _it = it._Ptr->_Myval._beizer.begin(); _it != it._Ptr->_Myval._beizer.end(); _it++) {
			for (auto __it = _it._Ptr->_Myval.angles.begin(); __it != _it._Ptr->_Myval.angles.end(); __it++) {
				for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
					//DrawingRobot::addSceneEllipse(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y);
					ui.openGLWidget->setViewAngles(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y);
					Sleep(8);
				}
			}
		}
	}
}
void DrawingRobot::paintBeizer(int index, int row)
{
	DrawingRobot::setScene();
		
	auto it = svg::_paths.paths.begin();
	std::advance(it, index);

	auto _it = (it._Ptr->_Myval._beizer.begin());
	std::advance(_it, row);
	
	for (auto __it = _it._Ptr->_Myval.coordinates.begin(); __it != _it._Ptr->_Myval.coordinates.end(); __it++) {
		for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
			DrawingRobot::addSceneEllipse(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y);			
		}
	}

}

void DrawingRobot::paintBeizer(int index)
{
	DrawingRobot::setScene();
	auto it = svg::_paths.paths.begin();
	std::advance(it, index);


	for (auto _it = it._Ptr->_Myval._beizer.begin(); _it != it._Ptr->_Myval._beizer.end(); _it++) {
		for (auto __it = _it._Ptr->_Myval.coordinates.begin(); __it != _it._Ptr->_Myval.coordinates.end(); __it++) {
			for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
				DrawingRobot::addSceneEllipse(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y);				
			}			
		}
	}

}

void DrawingRobot::action_PaintALL_clicked()
{
	DrawingRobot::setScene();
	

	for (auto _it = svg::_paths.paths.begin(); _it != svg::_paths.paths.end(); _it++) {
		for (auto __it = _it._Ptr->_Myval._beizer.begin(); __it != _it._Ptr->_Myval._beizer.end(); __it++) {
			for (auto ___it = __it._Ptr->_Myval.coordinates.begin(); ___it != __it._Ptr->_Myval.coordinates.end(); ___it++) {
				for (auto ____it = ___it._Ptr->_Myval.coordinate.begin(); ____it != ___it._Ptr->_Myval.coordinate.end(); ____it++) {
					//OGLWidget::setViewAngles(____it._Ptr->_Myval.x, ____it._Ptr->_Myval.y);
					DrawingRobot::addSceneEllipse(____it._Ptr->_Myval.x, ____it._Ptr->_Myval.y);
				}
			}	
		}		
	}

}

void DrawingRobot::action_SimulateALL_clicked()
{
	for (auto _it = svg::_paths.paths.begin(); _it != svg::_paths.paths.end(); _it++) {
		for (auto __it = _it._Ptr->_Myval._beizer.begin(); __it != _it._Ptr->_Myval._beizer.end(); __it++) {
			for (auto ___it = __it._Ptr->_Myval.angles.begin(); ___it != __it._Ptr->_Myval.angles.end(); ___it++) {
				for (auto ____it = ___it._Ptr->_Myval.coordinate.begin(); ____it != ___it._Ptr->_Myval.coordinate.end(); ____it++) {
					ui.openGLWidget->setViewAngles(____it._Ptr->_Myval.x, ____it._Ptr->_Myval.y);
					Sleep(8);
				}
			}
		}
	}
}

void DrawingRobot::action_RunALL_clicked()
{
	

	for (auto _it = svg::_paths.paths.begin(); _it != svg::_paths.paths.end(); _it++) {
		//MOVE_ABS
		bool move = true;
		dynamixel.penUP(_serial, _handPosition);
		for (auto __it = _it._Ptr->_Myval._beizer.begin(); __it != _it._Ptr->_Myval._beizer.end(); __it++) {
			while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
			for (auto ___it = __it._Ptr->_Myval.degrees.begin(); ___it != __it._Ptr->_Myval.degrees.end(); ___it++) {
				for (auto ____it = ___it._Ptr->_Myval.coordinate.begin(); ____it != ___it._Ptr->_Myval.coordinate.end(); ____it++) {
					//MOVE_ABS
					if (move) {
						move = setMovAbs(____it._Ptr->_Myval.x, ____it._Ptr->_Myval.y, ____it._Ptr->_Myval.difference);
					}else {
						//dynamixel.moveDrawingArm(_serial, ____it._Ptr->_Myval.x, ____it._Ptr->_Myval.y, ____it._Ptr->_Myval.difference);
						dynamixel.moveDrawingArm(_serial, ____it._Ptr->_Myval.interpolateX, ____it._Ptr->_Myval.interpolateY, ____it._Ptr->_Myval.difference);
						Sleep(33);					
					}
				}
			}
		}
	}
	while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
	dynamixel.penUP(_serial, _handPosition);
}

bool DrawingRobot::setMovAbs(int hombro, int codo, bool difference) {
	dynamixel.dxl_write_word(_serial, 1, Dynamixel::AXM_MOVING_SPEED_L, 150);
	dynamixel.dxl_write_word(_serial, 2, Dynamixel::AXM_MOVING_SPEED_L, 150);
	dynamixel.dxl_write_byte(_serial, 1, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, 32);
	dynamixel.dxl_write_byte(_serial, 1, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, 32);
	dynamixel.dxl_write_byte(_serial, 2, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, 32);
	dynamixel.dxl_write_byte(_serial, 2, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, 32);
	Sleep(200);
	dynamixel.moveDrawingArm(_serial, hombro, codo, difference);
	while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {};	
	dynamixel.penDown(_serial, _handPosition);
	dynamixel.dxl_write_word(_serial, 1, Dynamixel::AXM_MOVING_SPEED_L, 0);
	dynamixel.dxl_write_word(_serial, 2, Dynamixel::AXM_MOVING_SPEED_L, 0);
	dynamixel.dxl_write_byte(_serial, 1, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, 64);
	dynamixel.dxl_write_byte(_serial, 1, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, 64);
	dynamixel.dxl_write_byte(_serial, 2, Dynamixel::AXM_CW_COMPLIANCE_SLOPE, 64);
	dynamixel.dxl_write_byte(_serial, 2, Dynamixel::AXM_CCW_COMPLIANCE_SLOPE, 64);
	return false;
}

void DrawingRobot::setScene()
{
	scene->clear();
	ui.graphicsView->setScene(scene);
	scene->setSceneRect(-150, 150, 300, -300);
	scene->addLine(-300, 0, 300, 0, QPen(Qt::red, 2));
	scene->addLine(0, 300, 0, -300, QPen(Qt::red, 2));
	//,r2=|l1-l2|, OJO ui.graphicsView->scale(0.5, -0.5);
	scene->addEllipse(-88.0, -88.0, 176.0, 176.0, QPen(Qt::red, 2));
	scene->addEllipse(-88.0, -88.0, 176.0, 176.0, QPen(Qt::red, 2));
	scene->addEllipse(-300, -300, 600, 600, QPen(Qt::red, 2));
}

void DrawingRobot::addSceneEllipse(qreal x, qreal y)
{
	scene->addEllipse(x, y, .05, .05, QPen(Qt::black), QBrush(Qt::SolidPattern));
}

void DrawingRobot::action_Run_clicked()
{
	QModelIndex index = ui.treeView->currentIndex();
	if (index.parent().isValid()) {
		TRACE(<< "path : index " << index.parent().row() << " child:row " << index.row() << " child:column " << index.column() << std::endl);
		runDegrees(index.parent().row(), index.row());
	}
	else {
		TRACE(<< "path : index " << index.row() << std::endl);
		runDegrees(index.row());
	}
}

void DrawingRobot::runDegrees(int index, int row) {
	
	auto it = svg::_paths.paths.begin();
	std::advance(it, index);
	auto _it = (it._Ptr->_Myval._beizer.begin());
	std::advance(_it, row);

	//MOVE_ABS
	dynamixel.penUP(_serial, _handPosition);
	bool move = true;
	
	for (auto __it = _it._Ptr->_Myval.degrees.begin(); __it != _it._Ptr->_Myval.degrees.end(); __it++) {
		for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
			//MOVE_ABS
			if (move){
				move = setMovAbs(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y, ___it._Ptr->_Myval.difference);
			}else {
				dynamixel.moveDrawingArm(_serial, ___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y, ___it._Ptr->_Myval.difference);
			}
			//while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
		}
	}
	while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
	dynamixel.penUP(_serial, _handPosition);
}
void DrawingRobot::runDegrees(int index) {
	
	DrawingRobot::setScene();
	
	auto it = svg::_paths.paths.begin();
	std::advance(it, index);
	
	//MOVE_ABS
	bool move = true;
	dynamixel.penUP(_serial, _handPosition);

	for (auto _it = it._Ptr->_Myval._beizer.begin(); _it != it._Ptr->_Myval._beizer.end(); _it++) {
		while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
		for (auto __it = _it._Ptr->_Myval.degrees.begin(); __it != _it._Ptr->_Myval.degrees.end(); __it++) {
			for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
				//MOVE_ABS
				if (move) {
					move = setMovAbs(___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y, ___it._Ptr->_Myval.difference);					
				}
				else {
					//dynamixel.moveDrawingArm(_serial, ___it._Ptr->_Myval.x, ___it._Ptr->_Myval.y, ___it._Ptr->_Myval.difference);
					dynamixel.moveDrawingArm(_serial, ___it._Ptr->_Myval.interpolateX, ___it._Ptr->_Myval.interpolateY, ___it._Ptr->_Myval.difference);
					Sleep(33);
				}
			}
		}
	}
	while (dynamixel.isMoving(_serial, 1) || dynamixel.isMoving(_serial, 2)) {}
	dynamixel.penUP(_serial, _handPosition);
}

void DrawingRobot::on_actionExit_clicked() {
	this->close();
}


void DrawingRobot::on_dynamixelOpen_clicked() {
	Qt_Dynamixel qtDynamixel(this);
	//Qt_Dynamixel *qtDynamixel = new Qt_Dynamixel();
	connect(&qtDynamixel,SIGNAL(onDynamixelReady_signal(bool,SerialPort &,int )), this,SLOT(onDynamixelReady(bool, SerialPort &,int)));
	qtDynamixel.exec();
	
}

void DrawingRobot::on_fileOpen_clicked() {

	
	QString fileName = QFileDialog::getOpenFileName(this, ("Open File"),"",("Images (*.svg)"));
		
	if (fileName != "") {
		
		auto dom = svgdom::load(papki::FSFile(fileName.toStdString()));		
		ASSERT_ALWAYS(dom);
		ASSERT_ALWAYS(dom->children.size() != 0);
		//reseteo todos los paths  que se intente abrir un fichero
		svg::_paths.paths.clear();
		ui.listWidget->clear();
		ui.listWidget_2->clear();
		ui.listWidget_3->clear();
		ui.treeView->setModel(nullptr);

		dom->accept(svg::visitor);

		QStandardItemModel* model = new QStandardItemModel();
		
		for (auto it = svg::_paths.paths.begin(); it != svg::_paths.paths.end(); it++) {	
			QStandardItem* item = new QStandardItem();
			item->setEditable(false);
			for (auto _it = it._Ptr->_Myval.type.begin(); _it != it._Ptr->_Myval.type.end(); _it++) {
				QStandardItem* child = new QStandardItem(_it._Ptr->_Myval.data());
				
				//index del tipo para recuperrar las coordenas del fichero svg.
				int index = std::distance(it._Ptr->_Myval.type.begin(), _it);
				auto __it = it._Ptr->_Myval.coordinates.begin(); 
				std::advance(__it, index);				
				std::string tooltip = "x=";
				for (auto ___it = __it._Ptr->_Myval.coordinate.begin(); ___it != __it._Ptr->_Myval.coordinate.end(); ___it++) {
					tooltip = tooltip + std::to_string(___it._Ptr->_Myval.x) + " y=" + std::to_string(___it._Ptr->_Myval.y)+ " |";
				}

				child->setToolTip(QString::fromStdString(tooltip));
				child->setEditable(false);
				item->appendRow(child);
			}
			item->setText(it._Ptr->_Myval.path_id.data());
			model->appendRow(item);				
		}
		model->setHeaderData(0, Qt::Horizontal, "Paths");
		ui.treeView->setModel(model);

		_paths = true;
		//ui.treeView->show();
	}
	
}