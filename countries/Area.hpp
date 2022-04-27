#pragma once

#include <iostream>
#include <string>

class Area {
   public:
    Area();
    virtual ~Area();

    int getArea() const;
    int setArea(int area);

    std::string getName() const;
    std::string setName(const std::string& name);

    Area* getParent() const;
    void setParent(Area*);

    virtual Area* createChild() = 0;
    virtual Area* createSibling() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Area& c);

   protected:
    int _area{0};
    std::string _name{""};

    Area* _parent = nullptr;
};
