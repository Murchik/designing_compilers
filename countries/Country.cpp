#include "Country.hpp"

#include <iostream>

Country::Country() {}

Country::~Country() {}

void Country::addRegion(const Region& area) { _regions.emplace_back(area); }

void Country::addRegion(const std::string& name, int area) {
    _regions.emplace_back(Region(name, area));
}

bool Country::isValid() {
    int regionsArea = 0;
    for (const auto& region : _regions) {
        if (!region.isValid()) {
            return false;
        }
        regionsArea += region.getArea();
    }
    if (_area != regionsArea) {
        return false;
    }
    return true;
}

std::vector<Region>::const_iterator Country::begin() const {
    return _regions.begin();
}

std::vector<Region>::const_iterator Country::end() const {
    return _regions.end();
}
