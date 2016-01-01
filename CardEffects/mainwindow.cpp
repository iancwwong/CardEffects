#include "mainwindow.h"
#include "ui_mainwindow.h"


// ==   UI INITIALISATION   ==
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Customise the select card dropdown list
    ui->CardSelectBar->setMaxVisibleItems((int)NUM_CARDS/2 + 1);       // add the joker
    addCardSelectionItems(ui->CardSelectBar);

    // Customise the search bar
    ui->CardSearchBar->setPlaceholderText("Search for a card");
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ==   INTERFACE ACTIONS   ==

// Action when user selects a card
void MainWindow::on_CardSelectBar_activated(const QString &arg1)
{
    QString cardSelected = arg1;
    if (cardSelected == "Select a card") {

        // Clear the effect description box
        ui->CardDescriptionBox->setText("");
    } else {

        // Translate the card name into its code name
        QString codeName = toCodeName(cardSelected);

        // Obtain the appropriate description for the card selected
        // Cardobject cardObject = CardObjects->value(CardObjects->indexOf(codeName));
        // ui->CardDescriptionBox->setText(cardObject.getDescription());
        ui->CardDescriptionBox->setText("Some description.");
    }
}


// ==   MENU BAR ACTIONS    ==
void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutBox;
    aboutBox.setText("Card Viewer app for the Card Effects Game.");
    aboutBox.exec();
}

// ==   PRIVATE FUNCTIONS   ==

// Populate a combobox with all 52 playing cards and Joker
void MainWindow::addCardSelectionItems(QComboBox * comboBox) {

    // Create the list of cards into a list
    QStringList cardList;

    QVector<QString> * suitList = new QVector<QString>();
    suitList->append("Hearts");
    suitList->append("Diamonds");
    suitList->append("Spades");
    suitList->append("Clubs");
    suitList->append("Other");

    // Loop through each suit (ignore the last suit)
    for (int index = 0; index < suitList->size() - 1; index++) {

        // Loop through each value
        for (int value = 1; value <= 13; value++) {
            QString cardName = suitList->value(index);
            cardName.append(": ");

            // Determine the symbol representing the card value
            if (value == 1) {
                cardName.append("Ace");
            } else if (value == 11) {
                cardName.append("Jack");
            } else if (value == 12) {
                cardName.append("Queen");
            } else if (value == 13) {
                cardName.append("King");
            } else {
                cardName.append(QString::number(value));
            }

            // Add to the card list
            cardList.append(cardName);
        }
    }

    // Add special cards
    QString cardName = suitList->last();
    cardName.append(": ");
    cardName.append("Joker");
    cardList.append(cardName);

    // Add the list as a set of items into the combobox
    comboBox->addItems(cardList);
}

