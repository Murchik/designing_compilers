#include <iostream>

#include "elevator.hpp"

int main() {
    elevator elev;
    int button_pressed;

    while (true) {
        print_state(elev.state());

        std::cout << "Press button inside: ";
        std::cin >> button_pressed;
        if (button_pressed > 0 && button_pressed < 8) {
            std::cout << "Pressed button " << button_pressed << " from inside"
                      << std::endl;
            elev.press_inside(button_pressed);
        } else {
            std::cout << "Buttons not pressed" << std::endl;
        }

        std::cout << "Press button outside: ";
        std::cin >> button_pressed;
        if (button_pressed > 0 && button_pressed < 8) {
            std::cout << "Pressed button " << button_pressed << " from outside"
                      << std::endl;
            elev.press_outside(button_pressed);
        } else {
            std::cout << "Buttons not pressed" << std::endl;
        }

        elev.update_state();

        std::cout << std::endl;
    }

    return 0;
}
