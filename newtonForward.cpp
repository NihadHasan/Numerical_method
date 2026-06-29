#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x[20], y[20][20];
    int n, i, j;
    float value, h, u, sum, term;

    cout << "--- Newton Forward Interpolation ---\n";

    // 1. Input number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    // 2. Input data points (x and y)
    cout << "Enter the data points (x and y):\n";
    for (i = 0; i < n; i++) {
        cout << "x[" << i << "] = ";
        cin >> x[i];
        cout << "y[" << i << "] = ";
        cin >> y[i][0];
    }

    // 3. Construct the Forward Difference Table
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }

    // 4. Display the Difference Table
    cout << "\n--- Forward Difference Table ---\n";
    for (i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << x[i];
        for (j = 0; j < n - i; j++) {
            cout << "\t" << fixed << setprecision(2) << y[i][j];
        }
        cout << endl;
    }

    // 5. Input the interpolation value
    cout << "\nEnter the value of x to interpolate for: ";
    cin >> value;

    // 6. Applying the Formula
    h = x[1] - x[0];
    u = (value - x[0]) / h;

    sum = y[0][0];
    term = 1.0;

    for (i = 1; i < n; i++) {
        term = term * (u - i + 1) / i;
        sum = sum + term * y[0][i];
    }

    cout << "\nThe interpolated value at x = "
         << fixed << setprecision(2) << value
         << " is " << setprecision(4) << sum << endl;

    return 0;
}