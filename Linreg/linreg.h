#ifndef LINREG_H
#define LINREG_H

#include <vector>

using namespace std;

class Linreg
{

public:

    float a = 0;
    float b = 0;


    Linreg();
    Linreg(float a, float b);
    vector<float> fit(vector <float> x, vector <float> y, int epochs = 10, float learning_rate = 0.001);
    vector <float> predict(vector<float> x);
    float loss(vector <float> y, vector <float> y_predicted);
    vector <float> gradient(vector <float> y, vector <float> y_predicted, vector <float> x);

};

#endif // LINREG_H
