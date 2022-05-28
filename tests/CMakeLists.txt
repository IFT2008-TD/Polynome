set(TEST_SOURCES tests_polynome.cpp ${PROJECT_SOURCE_DIR}/Polynome.h)

add_executable(
        tests_polynome
        ${TEST_SOURCES}
)

target_include_directories(tests_polynome PRIVATE ${PROJECT_SOURCE_DIR} )

target_link_libraries(
        tests_polynome
        gtest_main
        gtest
        pthread
)

include(GoogleTest)
gtest_discover_tests(tests_polynome)