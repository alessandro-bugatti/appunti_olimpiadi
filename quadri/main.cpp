#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

static FILE *fr, *fw;

// Declaring variables
static int N;
static long long M;
static int* V;
static int B;

// Declaring functions
int quadri_prima_versione(int N, long long M, int* V)
{
    vector <long long int> somme;
    //partial_sum(V, V + N, somme.begin());
    somme.push_back(V[0]);
    for (int i = 1; i < N; i++)
        somme.push_back(somme.at(i-1) + V[i]);

    int i = 0, j = 0;
    long long int totale = V[0];
    //Inizializza l'intervallo di partenza,
    //serve nel caso l'intervallo migliore sia all'inizio
    while (totale <= M && j < N)
    {
        j++;
        totale += V[j];
    }
    int B = j - i;
    int risultato = B;
    totale = somme[j] - somme[i];
    while (j < N)
    {
        //cout << i <<" " <<  j << " " << totale << " "
        //<< risultato << endl;
        if (totale <= M)
            j++;
        else if (totale > M)
        {
            if (B - 1 < risultato)
                risultato = B - 1;
            i++;
        }
        B = j - i;
        totale = somme[j] - somme[i];
    }
    return risultato;
}

// Declaring functions
int quadri(int N, long long M, int* V)
{
    int i = -1, j = -1;
    long long int totale = 0;
    int B = N;
    int risultato = N;
    while (j < N)
    {   if (totale <= M)
            totale += V[++j];
        else
        {
           totale -= V[++i];
           B = j - i;
        }
        if (B < risultato)
            risultato = B;
    }
    return risultato ;
}


int main() {
	fr = stdin;
	fw = stdout;

	// Iterators used in for loops
	int i0;

	// Reading input
	fscanf(fr, "%d %lld", &N, &M);
	V = (int*)malloc(N * sizeof(int));
	for (i0 = 0; i0 < N; i0++) {
	    fscanf(fr, "%d", &V[i0]);
	}

	// Calling functions
	B = quadri(N, M, V);

	// Writing output
	fprintf(fw, "%d\n", B);

	fclose(fr);
	fclose(fw);
	return 0;
}
