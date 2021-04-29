/*
 * Soluzione del problema spy del CodeForces contest 713
 */

#include <iostream>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, a, b = -1, i_a, i_b, flag = 0;
        std::cin >> N;
        int valore;
        std::cin >> valore;
        a = valore;
        i_a = 1;
        for (int j = 2; j <= N; j++)
        {
            std::cin >> valore;
            if (valore == a)
                flag = 1;
            else
            {
                b = valore;
                i_b = j;
            }

        }
        if (flag == 1)
            std::cout << i_b << std::endl;
        else
            std::cout << i_a << std::endl;
    }
    return 0;
}
