#include <iostream>
#include <vector>
using namespace std;

int N;

int rc[27];
int lc[27];

void preorder(int now)
{
    cout << char(now + 64);
    if (lc[now] != int('.') - 64) preorder(lc[now]);
    if (rc[now] != int('.') - 64) preorder(rc[now]);
}

void inorder(int now)
{
    if (lc[now] != int('.') - 64) inorder(lc[now]);
    cout << char(now + 64);
    if (rc[now] != int('.') - 64) inorder(rc[now]);
}

void postorder(int now)
{
    if (lc[now] != int('.') - 64) postorder(lc[now]);
    if (rc[now] != int('.') - 64) postorder(rc[now]);
    cout << char(now + 64);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char mid, left, right;
        cin >> mid >> left >> right;
        rc[mid - 64] = right - 64;
        lc[mid - 64] = left - 64;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
    

    
    return 0;
}

