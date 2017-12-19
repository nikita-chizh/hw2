//
// Created by nikita on 19.12.17.
//
#pragma once

#include <exception>
#include "hw2.h"
#include <ostream>
class IP_Adress {
public:
    IP_Adress() = delete;
    explicit IP_Adress(const std::string &str);
    friend const bool operator < (const IP_Adress &left, const IP_Adress &right);
    friend const std::ostream& operator << (std::ostream &s, const IP_Adress &ip);
    const std::vector<unsigned>& get_tokens() const{
        return tokens;
    }
private:
    std::string ip_str;
    std::vector<unsigned > tokens;

};


