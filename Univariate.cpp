#include<bits/stdc++.h>

using namespace std;

vector<float> house_size = {1,1.5,2,2.5,3,3.5,4,4.5,5};
vector<float> house_price = {300,400,500,600,700,800,900,1000,1100}; // in thousands

float w = 0;
float b = 0;
int m = house_price.size();

float compute_costFunction(float w_temp, float b_temp) {
    float cost = 0;
    for (int i = 0; i < m; i++) {
        cost += pow((w_temp * house_size[i] + b_temp - house_price[i]), 2);
    }
    cost = cost / (2 * m);
    return cost;
}

void compute_Derivate(float &d_w, float &d_b) {
    d_w = 0;
    d_b = 0;
    for (int i = 0; i < m; i++) {
        d_w += (w * house_size[i] + b - house_price[i]) * house_size[i];
        d_b += (w * house_size[i] + b - house_price[i]);
    }
    d_w = d_w / m;
    d_b = d_b / m;
}


float alpha = 0.01; // smaller learning rate

void gradient_descent(float alpha, float &w, float &b) {
    int iterations = 10000;
    while (iterations > 0) {
        float d_w = 0, d_b = 0;
        compute_Derivate(d_w, d_b);
        w = w - alpha * d_w;
        b = b - alpha * d_b;
        iterations--;
        // Print the cost every 1000 iterations to track progress
       
        if (iterations % 1000 == 0) {
            cout << "Cost at iteration " << iterations << ": " << compute_costFunction(w, b) << endl;
        }
        
    }
}

int main() {
    float cost = compute_costFunction(w, b);
    cout << "Initial cost: " << cost << endl;

    gradient_descent(alpha, w, b);

    cout << "w: " << w << endl;
    cout << "b: " << b << endl;

    cout << "Enter size of the house (*1000 Sq Feet): ";
    float house_size;
    cin >> house_size;

    float estimated_price = w * house_size + b;
    cout << "Estimated Price: " << estimated_price << " thousand dollars" << endl;

    return 0;
}
