#ifndef _rsa_h
#define _rsa_h

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>

class Rsa {
    public:
        Rsa();
        std::map<std::string, int> generateKeyPair();
        int generatePrime();
        int phi(int n, int m);
        int generateE(int n, int m);
        long long generatePrivateKey();

    private:
        int generatePublicKey();
        bool isPrime(int n);
        void setE(int e);
        void setD(int d);
        int e;
        int d;

};

#endif