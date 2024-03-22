#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <string>
#include "Table.h"

class Philosopher {
private:
    int id;
    int leftForkID;
    int rightForkID;
    std::string state;
    Table& table;

public:
    Philosopher(int tempID, Table& tempTable);
    void think();
    void eat();
    void dine();
    std::string getState();
};

#endif // PHILOSOPHER_H
