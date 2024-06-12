#include "TreeFactory.h"

TreeNode* TreeFactory::create_node(const std::string& name, const std::string& value) {
    return new TreeNode(name, value);
}
