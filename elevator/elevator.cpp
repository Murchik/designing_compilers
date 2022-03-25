#include "elevator.hpp"

void elevator::change_state(int i) {
    switch (state_) {
        case first_stop:
            panel_.reset(1);
            if (panel_.check_range(2, 7)) {
                state_ = first_going_up;
            }
            break;

        case first_going_up:
            if (panel_.check(2)) {
                state_ = second_stop;
            } else if (panel_.check_range(3, 7)) {
                state_ = second_going_up;
            }
            break;

        case second_going_down:
            state_ = first_stop;
            break;

        case second_stop:
            panel_.reset(2);
            if (panel_.check(1)) {
                state_ = second_going_down;
            }
            break;

        case second_going_up:
            if (panel_.check(3)) {
                state_ = third_stop;
            } else if (panel_.check_range(4, 7)) {
                state_ = third_going_up;
            }
            break;

        case third_going_down:
            if (panel_.check(1)) {
                state_ = second_going_down;
            } else if (panel_.check(2)) {
                state_ = second_stop;
            }
            break;

        case third_stop:
            panel_.reset(3);
            if (panel_.check_range(1, 2)) {
                state_ = third_going_down;
            } else if (panel_.check_range(3, 7)) {
                state_ = third_going_up;
            }
            break;

        case third_going_up:
            if (panel_.check(4)) {
                state_ = fourth_stop;
            } else if (panel_.check_range(5, 7)) {
                state_ = fourth_going_up;
            }
            break;

        case fourth_going_down:
            if (panel_.check(3)) {
                state_ = third_stop;
            } else if (panel_.check_range(1, 2)) {
                state_ = third_going_down;
            }
            break;

        case fourth_stop:
            panel_.reset(4);
            if (panel_.check_range(1, 3)) {
                state_ = fourth_going_down;
            } else if (panel_.check_range(5, 7)) {
                state_ = fourth_going_up;
            }
            break;

        case fourth_going_up:
            if (panel_.check(5)) {
                state_ = fifth_stop;
            } else if (panel_.check_range(6, 7)) {
                state_ = fifth_going_up;
            }
            break;

        case fifth_going_down:
            if (panel_.check(4)) {
                state_ = fourth_stop;
            } else if (panel_.check_range(1, 3)) {
                state_ = fourth_going_down;
            }
            break;

        case fifth_stop:
            panel_.reset(5);
            if (panel_.check_range(1, 4)) {
                state_ = fifth_going_down;
            } else if (panel_.check_range(6, 7)) {
                state_ = fifth_going_up;
            }
            break;

        case fifth_going_up:
            if (panel_.check(6)) {
                state_ = sixth_stop;
            } else if (panel_.check(7)) {
                state_ = sixth_going_up;
            }
            break;

        case sixth_going_down:
            if (panel_.check(5)) {
                state_ = fifth_stop;
            } else if (panel_.check_range(1, 4)) {
                state_ = fifth_going_down;
            }
            break;

        case sixth_stop:
            panel_.reset(6);
            if (panel_.check_range(1, 5)) {
                state_ = sixth_going_down;
            } else if (panel_.check(7)) {
                state_ = sixth_going_up;
            }
            break;

        case sixth_going_up:
            if (panel_.check(7)) {
                state_ = seventh_stop;
            }
            break;

        case seventh_going_down:
            if (panel_.check(6)) {
                state_ = sixth_stop;
            } else if (panel_.check_range(1, 5)) {
                state_ = sixth_going_down;
            }
            break;

        case seventh_stop:
            panel_.reset(7);
            if (panel_.check_range(1, 6)) {
                state_ = seventh_going_down;
            }
            break;
        default:
            break;
    }
}
