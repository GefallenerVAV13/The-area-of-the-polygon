#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>

using std::endl;

double square(std::vector<float> x, std::vector<float> y, int size)
{
    float S = 0.00000;

    for (int i = 0; i < size-1; i++)
    {
        S = S + (y[i] + y[i + 1]) * (x[i + 1] - x[i]);
    }

    S = S - (y[0] + y[size-1]) * (x[size-1] - x[0]);

    return S/2;
}

int main()
{
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    int n;
    float x, y, S;
    std::vector <float> x_arr;
    std::vector <float> y_arr;

    input >> n;
    while (!input.eof())
    {
        input >> x >> y;
        x_arr.push_back(x);
        y_arr.push_back(y);
    }
    output.precision(5);
    output << std::fixed << square(x_arr, y_arr, n);
}