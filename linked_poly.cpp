#include "linkedlist.h"
using namespace std;    
struct elem
    {
        float coefficient;
        int pow;
        elem(float c,int p):coefficient(c),pow(p){}
    };

std::ostream& operator<<(std::ostream&os,const elem& l)
{
    os <<l.coefficient << "x^" << l.pow;
    return os;
}

class Polynomial{
    private:
    Linkedlist<elem> l;
    public:
    void add(float c,int p){
        auto it=l.begin();
        while (it != l.end() && (*it).pow > p)
        {
            ++it;
        }
        if (it == l.end())
            l.push_back(elem(c, p));
        else if ((*it).pow == p)
            (*it).coefficient += c;
        else
            l.insert_at(it, elem(c, p));
    }
    void show() 
    {
        auto it = l.begin();
        for (int i = 0; i < l.size()-1;i++)
        {
            cout << *it << '+';
            ++it;
        }            
        cout << *it;
    }
};

int main()
{
    // LINKED_LIST_TEST::mian();
    Polynomial p;
    p.add(1, 2);
    p.add(1, 2);
    p.add(1, 3);
    p.show();
}