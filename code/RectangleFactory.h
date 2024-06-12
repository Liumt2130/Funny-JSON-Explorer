#ifndef RECTANGLEFACTORY_H
#define RECTANGLEFACTORY_H

#include "AbstractFactory.h"
#include "RectangleNode.h"

class RectangleFactory : public AbstractFactory {
public:
    RectangleNode* create_node(const std::string& name, const std::string& value = nullptr) override;
};

#endif // RECTANGLEFACTORY_H
