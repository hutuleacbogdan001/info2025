#include <iostream>
#include <fstream>

using namespace std;

int a[10][10], n, x[10], v[10];

void citire_adiacenta()
{
    int x, y;
    ifstream f("graf.txt");
    f >> n;
    while (f >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
    }
    f.close();
}

void afisare_adiacenta()
{
    cout << "Matricea de adiacenta este: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int start)
{
    v[start] = 1;
    cout << " " << start;

    for (int i = 1; i <= n; i++)
    {
        if (a[start][i] && !v[i])
        {
            dfs(i);
        }
    }
}

void afisare_conexitate()
{
    int k = 0;

    cout << "Componentele conexe ale grafului sunt: \n";
    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            k++;
            cout << "Componeta conexa " << k << ": ";
            dfs(i);
            cout << endl;
        }
    }
}

int main()
{
    citire_adiacenta();
    afisare_adiacenta();

    afisare_conexitate();

    return 0;
}
