#pragma once 

#include<string>
#include<iostream>


class Merchant
{
public:
    Merchant(){}

    // pure virtual function
    virtual void sell_weapon()=0;

protected:
    int gold_;
    std::string territory_;

};