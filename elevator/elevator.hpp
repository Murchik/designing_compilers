#ifndef ELEVATOR_HPP
#define ELEVATOR_HPP

#include "buttons_panel.hpp"
#include "states.hpp"

class elevator {
   public:
    void press_inside(int floor_number);
    void press_outside(int floor_number);

    states state();

    void update_state();

    states get_new_state(buttons_panel<7>& panel);

   private:
    buttons_panel<7> panel_inner_;
    buttons_panel<7> panel_outer_;
    states state_ = first_stop;
};

#endif
