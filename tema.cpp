#include <iostream>
#include <fstream>

using namespace std;

#define INF INT32_MAX
int n, mat_cost[10][10], mat[10][10], in[100], out[100];

void create_mat()
{
    fstream file("graf.txt");
    file >> n;
    int x, y, cost;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            mat_cost[i][j] = (i == j) ? 0 : INF;
    }
    while (file >> x >> y >> cost) {
        mat_cost[x][y] = cost;
        mat[x][y] = 1;
    }
    file.close();
}

void get_degrees_i() {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += mat[i][j];
        }
        in[i] = sum;
    }
}


void get_degrees_o() {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= n; j++) {
            sum += mat[j][i];
        }
        out[i] = sum;
    }

}


void display(int a[10][10])
{
    cout << "\nMatricea de adiacenta:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (a[i][j] == INF)
                cout << " Inf";
            else
                cout << " " << a[i][j];
        cout << endl;
    }
    cout << "-----------------------------\n";
}

void afisare(int a[]) {

    cout << "\nAfisare grade: \n\t";
    for (int i = 1; i <= n; i++) {
        cout << " " << a[i];
    }
    cout << "\n-----------------------------";

}

int graf_complet() {
    for (int i = 1; i <= n; i++) {
            if (in[i] != n - 1 || out[i] != n - 1) return 0;
    }
    return 1;
}


int main()
{
    create_mat();
    display(mat_cost);
    display(mat);

    get_degrees_i();
    afisare(in);
    get_degrees_o();
    afisare(out);


    if(is_completed()){
        cout<<"\neste complet \n";
    }else cout<<"\nnu este complet";
}
