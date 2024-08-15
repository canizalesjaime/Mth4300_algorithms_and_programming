#pragma once

#include<string>
#include<iostream>

#include "player.h"
#include "merchant.h"

class Archer: public Player, Merchant
{
public:
    Archer(std::string name, int level, std::string bow, std::string snare): 
    Player(name,level), Merchant(),bow_type_(bow), snare_type_(snare){}

    void print_class(){std::cout<<"Class: Wizzard ";}

private:
    std::string bow_type_;
    std::string snare_type_;
};