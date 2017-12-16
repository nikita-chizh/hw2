#define BOOST_TEST_MODULE TestMain

#include <spdlog/spdlog.h>
#include <boost/test/unit_test.hpp>
#include "hw.h"

using in_out = std::pair<std::string, std::vector<std::string>>;

BOOST_AUTO_TEST_SUITE(test_split)

    BOOST_AUTO_TEST_CASE(test_split_general) {
        std::vector<in_out> cases = {
                {"",     {""}},
                {"11",    {"11"}},
                {"..",    {"",   "", ""}},
                {"11.",   {"11", ""}},
                {".11",   {"",   "11"}},
                {"11.22", {"11", "22"}},
        };
        BOOST_CHECK(split(cases[0].first, '.', 3) == cases[0].second);
        BOOST_CHECK(split(cases[1].first, '.', 3) == cases[1].second);
        BOOST_CHECK(split(cases[2].first, '.', 3) == cases[2].second);
        BOOST_CHECK(split(cases[3].first, '.', 3) == cases[3].second);
        BOOST_CHECK(split(cases[4].first, '.', 3) == cases[4].second);
        BOOST_CHECK(split(cases[5].first, '.', 3) == cases[5].second);
    }

    BOOST_AUTO_TEST_CASE(test_split_with_num) {
        std::vector<in_out> cases = {
                {"11.22. sdbvsd", {"11"}},
                {".11.22. sdbvsd", {""}},
                {"123.11.22. sdbvsd", {"123"}}
        };
        BOOST_CHECK(split(cases[0].first, '.', 1) == cases[0].second);
        BOOST_CHECK(split(cases[1].first, '.', 1) == cases[1].second);
        BOOST_CHECK(split(cases[2].first, '.', 1) == cases[2].second);
    }


BOOST_AUTO_TEST_SUITE_END()