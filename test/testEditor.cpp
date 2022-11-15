//
// Created by Weder on 15.11.2022.
//
#include "gtest/gtest.h"
#include "../TFracEditor.h"

TEST (FracEditor,Constructor) {
std::string expected = "0/1";
TFracEditor editor;
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,AddNumber) {
std::string expected = "8";
TFracEditor editor;
editor.addNumber(8);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,AddNumber_2) {
std::string expected = "-8";
TFracEditor editor;
editor.addNumber(-8);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,isZero) {
TFracEditor editor;
ASSERT_TRUE(editor.isZero());
}

TEST (FracEditor,isZero_2) {
TFracEditor editor;
editor.addNumber(8);
ASSERT_FALSE(editor.isZero());
}

TEST (FracEditor,addSign) {
std::string expected = "-8";
TFracEditor editor;
editor.addNumber(8);
editor.addSign();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,addSign_2) {
std::string expected = "8";
TFracEditor editor;
editor.addNumber(-8);
editor.addSign();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,addSign_3) {
std::string expected = "-1/2";
TFracEditor editor;
editor.addNumber(8);
editor.addDivider();
editor.addNumber(16);
editor.addSign();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,addZero) {
std::string expected = "0";
TFracEditor editor;
editor.addZero();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,addZero_2) {
std::string expected = "80";
TFracEditor editor;
editor.addNumber(8);
editor.addZero();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,removeLastDigit) {
std::string expected = "8";
TFracEditor editor;
editor.addNumber(80);
editor.removeLastDigit();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,removeLastDigit_2) {
std::string expected = "-8";
TFracEditor editor;
editor.addNumber(-80);
editor.removeLastDigit();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,removeLastDigit_3) {
std::string expected = "-3/";
TFracEditor editor;
editor.addNumber(3);
editor.addDivider();
editor.addNumber(-7);
editor.removeLastDigit();
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,editFraction) {
std::string expected = "0";
TFracEditor editor;
editor.editFraction(Operations::ADD_ZERO);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,editFraction_2) {
std::string expected = "1/2";
TFracEditor editor;
editor.addNumber(8);
editor.editFraction(Operations::ADD_DIVIDER);
editor.addNumber(16);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,editFraction_3) {
std::string expected = "1/";
TFracEditor editor;
editor.addNumber(8);
editor.editFraction(Operations::ADD_DIVIDER);
editor.addNumber(16);
editor.editFraction(Operations::REMOVE_LAST_DIGIT);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,editFraction_4) {
std::string expected = "-1/2";
TFracEditor editor;
editor.addNumber(8);
editor.editFraction(Operations::ADD_DIVIDER);
editor.addNumber(16);
editor.editFraction(Operations::ADD_SIGN);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,editFraction_5) {
std::string expected = "0/1";
TFracEditor editor;
editor.addNumber(8);
editor.editFraction(Operations::ADD_DIVIDER);
editor.addNumber(16);
editor.editFraction(Operations::CLEAR);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,getFraction) {
std::string expected = "0/1";
TFracEditor editor;
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,getFraction_2) {
std::string expected = "8";
TFracEditor editor;
editor.addNumber(8);
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,setFraction) {
std::string expected = "5/2";
TFracEditor editor;
editor.setFraction("5/2");
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,setFraction_2) {
std::string expected = "-5/2";
TFracEditor editor;
editor.setFraction("-5/2");
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,setFraction_3) {
std::string expected = "-5/2";
TFracEditor editor;
editor.setFraction("-10/4");
ASSERT_TRUE(expected == editor.getFraction());
}

TEST (FracEditor,setFraction_4) {
TFracEditor editor;
ASSERT_THROW(editor.setFraction("1"), std::invalid_argument);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}