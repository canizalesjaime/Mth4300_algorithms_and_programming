#include<iostream>
#include<cmath>
#include "matrix33.h"

using namespace std;


Matrix33::Matrix33(double (*arr)[3])
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            array[i][j]=arr[i][j];
}


Matrix33 Matrix33::operator+(const Matrix33& other)
{
    double arr[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            arr[i][j]=array[i][j]+other.array[i][j];
    return Matrix33(arr);
}


Matrix33 Matrix33::operator*(double scalar)
{
    double arr[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            arr[i][j]=array[i][j]*scalar;

    return Matrix33(arr);
}


Matrix33 Matrix33::operator*(Matrix33& other)
{
    double arr[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            arr[j][i]=array[j][0]*other.array[0][i]+
                      array[j][1]*other.array[1][i]+
                      array[j][2]*other.array[2][i];
    
    return Matrix33(arr);
}


ostream& operator<<(ostream& out,const Matrix33& arr)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
            out<<arr.array[i][j]<<" ";
        cout<<endl;
    }
    return out;
}


istream& operator>>(istream& in, Matrix33& arr)
{
    cout<<"Enter a 3 by 3 Matrix(as a sequence of 9 points(row-wise)): "<<endl;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            in>>arr.array[i][j];
    return in;
}


double Matrix33::operator()(int row, int col)
{
    return array[row][col];
}


double Matrix33::determinant()
{
    // a(ei−fh)−b(di−fg) +c(dh−eg)
    return array[0][0]*(array[1][1]*array[2][2]-array[1][2]*array[2][1])-
    array[0][1]*(array[1][0]*array[2][2]-array[1][2]*array[2][0])+
    array[0][2]*(array[1][0]*array[2][1]-array[1][1]*array[2][0]);
}

