#include "elevator.hpp"

void elevator::press_inside(int floor_number) {
    panel_inner_.press(floor_number);
}
void elevator::press_outside(int floor_number) {
    panel_outer_.press(floor_number);
}

states elevator::state() { return state_; }

void elevator::update_state() {
    states state_new = get_new_state(panel_inner_);
    if (state_ == state_new) {
        state_new = get_new_state(panel_outer_);
    }
    state_ = state_new;
}

states elevator::get_new_state(buttons_panel<7>& p) {
    states state = state_;

    switch (state) {
        case first_stop:
            p.reset(1);
            if (p.check_range(2, 7)) {
                state = first_going_up;
            }
            break;

        case first_going_up:
            if (p.check(2)) {
                state = second_stop;
            } else if (p.check_range(3, 7)) {
                state = second_going_up;
            }
            break;

        case second_going_down:
            state = first_stop;
            break;

        case second_stop:
            p.reset(2);
            if (p.check(1)) {
                state = second_going_down;
            }
            break;

        case second_going_up:
            if (p.check(3)) {
                state = third_stop;
            } else if (p.check_range(4, 7)) {
                state = third_going_up;
            }
            break;

        case third_going_down:
            if (p.check(1)) {
                state = second_going_down;
            } else if (p.check(2)) {
                state = second_stop;
            }
            break;

        case third_stop:
            p.reset(3);
            if (p.check_range(1, 2)) {
                state = third_going_down;
            } else if (p.check_range(3, 7)) {
                state = third_going_up;
            }
            break;

        case third_going_up:
            if (p.check(4)) {
                state = fourth_stop;
            } else if (p.check_range(5, 7)) {
                state = fourth_going_up;
            }
            break;

        case fourth_going_down:
            if (p.check(3)) {
                state = third_stop;
            } else if (p.check_range(1, 2)) {
                state = third_going_down;
            }
            break;

        case fourth_stop:
            p.reset(4);
            if (p.check_range(1, 3)) {
                state = fourth_going_down;
            } else if (p.check_range(5, 7)) {
                state = fourth_going_up;
            }
            break;

        case fourth_going_up:
            if (p.check(5)) {
                state = fifth_stop;
            } else if (p.check_range(6, 7)) {
                state = fifth_going_up;
            }
            break;

        case fifth_going_down:
            if (p.check(4)) {
                state = fourth_stop;
            } else if (p.check_range(1, 3)) {
                state = fourth_going_down;
            }
            break;

        case fifth_stop:
            p.reset(5);
            if (p.check_range(1, 4)) {
                state = fifth_going_down;
            } else if (p.check_range(6, 7)) {
                state = fifth_going_up;
            }
            break;

        case fifth_going_up:
            if (p.check(6)) {
                state = sixth_stop;
            } else if (p.check(7)) {
                state = sixth_going_up;
            }
            break;

        case sixth_going_down:
            if (p.check(5)) {
                state = fifth_stop;
            } else if (p.check_range(1, 4)) {
                state = fifth_going_down;
            }
            break;

        case sixth_stop:
            p.reset(6);
            if (p.check_range(1, 5)) {
                state = sixth_going_down;
            } else if (p.check(7)) {
                state = sixth_going_up;
            }
            break;

        case sixth_going_up:
            if (p.check(7)) {
                state = seventh_stop;
            }
            break;

        case seventh_going_down:
            if (p.check(6)) {
                state = sixth_stop;
            } else if (p.check_range(1, 5)) {
                state = sixth_going_down;
            }
            break;

        case seventh_stop:
            p.reset(7);
            if (p.check_range(1, 6)) {
                state = seventh_going_down;
            }
            break;
        default:
            break;
    }

    return state;
}
