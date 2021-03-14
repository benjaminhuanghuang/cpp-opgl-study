#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Qt3dWavefrontObject;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_openModel_pushButton_clicked();
    void on_matrixModeComboBox_activated(int index);
    void on_xScale_doubleSpinBox_valueChanged(double scale);
    void on_yScale_doubleSpinBox_valueChanged(double scale);
    void on_zScale_doubleSpinBox_valueChanged(double scale);
    void on_xRotate_checkBox_clicked(bool checked);
    void on_yRotate_checkBox_clicked(bool checked);
    void on_zRotate_checkBox_clicked(bool checked);
private:
    Ui::MainWindow *ui;
    Qt3dWavefrontObject *mObject;
};

#endif // MAINWINDOW_H
