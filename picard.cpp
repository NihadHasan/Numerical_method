#include <bits/stdc++.h>
using namespace std;

float f(float x, float y) {
    return x - y;   
}

int main() {
    float x0, y0, h, xn, x;
    int n, iterations;

    cout << "Enter x0 : ";
    cin >> x0;

    cout << "Enter y0 : ";
    cin >> y0;

    cout << "Enter step size (h): ";
    cin >> h;

    cout << "Enter final x (xn): ";
    cin >> xn;

    cout << "Enter number of iterations: ";
    cin >> iterations;

    n = (xn - x0) / h;

    float y[20][100];  

    for (int i = 0; i <= n; i++) {
        y[0][i] = y0;
    }

    cout << "\n" << setw(10) << "x";
    for (int i = 1; i <= iterations; i++) {
        cout << setw(12) << ("y" + to_string(i));
    }
    
    for (int j = 1; j <= iterations; j++) {
        y[j][0] = y0;

        for (int i = 1; i <= n; i++) {
            x = x0 + i * h;

            float integral = 0.0;

            integral += f(x0, y[j - 1][0]);

            for (int k = 1; k < i; k++) {
                integral += 2 * f(x0 + k * h, y[j - 1][k]);
            }

            integral += f(x, y[j - 1][i]);

            integral = integral * (h / 2.0);

            y[j][i] = y0 + integral;
        }
    }

    for (int i = 0; i <= n; i++) {
        x = x0 + i * h;
        cout << setw(10) << fixed << setprecision(4) << x;

        for (int j = 1; j <= iterations; j++) {
            cout << setw(12) << fixed << setprecision(6) << y[j][i];
        }
        cout << endl;
    }

    cout << "\nFinal Approximation:\n";
    cout << "y(" << xn << ") ≈ " << fixed << setprecision(8)
         << y[iterations][n] << endl;

    return 0;
}