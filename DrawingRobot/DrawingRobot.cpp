#include "DrawingRobot.h"
#include "QStandardItemModel"
#include "svg.h"
#include "oglwidget.h"



DrawingRobot::DrawingRobot(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.graphicsView->scale(0.5, -0.5);	
	
	paint->setText(QString("Paint"));
	connect(paint, SIGNAL(triggered()), this, SLOT(action_Paint_clicked()));
	simulate->setText(QString("Simulate"));
	connect(simulate, SIGNAL(triggered()), this, SLOT(action_Simulate_clicked()));
	run->setText(QString("Run"));
	connect(run, SIGNAL(triggered()), this, SLOT(action_Run_clicked()));
	
	paintAll->setText(QString("PaintALL"));
	connect(paintAll, SIGNAL(triggered()), this, SLOT(action_PaintALL_clicked()));
	simulateAll->setText(QString("SimulateALL"));
	connect(simulateAll, SIGNAL(triggered()), this, SLOT(action_SimulateALL_clicked()));
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
		paintAll->setEnabled(true);
		simulateAll->setEnabled(true);
		runAll->setEnabled(true);
	}else {
		paint->setEnabled(true);
		simulate->setEnabled(true);
		run->setEnabled(true);
		paintAll->setEnabled(false);
		simulateAll->setEnabled(false);
		runAll->setEnabled(false);
	}
	

	
	menu->exec(QCursor::pos());
}

void DrawingRobot::onDynamixelReady(bool connected, SerialPort &serial)
{
	if (connected) {
		_serial = &serial;
		int moving = dynamixel.dxl_read_byte(_serial, 1, Dynamixel::AXM_MOVING);
		
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
					Sleep(5);
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
					
				}
			}	
		}		
	}

}

void DrawingRobot::action_SimulateALL_clicked()
{
}

void DrawingRobot::action_RunALL_clicked()
{
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
	}
	else {
		TRACE(<< "path : index " << index.row() << std::endl);
	}
}

void DrawingRobot::on_actionExit_clicked() {
	this->close();
}


void DrawingRobot::on_dynamixelOpen_clicked() {
	Qt_Dynamixel qtDynamixel(this);
	//Qt_Dynamixel *qtDynamixel = new Qt_Dynamixel();
	connect(&qtDynamixel,SIGNAL(onDynamixelReady_signal(bool,SerialPort & )), this,SLOT(onDynamixelReady(bool, SerialPort &)));
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
		//ui.treeView->show();
	}
	
}