#include<bits/stdc++.h>
using namespace std;

// Function definition
float f(float x){
    return 1/(1 + x*x);
}

int main(){
    int n;
    float a, b;

    cout << "\n=== Trapezoidal Rule Integration ===\n";

    cout << "Enter lower limit (a): ";
    cin >> a;

    cout << "Enter upper limit (b): ";
    cin >> b;

    cout << "Enter number of subintervals (n): ";
    cin >> n;

    float h = (b - a) / n;   // Step size
    float sum = f(a) + f(b);

    for(int i = 1; i < n; i++){
        sum += 2 * f(a + i*h);
    }

    float integral = (h / 2) * sum;

    cout << fixed << setprecision(6);
    cout << "\nStep size (h) = " << h;
    cout << "\nApproximate Integral = " << integral << endl;

    return 0;
}