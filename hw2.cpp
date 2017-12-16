#include "hw.h"
#include "version.h"

int version(){
    return PROJECT_VERSION_PATCH;
}

std::vector<std::string> split(const std::string &str, char d, unsigned int words){
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    unsigned int counter = 1;
    while(counter < words && stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
        ++counter;
    }
    r.push_back(str.substr(start, stop - start));
    return r;
}
