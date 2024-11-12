#include<iostream>
#include<cmath>
#include"vector3.h"

using namespace std;

Vector3 Vector3::operator+(Vector3& other)
{
    return Vector3(x_+other.x_,y_+other.y_,z_+other.z_);
}


Vector3 Vector3::operator-(Vector3& other)
{
    return Vector3(x_-other.x_,y_-other.y_,z_-other.z_);
}


Vector3 Vector3::operator*(double scalar)
{
    return Vector3(x_*scalar,y_*scalar,z_*scalar);
}


Vector3 Vector3::operator/(double scalar)
{
    return Vector3(x_/scalar,y_/scalar,z_/scalar);
}


bool Vector3::operator==(Vector3& other)
{
    return x_==other.x_ && y_==other.y_ && z_==other.z_;
}


double Vector3::magnitude()
{
    return sqrt(pow(x_,2)+pow(y_,2)+pow(z_,2));
}


ostream& operator<<(ostream& out,const Vector3& p)
{
    out<<"("<<p.x_<<", "<<p.y_<<", "<<p.z_<<")"<<endl;
    return out;
}


istream& operator>>(istream& in, Vector3& p)
{
    cout<<"Enter a Point(x,y,z): "<<endl;
    in>>p.x_>>p.y_>>p.z_;
    return in;
}


double& Vector3::operator()(int row)
{
    if(row <= 0) return x_;
    else if(row == 1) return y_;
    else return z_;
}
