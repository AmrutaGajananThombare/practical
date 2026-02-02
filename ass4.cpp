#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    
    Fraction() {
        numerator = 1;
        denominator = 1;
    }

    
    Fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

  
    Fraction add(Fraction f) {
        int n = numerator * f.denominator + denominator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    
    Fraction subtract(Fraction f) {
        int n = numerator * f.denominator - denominator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

 
    Fraction multiply(Fraction f) {
        int n = numerator * f.numerator;
        int d = denominator * f.denominator;
        return Fraction(n, d);
    }

    
    Fraction divide(Fraction f) {
        int n = numerator * f.denominator;
        int d = denominator * f.numerator;
        return Fraction(n, d);
    }

    
    void print() {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Fraction f1(1, 4);
    Fraction f2(3, 4);

    Fraction sum = f1.add(f2);
    sum.print();  

    Fraction diff = f1.subtract(f2);
    diff.print(); 
    Fraction prod = f1.multiply(f2);
    prod.print(); 

    Fraction quot = f1.divide(f2);
    quot.print(); 
    return 0;
}

