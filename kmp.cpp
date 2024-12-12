#include <string>
#include <iostream>
#include <vector>
using namespace std;
int kmp(const string str1,const string str2)
{
    if(str1.length()<str2.length())
    {
        return 0;
    }
    vector<int> next(str2.length()-1);
    
    next[0] = 0;
    for (int i = 1, j = 0; i < str2.length(); i++)
    {
        while (j > 0 && str2[j] != str2[i])
        {
            j = next[j - 1];
        }            
        if (str2[j] == str2[i])
            j++;
        next[i] = j;
    }


}

int main()
{    
    string str1 = "abcbdbbbacba";
    string str2 = "bacba";
    string str3 = "01234";
}