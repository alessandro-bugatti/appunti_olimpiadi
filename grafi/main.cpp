#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

const int MAX_NODI = 100;

list<int> grafo[MAX_NODI];
int visitato[MAX_NODI];

void visita_profondita(int n)
{
    stack<int> pila;
    pila.push(n);
    while (!pila.empty())
    {
        int corrente = pila.top();
        pila.pop();
        if (visitato[corrente] == 0)
        {
            visitato[corrente] = 1;
            cout << corrente << endl;
            for (auto i: grafo[corrente])
                pila.push(i);
        }
    }
}

void visita_ampiezza(int n)
{
    queue<int> coda;
    coda.push(n);
    while (!coda.empty())
    {
        int corrente = coda.front();
        coda.pop();
        if (visitato[corrente] == 0)
        {
            visitato[corrente] = 1;
            cout << corrente << endl;
            for (auto i: grafo[corrente])
                coda.push(i);
        }
    }
}

int main()
{
    grafo[1].push_back(3);
    grafo[1].push_back(5);
    grafo[2].push_back(3);
    grafo[2].push_back(5);
    grafo[2].push_back(4);
    grafo[3].push_back(1);
    grafo[3].push_back(2);
    grafo[4].push_back(2);
    grafo[5].push_back(1);
    grafo[5].push_back(2);
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " -> ";
         for (auto j: grafo[i])
            cout << j << " ";
        cout << endl;
    }
    cout << "Visita profondita" << endl;
    visita_profondita(1);
    for (int i = 0; i< MAX_NODI; i++ )
        visitato[i] = 0;
    cout << "Visita ampiezza" << endl;
    visita_ampiezza(1);

    return 0;
}
