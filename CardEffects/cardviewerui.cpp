#include "cardviewerui.h"
#include "ui_cardeffects.h"

CardViewerUI::CardViewerUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CardViewerUI)
{
    //centralWidget()->layout()->setContentsMargins(0, 0, 0, 0);
    //centralWidget()->layout()->setContentsMargins(0,0,0,0);
    ui->setupUi(this);

}

CardViewerUI::~CardViewerUI()
{
    delete ui;
}

void CardViewerUI::on_CardViewerCloseButton_clicked()
{
    qApp->quit();
}
