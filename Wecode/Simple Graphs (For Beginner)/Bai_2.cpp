#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
class Graph
{
public:
    map<string, int> v_map;
    map<int, string> v_map_reverse;
    int v, e, n;
    vector<vector<int>> G;
    
    void nhap(int v, int e)
    {
        this->v = v;
        this->e = e;
        string v_temp;
        for (int i = 0; i < this->v; i++)
        {
            cin >> v_temp;
            v_map[v_temp] = i;
            v_map_reverse[i] = v_temp;
        }
        this->G = vector<vector<int>>(v, vector<int>(v, 0));
        string a, b;
        for (int i = 0; i < this->e; i++)
        {
            cin >> a >> b;
            this->G[v_map[a]][v_map[b]] = 1;
        }
    }
    
    void myProcess(int n) 
    {
        this->n = n;
        string A,B;
        int query_type;
        for(int i = 0; i < this->n; i++) 
        {
            cin >> query_type;
            if (query_type == 1) 
            {
                cin >> A >> B;
                if (G[v_map[A]][v_map[B]] == 1)
                    cout << "TRUE" << endl;
                else
                    cout << "FALSE" << endl;
            } 
            else if (query_type == 2) 
            {
                cin >> A;
                bool found = false;
                for (int j = 0; j < this->v; j++) 
                {
                    if (G[v_map[A]][j] == 1) 
                    {
                        cout << v_map_reverse[j] << " ";
                        found = true;
                    }
                }
                if (!found)
                    cout << "NONE";
                cout << endl;
            }
        }
    }
};
int main()
{
    Graph G;
    int v, e, n; cin >> v >> e >> n;
    G.nhap(v, e);
    G.myProcess(n);
    return 0;
}
