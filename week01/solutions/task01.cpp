#include <iostream>

struct Rational {
    int numerator;
    int denominator;
};

void print(const Rational& rational)
{
    std::cout << rational.numerator << "/" << rational.denominator<<std::endl;
}

Rational createRational(int numerator, int denominator)
{
    return Rational{ numerator, denominator };
}

int gcd(int a, int b)
{
    a = abs(a); 
    b = abs(b);

    if (a < b) {
        std::swap(a, b);
    }

    while (b != 0) {
        unsigned temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void simplify(Rational& rational) // we will change the inctance
{
    int gcdOfRational = gcd(rational.numerator, rational.denominator);

    rational.numerator /= gcdOfRational;
    rational.denominator /= gcdOfRational;
}

Rational sum(const Rational& lhs, const Rational& rhs)
{
    int resultNumerator = lhs.numerator * rhs.denominator + rhs.numerator * lhs.denominator;
    int resultDenumerator = lhs.denominator * rhs.denominator;

    Rational result = createRational(resultNumerator, resultDenumerator);
    simplify(result);

    return result;
}

Rational subs(const Rational& lhs, const Rational& rhs)
{
    Rational toSubtract = createRational(-rhs.numerator, rhs.denominator); // change the sign

    return sum(lhs, toSubtract); // reuse sum
}

Rational multiply(const Rational& lhs, const Rational& rhs)
{
    int resultNumerator = lhs.numerator * rhs.numerator;
    int resultDenumerator = lhs.denominator * rhs.denominator;

    Rational result = createRational(resultNumerator, resultDenumerator);
    simplify(result);

    return result;
}

Rational div(const Rational& lhs, const Rational& rhs)
{
    Rational divider = createRational(rhs.denominator, rhs.numerator); // reverse the fraction

    return multiply(lhs, divider);
}
int main()
{
    Rational lhs = createRational( 5,25 );
    Rational rhs = createRational( 1,3 );

    print(sum(rhs, lhs));
    print(subs(rhs, lhs));
    print(multiply(rhs, lhs));
    print(div(lhs, rhs));
}