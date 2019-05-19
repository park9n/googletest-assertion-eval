#include "sample.h"
#include "gtest/gtest.h"

TEST(WrongAssertionTest, DifferentType1) {
    char a = 128;
    int b = 128;
    EXPECT_EQ(a, b);    // FAILED
}

TEST(WrongAssertionTest, DifferentType2) {
    unsigned int a = -1;
    int b = -1;
    EXPECT_EQ(a, b);    // OK
}

void sub_func(int a, int b) {
    EXPECT_EQ(a, b);
}

TEST(WrongAssertionTest, BadSubFuncTest) {
    sub_func(1, 2);
}

TEST(WrongAssertionTest, GoodSubFuncTest) {
    SCOPED_TRACE("SubFuncTest");
    sub_func(1, 2);
}

TEST(WrongAssertionTest, FloatingPoint4Ulp) {
    EXPECT_FLOAT_EQ(2.00001, 2.000011); // OK
    EXPECT_FLOAT_EQ(2.00001, 2.000012); // FAILED
    EXPECT_FLOAT_EQ(2.00001, 2.000009); // OK
    EXPECT_FLOAT_EQ(2.00001, 2.000008); // FAILED
    EXPECT_FLOAT_EQ(20.00001, 20.000011); // OK
    EXPECT_FLOAT_EQ(20.00001, 20.000012); // OK
    EXPECT_FLOAT_EQ(20.0001, 20.00011); // FAILED
    EXPECT_FLOAT_EQ(20.0001, 20.00012); // FAILED
    EXPECT_FLOAT_EQ(200.00001, 200.000011); // OK
    EXPECT_FLOAT_EQ(200.00001, 200.000012); // OK
    EXPECT_FLOAT_EQ(200.0001, 200.00011); // OK
    EXPECT_FLOAT_EQ(200.0001, 200.00012); // OK

    EXPECT_FLOAT_EQ(2.000011, 2.000012); // OK
    EXPECT_FLOAT_EQ(2.000011, 2.000013); // FAILED

    float a = 1.0000001f;
    float b = 1.0000002f;
    EXPECT_FLOAT_EQ(a, b);  // OK
    EXPECT_DOUBLE_EQ(a, b); // FAILED
}

TEST(WrongAssertionTest, Meaningless) {
    unsigned int a = -1;
    ASSERT_TRUE(a > 0);
}

TEST(WrongAssertionTest, EqThanTrue) {
    int a = 1;
    int b = 2;
    EXPECT_TRUE(a == b);    // BAD
    EXPECT_EQ(a, b); // GOOD
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
