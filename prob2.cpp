#include <iostream>
#include <fstream>

using namespace std;

int n, m = 0, a[10][10], v[100], x[100];

void creare_matrice_adiacenta() 
{   
    fstream f("graf.txt");
    int i,x,y;
    f>>n;
    while(f >> x >> y)
    {
        a[x][y] = a[y][x] = 1;
        m++;
    }
    f.close();
}

void afisare_matrice_adiacenta()
{
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void bfs(int start)
{
    int i, k, st, dr;
    // Adaug varful initial in coada
    st = dr = 1;
    x[1] = start;
    // Vizitez varful
    v[start] = 1;

    // Cat timp coada != goala
    while(st<=dr) {
        // Extragem un element din coada
        k = x[st];
        // Afisam elementul
        cout << k << " ";

        // Determin vecinii
        for(int i = 1; i <= n; i++)
        {
            // Daca nu e vizitat si i este vecin
            if(v[i] == 0 && a[k][i] == 1) {
                // Vizitez varful si il adaug in coada
                v[i] = 1;
                x[++dr] = i;
            }
        }
        // "Sterg" din coada
        st++;
    }
}

int main()
{
    int x;
    creare_matrice_adiacenta();
    afisare_matrice_adiacenta();
    cout << "\n";

    cout << "\nIntroduceti nodul de start pentru parcurgerea grafului: ";
    cin >> x;
    bfs(x);

}
