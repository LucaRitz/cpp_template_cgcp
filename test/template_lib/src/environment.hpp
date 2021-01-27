#pragma once

#include <gtest/gtest.h>

namespace templatelib::test {
    class Environment : public ::testing::Environment {
    public:
        ~Environment() override;

        // Override this to define how to set up the environment.
        void SetUp() override;

        // Override this to define how to tear down the environment.
        void TearDown() override;
    };
}