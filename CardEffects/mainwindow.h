#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// ==   UI ELEMENTS     ==
#include <QMessageBox>
#include <QComboBox>

// ==   DATA REPRESENTATION     ==
#include <QVector>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

// Menu Bar actions
private slots:
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    const int NUM_CARDS = 52;

    // Private functions
    void addCardSelectionItems(QComboBox * comboBox);
};

#endif // MAINWINDOW_H
