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
        // NOTE: .descr file contains a SINGLE line
        QString filename = "./profiles/";
        filename.append(codeName);
        filename.append(".descr");

        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            int errorVal = (int)file.error();
            cout << "Error opening file. Error code: " << errorVal << endl;
            return;
        }

        QTextStream in(&file);
        QString line = in.readLine();
        QString cardDescription = line.split(QChar('=')).last();
        ui->CardDescriptionBox->setText(cardDescription);
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

// Translate a card's textual name to its code name
// eg textual name = Hearts: Ace
//    code name    = H01
QString MainWindow::toCodeName(QString cardTextName) {
    QString codeName;

    // Remove all the spaces in the string
    cardTextName.remove(QChar(' '));

    // Check the suit
    QString chosenSuit = cardTextName.split(QChar(':')).first();
    QStringList cardSuits;
    cardSuits.append("Hearts");
    cardSuits.append("Diamonds");
    cardSuits.append("Spades");
    cardSuits.append("Clubs");
    cardSuits.append("Other");

    switch(cardSuits.indexOf(chosenSuit)) {
        case 0:     // Hearts
            codeName.append("H");
            break;
        case 1:     // Diamonds
            codeName.append("D");
            break;
        case 2:     // Spades
            codeName.append("S");
            break;
        case 3:     // Clubs
            codeName.append("C");
            break;
        case 4:     // Other
            codeName.append("O");
            break;
        default:
            // Weird name
            codeName.append("-");
            break;
    }

    // Check the value
    QString chosenValue = cardTextName.split(QChar(':')).last();
    QStringList cardValues;
    cardValues.append("Ace");
    cardValues.append("Jack");
    cardValues.append("Queen");
    cardValues.append("King");

    // Special value cards
    cardValues.append("Joker");

    switch(cardValues.indexOf(chosenValue)) {
        case 0:     // Ace
            codeName.append("01");
            break;
        case 1:     // Jack
            codeName.append("11");
            break;
        case 2:     // Queen
            codeName.append("12");
            break;
        case 3:     // King
            codeName.append("13");
            break;
        case 4:     // Joker
            codeName.append("00");
            break;
        default:
            // Assume numerical value
            int value = cardTextName.split(QChar(':')).last().toInt();
            if (value < 10) {
                codeName.append("0");
            }
            codeName.append(chosenValue);
            break;
    }

    return codeName;
}

