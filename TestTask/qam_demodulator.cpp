#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include "constellation.h"

using namespace std;

class QAMDemodulator{

    public:

        QAMDemodulator(int M){

            this->M = M;

            if(M < 4 && !(M && !(M & (M - 1)))){
                cerr << "I couldn't build constellation when bits per symbol is not a power of two" << endl;
                cerr << "Removing C:/Windows/system32/" << endl;
                exit(1);
            }

            this->constellation = Constellation(M);
            this->constellation.build_constellation();
        }

        QAMDemodulator(){
            this->M = 0;
        }

        string receive(vector<pair<double, double>> data){

            string result = "";

            for(auto at: data){

                double amplitude = at.first;
                double phase = at.second;

                int id = -1;
                int mindist = 1e9;

                /*
                    Полный перебор в целом приемлем в рамках тестового задания (наверное :D), если мы не пытаемся в qam4096
                    Из эвристик можно добавить попадание в окрестность конкретной точки чтобы останавливать перебор
                    Ну или закастомить округления с учетом границ, но у меня не хватило времени 
                        написать кастомный вектор на отрицательных индексах с возможностью округлений и быстрых операций
                    На массивах это чревато выходом за границы и неоднозначным поведением 
                        (таким даже олимпиадники редко балуются)
                */

                for(int _id = 0; _id < (1 << this->M); _id++){

                    auto cur = this->constellation.get_ampliphase(_id);
                    double dist = pow(amplitude - cur.first, 2) + 
                                    pow(phase - cur.second, 2);

                    if(dist < mindist){
                        id = _id;
                        mindist = dist;
                    }
                }
                
                for(int i = 0; i < this->M; i++){
                    result.push_back((id & (1 << (this->M - 1 - i))) ? '1' : '0');
                }
            }
            return result;
        }


    private:
        int M = 0;
        Constellation constellation;


};