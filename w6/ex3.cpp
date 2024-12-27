#include<iostream>
#include<vector>
#include<functional>
using namespace std;
void toheap(vector<int>& tar)
{
    bool swap = false;
    function<bool(int,int)> method = less_equal<int>();
    if(tar[0]>=tar[1])
    {
        method = greater_equal<int>();
    }
    for (int i = 1; i <= tar.size() - 1;i++)
    {
        int n = i;
        int p = (n - n % 2) / 2;  
        if(n%2==0)
            p--;
        while(!method(tar[p],tar[n])&&n!=0)
        {
            int t = tar[p];
            tar[p] = tar[n];
            tar[n] = t;
            p = (n - n % 2) / 2;
            if (n % 2 == 0)
                p--;
            n = p;
            swap = true;
        }
    }
    if(swap)
    {
        cout << "non" << " ";
    }
    else
    {
        cout << "oui" << " ";
    }
}
int main()
{
    vector<int> HEAP1 = {100, 86, 48, 73, 35, 39, 42, 57, 66, 21};
    vector<int> HEAP2 = {12 , 70, 33, 65, 24, 56, 48, 92, 86, 33};
    toheap(HEAP1);
    for(auto i:HEAP1)
        cout << i << ' ';
    cout << endl;
    toheap(HEAP2);
    for (auto i : HEAP2)
        cout << i << ' ';
}