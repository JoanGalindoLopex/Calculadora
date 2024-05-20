#include "mcm_i_mcd.hpp"

int mcd(int a, int b) {
    if (b > a) return mcd(b, a);
    if (b == 0) return 1;
    int c = a % b;
    if (c == 0) return b;
    return mcd(b, c);
}

int mcm(int a, int b) {
    return (a * b) / mcd(a, b);
}
