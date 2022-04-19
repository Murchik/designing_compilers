#pragma once

#include "Region.hpp"

class Country : public Area {
   public:
    Country();
    Country(const std::string& name, int area) : Area(name, area){};
    ~Country();

    void addRegion(const Region& area);
    void addRegion(const std::string& name, int area);

    bool isValid();

    std::vector<Region>::const_iterator begin() const;
    std::vector<Region>::const_iterator end() const;

   private:
    std::vector<Region> _regions;
};
