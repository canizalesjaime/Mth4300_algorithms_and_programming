#include<iostream>
#include<string>

using namespace std;

class toaster
{
    private:
        int capacity_;
        double price_;
        int size_height_;
        int size_width_;
        string brand_;

    public:
        toaster(int capacity, double price, int size_height,int size_width, string brand)
        {
            capacity_=capacity;
            price_=price;
            size_height_=size_height;
            size_width_=size_width;
            brand_=brand;
        }

        void get_price()
        {
            cout<<"price is: "<<price_<<endl;
        }

        void increase_price(double amount)
        {
            price_=price_+amount;
        }

        void get_capacity()
        {
            cout<<"capacity is: "<<capacity_<<endl;
        }
};


int main()
{
    toaster one(1000,99.99, 5, 4, "NINJA");
    toaster two(500,20.99, 3, 3, "WALGREENS");

    one.get_price();
    return 0;
}