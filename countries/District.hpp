#pragma once

#include "Area.hpp"

class District : public Area {
   public:
    District();
    District(const std::string& name, int area) : Area(name, area){};
    ~District();
};
