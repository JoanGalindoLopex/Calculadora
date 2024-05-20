//  main.cpp
//  Calculadora en català
//  Creat per en Joan Galindo López al dia 19/11/2023.
//  Si estàs en terminal posa "gpp -o <nom del arxiu creat> <adreca de l'arxiu c++> && <adreca de l'arxiu creat>"

#include <iostream>
#include <unistd.h>
#include "Llib/mcm_i_mcd/mcm_i_mcd.hpp"
#include "Llib/Arrel/arrel.hpp"
#include "Llib/Operacio/operacio.hpp"
#include "Llib/Tornar_a_repetir/tornar_a_repetir.hpp"
#include "Llib/Signe/signe.hpp"
#include "Llib/Equacions/2n_grau/2g.hpp"
#include "Llib/Sumatori/sumatori.hpp"
#include "Llib/Exponent/exponent.hpp"

int main() {
    float num1, num2;
    unsigned int signe;
    double solucio;

    while (true) {
        std::cout << "Quina operació vols fer?\n";
        std::cout << " 1 = suma \n 2 = resta \n 3 = multiplicació \n 4 = divisió \n 5 = arrel \n 6 = MCM/MCD \n 7 = equacions de 2n grau \n 8 = sumatori \n 9 = més operacións \n> ";
        std::cin >> signe;
        std::cout << std::endl;
        
        if (signe >= 1 && signe <= 4) {
            std::cout << "Quin és el primer número? \n> ";
            std::cin >> num1;
            std::cout << "Quin és el segon número? \n> ";
            std::cin >> num2;
            std::cout << std::endl;

            solucio = operació(num1, num2, signe);
            std::cout << num1 << " " << sign(signe) << " " << num2 << " = " << solucio;
        } else if (signe == 5){
            std::cout << "Quan és el número elevat? x√ \n> ";
            std::cin >> num2;
            std::cout << std::endl;
            std::cout << "Quan és el nombre de dins? √x \n> ";
            std::cin >> num1;
            std::cout << std::endl;

            solucio = root(num1, num2);

            std::cout << num2 << "√" << num1 << " = " << solucio;
        } else if (signe == 6){
            int mcmd;
            
            std::cout << "Quin vols? \n 1 = MCM \n 2 = MCD \n 3 = Tots \n> ";
            std::cin >> mcmd;
            std::cout << "\nQuin és el primer número? \n> ";
            std::cin >> num1;
            std::cout << "Quin és el segon número? \n> ";
            std::cin >> num2;
            
            std::cout << std::endl;
            
            if (mcmd == 1){
                solucio = mcm(num1, num2);

                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << solucio;
            } else if (mcmd == 2){
                solucio = mcd(num1, num2);

                std::cout << "mcd(" << num1 << ", " << num2 << ") = " << solucio;
            } else if (mcmd == 3){
                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << mcm(num1, num2) << std::endl;
                std::cout << "mcm(" << num1 << ", " << num2 << ") = " << mcd(num1, num2);
            } else {
                std::cout << mcmd << " no és un nombre acceptat";
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
            
            std::cout << "\nx = " << eq2_positiu(num1, num2, num3) << "\nO\n" << "x = " << eq2_negatiu(num1, num2, num3);
        } else if (signe == 8){
            float a;
            float b;
            int c;
            std::cout << "Quin és el número final (el de dalt)? ∑^x \n> ";
            std::cin >> a;
            std::cout << "Quin és el número del principi (el de vaix)? ∑_n=x \n> ";
            std::cin >> b;
            std::cout << "Quina és la equació (el número del costat)? ∑ x \n 1 = n \n 2 = n^x \n 3 = x^n \n 4 = n+x \n 5 = n*x \n 6 = n/x \n 7 = x/n \n> ";
            std::cin >> c;

            float x = 0;
            if (c == 1){
                solucio = sumatori(a, b, c, x);

                std::cout << "\n∑^" << a << " _" << b << " " << signe_sum(c, x) << " = " << solucio;
            } else if (c > 1 && c < 8){
                std::string xneo;

                std::cout << "Quin número és x? \n> ";
                std::cin >> x;

                solucio = sumatori(a, b, c, x);

                std::cout << "\n∑^" << a << " _" << b << " " << signe_sum(c, x) << " = " << solucio;
            } else {
                std::cout << c << " no és un número acceptat";
            }
        } else if (signe == 9){
            std::cout << "MÉS OPERACIONS:\n 1 = exponent\n";
            int signeneo;
            std::cin >> signeneo;

            if (signeneo == 1){
                std::cout << "Quin és el primer número (a)? a^b \n> ";
                std::cin >> num1;
                std::cout << "Quin és el segon número (b)? a^b \n> ";
                std::cin >> num2;
                std::cout << std::endl;

                solucio = exponent(num1, num2);

                std::cout << num1 << "^(" << num2 << ") = " << solucio;
            }
        } else {
            std::cout << signe << " no és un nombre acceptat \n";
        }
        
        for (unsigned int i = 0; i < 2; i++){
            std::cout << std::endl;
        }

        unsigned int ms = 1000000;
        usleep(ms);
        std::cout << "Vols fer una altra operació? \n Y = Sí \n N = No \n> ";
        bool repetir = preguntar("Vols fer una altra operació? \n Y = Sí \n N = No \n> ");
        if (!repetir) {
            break;
        }
    }
    std::cout << std::endl;
    return 0;
}
    
