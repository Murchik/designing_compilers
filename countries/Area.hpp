#pragma once

#include <string>

class Area {
   public:
    Area();
    Area(const Area& area) : _name(area._name) { this->setArea(area._area); }
    Area(const std::string& name, int area) : _name(name) {
        this->setArea(area);
    }
    virtual ~Area();

    int getArea() const;
    int setArea(int area);

    std::string getName() const;
    std::string setName(const std::string& name);

   protected:
    int _area{0};
    std::string _name{""};
};