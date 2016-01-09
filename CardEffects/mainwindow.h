#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// ==   OTHER CLASSES   ==
#include <gameengine.h>
#include <commandparser.h>

// ==   UI ELEMENTS     ==
#include <QMessageBox>
#include <QComboBox>
#include <QPixmap>
#include <QLabel>
#include <QColor>

// ==   DATA REPRESENTATION     ==
#include <QVector>
#include <QStringList>
#include <QMap>
#include <QFile>    // for reading files
#include <QTextStream>
#include <iostream> // debugging

//  == CONSTANTS            ==
#define NUM_CARDS 52
#define COLOR_BLACK 0
#define COLOR_BLUE 1
#define COLOR_RED 2

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // ==   ATTRIBUTES  ==
    QMap<QString, QString> * cardNameMap;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

// Actions
private slots:

    // ------------------------------------
    // GAME WINDOW UI
    // ------------------------------------

    // Entry of command in command box
    void on_CommandEntryBox_returnPressed();

    // ------------------------------------
    // CARD VIEWER UI
    // ------------------------------------

    // Card Select Combo Box
    void on_CardSelectBar_activated(const QString &arg1);

    // ------------------------------------
    // MENU BAR
    // ------------------------------------

    // Menu Bar
    void on_actionAbout_triggered();
    void on_actionExit_triggered();
    void on_actionNew_Game_triggered();

private:

    //  ==  ATTRIBUTES          ==
    Ui::MainWindow *ui;
    GameEngine * gameEngine;
    CommandParser * commandParser;

    // ==   PRIVATE FUNCTIONS   ==

    // Initialise the items in the dropdown list for viewing card effect
    void addCardSelectionItems(QComboBox * comboBox);

    // Initialise the mappings of the card names (
    void initialiseCardNameMapping(QMap<QString, QString> * map);

    // translate a card's text name to its code name
    QString toCodeName(QString cardTextName);

    // Display the string inside the action log box
    void DisplayString(QString stringToDisplay, int color);
};

#endif // MAINWINDOW_H
