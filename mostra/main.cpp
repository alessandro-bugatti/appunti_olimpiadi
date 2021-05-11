#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

#define DINAMICA

int dina[MAXM + 1][MAXN + 1];

void stampa_matrice(int d[][MAXM + 1], int m, int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            cout << d[i][j] << " ";
        cout << endl;

    }
}

//Ci deve essere un problema che non mi permette di prendere
//tutti e 21 i punti, al massimo arrivo a 18
//Rimesso a posto, un errore nell'indice di un ciclo, 21 punti
int dinamica(int visitatore, int N, int guida, int M,
            vector<int> &V,
            vector<int> &G, int soluzione)
{
    for (int i = 0; i <= N; i++)
        dina[0][i] = i;
    for (int i = 0; i <= M; i++)
        dina[i][0] = 0;
    V.insert(V.begin(),0);
    G.insert(G.begin(),0);
    int risultato = 0;
    for (int j = 1; j <= N; j++)
    {
        for (int i = 1; i <= M; i++)
            {
                int temp = -1;
                if (V.at(j) < G.at(i))
                {
                    int massimo = 0;
                    for (int k = 0; k <= i - 1; k++)
                        if (dina[k][j-1] > massimo)
                            massimo = dina[k][j-1];
                    temp = massimo + 2;
                }
                if (dina[i][j-1] + 1 > temp)
                    dina[i][j] = dina[i][j-1] + 1;
                else
                    dina[i][j] = temp;
            }

    }
    for (int i = 0; i <= M; i++)
        if (dina[i][N] > risultato)
            risultato = dina[i][N];
    return risultato;
}

int esplora(int visitatore, int N, int guida, int M,
            const vector<int> &V,
            const vector<int> &G, int soluzione)
{

    if (visitatore == N)
        return soluzione;
    if (guida == M)
        return N - visitatore;
    int uno = -1, due, tre;
    if (V.at(visitatore) < G.at(guida))
        uno = esplora(visitatore + 1 , N, guida + 1, M, V, G, soluzione + 2);
    due = esplora(visitatore, N, guida + 1, M, V, G, soluzione);
    tre = esplora(visitatore + 1, N, guida, M, V, G, soluzione + 1);
    if (uno >= due && uno >= tre)
        return uno;
    if (uno <= due && due >= tre)
        return due;
    return tre;
}

int solve() {
    int N, M;
    cin >> N >> M;

    int risposta = 0;  // memorizza qui la risposta
    vector<int> V(N), G(M);

    for (int i=0; i<N; i++) {
        cin >> V[i];
    }
    for (int i=0; i<M; i++) {
        cin >> G[i];
    }

    #ifdef GREEDY_1
    //Versione greedy entra il visitatore solo se accompagnato,
    //testata 2 - 3 punti, dipende dall'input
    int visitatore = 0, guida = 0;
    while (visitatore < N && guida < M )
    {
        if (V.at(visitatore) < G.at(guida))
        {
            //Entrano un visitatore con la sua guida
            risposta += 2;
            visitatore++;
            guida++;
        }
        else
            guida++;
    }
    //Aggiunge gli eventuali visitatori rimasti in coda
    risposta += (N - visitatore);
    #endif // GREEDY_1

    #ifdef GREEDY_2
    //Versione greedy entra il visitatore finchè non c'è una guida adatta,
    //testata 0 punti
    int visitatore = 0, guida = 0;
    while (visitatore < N && guida < M )
    {
        if (V.at(visitatore) < G.at(guida))
        {
            //Entrano un visitatore con la sua guida
            risposta += 2;
            visitatore++;
            guida++;
        }
        else
            visitatore++;
    }
    //Aggiunge gli eventuali visitatori rimasti in coda
    risposta += (N - visitatore);
    #endif // GREEDY_2

    #ifdef RICORSIVA
    //Ricorsiva, prende 7 punti, perchè i successivi casi di test sono sempre
    //troppo grandi per ottenere una soluzione in tempo
    risposta = esplora(0, N, 0, M, V, G, 0);
    #endif // RICORSIVA

    //
    #ifdef DINAMICA
    risposta = dinamica(0, N, 0, M, V, G, 0);
    //cout << endl;
    //stampa_matrice(dina, N, M);
    #endif

    return risposta;
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
