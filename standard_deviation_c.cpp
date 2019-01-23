/*This is my standard deviation console project, you can use it to help you out with statistics calculations.
  I am currently working on a version of this program that can read data from files instead of requiring
  manual data inputs into the console
 */

#include <iostream>
#include <cmath>
//#include <algorithm>
using namespace std;

double sq(double x) {
    return (x*x);
};
double midRange(double x, double y) {
    return ((x+y) /2);
};
double range(double x, double y) {
    return (x-y);
};
void mode(double *x, int n) {
    int highest_m_count = 0;
    int current_count = 1;
    double *modes = new double[(n/2)];
    int mode_indx = 0;
    int mode_count = 0;
    for(int i=n-1; i>0; i--) {
        if(x[i] == x[i-1]) {
            current_count++;
        } else {
            current_count = 1;
        }
        if(current_count > highest_m_count) {
            highest_m_count = current_count;
        }
    }
    for(int i=n-1; i>0; i--) {
        if(x[i] == x[i-1]) {
            current_count++;
        } else {
            current_count = 1;
        }
        if((current_count == highest_m_count) && (highest_m_count >= 2)) {
            modes[mode_indx] = x[i];
            mode_indx++;
            mode_count++;
        }
    }

    if(mode_count == 0) {
        cout<<"\nThere is no Mode.";
    } else {
        cout<<"\nThe mode(s) are: ";
        for(int i=0; i<mode_count; i++) {
            cout<<modes[i]<<"  ";
        }
        cout<<"\nThe modes occur with a frequency of: "<<highest_m_count;
    }

};
void median(double *x, int n) {
    if(n % 2 == 0) {
        cout<<"\nThe medians are: "<<x[((n/2)-1)]<<" AND "<<x[((n/2))];
    } else {
        cout<<"\nThe median is: "<<x[((n/2))];
    }
};


int main() {
    int loops = 0;
    int n = 0;
    cout<<"Enter The Number of Values here: ";
    cin>>n;

    double *p = new double[n];
    while(loops < n) {
        cout<<"Enter a number to put into the array: ";
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
    cout<<"\nThe numbers sorted: ";
    for(int i=0; i<n; i++) {
        cout<<as[i]<<" ";
    }
    double sq_sum = 0.0;
    double sum = 0.0;
    double final = 0.0;
    for(int i=0; i<n; i++) {
        sum += as[i];
        sq_sum += sq(as[i]);
    }
    final = ((n * sq_sum) - (sum * sum)) / (n * (n -1));
    final = sqrt(final);
    cout<<"\nThe mean is: "<<(sum / n);
    cout<<"\nThe standard deviation is: "<<final;
    cout<<"\nMidrange is: "<<midRange(as[0], as[n-1]);
    cout<<"\nRange is: "<<range(as[n-1], as[0]);
    mode(as, n);
    median(as, n);
    delete p; delete as; delete ia;

    return 0;

};
