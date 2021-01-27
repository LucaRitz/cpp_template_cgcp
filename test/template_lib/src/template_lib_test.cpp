#include <gtest/gtest.h>
#include <template_lib/template_lib.hpp>
#include <fstream>
#include <nlohmann/json.hpp>
#include <iostream>
#include <chrono>

class TemplateLibTests : public ::testing::TestWithParam<std::string> {
};

TEST_P(TemplateLibTests, expectedValues) {
    const auto& testCasePath = GetParam();
    std::ifstream descriptionFile(testCasePath + "/description.json");
    nlohmann::json descriptionJson;
    descriptionFile >> descriptionJson;

    unsigned long long durations = 0;

    for (auto& test : descriptionJson) {
        std::cout << "TEST: -- " << test["title"] << std::endl;
        std::cout << "DESC: -- " << test["description"] << std::endl;

        // Act
        auto start = std::chrono::high_resolution_clock::now();

        auto result = templatelib::type(test["input"]["type"]["value"]);

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        durations += duration.count();
        std::cout << "Duration (in ms): " << duration.count() << std::endl;

        // Assert
        ASSERT_EQ(test["expected"]["type"]["value"], result._value);
    }
    std::cout << "Average duration (in ms): " << (durations / descriptionJson.size()) << std::endl;
}


INSTANTIATE_TEST_CASE_P
(
        TemplateLibTest,
        TemplateLibTests,
        ::testing::Values(
                "./resources/00_test_case_1"
        ));