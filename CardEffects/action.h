#ifndef ACTION_H
#define ACTION_H

#include <QString>

class Action
{
public:

    // CONSTRUCTORS
    // Default
    Action();

    // DESTRUCTOR
    ~Action();

    // -------------------
    // METHODS
    // -------------------

    // Return the original string command
    QString GetStringCommand();
    void SetStringCommand(QString commandStr);

private:

    // -------------------
    // ATTRIBUTES
    // -------------------
    QString stringCommand;  // string version of original command


};

#endif // ACTION_H
