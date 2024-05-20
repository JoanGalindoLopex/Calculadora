//
//  signe.cpp
//  Calculadora
//
//  Created by Joan Galindo López on 27/11/2023.
//

#include "signe.hpp"
char sign(int signe){
    char resultat_signe;
    
    if (signe == 1){
        resultat_signe = '+';
    } else if (signe == 2){
        resultat_signe = '-';
    } else if (signe == 3){
        resultat_signe = '*';
    } else if (signe == 4) {
        resultat_signe = '/';
    } else {
        resultat_signe = 0;
    }
    return resultat_signe;
}
