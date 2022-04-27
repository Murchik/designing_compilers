#include "District.hpp"

District::District() {}

District::~District() {}

Area* District::createChild() { return nullptr; }

Area* District::createSibling() { return _parent->createChild(); }
