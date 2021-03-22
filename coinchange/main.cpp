/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <fstream>
#include <iostream>

using namespace std;

// input data
long long V[15];

int main() {
//  uncomment the following lines if you want to read/write from files
 ifstream cin("input.txt");
 ofstream cout("output.txt");

    for (int i = 0; i < 15; i++)
        cin >> V[i];
    long long int coins[] = {50000, 20000, 10000, 5000, 2000, 1000, 500,
                    200, 100, 50, 20 , 10, 5, 2, 1};
    long long sol[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // insert your code here
    long long totale = 0;
    for (int i = 0; i < 15; i++)
        totale += V[i]*coins[15 -i - 1];
    //cout << totale << endl;
    for (int i = 0; i < 15; i++)
    {
        //cout << totale / coins[i] << endl;
        sol[15 - i - 1] = totale / coins[i];
        totale = totale % coins[i];
    }

    for (int i = 0; i < 15; i++)
        cout << sol[i] << " ";
    cout << endl;
    return 0;
}
