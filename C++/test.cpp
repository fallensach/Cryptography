#include "Rsa.h"

int main() {
    Rsa rsa;
    int n_prime = rsa.generatePrime();
    int m_prime = rsa.generatePrime();
    int e = rsa.generateE(n_prime, m_prime);
    long long x = rsa.generatePrivateKey();
    std::cout << std::fixed;
    std::cout << x << std::endl;

    return 0;
}
