#include<iostream>
#include<string>

using namespace std;

class Dragon
{
    private:
        string name_;
        int wing_span_;
        bool can_fly_;
        

    public:
        Dragon(string name, int wing_span, int can_fly)
        :name_(name),wing_span_(wing_span),can_fly_(can_fly){}

        string get_name() const
        {
            return name_;
        }

        void set_flight()
        {
            can_fly_=!can_fly_;
        }

        void set_wing_span(int wing_span)
        {
            wing_span_=wing_span;
        }
};


int main()
{
    Dragon one("Salamence",200, true);
    Dragon two("Dragonnite",100, false);

    cout<<one.get_name()<<endl;
    return 0;
}