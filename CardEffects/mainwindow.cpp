#include "mainwindow.h"
#include "ui_mainwindow.h"


// ==   UI INITIALISATION   ==
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialise the mapping of card names
    this->cardNameMap = new QMap<QString, QString>();
    initialiseCardNameMapping(this->cardNameMap);

    // Customise the select card dropdown list
    ui->CardSelectBar->setMaxVisibleItems((int)NUM_CARDS/2 + 1);       // add the joker
    addCardSelectionItems(ui->CardSelectBar);

    // Set default card picture (blank) in the QLabel
    QString imgFileName = QCoreApplication::applicationDirPath();
    imgFileName.append("/img/default_back.png");
    QPixmap * cardImg = new QPixmap(imgFileName);
    ui->CardDisplayBox->setPixmap(*cardImg);
    delete cardImg;

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

        // Display default blank card as the card display
        QString imgFileName = QCoreApplication::applicationDirPath();
        imgFileName.append("/img/default_back.png");
        QPixmap * cardImg = new QPixmap(imgFileName);
        ui->CardDisplayBox->setPixmap(*cardImg);
        delete cardImg;

    } else {

        QString executableDir = QCoreApplication::applicationDirPath();

        // Translate the card name into its code name
        QString codeName = toCodeName(cardSelected);

        // Obtain the appropriate description for the card selected
        // by opening the correct file
        QString filename = executableDir;      // executable directory
        filename.append("/profiles/");
        filename.append(codeName);
        filename.append(".descr");

        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            int errorVal = (int)file.error();
            cout << "Error opening file. Error code: " << errorVal << endl;
            return;
        }

        // Search for the description, depicted in a section labelled under "#effect"
        QString cardDescription;
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            if (line == "#effect") {
                while (!in.atEnd()) {
                    QString effectLine = in.readLine();
                    if (effectLine.startsWith(QChar('#'))) {
                        break;
                    }
                    cardDescription.append(effectLine);
                    cardDescription.append("\n");
                }
            }

        }
        ui->CardDescriptionBox->setText(cardDescription);

        // Display the face image of the card selected
        QString imgfilename = executableDir;      // executable directory
        imgfilename.append("/img/");
        imgfilename.append(codeName);
        imgfilename.append("_front.png");
        QPixmap * cardImg = new QPixmap(imgfilename);
        ui->CardDisplayBox->setPixmap(*cardImg);
        delete cardImg;
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
// NOTE: Does NOT make use of the keys in the map, as order of items in the
//       combobox is important
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

// Initialise the (key,value) hash table for the card name
// KEY: Text Name, VALUE: Code Name
void MainWindow::initialiseCardNameMapping(QMap<QString, QString> * map) {

    // Add the HEARTS cards
    map->insert(QString("Hearts: Ace"), QString("H01"));
    map->insert(QString("Hearts: 2"), QString("H02"));
    map->insert(QString("Hearts: 3"), QString("H03"));
    map->insert(QString("Hearts: 4"), QString("H04"));
    map->insert(QString("Hearts: 5"), QString("H05"));
    map->insert(QString("Hearts: 6"), QString("H06"));
    map->insert(QString("Hearts: 7"), QString("H07"));
    map->insert(QString("Hearts: 8"), QString("H08"));
    map->insert(QString("Hearts: 9"), QString("H09"));
    map->insert(QString("Hearts: 10"), QString("H10"));
    map->insert(QString("Hearts: Jack"), QString("H11"));
    map->insert(QString("Hearts: Queen"), QString("H12"));
    map->insert(QString("Hearts: King"), QString("H13"));

    // Add the DIAMONDS cards
    map->insert(QString("Diamonds: Ace"), QString("D01"));
    map->insert(QString("Diamonds: 2"), QString("D02"));
    map->insert(QString("Diamonds: 3"), QString("D03"));
    map->insert(QString("Diamonds: 4"), QString("D04"));
    map->insert(QString("Diamonds: 5"), QString("D05"));
    map->insert(QString("Diamonds: 6"), QString("D06"));
    map->insert(QString("Diamonds: 7"), QString("D07"));
    map->insert(QString("Diamonds: 8"), QString("D08"));
    map->insert(QString("Diamonds: 9"), QString("D09"));
    map->insert(QString("Diamonds: 10"), QString("D10"));
    map->insert(QString("Diamonds: Jack"), QString("D11"));
    map->insert(QString("Diamonds: Queen"), QString("D12"));
    map->insert(QString("Diamonds: King"), QString("D13"));

    // Add the SPADES cards
    map->insert(QString("Spades: Ace"), QString("S01"));
    map->insert(QString("Spades: 2"), QString("S02"));
    map->insert(QString("Spades: 3"), QString("S03"));
    map->insert(QString("Spades: 4"), QString("S04"));
    map->insert(QString("Spades: 5"), QString("S05"));
    map->insert(QString("Spades: 6"), QString("S06"));
    map->insert(QString("Spades: 7"), QString("S07"));
    map->insert(QString("Spades: 8"), QString("S08"));
    map->insert(QString("Spades: 9"), QString("S09"));
    map->insert(QString("Spades: 10"), QString("S10"));
    map->insert(QString("Spades: Jack"), QString("S11"));
    map->insert(QString("Spades: Queen"), QString("S12"));
    map->insert(QString("Spades: King"), QString("S13"));

    // Add the CLUBS cards
    map->insert(QString("Clubs: Ace"), QString("C01"));
    map->insert(QString("Clubs: 2"), QString("C02"));
    map->insert(QString("Clubs: 3"), QString("C03"));
    map->insert(QString("Clubs: 4"), QString("C04"));
    map->insert(QString("Clubs: 5"), QString("C05"));
    map->insert(QString("Clubs: 6"), QString("C06"));
    map->insert(QString("Clubs: 7"), QString("C07"));
    map->insert(QString("Clubs: 8"), QString("C08"));
    map->insert(QString("Clubs: 9"), QString("C09"));
    map->insert(QString("Clubs: 10"), QString("C10"));
    map->insert(QString("Clubs: Jack"), QString("C11"));
    map->insert(QString("Clubs: Queen"), QString("C12"));
    map->insert(QString("Clubs: King"), QString("C13"));

    // Add the SPECIAL cards
    map->insert(QString("Other: Joker"), QString("O00"));

}

// Translate a card's textual name to its code name
// eg textual name = Hearts: Ace
//    code name    = H01
QString MainWindow::toCodeName(QString cardTextName) {

    QString result = this->cardNameMap->value(cardTextName);
    return result;

}

