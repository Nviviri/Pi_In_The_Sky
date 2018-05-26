#ifndef DOFXYRZ_H
#define DOFXYRZ_H
#include "cartvec2d.h"

class DOFxyRz
{
   friend std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs);
   friend DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs);
   friend DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs);
   friend DOFxyRz operator+(double x, const DOFxyRz &rhs);
   friend DOFxyRz operator-(double x, const DOFxyRz &rhs);
   friend DOFxyRz operator+(const DOFxyRz &lhs, double x);
   friend DOFxyRz operator-(const DOFxyRz &lhs, double x);

public:
   DOFxyRz(double x, double y):
      vector_(x ,y),
      Rz_(0)
   {}
   DOFxyRz():
      vector_(0.0,0.0),
      Rz_(0)
   {}

   DOFxyRz &operator+=(const DOFxyRz &rhs);
   DOFxyRz &operator+=(const CartVec2D &rhs);
   DOFxyRz &operator-=(const DOFxyRz &rhs);

   inline double getRz() const{return Rz_;}
   inline void setRz(double x) {Rz_=x;}
   inline double getX() const{return vector_.getX();}
   inline double getY() const{return vector_.getY();}
   CartVec2D heading() const;

private:
   CartVec2D vector_;
   double Rz_;
};

#endif // DOFXYRZ_H
