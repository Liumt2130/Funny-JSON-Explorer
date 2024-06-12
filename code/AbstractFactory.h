#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include <string>

class Node;  // Forward declaration

class AbstractFactory {
public:
    virtual Node* create_node(const std::string& name, const std::string& value = nullptr) = 0;
};

#endif // ABSTRACTFACTORY_H
