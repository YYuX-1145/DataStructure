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
        int p = (i - i % 2) / 2;
        if(!method(tar[p],tar[i]))
        {
            int t = tar[p];
            tar[p] = tar[i];
            tar[i] = t;
            i=p-1;
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