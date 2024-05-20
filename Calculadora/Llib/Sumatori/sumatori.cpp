//  sumatori.cpp
//  Calculadora
//  Creat per Joan Galindo López al 03/12/2023.

/*
 a = ∑^x
 b = ∑_x
 c = ∑ x
 
 1 = n
 2 = n^x
 3 = x^n
 4 = n+x
 5 = n*x
 6 = n/x
 7 = x/n
*/

#include "sumatori.hpp"
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


std::string signe_sum(int c, int x){
    // std::string solució;
    std::ostringstream solució;

    if (c == 1){
        solució << "n";
    } else if (c == 2){
        solució << "n^" << x;
    } else if (c == 3){
        solució << x << "^n";
    } else if (c == 4){
        solució << "n+" << x;
    } else if (c == 5){
        solució << "n*" << x;
    } else if (c == 6){
        solució << "n/" << x;
    } else {
        solució << x << "/n";
    }

    return solució.str();
}

double sumatori(float a, float b, float c, float x){
    double solució = 0;
    float n = b;
    
    if (c == 1){
        for (; b <= a; b++){
            solució += b;
        }
    } else if (c >= 2 && c <= 7){
        if (c == 2){
            for (; b <= a; b++){
                solució += pow(b, x);
            }
        } else if (c == 3) {
            for (; b <= a; b++){
                solució += pow(x, b);
            }
        } else if (c == 4){
            n += x;
            for (; b <= a; b++){
                solució += n;
            }
        } else if (c == 5){
            n *= x;
            for (; b < a; b++){
                solució += n;
            }
        } else if (c == 6){
            n /= x;
            for (; b < a; b++){
                solució += n;
            }
        } else {
            x /= n;
            for (; b < a; b++){
                solució += x;
            }
        }
    }
    
    return solució;
}
