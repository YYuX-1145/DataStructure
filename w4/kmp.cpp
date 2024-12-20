#include <string>
#include <iostream>
#include <vector>
using namespace std;
int kmp(const string str1,const string str2)
{
    int ret=0;
    vector<int> pos;
    if(str1.length()<str2.length())
    {
        return 0;
    }
    vector<int> next(str2.length());
    
    next[0] = 0;
    for (int i = 1, j = 0; i < str2.length(); i++)
    {
        while (j > 0 && str2[j] != str2[i])
        {
            j = next[next[j-1]];
        }            
        if (str2[j] == str2[i])
        {
            j++;
        }            
        next[i] = j;        
    }

    int ptr2=0;
    int p=0;//
    for(auto c1:str1)
    {
        if(ptr2>0&&c1!=str2[ptr2])
        {
            ptr2=next[ptr2-1];
        }
        if(c1==str2[ptr2])
        {
            ptr2++;
        }
        if(ptr2==str2.length())
        {
            ptr2=0;
            ret++;
            pos.push_back(p-(str2.length()-1));//
        }
        p++;//         
    }
    //
    for(auto x:pos)
    cout<<x<<' ';
    cout<<endl;
    //
    return ret;
}

int main()
{    
    string str1 = "abababbbacbababaababa";
    string str2 = "ababa";
    cout<<kmp(str1,str2);
}