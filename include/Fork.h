#ifndef FORK_H
#define FORK_H

#include <mutex>

class Fork {
private:
    std::mutex mutex;

public:
    void pickUp();
    void putDown();
};

#endif // FORK_H
