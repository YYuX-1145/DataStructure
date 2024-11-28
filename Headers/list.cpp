#include <iostream>

template<class T>
class List
{
private:
    T* tab;
    int nb;
    int size;
    void expand(){
        T* old=tab;
        size*=2;
        tab=new T[size];
        for(int i=0;i<nb;i++)
            tab[i]=old[i];
        delete [] old;
    }
public:
    List(int sz=3):size(sz),tab(new T[size]),nb(0){}
    List(const List<T>& other)=delete ;
    List& operator=(const List<T>& other)=delete;
    virtual ~List(){delete[] tab;}
    int Size(){return nb;}
    void add(T x){
        if(nb==size)
        {
            expand();
        }
        tab[nb]=x;
        nb++;
    }
    List<T> &operator<<(T x)
    {
        this->add(x);
        return *this;
    }
    T& operator[](int x)
    {
        if(x>=nb)
            throw "Index out of range";
        return tab[x];
    }
    void insert(int idx,T value)//different from Linked_list,value will be at the given index.
    {
        if(idx>nb)
            throw "Index out of range";
        if(nb==size)
        {
            expand();
        }
        for(int i=nb-1;i>=idx;i--)
            tab[i+1]=tab[i];
        tab[idx]=value;
        nb++;
    }
    void pop(int idx)
    {
        if(idx>=nb)
            throw "Index out of range";
        for(int i=idx;i<nb-1;i++)
            tab[i]=tab[i+1];
        nb--;
    }
    int find(T tar)
    {
        for(int i=0;i<nb;i++)
        {
            if(tab[i]==tar)
                return i;
        }
        return -1;
    }
};

template <class T>
std::ostream &operator<<(std::ostream &os, List<T> &l)
{
    for (int i = 0; i < l.Size();i++)
        os << l[i];
    os << std::endl;
    return os;
}

using namespace std;
int main() {
    List<int> l;
    l << 1 << 2 << 3 << 4;
    cout << l;

    l.insert(4,7);
    cout << l;

    l.insert(0, 6);
    cout << l;

    l.pop(0);
    cout << l;

    cout<<l.find(7)<<endl;
    l.pop(l.find(7));
    cout << l;

    return 0;
}
