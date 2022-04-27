#pragma once

#include "Area.hpp"

class District : public Area {
   public:
    District();
    ~District();

    virtual Area* createChild() override;
    virtual Area* createSibling() override;
};
