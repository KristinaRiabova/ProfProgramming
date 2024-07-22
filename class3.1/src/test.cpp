#include <Helpers.hpp>
#include <UnitTests.hpp>
#include <gtest/gtest.h>  // я тут додала  Google Test


int main() {
    UnitTests testSuite;

    testSuite.addTest("Dummy_test1", [](){
        double value = 0.0;
        auto result = dummyFunc(value);
        ASSERT_EQ(result, 0.0); 
    });

    testSuite.addTest("Dummy_test2", [](){
        double value = -1.0;
        auto result = dummyFunc(value);
        ASSERT_NEQ(result, 0.4);
    });


    testSuite.addTest("Dummy_test3", [](){
        double value = -1.0;
        auto result = dummyFunc(value);
        ASSERT_EQ(result, 0.0); 
    });

    testSuite.addTest("RepeatStringTest_ZeroRepeat", [](){
        std::vector<int> numbers = {0, 2, 1};
        std::string str = "home";
        auto result = repeatString(numbers, str);
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatStringTest_SingleRepeat", [](){
        std::vector<int> numbers = {1, 3, 2};
        std::string str = "car";
        auto result = repeatString(numbers, str);
        ASSERT_EQ(result, "car");
    });

    testSuite.addTest("RepeatStringTest_MultipleRepeat", [](){
        std::vector<int> numbers = {2, 4, 3};
        std::string str = "apple";
        auto result = repeatString(numbers, str);
        ASSERT_EQ(result, "appleapple");
    });

    testSuite.addTest("RepeatStringTest_EmptyString", [](){
        std::vector<int> numbers = {3, 5, 1};
        std::string str = "";
        auto result = repeatString(numbers, str);
        ASSERT_EQ(result, "");
    });

    testSuite.addTest("RepeatStringTest_EmptyVector", [](){
        std::vector<int> numbers;
        std::string str = "test";
        auto result = repeatString(numbers, str);
        ASSERT_EQ(result, "");
    });

    testSuite.run();
}
