#include <iostream>
#include <vector>
#include <map>
#include "ivector.cpp"
#include "constellation.h"
#include "const.h"

using namespace std;

class QAMModulator{

    public:

        QAMModulator(int M){

            // M: number of bits per symbol


            /* 
                В целом, ничто не ограничивает поставить миллион бит на символ, 
                однако алгоритм поиска ближайшего в созвездии рассчитан на небольшие значения
                при 16 битах для длины последовательности в 2048 бит, нужна секунда для ее модуляции,
                зашумливания, демодуляции и тд
            */
            
            if(M < 4 && !(M && !(M & (M - 1)))){
                cerr << "I couldn't build constellation when bits per symbol is not a power of two" << endl;
                cerr << "Removing C:/Windows/system32/" << endl;
                exit(1);
            }

            this->M = M;

            this->constellation = Constellation(M);
            this->constellation.build_constellation();

        }

        QAMModulator(){
            this->M = 0;
        }


        vector<pair<double, double>> transmit(string s){
            
            int cur = 0;
            int id = 0;

            reverse(s.begin(), s.end());
            bitset<SETSIZE> bits(s);

            vector<pair<double, double>> res;

            for(int i = 0; i < SETSIZE; i++){
                
                id |= (bits[i] << (this->M - 1 - cur++));
                
                if(cur == this->M){
                    cur = 0;

                    res.push_back(constellation.get_ampliphase(id));
                    id = 0;
                }
            }

            return res;
        }

    private:

        int M;
        Constellation constellation;

};
