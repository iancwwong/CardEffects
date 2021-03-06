/*
 * This class is responsible for checking the validity of user-entered commands
 * and if a valid command, pass as an "Action" to the "GameEngine" class.
 * Then returns a result string to the UI.
 *
 * If a command is invalid, then it will return an error message to the UI instead.
 *
*/

#ifndef COMMANDPARSER_H
#define COMMANDPARSER_H

// DATA RESPRESENTATION
#include <QString>
#include <QStringList>
#include <QMap>
#include <QRegExp>
#include <QVector>

#include <gameobject.h>
#include <action.h>

class CommandParser
{

public:

    CommandParser();
    ~CommandParser();

    // ---------------------
    // METHODS
    // ---------------------

    // Attach a GameEngine
    void SetGameObject(GameObject * newGameObject);

    // Decrypt the meaning of a user-entered command
    QString ParseCommand(QString command);

private:
    GameObject * gameObject;
    QMap<QString, QList<QRegExp> > * commandFormatMap;   // maps a command name to parameters and their format

    // ---------------------
    // CONSTANTS
    // ---------------------

    // When all parameters are valid
    const int ALL_PARAMETERS_VALID = -1;

    // Regex's for checking parameters
    // NOTE: Lower case as the original command string is translated to lower case
    const QString VALID_CARD_REGEX = "[hdsc]([1-9]0?|[jqk])";
    const QString VALID_POSITION_REGEX = "[1-5]";

    // ---------------------
    // FUNCTIONS
    // ---------------------

    // Initialises the mapping of commands to parameters
    void InitialiseCommandMapping();

    // Returns whether the command exists
    bool CheckCommand(QString command);

    // Returns the first parameter that is incorrect
    int CheckParameters(QString command, QStringList parameters);
    QString BuildRegex(QStringList stringList);

    // ERROR BUILDING FUNCTIONS
    // For command
    QString BuildCommandErrorString(QString command);

    // For parameters
    QString BuildParameterErrorString(int parameterPosition, QString parameterValue);
    QString BuildNoParameterErrorString(QString command);
    QString BuildInsuffParameterErrorString(QString command);

};

#endif // COMMANDPARSER_H
