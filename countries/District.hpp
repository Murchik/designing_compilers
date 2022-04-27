#pragma once

#include "Area.hpp"

class District : public Area {
   public:
    District();
    ~District();

    virtual bool isValid() override;

    virtual Area* createChild() override;
    virtual Area* createSibling() override;
};
