#ifndef ICONFAMILY_H
#define ICONFAMILY_H

#include <string>

class IconFamily {
public:
    IconFamily(const std::string& midicon, const std::string& leaficon);
    std::string getMidicon() const;
    std::string getLeaficon() const;

private:
    std::string midicon;
    std::string leaficon;
};

#endif // ICONFAMILY_H
