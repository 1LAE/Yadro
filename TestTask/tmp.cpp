#include <vector>
#include <iostream>
#include <cmath>

# define USE_MATH_DEFINES

using namespace std;

// 00010010

int main(){
    int M = 4;
    int dimentions = 1 << (M / 2); // 2^M
    cout << dimentions << endl;

    vector<int> dxy;
    for(int i = 0; i < dimentions / 2; i++){
        dxy.push_back(-(1 + 2 * i));
        dxy.push_back(1 + 2 * i);

    }

    for(auto at: dxy){
        cout << at << " ";
    }

    for(int i = 0 ; i < dxy.size(); i++){
                for(int j = 0; j < dxy.size(); j++){
                    cout << i << ' ' << j << endl;
                }}

    return 0;
}