#include "hw2lib.h"
#include <spdlog/spdlog.h>
int main(int argc, char* argv[]){
    auto logger = spdlog::stdout_logger_mt("console");
    logger -> info("version {}", version());
    std::cout<<"hello world1";
    return 0;
}
