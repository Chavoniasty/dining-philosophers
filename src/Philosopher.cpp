#include "Philosopher.h"
#include <chrono>
#include <thread>
#include <cstdlib>

Philosopher::Philosopher(int tempID, Table& tempTable) : table(tempTable) {
    id = tempID;
    rightForkID = tempID;
    leftForkID = (tempID + 1) % NUMOFPHILOSOPHERS;
    state = "Thinking";
}

void Philosopher::think() {
    state = "Thinking";
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 1500));
}

void Philosopher::eat() {
    state = "Waiting";
    table.getFork(leftForkID).pickUp();
    table.getFork(rightForkID).pickUp();
    state = "Eating";
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000 + 500));
    table.getFork(leftForkID).putDown();
    table.getFork(rightForkID).putDown();
}

void Philosopher::dine() {
    while (true) {
        think();
        eat();
    }
}

std::string Philosopher::getState() {
    return state;
}
