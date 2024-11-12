#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Matrix_nm
{
private: 
    vector<vector<double>> matrix;

public:
    // Constructors 
    Matrix_nm(){}
    Matrix_nm(int rows, int cols):matrix(vector<vector<double>>(rows, vector<double>(cols))){}
    Matrix_nm(vector<vector<double>> mat):matrix(mat){}


    Matrix_nm operator+(const Matrix_nm& other)
    {
        if(matrix.size()!=other.matrix.size() || 
           matrix[0].size()!=other.matrix[0].size())
        {
            cout<<"dimensions dont match"<<endl;
            return Matrix_nm();
        }

        Matrix_nm mat(matrix.size(),matrix[0].size());
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++)
                mat.matrix[row][col]=matrix[row][col]+other.matrix[row][col];

        return mat;
    }


    Matrix_nm operator*(double scalar)
    {
        Matrix_nm mat(matrix.size(),matrix[0].size());
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++)
                mat.matrix[row][col]=matrix[row][col]*scalar;

        return mat;
    }


    Matrix_nm operator*(Matrix_nm& other)
    {
        if(matrix[0].size()!=other.matrix.size())
        {
           cout<<"dimensions dont match"<<endl;
           return Matrix_nm();
        }

        Matrix_nm mat(matrix.size(),other.matrix[0].size());
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < other.matrix[0].size(); j++)
                mat.matrix[j][i]=matrix[j][0]*other.matrix[0][i]+
                                 matrix[j][1]*other.matrix[1][i]+
                                 matrix[j][2]*other.matrix[2][i];
        
        return mat;
    }


    friend ostream& operator<<(ostream& out,const Matrix_nm& mat)
    {
        for(int row = 0; row < mat.matrix.size(); row++)
        {
            for(int col = 0; col < mat.matrix[0].size(); col++)
                out<<mat.matrix[row][col]<<" ";
            cout<<endl;
        }
        return out;
    }


    friend istream& operator>>(istream& in, Matrix_nm& mat)
    {
        cout<<"Enter a Matrix size(row, col): "<<endl;
        int rows,cols;
        in>>rows>>cols;
        mat=Matrix_nm(rows,cols);
        cout<<"Enter a Matrix(as a sequence of points(row-wise)): "<<endl;
        for(int row = 0; row < rows; row++)
            for(int col = 0; col < cols; col++)
                in>>mat.matrix[row][col];
        return in;
    }


    //remove ith row and jth column from matrix
    Matrix_nm construct_Aij(int i, int j)
    {
        Matrix_nm mat(matrix);
        mat.matrix.erase(mat.matrix.begin()+i); //remove ith row

        for(int row = 0; row < mat.matrix.size(); row++) //remove jth column
            mat.matrix[row].erase(mat.matrix[row].begin()+j);
        
        return mat;
    }


    double determinant()
    {
        if(matrix.size() != matrix[0].size())
        {
            cout<<"Not a square matrix, cannot compute determinant"<<endl;
            return 0;
        }

        else if (matrix.size()==1) return matrix[0][0];
        
        else if(matrix.size()==2) 
            return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];
        
        else
        {
            double sum = 0;
            for(int i = 0; i < matrix[0].size(); i++)
                sum=sum + pow(-1,i)*matrix[0][i]*(construct_Aij(0,i).determinant());
            
            return sum;
        }
    }
};


int main()
{
    Matrix_nm mat1({{0.0,1.0,0.0},
                    {1.0,0.0,0.0},
                    {0.0,0.0,1.0}});

    Matrix_nm mat2({{1.0,0.0,3.0},
                    {0.0,5.0,6.0},
                    {7.0,8.0,2.0}});


    cout<<mat1+mat2<<endl;
    cout<<mat1*mat2<<endl;
    cout<<mat1*3<<endl;
    cout<<"Determinants: "<<mat1.determinant()<<" "<<mat2.determinant()<<endl;

    
    Matrix_nm mat3;
    cin>>mat3;
    cout<<mat3;

    return 0;
}