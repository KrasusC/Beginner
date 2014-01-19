#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QMainWindow>

class QAction;
class QLabel;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void open();
    void getAColor();
    void setAColor();

private:
    QAction *openAction;
    QAction *getColor;
    QAction *setColor;
    QLabel *msgLabel;

};

#endif // MAINWINDOW_H
