#include <iostream>
using namespace std;
template<class T>
class BinaryTree{
    private:        
        struct Node{
            Node* parent;
            Node* LN=nullptr;
            Node* RN=nullptr;
            T data;
            Node(Node *p, T d) : data(d), parent(p) {}
        };
        Node* rootptr;
    public:
        class Iterator{
            private:
                Node *ptr;
            public:
                friend class BinaryTree;
                Iterator(Node* p):ptr(p){}
                int parent()
                {
                    if(ptr->parent==nullptr)
                        return 1;
                    ptr = ptr->parent;
                    return 0;
                }
                int left()
                {
                    if (ptr->LN == nullptr)
                        return 1;
                    ptr = ptr->LN;
                    return 0;
                }
                int right()
                {
                    if (ptr->RN == nullptr)
                        return 1;
                    ptr = ptr->RN;
                    return 0;
                }
                int insert(int dir,T data)
                {
                    if(dir==1)
                    {
                        if (ptr->LN!=nullptr)
                            return 1;
                        ptr->LN = new Node(ptr,data);
                    }
                    if (dir == 2)
                    {
                        if (ptr->RN != nullptr)
                            return 1;
                        ptr->RN = new Node(ptr,data);
                    }
                    return 0;
                }
                T &operator*() { return ptr->data; }
        };
        void free(BinaryTree<T>::Iterator &x)
        {
            auto it = x;
            auto it2 = x;
            if (!it.left())
            {
                free(it);
            }
            if (!it2.right())
            {
                free(it2);
            }
            delete x.ptr;
        }
    public:
        BinaryTree(T data):rootptr(new Node(nullptr,data)){}
        ~BinaryTree()
        {
            auto i = this->root();
            free(i);
        }
        Iterator root(){return Iterator(rootptr);}

};

template <class T>
void PreOrderTraverse(T &x)
{
    auto it = x;
    auto it2 = x;
    cout << *x << ' ';
    if (!it.left())
    {
        PreOrderTraverse(it);
    }
    if (!it2.right())
    {
        PreOrderTraverse(it2);
    }
}

template <class T>
void InOrderTraverse(T& x)
{

    auto it = x;
    auto it2 = x;
    if (!it.left())
    {
        InOrderTraverse(it);
    }
    cout << *x << ' ';
    if (!it2.right())
    {
        InOrderTraverse(it2);
    }
}

template <class T>
void PostOrderTraverse(T &x)
{

    auto it = x;
    auto it2 = x;
    if (!it.left())
    {
        PostOrderTraverse(it);
    }    
    if (!it2.right())
    {
        PostOrderTraverse(it2);
    }
    cout << *x << ' ';
}
int main()
{
    BinaryTree<int> x(0);
    auto it = x.root();
    it.insert(1,1);
    it.insert(2,2);
    it.left();
    it.insert(1, 3);
    it.insert(2, 4);
    it.parent();
    it.right();
    it.insert(1, 5);
    it.insert(2, 6);
    it = x.root();
    PreOrderTraverse(it);
    cout << endl;
    InOrderTraverse(it);
    cout << endl;
    PostOrderTraverse(it);
}