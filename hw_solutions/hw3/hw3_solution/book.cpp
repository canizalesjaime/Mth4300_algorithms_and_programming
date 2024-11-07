#include<iostream>
#include<string>

using namespace std;


class Book
{
private:
    string title;
    string author;
    int yearPublished;
    double price;

public:
    Book(string& bookTitle, string& bookAuthor, int publishedYear=1990,double bookPrice=0.0)
    :title(bookTitle), author(bookAuthor), yearPublished(publishedYear), price(bookPrice){}


    void applyDiscount(double& discountPercent)
    {
        if (discountPercent > 1) discountPercent=discountPercent/100;
        price=price*(1-discountPercent);
    }


    void getBookInfo() const
    {
        cout<<"Title: "<<title<<", Author: "<<author<<", Year Published: "
            <<yearPublished<<", Price: "<<price<<endl;
    }
};

int main()
{
    string bookName="The Great Gatsby";
    string author="F. Scott Fitzgerald";
    Book myBook(bookName, author, 1925, 15.99);
    double discount = 10.0; // 10% discount
    myBook.applyDiscount(discount);
    myBook.getBookInfo();
    return 0;
}