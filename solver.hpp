#pragma once
#include <cmath>
#include <complex>
namespace solver{

    class RealVariable{
        public:
        int a;
        double b;
        double c;

        RealVariable()
        {
            this->a = 0;
            this->b = 1;
            this->c = 0;
        }
             RealVariable(int a, double b, double c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        //+
        friend RealVariable operator+(double y,const RealVariable& x);
        friend RealVariable operator+(const RealVariable& x,double y);
        friend RealVariable operator+(const RealVariable& x,const RealVariable& y);
        //*
        friend RealVariable operator*(double y,const RealVariable& x);
        friend RealVariable operator*(const RealVariable& x, double y);
        friend RealVariable operator*(const RealVariable& x,const RealVariable& y);
        ///
        friend RealVariable operator/(const RealVariable& x,double y);
        friend RealVariable operator/(double y,const RealVariable& x);
        friend RealVariable operator/(const RealVariable& x,const RealVariable& y);
        //-
        friend RealVariable operator-(const RealVariable& x,double y);
        friend RealVariable operator-(const RealVariable& x,const RealVariable& y);
        friend RealVariable operator-(double y,const RealVariable& x);
        //^
        friend RealVariable operator^(const RealVariable& x,int y);
        //==
        friend RealVariable operator==(const RealVariable& x,  double y); 
        friend RealVariable operator==(const RealVariable& x,const RealVariable& y);
        friend RealVariable operator==(double y,const RealVariable& x);
        //
    
    };
    double solve(const RealVariable& x);
    
    class ComplexVariable{
        public:
        std::complex<double> a;
        std::complex<double> b;
        std::complex<double> c;

        ComplexVariable()
        {
            this->a = 0;
            this->b = 1;
            this->c = 0;
        }
        ComplexVariable(std::complex<double> a, std::complex<double> b, std::complex<double> c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }
       // std::complex<double> a,b,c;
       // ComplexVariable()=default;

        friend ComplexVariable operator+(double y,const ComplexVariable& x);
        friend ComplexVariable operator+(const ComplexVariable& x,double y);
        friend ComplexVariable operator+(const ComplexVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator+(std::complex<double> y,const ComplexVariable& x);
        friend ComplexVariable operator+(const ComplexVariable& x,std::complex<double> y);

        //*
        friend ComplexVariable operator*(double y,const ComplexVariable& x);
        friend ComplexVariable operator*(const ComplexVariable& x, double y);
        friend ComplexVariable operator*(const ComplexVariable& x,const ComplexVariable& y);
        ///
        friend ComplexVariable operator/(const ComplexVariable& x, double y);
        friend ComplexVariable operator/(double y,const ComplexVariable& x);
        friend ComplexVariable operator/(const ComplexVariable& x,const ComplexVariable& y);
        //-
        friend ComplexVariable operator-(const ComplexVariable& x,double y);
        friend ComplexVariable operator-(const ComplexVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator-(double y,const ComplexVariable& x);
        //^
        friend ComplexVariable operator^(const ComplexVariable& x,int y);
        //==
        friend ComplexVariable operator==(const ComplexVariable& x, double y); 
        friend ComplexVariable operator==(const ComplexVariable& x,const ComplexVariable& y);
        friend ComplexVariable operator==(double y,const ComplexVariable& x);
        friend ComplexVariable operator==(const ComplexVariable& x,std::complex<double> y);
        friend ComplexVariable operator==(std::complex<double> y,const ComplexVariable& x);

    
    };
    std::complex<double> solve(const ComplexVariable& x);

}