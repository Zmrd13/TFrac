//
// Created by Weder on 06.11.2022.
//
#include "gtest/gtest.h"
#include "../TFrac.h"
//TFrac_init//////////////////////////////////////////////////////////////////////////////////////////
TEST(TFrac_int_init, single_arg_as_param) {
    TFrac temp(1337);
    ASSERT_EQ(temp.getNum(), 1337);
}

TEST(TFrac_int_init, single_arg_as_assignment) {
    TFrac temp = 1337;
    ASSERT_EQ(temp.getNum(), 1337);
}

TEST(TFrac_int_init, exception_test_zero_div) {
//    int errorCode = 0;
//    try {
//        TFrac temp(1, 0);
//    }
//    catch (const ZeroDivEx &error) {
//        errorCode = ZeroDivEx::getCode();
//
//    }
//    ASSERT_EQ(errorCode, ZeroDivEx::getCode());
    ASSERT_ANY_THROW(TFrac temp(1, 0));
}

TEST(TFrac_int_init, reduce_at_init) {
    TFrac temp(2, 4);
    ASSERT_EQ(temp.getNum(), 1);
    ASSERT_EQ(temp.getDiv(), 2);
}
//TFrac_string_init/////////////////////////////////////////////////////////////////////////////////////////
TEST(TFrac_string_init, string_as_arg) {
    TFrac temp("2/4");
    ASSERT_EQ(temp.getNum(), 1);
    ASSERT_EQ(temp.getDiv(), 2);
}
//TFrac_operators_init/////////////////////////////////////////////////////////////////////////////////////////
TEST(TFrac_operators_init, mult_same_div) {
    TFrac a("2/9");
    TFrac b("2/9");
    a *= b;
    ASSERT_EQ(a.getNum(), 4);
    ASSERT_EQ(a.getDiv(), 81);
}

TEST(TFrac_operators_init, mult_diff_div) {
    TFrac a("2/9");
    TFrac b("2/10");
    a *= b;
    ASSERT_EQ(a.getNum(), 2);
    ASSERT_EQ(a.getDiv(), 45);
}

TEST(TFrac_operators_init, mult_assign) {
    TFrac a("2/9");
    TFrac b("2/9");
    TFrac temp = a * b;
    ASSERT_EQ(temp.getNum(), 4);
    ASSERT_EQ(temp.getDiv(), 81);
}

TEST(TFrac_operators_init, div_same_div) {
    TFrac a("2/9");
    TFrac b("2/9");
    a /= b;
    ASSERT_EQ(a.getNum(), 1);
    ASSERT_EQ(a.getDiv(), 1);
}

TEST(TFrac_operators_init, div_difdiv) {
    TFrac a("2/5");
    TFrac b("2/10");
    a /= b;
    ASSERT_EQ(a.getNum(), 2);
    ASSERT_EQ(a.getDiv(), 1);
}

TEST(TFrac_operators_init, div_assign) {
    TFrac a("2/9");
    TFrac b("2/9");
    TFrac temp = a / b;
    ASSERT_EQ(temp.getNum(), 1);
    ASSERT_EQ(temp.getDiv(), 1);
}

TEST(TFrac_operators_init, plus_same_div) {
    TFrac a("2/9");
    TFrac b("2/9");
    a += b;
    ASSERT_EQ(a.getNum(), 4);
    ASSERT_EQ(a.getDiv(), 9);
}

TEST(TFrac_operators_init, plus_diff_div) {
    TFrac a("1/2");
    TFrac b("1/3");
    a += b;
    ASSERT_EQ(a.getNum(), 5);
    ASSERT_EQ(a.getDiv(), 6);
}

TEST(TFrac_operators_init, plus_d_div_assign) {
    TFrac a("1/3");
    TFrac b("1/2");
    TFrac temp = a + b;
    ASSERT_EQ(temp.getNum(), 5);
    ASSERT_EQ(temp.getDiv(), 6);
}

TEST(TFrac_operators_init, minus_same_div) {
    TFrac a("2/9");
    TFrac b("2/9");
    a -= b;
    ASSERT_EQ(a.getNum(), 0);
    ASSERT_EQ(a.getDiv(), 9);
}

TEST(TFrac_operators_init, minus_diff_div) {
    TFrac a("1/2");
    TFrac b("1/3");
    a -= b;
    ASSERT_EQ(a.getNum(), 1);
    ASSERT_EQ(a.getDiv(), 6);
}

TEST(TFrac_operators_init, minus_div_assign) {
    TFrac a("1/3");
    TFrac b("1/2");
    TFrac temp = a + b;
    ASSERT_EQ(temp.getNum(), 5);
    ASSERT_EQ(temp.getDiv(), 6);
}
//TFrac_compare_init/////////////////////////////////////////////////////////////////////////////////////////
TEST(TFrac_compare_init, lesser_same) {
    TFrac a("1/3");
    TFrac b("2/3");
    ASSERT_TRUE(a < b);
}

TEST(TFrac_compare_init, lesser_diff) {
    TFrac a("1/6");
    TFrac b("1/5");
    ASSERT_TRUE(a < b);
}

TEST(TFrac_compare_init, less_equal_same) {
    TFrac a("1/3");
    TFrac t("1/3");
    TFrac b("2/3");
    ASSERT_TRUE(a < b);
    ASSERT_TRUE(a <= t);
}

TEST(TFrac_compare_init, less_equal_diff) {
    TFrac a("1/6");
    TFrac b("1/5");
    TFrac t("2/12");
    ASSERT_TRUE(a <= b);
    ASSERT_TRUE(a <= t);
}

TEST(TFrac_compare_init, equal_diff) {
    TFrac a("1/6");
    TFrac b("2/12");

    ASSERT_TRUE(a == b);

}

TEST(TFrac_compare_init, equal_same) {
    TFrac a("1/6");
    TFrac b("1/6");

    ASSERT_TRUE(a == b);

}
//TFrac_misc_init/////////////////////////////////////////////////////////////////////////////////////////
TEST(TFrac_misc_init, copy) {
    TFrac a("1/6");
    TFrac temp = a;

    ASSERT_TRUE(temp == a);

}

TEST(TFrac_misc_init, inverse_assign) {
    TFrac a("1/6");
    TFrac temp = a.inverse();
    ASSERT_EQ(temp.getNum(), 6);
    ASSERT_EQ(temp.getDiv(), 1);

}
TEST(TFrac_misc_init, get_as_string) {
    TFrac a("1/6");

    ASSERT_EQ(a.getNumString(), "1");
    ASSERT_EQ(a.getDivString(), "6");
    ASSERT_EQ(a.getString(),"1/6");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}