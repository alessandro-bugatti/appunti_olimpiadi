#include <iostream>
#include <algorithm>

using namespace std;

struct Persona{
    int N;
    int followers;
    int follows;
};

//Ritorna vero se a < b
//Ritorna falso altrimenti
bool cmp(Persona a, Persona b)
{
    if (a.followers > b.followers)
        return true;
    return false;
}

bool cmp_N(Persona a, Persona b)
{
    if (a.N < b.N)
        return true;
    return false;
}


int main()
{
    int T;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (int c = 1; c <= T; c++)
    {
        Persona p[1000];
        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            p[i].N = i;
            cin >> p[i].followers;
            p[i].follows = -1;
            //cout << p[i].N << " " << p[i].followers
            //<< " " << p[i].follows << endl;
        }
        sort(p, p + N, cmp);
//        for (int i = 0; i < N; i++)
//        {
//            cout << p[i].N << " " << p[i].followers
//            << " " << p[i].follows << endl;
//        }
        int inizio = 0, fine = N -1;
        while (inizio < N && p[inizio].followers > 0)
        {
            if (p[inizio].followers > 0)
            {
                p[fine].follows = p[inizio].N;
                p[inizio].followers--;
            }
            if (p[inizio].followers == 0)
                inizio++;
            fine--;
        }
        //cout << "Dopo l'algoritmo" << endl;
//        for (int i = 0; i < N; i++)
//        {
//            cout << p[i].N << " " << p[i].followers
//            << " " << p[i].follows << endl;
//        }
        sort(p, p+N, cmp_N);
//        cout << "Dopo il riordinamento" << endl;
//        for (int i = 0; i < N; i++)
//        {
//            cout << p[i].N << " " << p[i].followers
//            << " " << p[i].follows << endl;
//        }
        //Verifico che un utente non segua sè stesso
        for (int i = 0; i < N - 1; i++)
            if (p[i].N == p[i].follows)
        {
            int temp;
            temp = p[i].follows;
            p[i].follows = p[(i+1)%N].follows;
            p[(i+1)%N].follows = temp;
        }

        cout << "Case #" << c << ": ";
        for (int i = 0; i < N; i++)
        {
            cout << p[i].follows << " ";
        }
        cout << endl;

    }
    return 0;
}
