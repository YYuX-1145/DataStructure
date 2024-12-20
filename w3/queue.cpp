#include <iostream>
template<class T>
class Queue{
    private:
        T* tab;
        int front=0;
        int num=0;
        int sz;
    public:
        Queue(int size=5):tab(new T[size]),sz(size){}
        ~Queue() {delete[] tab;}
        int length(){return num;}
        bool in(T x){
            if (full())
            {
                throw ' ';
            }
            tab[(front+num)%sz]=x;
            num++;
            return true;
        }
        T out(){            
            T ret = tab[front];
            front=(front+1)%sz;
            return ret;
            num--;
            }
        bool empty(){return num==0;}
        bool full(){return num==sz;}
};

int main()
{
    using namespace std;
    Queue<int> q(4);
    q.in(1);
    q.in(2);
    q.in(3);
    cout<<q.out()<<endl<<q.out()<<endl<<q.out();
}