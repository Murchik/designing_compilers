#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include "buttons_panel.hpp"
#include "states.hpp"

class elevator {
   public:
    void press(int floor_number) { panel_.press(floor_number); }

    void reset(int floor_number) { panel_.reset(floor_number); }

    states state() { return state_; }

    void change_state(int i);

   private:
    buttons_panel<7> panel_;
    states state_ = first_stop;
};

#endif
