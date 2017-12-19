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
    std::vector<std::string> ip_strs = {
            "1.10.1.1",
            "1.2.1.1",
            "1.1.1.1",
            "1.1.234.8",
            "222.173.235.246",
            "222.82.198.61",
            "1.70.44.170",
            "1.29.168.152",
            "222.130.177.64",
            "1.231.69.33",
            "46.70.225.39",
            "46.70.147.26",
            "46.70.113.73",
            "46.70.29.76",
            "228.46.29.76"
    };
    std::vector<IP_Adress> ips;
    for(const auto& str: ip_strs){
        ips.emplace_back(IP_Adress(str));
    }
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
    std::cout<<"ALL 1's"<<std::endl;
    conditional_show(ips, all_1);
    // all_46_70
    auto all_46_70 = [](const IP_Adress& ip){
        auto& tokens = ip.get_tokens();
        if(tokens[0] == 46 && tokens[1] == 70)
            return true;
    };
    std::cout<<"ALL 46's"<<std::endl;
    conditional_show(ips, all_46_70);
    // any 46
    std::cout<<"ANY 46's"<<std::endl;
    auto any_46 = [](const IP_Adress& ip){
        auto& tokens = ip.get_tokens();
        if(std::find(tokens.begin(), tokens.end(), 46) != tokens.end())
            return true;
    };
    conditional_show(ips, any_46);
    return 0;
}
