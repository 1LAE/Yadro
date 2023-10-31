#ifndef RUNNER_H
#define RUNNER_H

#include <vector>
#include "qam_modulator.h"
#include "qam_demodulator.h"
#include "constellation.h"
#include "blur.h"
#include "const.h"
#include <random>
#include <ctime>

using namespace std;

class Runner{

    public:
        Runner(string s, int M){
            this->M = M;
            this->modulator = QAMModulator(M);
            this->demodulator = QAMDemodulator(M);
            this->input = s;
        }

        void run(vector<pair<double, double>> var){

            this->var = var;
            auto result = this->modulator.transmit(this->input);

            for(auto at: var){
                double amp_std = at.first;
                double phase_std = at.second;

                auto noiser = HaussianBlur({0, 0}, {amp_std, phase_std});
                

                vector<string> cur_res;

                // работает долго, зато объемная выборка
                for(int p = 0; p < 1000; p++){

                    auto noised = noiser.get_blur(result);

                    string out = this->demodulator.receive(noised);
                    cur_res.push_back(out);

                }

                this->output.push_back({amp_std, cur_res});
            }

            auto fp = freopen("output.txt", "w", stdout);

            cout << this->input << endl;
            cout << this->output.size() << endl;

            for(auto at: this->output){
                cout << at.first << endl;
                cout << at.second.size() << endl;
                for(auto bt: at.second){
                    cout << bt << endl;
                }
            }

            fclose(fp);
        }

    private:

        int M;
        // Make default initializers
        QAMModulator modulator;
        QAMDemodulator demodulator;
        string input;
        vector<pair<double, vector<string>>> output = {};
        vector<pair<double, double>> var;


};

#endif