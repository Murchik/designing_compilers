#ifndef BUTTONS_PANEL_HPP
#define BUTTONS_PANEL_HPP

#include <array>

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

#endif
