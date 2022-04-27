#include "Country.hpp"

#include <iostream>

Country::Country() {}

Country::~Country() {}

bool Country::isValid() {
    int regionsArea = 0;
    for (auto& region : _regions) {
        if (!region->isValid()) {
            return false;
        }
        regionsArea += region->getArea();
    }
    if (_area != regionsArea) {
        return false;
    }
    return true;
}

Area* Country::createChild() {
    Region* tmpRegPtr = new Region();
    tmpRegPtr->setParent(this);
    _regions.emplace_back(tmpRegPtr);
    return tmpRegPtr;
}

Area* Country::createSibling() { return nullptr; }

std::vector<Region*>::const_iterator Country::begin() const {
    return _regions.begin();
}

std::vector<Region*>::const_iterator Country::end() const {
    return _regions.end();
}
