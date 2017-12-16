#include "hw2.h"
#include <spdlog/spdlog.h>
int main(int argc, char* argv[]){
    auto logger = spdlog::stdout_logger_mt("console");
    logger -> info("hello world");
    return 0;
}
