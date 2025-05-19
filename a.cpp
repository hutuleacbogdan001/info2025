#include <iostream>
#include <fstream>

using namespace std;
struct Nod
{
    int info;
    Nod *st, *dr;
};

void creaza(Nod *&rad, ifstream &f)
{
    int x;
    f >> x;

    if (x == 0)
        rad = NULL;
    else
    {
        rad = new Nod;
        rad->info = x;
        creaza(rad->st, f);
        creaza(rad->dr, f);
    }
}

void RSD(Nod *rad)
{
    if (rad)
    {
        cout << rad->info << " ";
        RSD(rad->st);
        RSD(rad->dr);
    }
}

int la_fel(Nod *rad1, Nod *rad2)
{
    if (rad1 == nullptr && rad2 == nullptr)
        return 1; 

    if (rad1 == nullptr || rad2 == nullptr)
        return 0;

    if (rad1->info != rad2->info)
        return 0; 

    return la_fel(rad1->st, rad2->st) && la_fel(rad1->dr, rad2->dr);
}


int main()
{
    ifstream copac1("../text/bfs.txt");
    ifstream copac2("../text/cost.txt");

    Nod *rad = nullptr;
    Nod *root2 = nullptr;

    creaza(rad, copac1);
    creaza(root2, copac2);

    if(la_fel(rad, root2)) cout<<"\nSunt la fel";
    else cout<<"\nNu sunt la fel";

    return 0;
}


//

1
2 
4 
0
0
5
7
0
0
0
3 
0 
6 
8 
0
0
9
0
0
