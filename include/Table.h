#ifndef TABLE_H
#define TABLE_H

#include <vector>
#include <memory>
#include "Fork.h"

#define NUMOFPHILOSOPHERS 5

class Table {
private:
    std::vector<std::unique_ptr<Fork>> forks;

public:
    Table();
    Fork& getFork(int id);
};

#endif // TABLE_H
