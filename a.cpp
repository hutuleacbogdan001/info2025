#include <iostream>
#include <fstream>

using namespace std;
struct Nod
{
    int info;
    Nod *left, *right;
};

void create(Nod *&root, ifstream &f)
{
    int value;
    f >> value;

    if (value == 0)
        root = NULL;
    else
    {
        root = new Nod;
        root->info = value;
        create(root->left, f); // Left child
        create(root->right, f);
    }
}

void RSD(Nod *root)
{
    if (root)
    {
        cout << root->info << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

int isSame(Nod *root1, Nod *root2)
{
    if (root1 == nullptr && root2 == nullptr)
        return 1; 

    if (root1 == nullptr || root2 == nullptr)
        return 0;

    if (root1->info != root2->info)
        return 0; 

    return isSame(root1->left, root2->left) && isSame(root1->right, root2->right);
}


int main()
{
    ifstream copac1("../text/bfs.txt");
    ifstream copac2("../text/cost.txt");

    Nod *root = nullptr;
    Nod *root2 = nullptr;

    create(root, copac1);
    create(root2, copac2);

    if(isSame(root, root2)) cout<<"\nSunt la fel";
    else cout<<"\nNu sunt la fel";

    return 0;
}


//

#include <iostream>
#include <fstream>

using namespace std;
struct Nod
{
    int info;
    Nod *left, *right;
};

void create(Nod *&root, ifstream &f)
{
    int value;
    f >> value;

    if (value == 0)
        root = NULL;
    else
    {
        root = new Nod;
        root->info = value;
        create(root->left, f); // Left child
        create(root->right, f);
    }
}

void RSD(Nod *root)
{
    if (root)
    {
        cout << root->info << " ";
        RSD(root->left);
        RSD(root->right);
    }
}

void SRD(Nod *root)
{
    if (root)
    {
        SRD(root->left);
        cout << root->info << " ";
        SRD(root->right);
    }
}

void SDR(Nod *root)
{
    if (root)
    {
        SDR(root->left);
        SDR(root->right);
        cout << root->info << " ";
    }
}

int height(Nod *root)
{
    int x, y;
    if (root == nullptr)
        return -1;
    else
    {
        x = height(root->left);
        y = height(root->right);
        if (x < y)
            return y + 1;
        else
            return x + 1;
    }
}

int count_nodes(Nod *root, int &n)
{
    if (root)
    {
        n++;
        count_nodes(root->left, n);
        count_nodes(root->right, n);
        return n;
    }
}

int strict(Nod *root)
{
    int x, y;
    if (root == nullptr)
        return 1;
    else
    {
        bool condition1 = root->left == nullptr && root->right != nullptr;
        bool condition2 = root->left != nullptr && root->right == nullptr;
        if (condition1 || condition2)
            return 0;
        else
            return strict(root->left) && strict(root->right);
    }
}

int echilibrat(Nod *root)
{
    int left_n = 0, right_n = 0;
    if (root == nullptr)
        return 1;
    else
    {
        left_n = count_nodes(root->left, left_n);
        right_n = count_nodes(root->right, right_n);

        if (abs(left_n - right_n) > 1)
            return 0;
        return echilibrat(root->left) && echilibrat(root->right);
    }
}
int terminal(Nod *root)
{
    if (root == nullptr)
        return 0;

    if (root->left == nullptr && root->right == nullptr)
        return 1;

    int smt = terminal(root->left);
    int smt2 = terminal(root->right);

    return smt + smt2;
}

void scrie_terminal(Nod* root)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
        cout<<root->info<<" ";

    scrie_terminal(root->left);
    scrie_terminal(root->right);



}


int main()
{
    ifstream f("../text/bfs.txt");
    ifstream file("../text/cost.txt");

    if (!f)
    {
        cout << "Error opening file!" << endl;
        return 1;
    }
    Nod *root = nullptr;
    Nod *root2 = nullptr;
    create(root, f);
    create(root2, file)

    cout << "Preorder Traversal (RSD): ";
    RSD(root);
    cout << endl;

    cout << "Inorder Traversal (SRD): ";
    SRD(root);
    cout << endl;

    cout << "Postorder Traversal (SDR): ";
    SDR(root);
    cout << endl;

    cout << "Inaltimea arborelui este: " << height(root);

    if (strict(root))
        cout << "\n arborele este binar strict";
    else
        cout << "\narborele nu este binar strict";

    int n = 0;
    n = count_nodes(root, n);
    cout << "\nnumar de noduri: " << n;
    f.close();

    if (echilibrat(root))
        cout << "\nThe tree is balanced." << endl;
    else
        cout << "\nThe tree is not balanced." << endl;

    cout << "\nsunt " << terminal(root) << " noduri terminale";

    cout<<"\nse vor scrie nodurile terminale ";
    scrie_terminal(root);
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
