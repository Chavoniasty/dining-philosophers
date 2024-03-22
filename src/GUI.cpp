#include "GUI.h"
#include <ncurses.h>
#include <chrono>
#include <thread>

void GUI(std::vector<Philosopher>& philosophers) {
    initscr();
    start_color();
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);

    while (true) {
        for (size_t i = 0; i < philosophers.size(); i++) {
            std::string state = philosophers[i].getState();
            std::string displayStr = "Philosopher " + std::to_string(i + 1) + " is " + state;
            if (state == "Thinking") {
                attron(COLOR_PAIR(1));
                mvprintw(i, 0, displayStr.c_str());
                attroff(COLOR_PAIR(1));
            } else if (state == "Eating") {
                attron(COLOR_PAIR(2));
                mvprintw(i, 0, displayStr.c_str());
                attroff(COLOR_PAIR(2));
            } else if (state == "Waiting") {
                attron(COLOR_PAIR(3));
                mvprintw(i, 0, displayStr.c_str());
                attroff(COLOR_PAIR(3));
            }
            for (size_t j = displayStr.length(); j < COLS; j++) {
                mvaddch(i, j, ' ');
            }
        }
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    endwin();
}
