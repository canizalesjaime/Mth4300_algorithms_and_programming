class Matrix33
{
private: 
    double array[3][3];

public:
    Matrix33(double (*arr)[3]);
    Matrix33(){}

    Matrix33 operator+(const Matrix33& other);
    Matrix33 operator*(double scalar);
    Matrix33 operator*(Matrix33& other);
    double operator()(int row, int col);
    friend std::ostream& operator<<(std::ostream& out,const Matrix33& p);
    friend std::istream& operator>>(std::istream& in, Matrix33& p);
    
    double determinant();
};