#include "circularlinkedlist.h"
using namespace std;    
struct elem
    {
        float coefficient;
        int pow;
        elem(){}
        elem(float c,int p):coefficient(c),pow(p){}
    };

std::ostream& operator<<(std::ostream&os,const elem& l)
{
    os <<l.coefficient << "x^" << l.pow;
    return os;
}

float Power(float x,int i)
{
    float mul=x;
    for(int j=1;j<i;j++)
    {
        mul*=x;
    }
    return mul;
}

class Polynomial{
    private:
    CircularLinkedlist<elem> l;
    public:
    void add(float c,int p){
        if(c==0)
            return;
        auto it=l.begin();
        while (it != l.end() && (*it).pow > p)
        {
            ++it;
        }
        if (it == l.end())
        {
            l.push_back(elem(c, p));
        }            
        else if ((*it).pow == p)
        {
            (*it).coefficient += c;
            if((*it).coefficient==0)
            {
                l.erase(it);
            }
        }            
        else
            l.insert_at(it, elem(c, p));
    }
    auto begin(){return l.begin();}
    auto end(){return l.end();}
    Polynomial operator+(const Polynomial& other){
        Polynomial ret=*this;
        for(auto& i:other.l)
            ret.add(i.coefficient,i.pow);
        return ret;
    }
    void show() 
    {
        auto it = l.begin();
        for (int i = 0; i < l.size()-1;i++)
        {
            cout << *it << '+';
            ++it;
        }            
        cout << *it<<endl;
    }
    float calc(float x)
    {
        float ret=0;
        for(auto&i:l)
        {
            ret+=i.coefficient*(Power(x,i.pow));
        }
        return ret;
    }
};

int main()
{
    CIRCULAR_LINKED_LIST_TEST::mian();
    Polynomial p,p2;
    p.add(1, 2);
    p.add(1, 2);
    p.add(1, 3);
    p.show();
    p2.add(5,5);
    p2.add(1,2);
    p2.add(-1,3);
    p2.show();
    p=p+p2;
    p.show();
    cout<<endl<<p.calc(2);
}