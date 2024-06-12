#include "RectangleNode.h"
#include "IconFamily.h"
#include <iostream>
#include <iomanip> // For std::setw

RectangleNode::RectangleNode(const std::string& name, const std::string& value)
    : Node(name, value) {}

void RectangleNode::display(IconFamily* icon_family) const {
    // Prevent displaying root node
    for (const auto& child : children) {
        child->display_without_root(icon_family);
    }
}

void RectangleNode::display_without_root(IconFamily* icon_family) const {
    std::string icon = " ";
    if (icon_family != nullptr) {
        if (children.empty()) {
            icon = icon_family->leaficon;
        } else {
            icon = icon_family->midicon;
        }
    }

    std::string display_value = value;
    if (!value.empty() && value != "None") {
        display_value = ": " + value;
    }

    std::string cur_str;
    if (FirstRow) {
        cur_str = "┌─" + icon + name + display_value + " ";
        std::cout << cur_str << std::setw(length - cur_str.length() - 1) << std::setfill('─') << "┐" << std::endl;
    } else if (LastRow) {
        cur_str = std::string(level, ' ') + "└──" + "└─" + icon + name + display_value + " ";
        std::cout << cur_str << std::setw(length - cur_str.length() - 1) << std::setfill('─') << "┘" << std::endl;
    } else {
        cur_str = std::string(level, ' ') + "|  " + "├─" + icon + name + display_value + " ";
        std::cout << cur_str << std::setw(length - cur_str.length() - 1) << std::setfill('─') << "┤" << std::endl;
    }

    // Recursively display child nodes
    for (const auto& child : children) {
        child->display_without_root(icon_family);
    }
}
