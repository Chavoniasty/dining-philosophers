#include <thread>
#include <vector>
#include "Philosopher.h"
#include "GUI.h"

void init() {
    Table table;
    std::vector<Philosopher> philosophers;
    std::vector<std::thread> threads;

    for (int i = 0; i < NUMOFPHILOSOPHERS; i++) {
        philosophers.emplace_back(i, table);
    }

    for (int i = 0; i < NUMOFPHILOSOPHERS; i++) {
        threads.emplace_back(&Philosopher::dine, &philosophers[i]);
    }
    std::thread guiThread(GUI, std::ref(philosophers));

    for (int i = 0; i < NUMOFPHILOSOPHERS; i++) {
        threads[i].join();
    }
}

int main() {
    init();
    return 0;
}
