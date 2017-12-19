//
// Created by nikita on 19.12.17.
//

#include "IP_Adress.h"
IP_Adress::IP_Adress(const std::string &str){
    if(!ip_validate(str))
        throw std::runtime_error("str is not ip");
    ip_str = str;
    tokens = ip_split(str);
}

const bool operator < (const IP_Adress &left, const IP_Adress &right){
    for(int i = 0; i < 4; ++i){
        if(left.tokens[i] < right.tokens[i]) return true;
        else if(left.tokens[i] > right.tokens[i]) return false;
    }
    //all tokens are equal case
    return false;
}

const std::ostream& operator << (std::ostream &s, const IP_Adress &ip){
    s<<ip.ip_str<<std::endl;
}


