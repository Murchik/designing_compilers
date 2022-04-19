#include "Region.hpp"

#include <iostream>

Region::Region() {}

Region::~Region() {}

void Region::addDistrict(const District& area) {
    _districts.emplace_back(area);
}

void Region::addDistrict(const std::string& name, int area) {
    _districts.emplace_back(District(name, area));
}

bool Region::isValid() const {
    int districtsArea = 0;
    for (const auto& district : _districts) {
        districtsArea += district.getArea();
    }
    if (_area != districtsArea) {
        return false;
    }
    return true;
}

std::vector<District>::const_iterator Region::begin() const {
    return _districts.begin();
}

std::vector<District>::const_iterator Region::end() const {
    return _districts.end();
}
