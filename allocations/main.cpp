#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        int soluzione = 0;
        int N, B;
        int houses[100001];
        cin >> N >> B;
        for (int i = 0; i < N; i++)
            cin >> houses[i];
        sort (houses,houses + N);
        int totale = 0;
        //Attenzione alla condizione soluzione <= N
        while (soluzione <= N && totale <= B)
        {
            totale += houses[soluzione];
            soluzione++;
        }
        cout << "Case #" << c << ": " << soluzione - 1 << endl;
    }
    return 0;
}
