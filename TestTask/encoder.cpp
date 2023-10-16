#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Encoder{

    public:
        Encoder(string s){
            this -> str = s;
        }

        Encoder(vector<bitset<12>> b){
            // 12 потому что можно запихать символы по 2 (qpsk) / 4 (qam16) / 6 (qam64) бит целиком в сет без дырок и головняка
            this -> bits = b;
        }

        vector<int> encode(int n){
            
            // n --- 

        }

        string decode(int n){

        }

    private:
        string str;
        vector<bitset<12>> bits;

};