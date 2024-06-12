#include "Node.h"
#include "IconFamily.h"  // Include only if IconFamily is used

Node::Node(const std::string& name, const std::string& value)
    : name(name), value(value), level(0), isLast(false), Lastchar(false), FirstRow(false), LastRow(false) {}

void Node::add_child(Node* child) {
    children.push_back(child);
    child->level = level + 1;
}

void Node::display(IconFamily* icon_family) const {
    // Placeholder for display logic, potentially using icon_family
}

void Node::display_without_root(IconFamily* icon_family) const {
    // Placeholder for display without root logic, potentially using icon_family
}

void Node::set_isLast(bool isLast) {
    this->isLast = isLast;
}

void Node::set_Lastchar(bool Lastchar) {
    this->Lastchar = Lastchar;
}

void Node::set_FirstRow(bool FirstRow) {
    this->FirstRow = FirstRow;
}

void Node::set_LastRow(bool LastRow) {
    this->LastRow = LastRow;
}
