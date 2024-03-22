#include "Table.h"

Table::Table() {
    for (int i = 0; i < NUMOFPHILOSOPHERS; i++) {
        forks.push_back(std::make_unique<Fork>());
    }
}

Fork& Table::getFork(int id) {
    return *(forks[id]);
}
