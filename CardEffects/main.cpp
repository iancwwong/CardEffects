#include "cardviewerui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CardViewerUI w;

    // Set the main window to have no margins
    //QWidget* QMainWindow::centralWidget();
    //centralWidget()->layout()->setContentsMargin(0,0,0,0);

    // Enable and display the window
    w.show();
    return a.exec();
}
