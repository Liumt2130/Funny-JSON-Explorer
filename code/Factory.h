#ifndef FACTORY_H
#define FACTORY_H

#include <string>
#include "TreeFactory.h"
#include "RectangleFactory.h"

class Factory {
public:
    static AbstractFactory* get_factory(const std::string& style_type);
};

#endif // FACTORY_H
