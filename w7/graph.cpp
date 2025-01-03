#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Graph{
    private:
    string name;
    vector<vector<int>> matrix;
    public:
    const string& getname() const {return name;}
    Graph(string n,int x):name(n)
    {
        matrix.resize(x,vector<int>(x,0));
        // for(int i=1;i<=x;i++)
        //     matrix[i][i]=1;
    }
    void addEdge(int a,int b){
        if(a>=matrix.size()||b>=matrix.size())
        {
            throw runtime_error("err");
        }           
        matrix[a][b]=1;
        matrix[b][a]=1;
        }
    friend ostream& operator<<(ostream& os,Graph& g);
};

ostream& operator<<(ostream& os,Graph& g)
{
    os<<g.getname()<<endl;
    for(int x=0;x<g.matrix.size();x++)
        os<<x<<' ';
    os<<endl<<endl;
    for(auto& i:g.matrix)
    {
        for(auto j:i)
        {
            os<<j<<' ';
        }
        os<<endl;
    }
    return os;
}

int main() {

    try
    {
        Graph G1("G1",6);
        //cout<<G1;
        G1.addEdge(0,1);
        G1.addEdge(0,3);
        G1.addEdge(1,3);
        G1.addEdge(2,3);
        G1.addEdge(1,4);
        G1.addEdge(3,5);
        G1.addEdge(3,4);
        G1.addEdge(2,5);
        G1.addEdge(4,5);
        cout<<G1;
    }
    catch(exception& e)
    {
        std::cout<<e.what()<<"\n";
    }

    return 0;
}
