#pragma once

#include <vector>

#include "District.hpp"

class Region : public Area {
   public:
    Region();
    ~Region();

    bool isValid() const;

    virtual Area* createChild() override;
    virtual Area* createSibling() override;

    std::vector<District*>::const_iterator begin() const;
    std::vector<District*>::const_iterator end() const;

   private:
    std::vector<District*> _districts;
};
