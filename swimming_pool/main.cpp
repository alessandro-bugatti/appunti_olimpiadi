/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <iostream>

using namespace std;

// constraints
#define MAXN 10000

// input data
int N, i;
int P[MAXN];

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &P[i]));

    //Inseriamo la nostra soluzione
    int minimo = P[0];
    int massimo = P[N - 1];
    int mezzo = (massimo - minimo)/2 + minimo;
    int trovato;
    for (int i = 0; i < N; i++)
        if (P[i] >= mezzo){
            trovato = i;
            break;
        }
    int P1 = P[trovato - 1];
    int P2 = P[trovato];
    //cout << P1 << " " << P2 << endl;
    int risultato;
    int maxP1;
    if (P1 - minimo > massimo - P1)
        maxP1 = P1 - minimo;
    else
        maxP1 = massimo - P1;
    int maxP2;
    if (P2 - minimo > massimo - P2)
        maxP2 = P2 - minimo;
    else
        maxP2 = massimo - P2;

    if (maxP1 < maxP2)
        risultato = maxP1;
    else
        risultato = maxP2;


    printf("%d\n", risultato); // print the result
    return 0;
}




