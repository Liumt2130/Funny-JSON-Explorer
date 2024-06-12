#ifndef BUILDER_H
#define BUILDER_H

#include <unordered_map>
#include "AbstractFactory.h"
#include "Node.h"

class Builder {
public:
    Builder(AbstractFactory* factory);
    Node* build(const std::unordered_map<std::string, std::string>& data);
    void display(Node* root_node);
    void display_without_root(Node* root_node);

private:
    AbstractFactory* factory;

    void recbuild(Node* parent_node, const std::unordered_map<std::string, std::string>& data, int level = 0, bool Lastchar = false);
    void first_row(Node* root_node);
    void last_row(Node* root_node);
};

#endif // BUILDER_H
