#ifndef PCSC2017_GROUP5_GRAPH_H
#define PCSC2017_GROUP5_GRAPH_H

#include "readFile.h"
using namespace std;
class Graph {
public:
    Graph(Data data);

    void make_graph_least_square(Data data, int degree);
    void make_graph_lagrange(Data data);
    void make_graph_piece_wise_least_squares(Data data, int degree,int intervalle);
    void make_graph_piece_wise_lagrange(Data data, int intervalle);
    void make_graph_FFT(Data data, Data data_original);
private:
};

#endif //PCSC2017_GROUP5_GRAPH_H
