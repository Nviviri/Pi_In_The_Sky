#include "dofxyrz.h"
#include <math.h>
const double PI  =3.141592653589793238463;

std::ostream& operator<<(std::ostream &os, const DOFxyRz &rhs)
{
   os << "[" << rhs.vector_.getX() << ", " << rhs.vector_.getY() << "]"
      << ", " << rhs.Rz_ << "\n";
   return os;
}

DOFxyRz operator+(const DOFxyRz &lhs, const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_ + rhs;
   return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, const CartVec2D &rhs)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_ - rhs;
   return result;
}

DOFxyRz operator+(double x, const DOFxyRz &rhs)
{
   DOFxyRz result;
   result.vector_ = rhs.vector_;
   result.Rz_ = x + rhs.Rz_;
   while(result.Rz_>PI)
   {
      result.Rz_ -= 2*PI;
   }
   while(result.Rz_<-PI)
   {
      result.Rz_ += 2*PI;
   }
   return result;
}
DOFxyRz operator-(double x, const DOFxyRz &rhs)
{
   DOFxyRz result;
   result.vector_ = rhs.vector_;
   result.Rz_ = x - rhs.Rz_;
   while(result.Rz_>PI)
   {
      result.Rz_ -= 2*PI;
   }
   while(result.Rz_<-PI)
   {
      result.Rz_ += 2*PI;
   }
   return result;
}

DOFxyRz operator+(const DOFxyRz &lhs, double x)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_;
   result.Rz_ = lhs.Rz_ + x;
   while(result.Rz_>PI)
   {
      result.Rz_ -= 2*PI;
   }
   while(result.Rz_<-PI)
   {
      result.Rz_ += 2*PI;
   }
   return result;
}

DOFxyRz operator-(const DOFxyRz &lhs, double x)
{
   DOFxyRz result;
   result.vector_ = lhs.vector_;
   result.Rz_ = lhs.Rz_ - x;
   while(result.Rz_>PI)
   {
      result.Rz_ -= 2*PI;
   }
   while(result.Rz_<-PI)
   {
      result.Rz_ += 2*PI;
   }
   return result;
}

/////////////////////////////////////////////////////
DOFxyRz &DOFxyRz::operator+=(const DOFxyRz &rhs)
{
   //vector_.setX(vector_.getX() + rhs.vector_.getX());
   //vector_.setY(vector_.getY() + rhs.vector_.getY());
   vector_ += rhs.vector_;
   return *this;
}

DOFxyRz &DOFxyRz::operator+=(const CartVec2D &rhs)
{
   vector_ += rhs;
   return *this;
}

DOFxyRz &DOFxyRz::operator-=(const DOFxyRz &rhs)
{
   //vector_.setX(vector_.getX() - rhs.vector_.getX());
   //vector_.setY(vector_.getY() - rhs.vector_.getY());
   vector_ -= rhs.vector_;
   return *this;
}

CartVec2D DOFxyRz::heading() const
{
   CartVec2D hVector;
   hVector.setX(cos(Rz_));
   hVector.setY(sin(Rz_));
   return hVector;
}
