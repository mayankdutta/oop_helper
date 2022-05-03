// make sure to read comments in main. 

#include <iostream>

using namespace std;

template<typename INT>
INT GCD(INT a, INT b) { return b ? GCD(b, a % b) : a; }

class Fraction {
    int numerator;
    int denominator;

public:
    Fraction(int, int);

    Fraction(int);

    Fraction operator+(const Fraction &f);

    Fraction operator-(const Fraction &f);

    Fraction operator*(const Fraction &f);

    Fraction operator/(const Fraction &f);

    // doubt, overload COUT
    void display() const;

    void simplify();

    bool operator==(Fraction &);

    Fraction &operator+=(const Fraction &);

    Fraction &operator-=(const Fraction &);

    Fraction &operator*=(const Fraction &);

    Fraction &operator/=(const Fraction &);


    // pre increment, first update then use
    Fraction &operator++();

    Fraction &operator--();

    // post increment, first use then update
    Fraction operator++(int);

    Fraction operator--(int);

    friend ostream &operator<<(ostream &COUT, const Fraction &f);
};

int main() {
    Fraction one(1, 2);
    Fraction two(2, 3);

    /*
    * value will update and answer will be correct, but it won't be stored in one
    * one will be updated only once.
    * we aren't updating the new value of one, in one.
    * after updating the function will return a copy of one, not the original one.
    * therefore the outer ++ is updating the copy of one, not the original one.
    * if we want to return the same function then naturally we will have to return a reference to the original variable.
    */

    auto three = ++(++one);
    one.display();
    three.display();

    // no such multiteration allowed in postorder,
    // can't do something like (one++)++ in c++.

    auto four = (two++);
    four.display();
    two.display();

    Fraction f1 = {10, 3};
    Fraction f2 = {5, 2};

    /*
     * same scenario as mentioned in above comments.
     */
    (f1 += f2) += f2;
    f1.display();
    f2.display();

    /* operator overlaoding for streaming operators can only be friend.
     * The stream operators:
     * > operator << output
     * > operator >> input
     * When you use these as stream operators (rather than binary shift) the first parameter is a stream.
     * Since you do not have access to the stream object (its not yours to modify)
     * these can not be member operators they have to be external to the class.
     * Thus they must either be friends of the class or have access to a public method that will do the streaming for you.
     *
     * It is also traditional for these objects to return a reference to a stream object
     * so you can chain stream operations together.
     */

    cout << f1 << '\n';
}

Fraction &Fraction::operator-=(const Fraction &f) {
    int new_denominator = (f.denominator * this->denominator);
    int new_numerator =
            (f.numerator * this->denominator - this->numerator * f.denominator);

    this->numerator = new_numerator;
    this->denominator = new_denominator;
    simplify();
    return *this;
}

Fraction &Fraction::operator+=(const Fraction &f) {
    int new_denominator = (f.denominator * this->denominator);
    int new_numerator =
            (f.numerator * this->denominator + this->numerator * f.denominator);
    this->numerator = new_numerator;
    this->denominator = new_denominator;
    simplify();
    return *this;
}

Fraction &Fraction::operator*=(const Fraction &f) {
    this->numerator *= f.numerator;
    this->denominator *= f.denominator;
    simplify();
    return *this;
}

Fraction &Fraction::operator/=(const Fraction &f) {
    this->numerator *= f.denominator;
    this->denominator *= f.numerator;
    simplify();
    return *this;
}

bool Fraction::operator==(Fraction &f) {
    simplify();
    f.simplify();
    return (this->numerator == f.numerator && this->denominator == f.denominator);
}

void Fraction::simplify() {
    int common = GCD(this->numerator, this->denominator);
    this->numerator /= common;
    this->denominator /= common;
}

void Fraction::display() const {
    cout << this->numerator << "/" << this->denominator << '\n';
}

Fraction Fraction::operator-(const Fraction &f) {
    int new_denominator = (f.denominator * this->denominator);
    int new_numerator =
            (f.numerator * this->denominator - this->numerator * f.denominator);

    simplify();
    return {new_numerator, new_denominator};
}

Fraction Fraction::operator+(const Fraction &f) {
    int new_denominator = (f.denominator * this->denominator);
    int new_numerator =
            (f.numerator * this->denominator + this->numerator * f.denominator);
    simplify();
    return {new_numerator, new_denominator};
}

Fraction Fraction::operator*(const Fraction &f) {
    this->denominator *= f.denominator;
    this->numerator *= f.numerator;
    simplify();
    return *this;
}

Fraction Fraction::operator/(const Fraction &f) {
    this->denominator *= f.numerator;
    this->numerator *= f.denominator;
    simplify();
    return *this;
}


Fraction::Fraction(int numerator, int denominator)
        : numerator(numerator), denominator(denominator) {}

Fraction::Fraction(int numerator) : numerator(numerator), denominator(1) {}

Fraction &Fraction::operator++() {
    *this += 1;
    return (*this);
}

Fraction &Fraction::operator--() {
    *this -= 1;
    return (*this);
}

Fraction Fraction::operator++(int) {
    Fraction *temp = new Fraction(this->numerator, this->denominator);
    *this += 1;
    return *temp;
}

Fraction Fraction::operator--(int) {
    Fraction *temp = new Fraction(this->numerator, this->denominator);
    *this -= 1;
    return *temp;
}

ostream &operator<<(ostream &COUT, const Fraction &f) {
    COUT << f.numerator << "/" << f.denominator << '\n';
    return COUT;
}
