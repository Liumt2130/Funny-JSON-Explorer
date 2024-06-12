#include "Factory.h"

AbstractFactory* Factory::get_factory(const std::string& style_type) {
    if (style_type == "tree") {
        return new TreeFactory();
    } else if (style_type == "rectangle") {
        return new RectangleFactory();
    } else {
        throw std::invalid_argument("Unknown style type: " + style_type);
    }
}
