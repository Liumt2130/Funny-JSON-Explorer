#ifndef RECTANGLENODE_H
#define RECTANGLENODE_H

#include "Node.h"

class RectangleNode : public Node {
public:
    RectangleNode(const std::string& name, const std::string& value = "");
    void display(IconFamily* icon_family = nullptr) const override;
    void display_without_root(IconFamily* icon_family = nullptr) const override;

private:
    static const int length = 50;
};

#endif // RECTANGLENODE_H
