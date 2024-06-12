#include "TreeNode.h"
#include <iostream>

void TreeNode::display(IconFamily* icon_family) const {
    for (const auto& child : children) {
        child->display_without_root(icon_family);
    }
}

void TreeNode::display_without_root(IconFamily* icon_family) const {
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

    std::string prefix;
    if (level > 0) {
        if (Lastchar) {
            prefix += std::string((level - 1) * 3, ' ');
        } else {
            prefix += "|  " + std::string((level - 1) * 3, ' ');
        }
    }

    std::string node_line;
    if (isLast) {
        node_line = prefix + "└─" + icon + name + display_value;
    } else {
        node_line = prefix + "├─" + icon + name + display_value;
    }

    std::cout << node_line << std::endl;

    for (const auto& child : children) {
        child->display_without_root(icon_family);
    }
}
