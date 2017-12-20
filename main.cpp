#include <iostream>
#include <algorithm>
#include <functional>
#include "IP_Adress.h"
auto always_true = [](const IP_Adress& s){
    return true;
};
void conditional_show(const std::vector<IP_Adress>& ips,
                      const std::function<bool(const IP_Adress&)>& cond = always_true){
    for(const auto& i: ips){
        if(cond(i))
            std::cout<<i;
    }
}

int main(int argc, char *argv[]) {


    std::vector<IP_Adress> ips;
    std::string str;
    while (getline(std::cin, str)) {
        try {
            std::vector<std::string> spliting = split(str, '\t', 1);
            ips.emplace_back(IP_Adress(spliting[0]));
        }
        catch(std::runtime_error& err){

        }
    }
    //opposite of < operator
    auto ip_greater = [](const IP_Adress &f, const IP_Adress &s){
        return !(f < s);
    };
    std::sort(ips.begin(), ips.end(), ip_greater);
    //sorted
    conditional_show(ips);
    //all 1
    auto all_1 = [](const IP_Adress& ip){
        auto& tokens = ip.get_tokens();
        if(tokens[0] == 1)
            return true;
    };
    conditional_show(ips, all_1);
    // any 46
    auto any_46 = [](const IP_Adress& ip){
        auto& tokens = ip.get_tokens();
        if(std::find(tokens.begin(), tokens.end(), 46) != tokens.end())
            return true;
    };
    conditional_show(ips, any_46);
    return 0;
}
