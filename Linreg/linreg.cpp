#include "linreg.h"

#include <math.h>

Linreg::Linreg()
{

}
Linreg::Linreg(float a, float b)
{
    this->a = a;
    this->b = b;
}

vector <float> Linreg::predict(vector<float> x)
{
    vector <float> predictions{};

    for (int i = 0; i < x.size(); i++)
    {
        predictions.push_back(this->a * x[i] + this->b);
    }
    return predictions;
}


// loss = 1/n /sigma{n} (y - y_predicted)^2
float Linreg::loss(vector <float> y, vector <float> y_predicted)
{
    int length = y.size();
    if (y_predicted.size() != length) {
        return -1;
    }
    float loss = 0;
    for (int i = 0; i < length; i++)
    {
        loss += pow(y[i] - y_predicted[i], 2.0);
    }
    loss = loss / length;
    return loss;
}
vector <float> Linreg::gradient(vector <float> y, vector <float> y_predicted, vector <float> x)
{
    float gradient_a = 0;
    float gradient_b = 0;
    int length = y.size();

    for (int i = 0; i < length; i++)
    {
        gradient_b += -2 * (y[i] - y_predicted[i]);
        gradient_a += -2 * x[i] * (y[i] - y_predicted[i]);
    }

    gradient_a /= length;
    gradient_b /= length;

    return vector<float>{gradient_a, gradient_b};
}

vector<float> Linreg::fit(vector <float> x, vector <float> y, int epochs, float learning_rate)
{

    vector<float>losses{};

    for (int i = 0; i < epochs; i++)
    {
        auto predictions = this->predict(x);
        losses.push_back(this->loss(y, predictions));
        auto gradients = this->gradient(y, predictions, x);
        this->a -= learning_rate * gradients[0];
        this->b -= learning_rate * gradients[1];
    }

    return losses;
}




