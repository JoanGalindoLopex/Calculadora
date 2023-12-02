//  Operació.cpp
//  Calculadora
//  Created by Joan Galindo López on 26/11/2023.

#include "Operation.hpp"

double operació(float num1, float num2, int signe) {
    double resultat;
    
    if (signe == 1){
        resultat = num1 + num2;
    } else if (signe == 2){
        resultat = num1 - num2;
    } else if (signe == 3){
        resultat = num1 * num2;
    } else if (signe == 4){
        resultat = num1 / num2;
    } else {
        resultat = 0;
    }
    
    return resultat;
}
