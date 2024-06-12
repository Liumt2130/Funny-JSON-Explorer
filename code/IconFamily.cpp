#include "IconFamily.h"

IconFamily::IconFamily(const std::string& midicon, const std::string& leaficon)
    : midicon(midicon), leaficon(leaficon) {}

std::string IconFamily::getMidicon() const {
    return midicon;
}

std::string IconFamily::getLeaficon() const {
    return leaficon;
}
