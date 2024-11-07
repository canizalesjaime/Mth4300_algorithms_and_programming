#include<iostream>
#include<cmath>
#include"vector3.h"
#include"matrix33.h"


using namespace std;

void test_mat();
void test_vec();
Vector3 mat_times_vec(Matrix33 mat, Vector3 vec);

int main()
{
    //test_mat();
    //test_vec();

    double angle=M_PI/4;
    double arr1[3][3]={{cos(angle),-sin(angle),0.0},
                       {sin(angle),cos(angle),0.0},
                       {0.0,0.0,1.0}};
    Matrix33 mat1(arr1);
    Vector3 vec1(1,0,0);
    cout<<mat_times_vec(mat1, vec1);
    return 0;
}


void test_mat()
{
    double arr1[3][3]={{0.0,1.0,0.0},
                       {1.0,0.0,0.0},
                       {0.0,0.0,1.0}};
    Matrix33 mat1(arr1);

    double arr2[3][3]={{1.0,0.0,3.0},
                       {0.0,5.0,6.0},
                       {7.0,8.0,0.0}};
    Matrix33 mat2(arr2);

    cout<<mat1*mat2<<endl;
    cout<<mat1.determinant()<<" "<<mat2.determinant()<<endl;

    
    Matrix33 mat3;
    cin>>mat3;
    cout<<mat3;
}


void test_vec()
{
    Vector3 vec1(1.0,2.0,3);
    Vector3 vec2(2.0,4.0,7.0);

    Vector3 vec3=vec1+vec2;
    Vector3 vec4=vec1-vec2;
    Vector3 vec5=vec1*2;
    Vector3 vec6=vec2/5;

    Vector3 vec7;
    cin>>vec7;

    bool check = vec1 == vec2;
    cout<<vec1<<vec2<<vec3<<vec4<<vec5<<vec6<<vec7<<check<<" magnitude: "<<vec1.magnitude();
}


Vector3 mat_times_vec(Matrix33 mat, Vector3 vec)
{
    Vector3 out_vec;
    for(int j=0;j<3;j++)
        out_vec(j)=mat(j,0)*vec(0)+mat(j,1)*vec(1)+mat(j,2)*vec(2);
    
    return out_vec;
}