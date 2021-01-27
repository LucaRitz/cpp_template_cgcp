#include "gtest/gtest.h"
#include "environment.hpp"

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::Environment* const foo_env =
            ::testing::AddGlobalTestEnvironment(new templatelib::test::Environment());


    return RUN_ALL_TESTS();
}