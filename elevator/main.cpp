#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

enum states {
    first_stop,
    first_going_up,
    second_going_down,
    second_stop,
    second_going_up,
    third_going_down,
    third_stop,
    third_going_up,
    fourth_going_down,
    fourth_stop,
    fourth_going_up,
    fifth_going_down,
    fifth_stop,
    fifth_going_up,
    sixth_going_down,
    sixth_stop,
    sixth_going_up,
    seventh_going_down,
    seventh_stop
};

template <std::size_t S>
class buttons_panel {
   public:
    void press(int floor_number) { buttons_[floor_number - 1] = true; }

    void reset(int floor_number) { buttons_[floor_number - 1] = false; }

    bool check(int floor_number) { return buttons_[floor_number - 1]; }

    bool check_range(int l, int r) {
        bool result = false;
        for (int index = l - 1; index < r; index++) {
            result = result || buttons_[index];
        }
        return result;
    }

   private:
    std::array<bool, S> buttons_{false};
};

int main() {
    states state = first_stop;

    int floorFrom;

    buttons_panel<7> panel_inner;
    buttons_panel<7> panel_outer;

    while (true) {
        std::cout << "Current state: " << state << std::endl;

        std::cin >> floorFrom;

        if (floorFrom > 0 && floorFrom < 8) {
            std::cout << "pressed button " << floorFrom << std::endl;
            panel_outer.press(floorFrom);
        } else {
            std::cout << "Buttons not pressed" << std::endl;
        }

        switch (state) {
            case first_stop:
                panel_outer.reset(1);
                if (panel_outer.check_range(2, 7)) {
                    state = first_going_up;
                }
                break;

            case first_going_up:
                if (panel_outer.check(2)) {
                    state = second_stop;
                } else if (panel_outer.check_range(3, 7)) {
                    state = second_going_up;
                }
                break;

            case second_going_down:
                state = first_stop;
                break;

            case second_stop:
                panel_outer.reset(2);
                if (panel_outer.check(1)) {
                    state = second_going_down;
                }
                break;

            case second_going_up:
                if (panel_outer.check(3)) {
                    state = third_stop;
                } else if (panel_outer.check_range(4, 7)) {
                    state = third_going_up;
                }
                break;

            case third_going_down:
                if (panel_outer.check(1)) {
                    state = second_going_down;
                } else if (panel_outer.check(2)) {
                    state = second_stop;
                }
                break;

            case third_stop:
                panel_outer.reset(3);
                if (panel_outer.check_range(1, 2)) {
                    state = third_going_down;
                } else if (panel_outer.check_range(3, 7)) {
                    state = third_going_up;
                }
                break;

            case third_going_up:
                if (panel_outer.check(4)) {
                    state = fourth_stop;
                } else if (panel_outer.check_range(5, 7)) {
                    state = fourth_going_up;
                }
                break;

            case fourth_going_down:
                if (panel_outer.check(3)) {
                    state = third_stop;
                } else if (panel_outer.check_range(1, 2)) {
                    state = third_going_down;
                }
                break;

            case fourth_stop:
                panel_outer.reset(4);
                if (panel_outer.check_range(1, 3)) {
                    state = fourth_going_down;
                } else if (panel_outer.check_range(5, 7)) {
                    state = fourth_going_up;
                }
                break;

            case fourth_going_up:
                if (panel_outer.check(5)) {
                    state = fifth_stop;
                } else if (panel_outer.check_range(6, 7)) {
                    state = fifth_going_up;
                }
                break;

            case fifth_going_down:
                if (panel_outer.check(4)) {
                    state = fourth_stop;
                } else if (panel_outer.check_range(1, 3)) {
                    state = fourth_going_down;
                }
                break;

            case fifth_stop:
                panel_outer.reset(5);
                if (panel_outer.check_range(1, 4)) {
                    state = fifth_going_down;
                } else if (panel_outer.check_range(6, 7)) {
                    state = fifth_going_up;
                }
                break;

            case fifth_going_up:
                if (panel_outer.check(6)) {
                    state = sixth_stop;
                } else if (panel_outer.check(7)) {
                    state = sixth_going_up;
                }
                break;

            case sixth_going_down:
                if (panel_outer.check(5)) {
                    state = fifth_stop;
                } else if (panel_outer.check_range(1, 4)) {
                    state = fifth_going_down;
                }
                break;

            case sixth_stop:
                panel_outer.reset(6);
                if (panel_outer.check_range(1, 5)) {
                    state = sixth_going_down;
                } else if (panel_outer.check(7)) {
                    state = sixth_going_up;
                }
                break;

            case sixth_going_up:
                if (panel_outer.check(7)) {
                    state = seventh_stop;
                }
                break;

            case seventh_going_down:
                if (panel_outer.check(6)) {
                    state = sixth_stop;
                } else if (panel_outer.check_range(1, 5)) {
                    state = sixth_going_down;
                }
                break;

            case seventh_stop:
                panel_outer.reset(7);
                if (panel_outer.check_range(1, 6)) {
                    state = seventh_going_down;
                }
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }

    return 0;
}
