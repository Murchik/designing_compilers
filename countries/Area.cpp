#include "Area.hpp"

Area::Area() {}

Area::~Area() {}

int Area::getArea() const { return _area; }

int Area::setArea(int area) {
    if (area < 1 || area > 999) return -1;
    _area = area;
    return getArea();
}

std::string Area::getName() const { return _name; }

std::string Area::setName(const std::string& name) {
    if (name == "") {
        return "";
    }
    _name = name;
    return getName();
}

std::ostream& operator<<(std::ostream& os, const Area& a) {
    os << a.getName() << " : " << a.getArea();
    return os;
}
