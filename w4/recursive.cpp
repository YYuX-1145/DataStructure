#include <iostream>
#include <stack>

using namespace std;
int ACK(int m,int n)
{
    if(m==0)
        return n+1;
    if(m!=0&&n==0)
        return ACK(m-1,1);
    if(m!=0&&n!=0)
        return ACK(m-1,ACK(m,n-1));
    throw ' ';
}

int ACK_NR(int m,int n)
{
    stack<pair<int, int>> s;
    s.push({m, n});
    int m_,n_;
    while (!s.empty()) 
    {
        auto x = s.top();        
        m_=x.first;
        n_=x.second;
        s.pop();
        if (m_ == 0) 
        {
            if (s.empty()) 
            {
                return n_ + 1;
            }
            s.top().second = n_ + 1;
        } 
        else if (n_ == 0) 
        {
            s.push({m_ - 1, 1});
        } 
        else 
        {
            s.push({m_ - 1, -1});
            s.push({m_, n_ - 1});
        }
    }
    return -1;
}

int main()
{
   cout<<ACK(2,1)<<endl;
   cout<<ACK_NR(2,1);
}