#ifndef TREENODE_H
#define TREENODE_H

#include "Node.h"

class TreeNode : public Node {
public:
    void display(IconFamily* icon_family = nullptr) const override;
    void display_without_root(IconFamily* icon_family = nullptr) const override;
};

#endif // TREENODE_H
