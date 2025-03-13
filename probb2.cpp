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

int init_v()
{
    for (int i = 0; i < 100; i++)
    {
        v[i] = 0;
    }
}

void bfs(int start)
{
    int i, k, st = 0, dr = 0;
    x[1] = start;
    v[start] = 1;

    while (st <= dr)
    {
        k = x[st];
        cout << k << " ";
        for (int i = 1; i <= n; i++)
        {
            if (v[i] == 0 && a[k][i] == 1)
            {
                v[i] = 1;
                x[++dr] = i;
            }
        }
        st++;
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
    int input, start;
    citire_adiacenta();
    afisare_adiacenta();

    init_v();
    afisare_conexitate();

    return 0;
}
