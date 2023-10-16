#include <vector>
#include <map>
#include <random>

using namespace std;

class HaussianBlur{

    public:
        HaussianBlur(pair<double, double> mean, pair<double, double> var){
            this->mean = mean;
            this->var = var;

            random_device rd;
            gen = mt19937(rd());
            d_amp = normal_distribution<double>(mean.first, var.first);
            d_phase = normal_distribution<double>(mean.second, var.second);

        }

        HaussianBlur(){
            this->mean = {0, 0};
            this->var = {0, 0};
        }

        vector<pair<double, double>> get_blur(vector<pair<double, double>> constellation_values){
            
            vector<pair<double, double>> result;

            double noise_amp = d_amp(gen);
            double noise_phase = d_phase(gen);

            for (auto at: constellation_values){
                double amplitude = at.first + noise_amp;
                double phase = at.second + noise_phase;

                result.push_back({amplitude, phase});
            }

            return result;
        }


    private:
        pair<double, double> mean, var;
        normal_distribution<double> d_amp;
        normal_distribution<double> d_phase;
        mt19937 gen; 


};