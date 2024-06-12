#ifndef TREEFACTORY_H
#define TREEFACTORY_H

#include "AbstractFactory.h"
#include "TreeNode.h"

class TreeFactory : public AbstractFactory {
public:
    TreeNode* create_node(const std::string& name, const std::string& value = nullptr) override;
};

#endif // TREEFACTORY_H
