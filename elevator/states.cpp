#include "states.hpp"

#include <iostream>

void print_to_console(const std::string& str) { std::cout << str << std::endl; }

#define PRINT(...) print_to_console(__VA_ARGS__)

void print_state(states s) {
    switch (s) {
        case first_stop:
            PRINT("Stopped on the first floor");
            break;
        case first_going_up:
            PRINT("Goes from the first to the second");
            break;
        case second_going_down:
            PRINT("Goes from the second to the first");
            break;
        case second_stop:
            PRINT("Stopped on the second floor");
            break;
        case second_going_up:
            PRINT("Goes from the second to the third");
            break;
        case third_going_down:
            PRINT("Goes from the third to the second");
            break;
        case third_stop:
            PRINT("Stopped on the third floor");
            break;
        case third_going_up:
            PRINT("Goes from the third to the fourth");
            break;
        case fourth_going_down:
            PRINT("Goes from the fourth to the third");
            break;
        case fourth_stop:
            PRINT("Stopped on the fourth floor");
            break;
        case fourth_going_up:
            PRINT("Goes from the fourth to the fifth");
            break;
        case fifth_going_down:
            PRINT("Goes from the fifth to the fourth");
            break;
        case fifth_stop:
            PRINT("Stopped on the fifth floor");
            break;
        case fifth_going_up:
            PRINT("Goes from the fifth to the sixth");
            break;
        case sixth_going_down:
            PRINT("Goes from the sixth to the fifth");
            break;
        case sixth_stop:
            PRINT("Stopped on the sixth floor");
            break;
        case sixth_going_up:
            PRINT("Goes from the sixth to the seventh");
            break;
        case seventh_going_down:
            PRINT("Goes from the seventh to the sixth");
            break;
        case seventh_stop:
            PRINT("Stopped on the seventh floor");
            break;

        default:
            PRINT("Unknown state");
            break;
    }
}