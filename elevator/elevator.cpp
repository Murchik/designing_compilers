#include "elevator.hpp"

void elevator::press_inside(int floor_number) {
    panel_inner_.press(floor_number);
}
void elevator::press_outside(int floor_number) {
    panel_outer_.press(floor_number);
}

states elevator::state() const { return state_; }

void elevator::update_state() { state_ = get_new_state(); }

states elevator::get_new_state() {
    states state = state_;

    switch (state) {
        case first_stop:
            panel_inner_.reset(1);
            panel_outer_.reset(1);
            if (panel_inner_.check_range(2, 7)) {
                state = first_going_up;
                break;
            }
            if (panel_outer_.check_range(2, 7)) {
                state = first_going_up;
                break;
            }
            break;

        case first_going_up:
            if (panel_inner_.check(2) || panel_outer_.check(2)) {
                state = second_stop;
                break;
            }
            if (panel_inner_.check_range(3, 7) ||
                panel_outer_.check_range(3, 7)) {
                state = second_going_up;
                break;
            }
            break;

        case second_going_down:
            state = first_stop;
            break;

        case second_stop:
            panel_inner_.reset(2);
            panel_outer_.reset(2);
            if (panel_inner_.check(1) || panel_outer_.check(1)) {
                state = second_going_down;
                break;
            }
            if (panel_inner_.check_range(3, 7) ||
                panel_outer_.check_range(3, 7)) {
                state = second_going_up;
                break;
            }
            break;

        case second_going_up:
            if (panel_inner_.check(3) || panel_outer_.check(3)) {
                state = third_stop;
                break;
            }
            if (panel_inner_.check_range(4, 7) ||
                panel_outer_.check_range(4, 7)) {
                state = third_going_up;
                break;
            }
            break;

        case third_going_down:
            if (panel_outer_.check(2) || panel_inner_.check(2)) {
                state = second_stop;
                break;
            }
            if (panel_inner_.check(1) || panel_outer_.check(1)) {
                state = second_going_down;
                break;
            }
            break;

        case third_stop:
            panel_inner_.reset(3);
            panel_outer_.reset(3);
            if (panel_inner_.check_range(1, 2) ||
                panel_outer_.check_range(1, 2)) {
                state = third_going_down;
                break;
            }
            if (panel_inner_.check_range(3, 7) ||
                panel_outer_.check_range(3, 7)) {
                state = third_going_up;
                break;
            }
            break;

        case third_going_up:
            if (panel_inner_.check(4) || panel_outer_.check(4)) {
                state = fourth_stop;
                break;
            }
            if (panel_inner_.check_range(5, 7) ||
                panel_outer_.check_range(5, 7)) {
                state = fourth_going_up;
                break;
            }
            break;

        case fourth_going_down:
            if (panel_outer_.check(3) || panel_inner_.check(3)) {
                state = third_stop;
                break;
            }
            if (panel_inner_.check_range(1, 2) ||
                panel_outer_.check_range(1, 2)) {
                state = third_going_down;
                break;
            }
            break;

        case fourth_stop:
            panel_inner_.reset(4);
            panel_outer_.reset(4);
            if (panel_inner_.check_range(1, 3) ||
                panel_outer_.check_range(1, 3)) {
                state = fourth_going_down;
                break;
            }
            if (panel_inner_.check_range(5, 7) ||
                panel_outer_.check_range(5, 7)) {
                state = fourth_going_up;
                break;
            }
            break;

        case fourth_going_up:
            if (panel_inner_.check(5) || panel_outer_.check(5)) {
                state = fifth_stop;
                break;
            }
            if (panel_inner_.check_range(6, 7) ||
                panel_outer_.check_range(6, 7)) {
                state = fifth_going_up;
                break;
            }
            break;

        case fifth_going_down:
            if (panel_outer_.check(4) || panel_inner_.check(4)) {
                state = fourth_stop;
                break;
            }
            if (panel_inner_.check_range(1, 3) ||
                panel_outer_.check_range(1, 3)) {
                state = fourth_going_down;
                break;
            }
            break;

        case fifth_stop:
            panel_inner_.reset(5);
            panel_outer_.reset(5);
            if (panel_inner_.check_range(1, 4) ||
                panel_outer_.check_range(1, 4)) {
                state = fifth_going_down;
                break;
            }
            if (panel_inner_.check_range(6, 7) ||
                panel_outer_.check_range(6, 7)) {
                state = fifth_going_up;
                break;
            }
            break;

        case fifth_going_up:
            if (panel_inner_.check(6) || panel_outer_.check(6)) {
                state = sixth_stop;
                break;
            }
            if (panel_inner_.check(7) || panel_outer_.check(7)) {
                state = sixth_going_up;
                break;
            }
            break;

        case sixth_going_down:
            if (panel_outer_.check(5) || panel_inner_.check(5)) {
                state = fifth_stop;
                break;
            }
            if (panel_inner_.check_range(1, 4) ||
                panel_outer_.check_range(1, 4)) {
                state = fifth_going_down;
                break;
            }
            break;

        case sixth_stop:
            panel_inner_.reset(6);
            panel_outer_.reset(6);
            if (panel_inner_.check_range(1, 5) ||
                panel_outer_.check_range(1, 5)) {
                state = sixth_going_down;
                break;
            }
            if (panel_inner_.check(7) || panel_outer_.check(7)) {
                state = sixth_going_up;
                break;
            }
            break;

        case sixth_going_up:
            if (panel_inner_.check(7) || panel_outer_.check(7)) {
                state = seventh_stop;
                break;
            }
            break;

        case seventh_going_down:
            if (panel_outer_.check(6) || panel_inner_.check(6)) {
                state = sixth_stop;
                break;
            }
            if (panel_inner_.check_range(1, 5) ||
                panel_outer_.check_range(1, 5)) {
                state = sixth_going_down;
                break;
            }
            break;

        case seventh_stop:
            panel_inner_.reset(7);
            panel_outer_.reset(7);
            if (panel_inner_.check_range(1, 6) ||
                panel_outer_.check_range(1, 6)) {
                state = seventh_going_down;
                break;
            }
            break;
        default:
            break;
    }

    return state_;
}
