#include <iostream>
//#include <algorithm>
using namespace std;



int main() {
    int loops = 0;
    int n = 0;
    cout<<"Enter Number of Values here\n";
    cin>>n;

    double *p = new double[n];
    while(loops < n) {
        cout<<"Enter a number to put into the array\n";
        double tmp;
        cin>>tmp;
        p[loops] = tmp;
        loops++;
    }
    //sort(p, p + n);
    double *as = new double[n]; //array sorted
    double smallest = p[0];
    double largest = -1024.00;
    int *ia = new int[n]; //index array, for checking
    for(int i=0; i<n; i++) {
        ia[i] = 1024;
    }
    for(int i=0; i<n; i++) {
        if(p[i] > largest) {
            largest = p[i];
        }
        if(p[i] < smallest) {
            smallest = p[i];
        }
    }


    int index = 0;
    while(as[n-1] != largest) {
        bool notInIA = true;
        int pos;
        for(int i=0; i<n; i++) {
            if(p[i] <= smallest) {
                for(int j=0; j<n; j++) {
                    if(ia[j] == i) {
                        notInIA = false;
                        break;
                    }
                }
                if(notInIA) {
                    pos = i;
                    smallest = p[i];
                }
            }
            notInIA = true;
        }
        smallest = largest +1;
        as[index] = p[pos];
        ia[index] = pos;
        index++;

    }

    for(int i=0; i<n; i++) {
        cout<<as[i]<<" ";
    }

    return 0;

}
