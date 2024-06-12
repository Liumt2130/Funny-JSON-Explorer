#include <iostream>
#include <fstream>
#include "Builder.h"
#include "Factory.h"
#include "ConIconFamily.h"
#include "NumIconFamily.h"
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // 读取JSON数据
    std::ifstream file("data.json");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    json data;
    file >> data;

    // 创建tree工厂
    Factory* treeFactory = Factory::get_factory("tree");
    // 创建节点树并展示
    Builder treeBuilder(treeFactory);
    Node* rootTree = treeBuilder.build(data);
    // 图标族1
    ConIconFamily iconFamily1;
    treeBuilder.display(rootTree, &iconFamily1);

    // 创建rectangle工厂
    Factory* rectangleFactory = Factory::get_factory("rectangle");
    Builder rectangleBuilder(rectangleFactory);
    Node* rootRectangle = rectangleBuilder.build(data);
    rectangleBuilder.display(rootRectangle, &iconFamily1);

    // 创建tree工厂
    Factory* treeFactory2 = Factory::get_factory("tree");
    // 创建节点树并展示
    Builder treeBuilder2(treeFactory2);
    Node* rootTree2 = treeBuilder2.build(data);
    // 图标族2
    ConIconFamily iconFamily2;
    treeBuilder2.display(rootTree2, &iconFamily2);

    // 创建rectangle工厂
    Factory* rectangleFactory2 = Factory::get_factory("rectangle");
    Builder rectangleBuilder2(rectangleFactory2);
    Node* rootRectangle2 = rectangleBuilder2.build(data);
    rectangleBuilder2.display(rootRectangle2, &iconFamily2);

    return 0;
}
