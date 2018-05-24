#include "cartvec2d.h"


std::ostream& operator<<(std::ostream &os, const CartVec2D &rhs)
{
    os << "[" << rhs.x_ << ", " << rhs.y_ << "]" << "\n";
    return os;
}

CartVec2D operator+(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result{lhs};
    return result += rhs;
}

CartVec2D operator-(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = lhs.x_ - rhs.x_;
    result.y_ = lhs.y_ - rhs.y_;
    return result;
}

CartVec2D operator*(const CartVec2D &lhs, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = lhs.x_ * rhs.x_;
    result.y_ = lhs.y_ * rhs.y_;
    return result;
}
CartVec2D operator*(double n, const CartVec2D &rhs)
{
    CartVec2D result;
    result.x_ = n * rhs.x_;
    result.y_ = n * rhs.y_;
    return result;
}

CartVec2D operator*(const CartVec2D &rhs, double n)
{
    CartVec2D result;
    result.x_ = n * rhs.x_;
    result.y_ = n * rhs.y_;
    return result;
}
/////////////////////////////////////////////////////////////////////////
CartVec2D &CartVec2D::operator+=(const CartVec2D &rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}

CartVec2D &CartVec2D::operator-=(const CartVec2D &rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

CartVec2D CartVec2D::operator-() const
{
    //x_ = -rhs.x_;
    //y_ = -rhs.y_;
    //return *this;
    return CartVec2D(-x_,-y_);
}
