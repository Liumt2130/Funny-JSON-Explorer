#include "Builder.h"
#include <unordered_map>

Builder::Builder(AbstractFactory* factory) : factory(factory) {}

Node* Builder::build(const std::unordered_map<std::string, std::string>& data) {
    Node* root = factory->create_node("root");
    recbuild(root, data);
    first_row(root);
    last_row(root);
    return root;
}

void Builder::display(Node* root_node) {
    root_node->display();
}

void Builder::display_without_root(Node* root_node) {
    root_node->display_without_root();
}

void Builder::recbuild(Node* parent_node, const std::unordered_map<std::string, std::string>& data, int level, bool Lastchar) {
    int data_len = data.size();
    for (auto it = data.begin(); it != data.end(); ++it) {
        const std::string& key = it->first;
        const std::string& value = it->second;

        if (level == 0) {
            if (std::next(it) == data.end()) {
                Lastchar = true;
            } else {
                Lastchar = false;
            }
        }

        Node* node = factory->create_node(key, value);
        parent_node->adding_child(node);

        if (it == data.begin()) {
            node->isFirst = true;
        } else {
            node->isFirst = false;
        }

        if (std::next(it) == data.end()) {
            node->isLast = true;
        } else {
            node->isLast = false;
        }

        node->level = level;
        node->Lastchar = Lastchar;

        if (!value.empty()) {
            node->value = value;
        }

        if (value.empty() || value == "None") {
            node->value = "";
        }

        if (value.empty() || value == "None") {
            node->value = "";
        }

        recbuild(node, {}, level + 1, Lastchar);
    }
}

void Builder::first_row(Node* root_node) {
    root_node->children[0]->FirstRow = true;
}

void Builder::last_row(Node* root_node) {
    if (root_node->children.size() > 1) {
        last_row(root_node->children.back());
    } else if (root_node->children.size() == 1) {
        last_row(root_node->children[0]);
    } else {
        root_node->LastRow = true;
    }
}
