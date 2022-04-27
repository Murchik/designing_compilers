#pragma once

#include "Region.hpp"

class Country : public Area {
   public:
    Country();
    ~Country();

    virtual bool isValid() override;

    virtual Area* createChild() override;
    virtual Area* createSibling() override;

    std::vector<Region*>::const_iterator begin() const;
    std::vector<Region*>::const_iterator end() const;

   private:
    std::vector<Region*> _regions;
};
