#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>

class IconFamily;  // Forward declaration

class Node {
public:
    Node(const std::string& name, const std::string& value = "");
    void add_child(Node* child);
    virtual void display(IconFamily* icon_family = nullptr) const;
    virtual void display_without_root(IconFamily* icon_family = nullptr) const;

    void set_isLast(bool isLast);
    void set_Lastchar(bool Lastchar);
    void set_FirstRow(bool FirstRow);
    void set_LastRow(bool LastRow);

protected:
    std::string name;
    std::string value;
    std::vector<Node*> children;
    int level;
    bool isLast;
    bool Lastchar;
    bool FirstRow;
    bool LastRow;
};

#endif // NODE_H
