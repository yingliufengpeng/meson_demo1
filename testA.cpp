#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// 测试加法函数
TEST(MathUtilsTest, Addition) {
EXPECT_EQ(add(2, 3), 5);
EXPECT_EQ(add(-1, 1), 0);
EXPECT_EQ(add(0, 0), 0);
}

// 测试减法函数
TEST(MathUtilsTest, Subtraction) {
EXPECT_EQ(subtract(5, 3), 2);
EXPECT_EQ(subtract(0, 5), -5);
EXPECT_EQ(subtract(10, 10), 0);
}





// 测试参数化测试
class MathUtilsParamTest : public ::testing::TestWithParam<std::tuple<int, int, int>> {};

TEST_P(MathUtilsParamTest, AdditionParametrized) {
auto [a, b, expected] = GetParam();
EXPECT_EQ(add(a, b), expected);
}

INSTANTIATE_TEST_SUITE_P(
        AdditionValues,
        MathUtilsParamTest,
        ::testing::Values(
        std::make_tuple(1, 1, 2),
        std::make_tuple(2, 3, 5),
        std::make_tuple(-1, -1, -2),
        std::make_tuple(0, 0, 0)
)
);

// 主函数 - GTest 会自动提供，但如果需要自定义可以在这里定义
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}