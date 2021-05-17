#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <list>
#include <queue>

using namespace std;

struct Nodo{
    bool terminale = false;
    list<int> collegati;
    int distanza = 1;
};

//Al momento risolve 14 casi su 24
int risolvi(vector<Nodo> &nodi, int partenza)
{
    int visitati[nodi.size()] = {0};
    for (int i = 0; i < nodi.size(); i++)
        nodi.at(i).distanza = -1;
    queue<int> coda;
    coda.push(partenza);
    nodi.at(partenza).distanza = 1;
    //cout << "Visita" << endl;
    while (!coda.empty())
    {
        partenza = coda.front();
        //cout << partenza << " " << nodi.at(partenza).distanza << endl;
        if (nodi.at(partenza).terminale)
            return nodi.at(partenza).distanza;
        coda.pop();
        if (visitati[partenza] == 0)
        {
            visitati[partenza] = 1;
            for (auto i : nodi.at(partenza).collegati)
            {
                //cout << "set distanza" << i << " - > " << nodi.at(partenza).distanza + 1 << endl;
                if (nodi.at(i).distanza == -1)
                    nodi.at(i).distanza = nodi.at(partenza).distanza + 1;
                coda.push(i);
            }
        }
    }
}

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A), X(B), Y(B);

    for (int i = 0; i < A; i++) {
        cin >> Z[i];
    }

    for (int i = 0; i < B; i++) {
        cin >> X[i] >> Y[i];
    }


    int idx = 0; // memorizza qui l'indice della lampadina
    int num = 1; // memorizza qui il numero di interruttori

    vector<Nodo> nodi(N);
    for (int i = 0; i < A; i++)
        nodi.at(Z.at(i)).terminale = true;
    for (int i = 0; i < B; i++)
    {
        nodi.at(X.at(i)).collegati.push_back(Y.at(i));
        nodi.at(Y.at(i)).collegati.push_back(X.at(i));
    }

    for (int i = 0; i < N; i++)
        if (!nodi.at(i).terminale)
    {
        int valore = risolvi(nodi, i);
        if (valore > num)
        {
            num = valore;
            idx = i;
        }
    }
    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
