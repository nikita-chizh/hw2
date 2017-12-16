#pragma once

#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string &str, char sign, unsigned int words);

bool ip_validate(const std::string &str);

