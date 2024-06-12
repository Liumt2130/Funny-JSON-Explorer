#include "RectangleFactory.h"

RectangleNode* RectangleFactory::create_node(const std::string& name, const std::string& value) {
    return new RectangleNode(name, value);
}
