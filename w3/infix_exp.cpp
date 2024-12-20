#include <stack>
#include <map>
#include <iostream>

const std::map<char,int> isp = {{'(',1},{'*',5},{'/',5},{'+',3},{'-',3},{')',8}};
const std::map<char,int> icp = {{'(',8},{'*',4},{'/',4},{'+',2},{'-',2},{')',1}};

class Calc{
    std::stack<char> c;
    std::stack<float> n;
    float calc(float x1,float x2,char c){
        switch (c)
        {
        case '*':
            return x1*x2;
        case '/':
            return x1/x2;
        case '+':
            return x1+x2;
        case '-':
            return x1-x2;
        default:
            throw ' ';
        }
    }
    public:
        void add(char x)
        {
            if(c.empty()||icp.at(x)>isp.at(c.top()))
            {
                c.push(x);
            }
            else{
                while(!c.empty()&&icp.at(x)<=isp.at(c.top())&&c.top()!='('&&c.top()!=')')
                {
                    float x1=n.top();
                    n.pop();
                    float x2=n.top();
                    n.pop();
                    char ca=c.top();
                    c.pop();
                    n.push(calc(x2,x1,ca));
                }
                if(!c.empty()&&c.top()=='('&&x==')')
                {
                    c.pop();
                }
                if(x!=')')
                {
                    c.push(x);
                }
            }
        }
        void add(int x)
        {
            n.push(x);
        }
        void calc()
        {
            while(!c.empty())
                {
                    float x1=n.top();
                    n.pop();
                    float x2=n.top();
                    n.pop();
                    char ca=c.top();
                    c.pop();
                    n.push(calc(x2,x1,ca));
                }
            std::cout<<n.top();
            if(n.size()>1)
                throw ' ';
        }
};
//1+2*(3*5)-3 =14
int main()
{
Calc x;
x.add(1);
x.add('+');
x.add(2);
x.add('*');
x.add('(');
x.add(3);
x.add('+');
x.add(5);
x.add(')');
x.add('-');
x.add(3);
x.calc();
}