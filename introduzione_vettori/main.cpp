#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //A volte i valori sono molto grandi (>2000000000)
    //allora si usano i long long
    //Vettore del C, la dimensione viene stabilita nel problema
    const int DIM = 10;
    long long int v[DIM];

    //Vettore del C++
    vector <long long int> v2;

    //Inserimento valori
    for (int i = 0; i < DIM; i++)
        v[i] = rand()%100;

    for (int i = 0; i < DIM; i++)
        v2.push_back(rand()%100);
    cout << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << v[i] << " ";
    }

    //Uguale al C, quindi non devo imparare niente
    //Se i è fuori dal range di indici validi, il comportamento
    //è indeterminato, come in C
    cout << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << v2[i] << " ";
    }

    //Fa un controllo sull'indice e se è sbagliato "salta"
    //Risulta però in filo più lento del precedente
    cout << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << v2.at(i) << " ";
    }

    //Veloce da scrivere, non puoi sbagliare gli indici
    //Però funziona solo se vuoi scorrere tutti gli elementi
    cout << endl;
    for (auto el: v2)
        cout << el << " ";
    //Ordinamento per un vettore del C
    sort(v, v + DIM);
    cout << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << v[i] << " ";
    }
    //Ordinamento per un vettore C++
    sort(v2.begin() + 2, v2.end());
    cout << endl;
    for (int i = 0; i < DIM; i++)
    {
        cout << v2[i] << " ";
    }

    return 0;
}
