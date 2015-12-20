#ifndef CARDVIEWERUI_H
#define CARDVIEWERUI_H

#include <QMainWindow>

namespace Ui {
class CardViewerUI;
}

class CardViewerUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit CardViewerUI(QWidget *parent = 0);
    ~CardViewerUI();

private slots:
    void on_CardViewerCloseButton_clicked();

private:
    Ui::CardViewerUI *ui;
};

#endif // CARDEFFECTS_H
