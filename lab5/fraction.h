#ifndef FRACTION_H
#define FRACTION_H
#include<string>
#include<iostream>
class Fraction
{
public:
    int deno;
    int num;

public:
    Fraction(int n, int d) : deno(d), num(n){}
    ~Fraction();
    void double_to_fraction();
    int gcd(int a, int b);
    void fraction_to_decimal();
    void add_two_fractions();
    void subtract_two_fractions();
    void multiply_two_fractions();
    void divide_two_fractions();
    void compare_two_fractions();
};

#endif // !FRACTION_H