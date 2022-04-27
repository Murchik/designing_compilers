#include "District.hpp"

District::District() {}

District::~District() {}

bool District::isValid() { return false; }

Area* District::createChild() { return nullptr; }

Area* District::createSibling() { return _parent->createChild(); }
