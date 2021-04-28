#include <iostream>

using namespace std;

int lunghezza_stringa(string s)
{
    if (s == "")
        return 0;
    return 1 + lunghezza_stringa(s.erase(0,1));
}

int somma (int a, int b)
{
    if (b == 0)
        return a;
    return 1 + somma(a , b - 1);
}

int main()
{
    cout << lunghezza_stringa("pippo") << endl;
    return 0;
}
