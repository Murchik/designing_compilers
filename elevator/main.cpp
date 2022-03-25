#include <iostream>

#include "elevator.hpp"

int main() {
    elevator elev;
    int button_pressed;

    while (true) {
        std::cout << "Current state: " << elev.state() << std::endl;

        std::cin >> button_pressed;
        if (button_pressed > 0 && button_pressed < 8) {
            std::cout << "pressed button " << button_pressed << std::endl;
            elev.press(button_pressed);
        } else {
            std::cout << "Buttons not pressed" << std::endl;
        }

        elev.change_state(button_pressed);

        std::cout << std::endl;
    }

    return 0;
}
