#include"fraction.h"
int main() {
    Fraction myFraction(1,2);
    std::cout<<"Enter 1 to change decimal string to fraction\n";
    std::cout<<"Enter 2 to change fraction to decimal string\n";
    std::cout<<"Enter 3 to add two fractions\n";
    std::cout<<"Enter 4 to subtract two fractions\n";
    std::cout<<"Enter 5 to multiply two fractions\n";
    std::cout<<"Enter 6 to divide two fractions\n";
    std::cout<<"Enter 7 to compare two fraction\n";
    std::cout<<"Enter 10 to exit\n";
    int choice;
    back:
    std::cin>>choice;
    switch (choice)
    {
    case 1:
        myFraction.double_to_fraction();
        break;
    case 2:
        myFraction.fraction_to_decimal();
        break;
    case 3:
        myFraction.add_two_fractions();
        break;
    case 4:
        myFraction.subtract_two_fractions();
        break;
    case 5:
        myFraction.multiply_two_fractions();
        break;
    case 6:
        myFraction.divide_two_fractions();
        break;
    case 7:
        myFraction.compare_two_fractions();
        break;
    case 10:
        exit(0);
        break;
    default:
        std::cout<<"Wrong choice\n";
        break;
    }
    goto back;
}