#ifndef CONST_H
#define CONST_H

#define SETSIZE 1024

#define QPSK 2

// Почему-то на qam16 при нулевой дисперсии шума выдает искажения :(
// При том на постоянную величину вероятности ошибки на бит 0.17
#define QAM16 4
#define QAM64 6

#include <map>
std::map<std::string, int> mapping = {
    {"QPSK", QPSK},
    {"QAM16", QAM16},
    {"QAM64", QAM64}
};

#endif