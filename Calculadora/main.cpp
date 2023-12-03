//  main.cpp
//  Calculadora en català
//  Creat per en Joan Galindo López al dia 19/11/2023.
//  Si estàs en terminal posa "gpp -o <nom del arxiu creat> <adreca de l'arxiu c++> && <adreca de l'arxiu creat>"

#include <iostream>
#include <unistd.h>
#include "Llib/mcm_i_mcd/mcm_i_mcd.h"
#include "Llib/root/root.hpp"
#include "Llib/Operation/Operation.hpp"
#include "Llib/Tornar_a_repetir/tornar_a_repetir.hpp"
#include "Llib/Sign/sign.hpp"
#include "Llib/Equacions/2n_grau/2g.hpp"

int main() {
    float num1, num2;
    unsigned int signe;
    
    while (true) {
        std::cout << "Quina operació vols fer?\n";
        std::cout << "1 = suma \n2 = resta \n3 = multiplicació \n4 = divisió \n5 = arrel \n6 = MCM/MCD \n7 = equacions de 2n grau\n> ";
        std::cin >> signe;
        std::cout << std::endl;
        
        if (signe >= 1 && signe <= 4) {
            std::cout << "Quin és el primer número? \n> ";
            std::cin >> num1;
            std::cout << "Quin és el segon número? \n> ";
            std::cin >> num2;
            std::cout << std::endl;
            std::cout << num1 << " " << sign(signe) << " " << num2 << " = " << operació(num1, num2, signe);
        } else if (signe == 5){
            std::cout << "Quan és el número elevat? x√ \n> ";
            std::cin >> num2;
            std::cout << std::endl;
            std::cout << "Quan és el nombre de dins? √x \n> ";
            std::cin >> num1;
            std::cout << std::endl;
            
            std::cout << num2 << "√" << num1 << " = " << root(num1, num2);
        } else if (signe == 6){
            int mcmd;
            
            std::cout << "Quin vols? \n1 = MCM \n2 = MCD \n3 = Tots \n> ";
            std::cin >> mcmd;
            std::cout << "Quin és el primer número? \n> ";
            std::cin >> num1;
            std::cout << "Quin és el segon número? \n> ";
            std::cin >> num2;
            
            if (mcmd == 1){
                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << mcm(num1, num2);
            } else if (mcmd == 2){
                std::cout << "mcd(" << num1 << ", " << num2 << ") = " << mcd(num1, num2);
            } else if (mcmd == 3){
                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << mcm(num1, num2) << std::endl;
                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << mcd(num1, num2) << std::endl;
            } else {
                std::cout << mcmd << " no és un nombre acceptat \n";
            }
            std::cout << std::endl;
        } else if (signe == 7){
            float num3;
            std::cout << "Quin és el número a? ax^2 +bx +c \n> ";
            std::cin >> num1;
            std::cout << "Quin és el número b? ax^2 +bx +c \n> ";
            std::cin >> num2;
            std::cout << "Quin és el número c? ax^2 +bx +c \n> ";
            std::cin >> num3;
            for ( int i = 0; i < 2; i++){
                std::cout << std::endl;
            }
            
            std::cout << "x = " << eq2_positiu(num1, num2, num3) << "\nO\n" << "x = " << eq2_negatiu(num1, num2, num3);
        } else {
            std::cout << signe << " no és un nombre acceptat \n";
        }
        
        for (unsigned int i = 0; i < 2; i++){
            std::cout << std::endl;
        }
        
        unsigned int ms = 1000000;
        usleep(ms);
        std::cout << "Vols fer una altra operació? \nY = Sí \nN = No \n> ";
        bool repetir = preguntar("Vols fer una altra operació? \nY = Sí \nN = No \n> ");
        if (!repetir) {
            break;
        }
    }
    std::cout << std::endl;
    return 0;
}
    
