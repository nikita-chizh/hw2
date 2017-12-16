#define BOOST_TEST_MODULE TestMain

#include <spdlog/spdlog.h>
#include <boost/test/unit_test.hpp>
#include "hw.h"

using in_out = std::pair<std::string, std::vector<std::string>>;

BOOST_AUTO_TEST_SUITE(test_suite)

    BOOST_AUTO_TEST_CASE(test_version) {
        auto console = spdlog::stdout_logger_st("console");
        console->info("test version1()");

        BOOST_CHECK(version() > 0);
    }

    BOOST_AUTO_TEST_CASE(test_split) {
        std::vector<in_out> tests = {
                {"",     {""}},
                {"11",    {"11"}},
                {"..",    {"",   "", ""}},
                {"11.",   {"11", ""}},
                {".11",   {"",   "11"}},
                {"11.22", {"11", "22"}},
        };
        BOOST_CHECK(split(tests[0].first, '.', 3) == tests[0].second);
        BOOST_CHECK(split(tests[1].first, '.', 3) == tests[1].second);
        BOOST_CHECK(split(tests[2].first, '.', 3) == tests[2].second);
        BOOST_CHECK(split(tests[3].first, '.', 3) == tests[3].second);
        BOOST_CHECK(split(tests[4].first, '.', 3) == tests[4].second);
        BOOST_CHECK(split(tests[5].first, '.', 3) == tests[5].second);
    }


BOOST_AUTO_TEST_SUITE_END()