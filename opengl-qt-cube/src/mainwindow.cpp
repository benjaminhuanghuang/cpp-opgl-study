#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qt3dwavefrontobject.h"
#include <OpenGL/gl.h>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->matrixModeComboBox->addItem("MODELVIEW", GL_MODELVIEW);
    ui->matrixModeComboBox->addItem("PROJECTION", GL_PROJECTION);
    ui->matrixModeComboBox->addItem("TEXTURE", GL_TEXTURE);
    ui->matrixModeComboBox->setCurrentText("PROJECTION");

    ui->backgroundComboBox->setCurrentColor(Qt::black);

    ui->xScale_doubleSpinBox->setLocale(QLocale(QLocale::English));
    ui->yScale_doubleSpinBox->setLocale(QLocale(QLocale::English));
    ui->zScale_doubleSpinBox->setLocale(QLocale(QLocale::English));
    ui->xScale_doubleSpinBox->setRange(0.0, std::numeric_limits<float>::max());
    ui->yScale_doubleSpinBox->setRange(0.0, std::numeric_limits<float>::max());
    ui->zScale_doubleSpinBox->setRange(0.0, std::numeric_limits<float>::max());
    ui->xScale_doubleSpinBox->setValue(0.1);
    ui->yScale_doubleSpinBox->setValue(0.1);
    ui->zScale_doubleSpinBox->setValue(0.1);
    ui->xScale_doubleSpinBox->setSingleStep(0.1);
    ui->yScale_doubleSpinBox->setSingleStep(0.1);
    ui->zScale_doubleSpinBox->setSingleStep(0.1);

    ui->xRotate_checkBox->setChecked(false);
    ui->yRotate_checkBox->setChecked(true);
    ui->zRotate_checkBox->setChecked(false);

    ui->objectColorComboBox->setCurrentColor(Qt::red);

    mObject = new Qt3dWavefrontObject;
    ui->qt3dopenglWidget->set3dObject(mObject);

    connect(ui->backgroundComboBox, &ColorComboBox::currentColorChanged,
            ui->qt3dopenglWidget, &Qt3dOpenGLWidget::setBackground);

    connect(ui->objectColorComboBox, &ColorComboBox::currentColorChanged,
            ui->qt3dopenglWidget, &Qt3dOpenGLWidget::setObjectColor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openModel_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Abrir modelo", QDir::rootPath(), "Wavefront Object (*.obj)");
    if (!filename.isEmpty())
    {
        mObject->loadFromFile(filename);
    }
}

void MainWindow::on_matrixModeComboBox_activated(int index)
{
    ui->qt3dopenglWidget->setMode(ui->matrixModeComboBox->itemData(index).toInt());
}

void MainWindow::on_xScale_doubleSpinBox_valueChanged(double scale)
{
    ui->qt3dopenglWidget->set_xScale(scale);
}

void MainWindow::on_yScale_doubleSpinBox_valueChanged(double scale)
{
    ui->qt3dopenglWidget->set_yScale(scale);
}

void MainWindow::on_zScale_doubleSpinBox_valueChanged(double scale)
{
    ui->qt3dopenglWidget->set_zScale(scale);
}

void MainWindow::on_xRotate_checkBox_clicked(bool checked)
{
    ui->qt3dopenglWidget->set_xRotationEnabled(checked);
}

void MainWindow::on_yRotate_checkBox_clicked(bool checked)
{
    ui->qt3dopenglWidget->set_yRotationEnabled(checked);
}

void MainWindow::on_zRotate_checkBox_clicked(bool checked)
{
    ui->qt3dopenglWidget->set_zRotationEnabled(checked);
}
