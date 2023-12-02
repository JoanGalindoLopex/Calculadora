//  root.cpp
//  Calculadora
//  Created by Joan Galindo López on 26/11/
#include <iostream>
#include "root.hpp"

double root(float num1, float num2){
    double resposta;
    
    // num2√num1 = num1^(1/num2)
    resposta = pow(num1, 1 / num2);
    
    return resposta;
}
