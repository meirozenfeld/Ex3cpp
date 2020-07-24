#include "solver.hpp"
using namespace std;
using namespace solver;

double solver::solve(const RealVariable& x){
   if (x.a != 0)
    {
        if((x.b*x.b - 4 *x.a*x.c) > 0)
        {
            double ans = (-x.b + sqrt(x.b * x.b - 4 * x.a * x.c)) / (2 * x.a);
            return ans;   
        }
            throw invalid_argument("No solution!");
    }
    else
    {
        if (x.b != 0)
        {
            
             //x.c = -(x.c);
             return (-(x.c) / x.b); 
        }
            throw invalid_argument("No solution");  
    }

    return 10;
}
std::complex<double>  solver::solve(const ComplexVariable& x){
   if (x.a != 0.0)
    {
      std::complex<double>  ans = (-x.b + sqrt(x.b * x.b - 4.0 * x.a * x.c)) / (2.0 * x.a);
        return ans;   
    }
    else
    {
        if (x.b != 0.0)
        {
             return (-(x.c) / x.b); 
        }
            throw invalid_argument("No solution");  
    }

    return 10;
}
RealVariable solver::operator+(const RealVariable& x, const RealVariable& y){
  return RealVariable(x.a+y.a , x.b+y.b , x.c+y.c);
    
}

RealVariable solver::operator+(const RealVariable& x,double y){
  return  RealVariable(x.a , x.b , x.c+y);
   
}
RealVariable solver::operator+(double y,const RealVariable& x){
return  RealVariable(x.a , x.b , x.c+y);    
}

RealVariable solver::operator*(double x,const RealVariable& y){
   return RealVariable(x*y.a , x*y.b , y.c);
}

RealVariable solver::operator*(const RealVariable& x,const RealVariable& y){
    return RealVariable(x.a+y.a , x.b*y.b , x.c*y.c);
}

RealVariable solver::operator*(const RealVariable& y,double x){
   return RealVariable(y.a , x*y.b , y.c);
}
RealVariable solver::operator/(const RealVariable& x,double y){
  if(y!=0)
  {
  return  RealVariable(x.a , x.b/y , x.c);
  }
  else
  {
     throw invalid_argument("can't divide zero");
  }

}
RealVariable solver::operator/(const RealVariable& x,const RealVariable& y){
    return RealVariable(x.a/y.a , x.b/y.b , x.c/y.c);
}
RealVariable solver::operator/(double x,const RealVariable& y){
     if(y.b!=0)
  {
  return RealVariable(y.a , x/y.b , y.c);
  }
  else
  {
    throw invalid_argument("can't divide zero");
  }
}
RealVariable solver::operator-(const RealVariable& x, double y){
  return RealVariable(x.a, x.b , x.c-y);
}
RealVariable solver::operator-(double x,const RealVariable& y){
   return RealVariable(-y.a , -y.b , x-y.c);
}
RealVariable solver::operator-(const RealVariable& x,const RealVariable& y){
  return  RealVariable(x.a-y.a , x.b-y.b , x.c-y.c);
}
        
RealVariable solver::operator^(const solver::RealVariable &x,int y){
    if(y==0){
        return RealVariable(0 , 0 , 1); 
    }
    else if(y==1){
    return RealVariable(0 , 1 , 0);
    }
    else if(y==2){
    return RealVariable(1 , 0 , 0);
    }
        throw invalid_argument("power bigger or lower than 2!");
} 
RealVariable solver::operator==(const RealVariable& x, const RealVariable& y) {
   return RealVariable(x.a-y.a , x.b-y.b , x.c-y.c);
}
RealVariable solver::operator==(double x,const RealVariable& y) {
    return RealVariable(-y.a , -y.b , x-y.c);
}
RealVariable solver::operator==(const RealVariable& x, double y) {
    return RealVariable(x.a , x.b , x.c-y);        
}

ComplexVariable solver::operator+(const ComplexVariable& x,const ComplexVariable& y){
   return ComplexVariable(x.a+y.a , x.b+y.b , x.c+y.c);
}

ComplexVariable solver::operator+(const ComplexVariable& x,double y){
  return  ComplexVariable(x.a , x.b , x.c+y);
}
ComplexVariable solver::operator+(double y,const ComplexVariable& x){
return  ComplexVariable(x.a , x.b , x.c+y);    
}
ComplexVariable solver::operator+(std::complex<double> y,const ComplexVariable& x){
  return  ComplexVariable(x.a , x.b , x.c+y);

}


ComplexVariable solver::operator+(const ComplexVariable& x,std::complex<double> y){
  return  ComplexVariable(x.a , x.b , x.c+y);

}

ComplexVariable solver::operator*(double x,const ComplexVariable& y){
   return ComplexVariable(x*y.a , x*y.b , y.c);
}

ComplexVariable solver::operator*(const ComplexVariable& x,const ComplexVariable& y){
    return ComplexVariable(x.a+y.a , x.b*y.b , x.c*y.c);

}

ComplexVariable solver::operator*(const ComplexVariable& y,double x){
   return ComplexVariable(y.a , x*y.b , y.c);

}
ComplexVariable solver::operator/(const ComplexVariable& x,double y){
   if(y!=0)
  {
  return  ComplexVariable(x.a , x.b/y , x.c);
  }
  else
  {
     throw invalid_argument("can't divide zero");
  }


}
ComplexVariable solver::operator/(const ComplexVariable& x,const ComplexVariable& y){
     return ComplexVariable(x.a/y.a , x.b/y.b , x.c/y.c);
}
ComplexVariable solver::operator/(double x,const ComplexVariable& y){
    if(y.b!=0.0)
  {
  return ComplexVariable(y.a , x/y.b , y.c);
  }
  else
  {
    throw invalid_argument("can't divide zero");
  }
    }
ComplexVariable solver::operator-(const ComplexVariable& x, double y){
    return ComplexVariable(x.a, x.b , x.c-y);
    }
ComplexVariable solver::operator-(double x,const ComplexVariable& y){
   return ComplexVariable(-y.a , -y.b , x-y.c);

}
ComplexVariable solver::operator-(const ComplexVariable& x,const ComplexVariable& y){
    return  ComplexVariable(x.a-y.a , x.b-y.b , x.c-y.c);

}
        
ComplexVariable solver::operator^(const ComplexVariable& x,int y){
       if(y==0){
        return ComplexVariable(0 , 0 , 1); 
    }
    else if(y==1){
    return ComplexVariable(0 , 1 , 0);
    }
    else if(y==2){
    return ComplexVariable(1 , 0 , 0);
    }
        throw invalid_argument("power bigger or lower than 2!");
} 
ComplexVariable solver::operator==(const ComplexVariable& x, const ComplexVariable& y) {
    return ComplexVariable(x.a-y.a , x.b-y.b , x.c-y.c);
}
ComplexVariable solver::operator==(double x,const ComplexVariable& y) {
     return ComplexVariable(-y.a , -y.b , x-y.c);
}
ComplexVariable solver::operator==(const ComplexVariable& x, double y) {
    return ComplexVariable(x.a , x.b , x.c-y);        

}
ComplexVariable solver::operator==(const ComplexVariable& x,std::complex<double> y){
      return ComplexVariable(x.a , x.b , x.c-y);        

}

ComplexVariable solver::operator==(std::complex<double> y,const ComplexVariable& x){
      return ComplexVariable(-x.a , -x.b , y-x.c);        

}

