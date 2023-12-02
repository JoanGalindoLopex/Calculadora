//  tornar_a_repetir.cpp
//  Calculadora
//  Created by Joan Galindo López on 26/11/2023.
#include <iostream>
#include "tornar_a_repetir.hpp"

int tornar_repetir(int a){
    int resposta = 2;
    char repetir = 0;
    std::cout << "Vols fer una altre operació?\nY = si\nN = no \n";
    std::cin >> repetir;
    
    if (repetir == 'Y' || repetir == 'y'){
        resposta = 1;
    } else if (repetir == 'N' || repetir == 'n'){
        resposta = 0;
    } else {
        resposta = 2;
    }
    return resposta;
} // antic model ^^

bool preguntar(std::string pregunta) {
    char respostaYN;
    while (true) {
        std::cin >> respostaYN;
        if (respostaYN == 'Y' || respostaYN == 'y') {
            std::cout << std::endl;
            return true;
        }
        if (respostaYN == 'N' || respostaYN == 'n') {
            return false;
        }
        std::cout << respostaYN << " no és un nombre acceptat, torna a provar si us plau \n> ";
    }
}
