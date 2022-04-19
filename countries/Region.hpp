#pragma once

#include <vector>

#include "District.hpp"

class Region : public Area {
   public:
    Region();
    Region(const std::string& name, int area) : Area(name, area){};
    ~Region();

    void addDistrict(const District& area);
    void addDistrict(const std::string& name, int area);

    bool isValid() const;

    std::vector<District>::const_iterator begin() const;
    std::vector<District>::const_iterator end() const;

   private:
    std::vector<District> _districts;
};
