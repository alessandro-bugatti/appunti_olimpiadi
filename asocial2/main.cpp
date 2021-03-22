#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        int f[1000];
        int N;
        int j = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int followers;
            cin >> followers;
            while (followers > 0)
            {
                f[j] = i;
                j++;
                followers--;
            }
        }
        //Verifico che un utente non segua se stesso
        //eventualmente lo scambio con un posto a caso
        //fino a quando non va bene
        for (int i = 0; i < N; i++)
            while (f[i] == i)
            {
                int temp;
                int pos = rand();
                temp = f[i];
                f[i]= f[pos%N];
                f[pos%N] = temp;
            }
        cout << "Case #" << c << ": ";
        for (int i = 0; i < N; i++)
        {
            cout << f[i]<< " ";
        }
        cout << endl;
    }
    return 0;
}
