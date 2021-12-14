#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pWindow = new QHalconWindow(ui->view,ui->view->width(),ui->view->height());
    m_pWindow->GetHalconBuffer()->SetColored(12);
    QString PicPath=QCoreApplication::applicationDirPath()+"/image.bmp";
    std::string Str=PicPath.toStdString();
    ReadImage(&ho_Image, Str.c_str());
    GetImageSize(ho_Image, &hv_ImageWidth, &hv_ImageHeight);
    m_pWindow->GetHalconBuffer()->SetPart(0,0,hv_ImageHeight[0].I()-1,hv_ImageWidth[0].I()-1);
    m_pWindow->GetHalconBuffer()->DispObj(ho_Image);
    m_pWindow->GetHalconBuffer()->FlushBuffer();
    ui->tableWidget->setRowCount(4);
    ui->tableWidget->setColumnCount(4);
    for(int row=1;row<ui->tableWidget->rowCount();row++){
        for(int column=1;column<ui->tableWidget->columnCount();column++){
            ui->tableWidget->setItem(row,column,new QTableWidgetItem());

          ui->tableWidget->item(row,column)->setTextAlignment(Qt::AlignCenter);
        }
    }
    ui->tableWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

