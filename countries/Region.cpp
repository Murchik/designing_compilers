#include "Region.hpp"

#include <iostream>

Region::Region() {}

Region::~Region() {}

bool Region::isValid() {
    int districtsArea = 0;
    for (auto& district : _districts) {
        districtsArea += district->getArea();
    }
    if (_area != districtsArea) {
        return false;
    }
    return true;
}

Area* Region::createChild() {
    District* tmpDistPtr = new District();
    tmpDistPtr->setParent(this);
    _districts.emplace_back(tmpDistPtr);
    return tmpDistPtr;
}

Area* Region::createSibling() { return _parent->createChild(); }

std::vector<District*>::const_iterator Region::begin() const {
    return _districts.begin();
}

std::vector<District*>::const_iterator Region::end() const {
    return _districts.end();
}
