#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <boost/lexical_cast.hpp>
std::vector<std::string> split(const std::string &str, char sign, unsigned int words);

std::vector<unsigned> ip_split(const std::string &str);

bool ip_validate(const std::string &str);
