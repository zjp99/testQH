#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "HalconCpp.h"
#include <QFileDialog>

#  include "HDevEngineCpp.h"
#  include "HDevThread.h"

#include "qhalconwindow.h"

using namespace HDevEngineCpp;
using namespace HalconCpp;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QHalconWindow *m_pWindow;
    HObject ho_Image;
    HTuple hv_ImageWidth,hv_ImageHeight;

};
#endif // MAINWINDOW_H
