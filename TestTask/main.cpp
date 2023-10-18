#include <vector>
#include <iostream>
#include <random>
#include <ctime>
#include "const.h"
#include "runner.h"


using namespace std;


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    srand(time(0));

    string input;

    for(int i = 0; i < SETSIZE; i++){
        char c = (rand() % 2) + '0';
        input.push_back(c);
    }

    int qam_scheme;
    auto fp = freopen("config.txt", "r", stdin);
    string qam_scheme_name;
    cin >> qam_scheme_name;
    try {
        qam_scheme = mapping.at(qam_scheme_name);
    } catch (const std::out_of_range& oor) {
        cerr << "I couldn't find this qam scheme" << endl;
        cerr << "Removing C:/Windows/system32/" << endl;
        exit(1);
    }
    fclose(fp);


    // int qam_scheme = mapping[qam_scheme_name]; // Задаем схему модуляции

    auto runner = Runner(input, qam_scheme);
    
    /*
        здесь вышла небольшая путаница, где-то var, где-то std, везде имеется в виду 
        стандартное отклонение как параметр для нормального распределения
        принципиальной разницы, надеюсь, нет
    */
    
    vector<pair<double, double>> var;

    for(int i = 0; i < 10; i++){
        double amp_std = 0.1 * i;
        double phase_std = 0.1 * i;
        var.push_back({amp_std, phase_std});
    }

    runner.run(var);
    


    cout << "DONE" << endl;
    return 0;
}