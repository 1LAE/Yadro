
#ifndef CONSTELLATION_H
#define CONSTELLATION_H

#include <iostream>
#include <map>
#include <vector>
#include <cmath>

#define CONST 1 // нормировочная константа

using namespace std;

class Constellation{

    public:

        Constellation(int M){
            this->M = M;
        }

        Constellation(){
            this->M = 0;
        }


        void build_constellation(){
            
            // столько будет точек в одном ряду / колонке созвездия

            int dimentions = 1 << (M / 2); // sqrt(2^M)
            vector<int> dxy;
            for(int i = 0; i < dimentions / 2; i++){
                dxy.push_back(-(1 + 2 * i));
                dxy.push_back(1 + 2 * i);

            }

            int T = 0;

            // fill data
            for(int i = 0 ; i < dxy.size(); i++){
                for(int j = 0; j < dxy.size(); j++){
                    
                    constellation_coordinates.push_back({dxy[i], dxy[j]});
                    constellation_id[{dxy[i], dxy[j]}] = T++;

                    // амплитуду я не нормировал, но это не принципиально
                    double amplitude = sqrt(dxy[i] * dxy[i] +dxy[j] * dxy[j]) * CONST;
                    double phase = atan2(dxy[j], dxy[i]);
                    if(phase < 0){
                        phase += 2 * M_PI;
                    }

                    // Это работает, потому что id это индекс в векторе он же представим в виде двоичного числа
                    // И созвездие получается как надо с последовательным порядком данных
                    constellation_values.push_back({amplitude, phase});

                }
            }
        }

        pair<double, double> get_ampliphase(int id){
            if(id >= constellation_values.size()){
                cout << "id " << id << " is too big" << endl;
            }
            return constellation_values[id]; 
        }




    private:

        int M = 0;
        map<pair<int, int>, int> constellation_id; // созвездие в виде словаря
        vector<pair<int, int>> constellation_coordinates; // созвездие в виде вектора
        vector<pair<double, double>> constellation_values; 
        // Немного получилось лишних данных, зато универсально

};



#endif