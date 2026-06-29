#include<bits/stdc++.h>
using namespace std;
double f(double x){
    return 1.0/(1.0+ x*x);
}
int main(){
    double a,b,h,sum,integral;
    cout<<"\n=== Simpson's 1/3 Rule  Integration ===\n";
    cout<<"Enter lower limit (a): "<<endl;
    cin>>a;
    cout<<"Enter lower limit (b): "<<endl;
    cin>>b;
    cout<<"Enter number of subintervals (n) :";
    int n;
    cin>>n;
    if(n%2!=0){
        cout<<"\n Error!! Number of interval must be even.."<<endl;
        cout<<"Please run again with even n ."<<endl;

    }
    else{
        h=(b-a)/(double)n;
        sum=f(a)+ f(b);
        for(int i=1;i<n;i++){
            if(i%2==0){
                sum+=2* f(a+ i*h);
            }
            else{
                sum+=4* f(a+i*h);
            }

        }
         integral=(h/3.0)*sum;
         cout<<"\n================================"<<endl<<"Step size(h)       ="<<setprecision(6)<<h;
         cout<<"\n Integral value = "<<setprecision(10)<<integral;
         cout<<"\n================================\n";

    }
return 0;

}