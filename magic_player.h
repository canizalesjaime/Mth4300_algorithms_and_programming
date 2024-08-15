#pragma once

#include<string>
#include<iostream>

#include "player.h"

class MagicPlayer: protected Player
{
public:
    MagicPlayer(std::string name, int level, int healer_level, int magic_level): 
    Player(name,level), healer_level_(healer_level), magic_level_(magic_level){}
    void print_class()override{std::cout<<"Class: Warrior ";}
    void print_level_warrior(){print_level();}

private:
    int healer_level_;
    int magic_level_;

};