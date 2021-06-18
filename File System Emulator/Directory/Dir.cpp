#include "Dir.h"

std::string Dir::getName() const {return _name;}
void Dir::setName(std::string name) {_name = std::move(name);}