//
// Created by Weder on 07.11.2022.
//

#ifndef TFRAC_TFRAC_H
#define TFRAC_TFRAC_H

#include <stdexcept>
#include <numeric>

class ZeroDivEx : public std::runtime_error {
public:
    explicit ZeroDivEx(int dividend) : runtime_error(
            "Attempted to divide " + std::to_string(dividend) + " by zero") {
    }

    [[nodiscard]] static int getCode() {
        return -1;
    }
};

class TFrac {
private:
    int num, div;

    void checkZeroDiv() const {
        if (this->div == 0) {
            throw ZeroDivEx(num);
        }
    }

    [[nodiscard]] static int gcd(int a, int b) {
        int result = std::min(a, b); // Find Minimum of a nd b
        while (result > 0) {
            if (a % result == 0 && b % result == 0) {
                break;
            }
            result--;
        }
        return result; // return gcd of a nd b
    }

    void reduce() {
        if (div < 0) {
            num *= -1;
            div *= -1;
        }
        auto temp = gcd(num, div);
        num /= temp;
        div /= temp;
    }


public:
    TFrac(int num) {
        this->num = num;
        this->div = 1;
    }
//Tfrac temp="123/23"
    explicit TFrac(int num, int div) {
        this->num = num;
        this->div = div;
        checkZeroDiv();
        reduce();
        checkZeroDiv();
    }

    explicit TFrac(const std::string &input) {
        std::string strNum, strDiv;
//        for (auto &i: input) {
//            if (i == '/' || i == '\\') {
//                break;
//            } else {
//                strNum.push_back(i);
//            }
//        }
//        bool afterNum=false;
//        for (auto &i: input) {
//            if (i == '/' || i == '\\') {
//                afterNum=true;
//                continue;
//            }
//            if(afterNum){
//                strDiv.push_back(i);
//            }
//        }
        // std::cout << strNum << "\n" << strDiv;
        size_t delim;
        this->num = std::stoi(input, &delim);
        this->div = std::stoi(&input[delim + 1]);;
        checkZeroDiv();
        reduce();
        checkZeroDiv();
    }

    [[nodiscard]] int getNum() const {
        return this->num;

    }

    [[nodiscard]]int getDiv() const {
        return this->div;

    }
    [[nodiscard]] std::string getNumString() const {
        return std::to_string(this->num);

    }

    [[nodiscard]]std::string getDivString() const {
        return  std::to_string(this->div);

    }
    [[nodiscard]]std::string getString() const {
        return  getNumString()+"/"+getDivString();

    }


    TFrac operator/(const TFrac &b) const {
        return TFrac(this->num / b.getNum(), this->div / b.getDiv());
    }

    int operator/=(const TFrac &b) {
        this->num /= b.getNum();
        this->div /= b.getDiv();
        return 0;
    }

    TFrac operator*(const TFrac &b) const {
        return TFrac(this->num * b.getNum(), this->div * b.getDiv());
    }

    int operator*=(const TFrac &b) {
        this->num *= b.getNum();
        this->div *= b.getDiv();
        reduce();
        return 0;
    }

    int operator+=(const TFrac &b) {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        this->num = lcm / this->getDiv() * this->getNum() + lcm / b.getDiv() * b.getNum();
        this->div = lcm;
        checkZeroDiv();
        // return TFrac(lcm / this->getDiv() * this->getNum() + lcm / b.getDiv() * b.getNum(), lcm);
        return 0;
    }

    TFrac operator+(const TFrac &b) const {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        return TFrac(lcm / this->getDiv() * this->getNum() + lcm / b.getDiv() * b.getNum(), lcm);
    }

    TFrac operator-(const TFrac &b) const {
        return TFrac(-b.getNum(), b.getDiv());
    }

    int operator-=(const TFrac &b) {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        this->num = lcm / this->getDiv() * this->getNum() - lcm / b.getDiv() * b.getNum();
        this->div = lcm;
        checkZeroDiv();
        return 0;
    }

    bool operator==(const TFrac &b) const {
        return this->getNum() == b.getNum() && this->getDiv() == b.getDiv();
    }

    bool operator!=(const TFrac &b) const {
        return this->getNum() != b.getNum() || this->getDiv() != b.getDiv();
    }

    bool operator>(const TFrac &b) const {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        return lcm / this->getDiv() * this->getNum() > lcm / b.getDiv() * b.getNum();
    }

    bool operator>=(const TFrac &b) const {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        return lcm / this->getDiv() * this->getNum() >= lcm / b.getDiv() * b.getNum();
    }

    bool operator<(const TFrac &b) const {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        return lcm / this->getDiv() * this->getNum() < lcm / b.getDiv() * b.getNum();
    }

    bool operator<=(const TFrac &b) const {
        auto lcm = std::lcm(this->getDiv(), b.getDiv());
        return lcm / this->getDiv() * this->getNum() <= lcm / b.getDiv() * b.getNum();
    }

    [[nodiscard]] TFrac inverse() const {
        return TFrac(this->getDiv(), this->getNum());
    }

};


#endif //TFRAC_TFRAC_H
