class Vector3
{
private: 
    double x_;
    double y_;
    double z_;

public:
    Vector3(double x=0, double y=0, double z=0): x_(x), y_(y), z_(z){}

    Vector3 operator+(Vector3& other);
    Vector3 operator-(Vector3& other);
    Vector3 operator*(double scalar);
    Vector3 operator/(double scalar);
    bool operator==(Vector3& other);
    double& operator()(int row);

    friend std::ostream& operator<<(std::ostream& out,const Vector3& p);
    friend std::istream& operator>>(std::istream& in, Vector3& p);
    
    double magnitude();

};
