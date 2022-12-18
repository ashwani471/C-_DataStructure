#include<iostream>
using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;
    public:
         Fraction(int numerator , int denominator){
            this->numerator = numerator;
            this-> denominator = denominator;
         }

         int getnumerator() const{
            return numerator;
         }

         int denominator() const{
            return denominator;
         }

         void setnumerator(int n){
           numerator = n;
         }

         void setdenominator(int d){
            denominator = d;
         }

         void print() const{
           cout<<this->numerator<<"/"<<this->denominator;
         }    
          
         void simplify(){
            int gcd = 1;
            int j = min(this->numerator,this->denominator);
            for(int i=1;i<=j;i++){
               if(this->numerator%i == 0 && this->denominator%i == 0){
                gcd = i;
               }
            }
            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
         }

          void add(Fraction const &f2){
            int lcm = denominator*f2.denominator;
            int x= lcm/this->denominator;
            int y = lcm/f2.denominator;

            int num = x*this->numerator+(y*f2.numerator);
            numerator = num;
            denominator = lcm;
            simplify();
          }

          Fraction addNew(Fraction const &f2){
            int lcm = denominator*f2.denominator;
            int x= lcm/this->denominator;
            int y = lcm/f2.denominator;

            int num = x*this->numerator+(y*f2.numerator);
            // numerator = num;
            // denominator = lcm;
            Fraction fNew(num,lcm);
            fNew.simplify();
            return fNew;
          }

          Fraction operator+(Fraction const &f2) const{
            int lcm = denominator*f2.denominator;
            int x= lcm/this->denominator;
            int y = lcm/f2.denominator;

            int num = x*this->numerator+(y*f2.numerator);
            // numerator = num;
            // denominator = lcm;
            Fraction fNew(num,lcm);
            fNew.simplify();
            return fNew;
          }

         Fraction operator*(Fraction const &f2) const{
            int n = this->numerator*f2.numerator;
            int d = this->denominator*f2.denominator;
            Fraction fNewMul(n,d);
            fNewMul.simplify();
            return fNewMul;
          }

          void miltiplication(Fraction const &f2){
            numerator = this->numerator*f2.numerator;
            denominator = this->denominator*f2.denominator;
            simplify();
          }
};

class Complex {
    private:
     int real;
     int imaginary;

    public:
     Complex(int real , int imaginary){
        this->real=real;
        this->imaginary=imaginary;
     }

    void printComplex(){
        cout<<this->real<<"+i"<<this->imaginary;
    } 

    void add(Complex c2){
        int realPart = this->real + c2.real;
        int imagPart = this->imaginary + c2.imaginary;
        real = realPart;
        imaginary = imagPart;
    }

    void multiple(Complex c2){
        int realPart = this->real*c2.real;
        int imagPart = this->imaginary*c2.imaginary;
        real=realPart;
        imaginary=imagPart;
    }

};