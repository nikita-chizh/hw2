#include "hw2.h"
#include <boost/lexical_cast.hpp>


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
//
std::vector<unsigned> ip_split(const std::string &str){
    std::vector<std::string> ip_tokens = split(str, '.', 4);
    if(ip_tokens.size() != 4) throw std::runtime_error("invalid ip string");
    std::vector<unsigned> result;
    for(auto& token: ip_tokens){
        try {
            auto byte = boost::lexical_cast<int>(token);
            if(byte < 0 || byte > 255) throw std::runtime_error("invalid ip string");
            result.push_back(byte);
        } catch (boost::bad_lexical_cast& ex) {
            throw std::runtime_error("invalid ip string");
        }
    }
    return result;
}

//
bool ip_validate(const std::string &str){
    std::vector<std::string> ip_tokens = split(str, '.', 4);
    if(ip_tokens.size() != 4) return false;
    for(auto& token: ip_tokens){
        try {
            auto byte = boost::lexical_cast<int>(token);
            if(byte < 0 || byte > 255) return false;
        } catch (boost::bad_lexical_cast& ex) {
            return false;
        }
    }
    return true;
}
