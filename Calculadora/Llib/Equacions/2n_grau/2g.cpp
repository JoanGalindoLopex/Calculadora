//
//  2g.cpp
//  Calculadora
//
//  Created by Joan Galindo López on 02/12/2023.
//

#include "2g.hpp"
double eq2_positiu(float a, float b, float c){
    double x = (-b+sqrt(pow(b, 2)-4*a*c))/(2*a);
    
    return x;
}

double eq2_negatiu(float a, float b, float c){
    double x = (-b-sqrt(pow(b, 2)-4*a*c))/(2*a);
    
    return x;
}
