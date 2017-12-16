cmake_minimum_required(VERSION 3.2)
MESSAGE(STATUS $ENV{TRAVIS_BUILD_NUMBER})
project(hw2 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
find_package(Boost COMPONENTS unit_test_framework REQUIRED)
set(CMAKE_CXX_STANDARD 14)

configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

add_executable(hw2_cli main.cpp)
add_executable(test_version test.cpp)


add_library(hw2 hw2.cpp)

set_target_properties(hw2_cli hw2 test_version PROPERTIES
        CXX_STANDART 14
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

set_target_properties(test_version PROPERTIES
        COMPILE_DEFENITONS BOOST_TEST_DYN_LINK
        INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
        )
ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

target_link_libraries(hw2_cli hw2 pthread)

target_link_libraries(test_version
        ${Boost_LIBRARIES}
        hw2
        pthread
        )
install(TARGETS hw2_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT nikita1993chizh@gmail.com)
include(CPack)
enable_testing()
add_test(test_version test_version)