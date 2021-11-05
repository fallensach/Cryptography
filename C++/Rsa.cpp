#include "Rsa.h"
#include <time.h>
#include <random>
static const int MAXPRIME = 1000;
static const int MINPRIME = 50;
static const char englishAlphabetUpper[] = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 random(rd()); //Standard mersenne_twister_engine seeded with rd()


Rsa::Rsa() {}

/**
std::map<std::string, int> Rsa::generateKeyPair() {
    
}
**/

int generateNumber(int from, int to) {
    std::uniform_int_distribution<> randomizer(from, to);
    return randomizer(random);
}

int Rsa::generatePrime() {
    int prime = 4;
    while (!isPrime(prime)) {
        int randomNum = generateNumber(MINPRIME, MAXPRIME);
        prime = randomNum;
    }
    return prime;
}

bool Rsa::isPrime(int n) {
    for (int i = 2; i < n-1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int Rsa::generatePublicKey() {
    int n_prime = generatePrime();
    int m_prime = generatePrime();
    setE(generateE(n_prime, m_prime));
    generatePrivateKey();
    return n_prime * m_prime;
}

long long Rsa::generatePrivateKey() {
    int n_prime = generatePrime();
    int m_prime = generatePrime();
    std::cout << n_prime << " " << m_prime << " " << e << std::endl;
    return ((phi(n_prime, m_prime) * generatePrime()) + 1) / e;
}

int Rsa::generateE(int n_prime, int m_prime) {
    //Real e value, too big to use in testing
    //int randomE = rand() % (phi(n_prime, m_prime)-1) + 2;
    int randomE = generateNumber(1,10); // e will be 1-10
    if (randomE == n_prime || randomE == m_prime) {
        return generateE(n_prime, m_prime);
    }
    return randomE;
}

int Rsa::phi(int n, int m) {
    return (n-1)*(m-1);
}

void Rsa::setE(int eValue) {
    e = eValue;
}
