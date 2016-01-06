#ifndef ACTION_H
#define ACTION_H

#include <QString>

class Action
{
public:

    // CONSTRUCTORS
    // Default
    Action();

    // When given a string as the command
    Action(QString command);

    // DESTRUCTOR
    ~Action();

    // -------------------
    // METHODS
    // -------------------

    // Return the original string command
    QString GetStringCommand();

private:

    // -------------------
    // ATTRIBUTES
    // -------------------
    QString stringCommand;  // string version of original command


};

#endif // ACTION_H
