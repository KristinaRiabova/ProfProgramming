#include <UnitTests.hpp>
#include <Helpers.hpp>

int main() {
    UnitTests testSuite;

    testSuite.addTest("Test_empty_vector",
    [](){
        std::vector<int> integers;
        std::string result = repeatString(integers, "home");
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("Test_repeat_string",
    [](){
        std::vector<int> integers = {0, 2, 1};
        std::string result = repeatString(integers, "home");
        ASSERT_EQ(result, "homehome");
    });

    testSuite.addTest("Test_repeat_string_single",
    [](){
        std::vector<int> integers = {3};
        std::string result = repeatString(integers, "hello");
        ASSERT_EQ(result, "hellohellohello");
    });

    testSuite.addTest("Test_repeat_string_zero",
    [](){
        std::vector<int> integers = {0, 0, 0};
        std::string result = repeatString(integers, "test");
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("Test_repeat_string_negative",
    [](){
        std::vector<int> integers = {-1, -2, -3};
        std::string result = repeatString(integers, "negative");
        ASSERT_EQ(result, "");
    });

    testSuite.run();
}
