#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>

template<class T>
struct Node{
    T data;
    Node<T>* next;
    Node(T x,Node<T>* p):data(x),next(p){}
};

template<class T>
class Linkedlist{
private:
    Node<T>* head= nullptr;
    Node<T>* endp= nullptr;
    int nb=0;
public:
    class Iterator{
    private:
        Node<T>* pre;
        Node<T>* ptr;
    public:
        friend class Linkedlist;
        Iterator(Node<T> *p, Node<T> *pre=nullptr) : ptr(p), pre(pre) {}
        Iterator& operator++(){
            pre=ptr;
            ptr=ptr->next;
            return *this;
        }
        bool operator!=(const Iterator& other)
        {
            return ptr!=other.ptr;
        }
        T& operator*(){return ptr->data;}
    };
    class Const_Iterator
    {
    private:
        Node<T> *pre;
        Node<T> *ptr;
    public:
        Const_Iterator(Node<T> *p, Node<T> *pre=nullptr) : ptr(p), pre(pre) {}
        Const_Iterator &operator++()
        {
            pre = ptr;
            ptr = ptr->next;
            return *this;
        }
        bool operator!=(const Const_Iterator &other)
        {
            return ptr != other.ptr;
        }
        T &operator*() { return ptr->data; }
    };
    Linkedlist(){}
    Linkedlist(const Linkedlist<T>& other)
    {
        for(auto& i:other)
        {
            this->push_back(i);
        }
    }
    Linkedlist& operator=(const Linkedlist<T>& other)
    {
        this->clear();
        for (auto &i : other)
        {
            this->push_back(i);
        }
        return *this;
    }
    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }
    Const_Iterator begin() const {return Const_Iterator(head);}
    Const_Iterator end() const { return Const_Iterator(nullptr); }
    Iterator push_back(T x)
    {
        nb++;
        if(endp== nullptr)
        {
            head=new Node<T>(x, nullptr);
            endp=head;
            return Iterator(head, nullptr);
        }
        else
        {
            endp->next=new Node<T>(x, nullptr);
            Iterator i(endp->next, endp);
            endp=endp->next;
            return i;
        }
        }
    Linkedlist<T>& operator<<(T x)
    {
        this->push_back(x);
        return *this;
    }
    Iterator index(int ind)//return end() if index out of range
    {
        Iterator it=begin();
        for(int i=0;it!=this->end()&&i<ind;i++)
        {
            ++it;
        }
        return it;
    }
    Const_Iterator index(int ind) const // return end() if index out of range
    {
        Const_Iterator it = begin();
        for (int i = 0; it != this->end() && i < ind; i++)
        {
            ++it;
        }
        return it;
    }
    T& operator[](int idx){
        if (idx>=nb)
            throw "index out of range";
        return *index(idx);
    }
    const T& operator[](int idx) const
    {
        if (idx >= nb)
            throw "index out of range";
        return *index(idx);
    }
    Iterator insert(const Iterator i, T x) // insert data to the position behind the given iterator/index, different from list.
    {
        Node<T>* nextptr=i.ptr->next;        
        i.ptr->next = new Node<T>(x, nextptr);
        return Iterator(i.ptr->next, i.ptr);
    }
    Iterator insert(int i, T x) // to push_back data to the head,make first argument <=-1.
    {
        if(i>=nb)
            throw "index out of range";
        nb++;
        if(i>-1)
            return insert(index(i),x);
        else{
            Node<T>* nextptr=head;
            head=new Node<T>(x,nextptr);
            return Iterator(head);
        }
        }
    Iterator find(T tar)
    {
        Iterator it=this->begin();
        while (it!=this->end())
        {
            if(*it==tar)
                return it;
            ++it;
        }
        return it;
    }
    Const_Iterator find(T tar) const
    {
        Iterator it = this->begin();
        while (it != this->end())
        {
            if (*it == tar)
                return it;
            ++it;
        }
        return it;
    }
    void erase(Iterator& it)
    {
        if(it!=this->end())
        {
            if(it!=this->begin())
            {
                it.pre->next=it.ptr->next;
                delete it.ptr;
                it=this->end();
            }
            else
            {
                Node<T> *old = head;
                head = head->next;
                delete old;
                it = this->begin();
            }
            nb--;
        }
        else
        {
            std::cout<<"invalid";
        }
    }
    int size() { return nb; }
    void clear(){
        if(nb==0)
            return;
        Node<T>* nextptr=head->next;
        Node<T>* ptr=head;
        while (nextptr->next!= nullptr)
        {
            delete ptr;
            ptr=nextptr;
            nextptr=nextptr->next;}
        delete nextptr;
        head=nullptr;
        endp=nullptr;
        nb = 0;
    }
    virtual ~Linkedlist(){
        this->clear();
    }
};

template<class T>
std::ostream& operator<<(std::ostream&os,Linkedlist<T>& l)
{
    for(auto i:l)
        os<<i;
    os<<std::endl;
    return os;
}

namespace LINKED_LIST_TEST
{
int mian() {
    Linkedlist<int> l2;
    {
        Linkedlist<int> *L = new Linkedlist<int>;
        Linkedlist<int> &l = *L;
        Linkedlist<int> X;
        l << 1 << 2 << 3 << 4;
        std::cout << l;

        l.insert(3, 5);
        std::cout << l;

        l.insert(-1, 9);
        l[1] = 8;
        std::cout << l;

        auto it = l.find(9);
        l.erase(it);
        std::cout << l;

        l2 = l;
    }

    std::cout << l2;

    try{
        std::cout<<l2[5];
    }
    catch(const char* err)
    {
        std::cout << err;
    }
    return 0;
}
}
#endif

