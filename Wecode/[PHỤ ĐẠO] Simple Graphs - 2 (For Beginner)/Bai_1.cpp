#include <iostream>
#include <map>
#include <set>
#include<vector>
using namespace std;
class Graph
{
public:
    vector<string> names;
    map <string, set<string>> adjlist;

    void inputGraph(int e)
    {
        string x, y;
        for (int i = 0; i < e; i++) // nhap e canh 
        {
            cin>> x >> y;
            adjlist[x].insert(y);
        }
    }
    void process(int n)
    {
        vector<vector<string>> arr_queries(n, vector<string>(3, "0"));

        for (int i = 0; i < n; i++) {
            cin >> arr_queries[i][0];
            if (arr_queries[i][0] == "1") {
                cin >> arr_queries[i][1] >> arr_queries[i][2];
            }
            else if (arr_queries[i][0] == "2") {
                cin >> arr_queries[i][1];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr_queries[i][0] == "1")
            {
                set<string> s = adjlist[arr_queries[i][1]];
                if (s.find(arr_queries[i][2]) != s.end())
                {
                    cout << "TRUE" << endl;
                }
                else
                {
                    cout << "FALSE" << endl;
                }
            }
            else if (arr_queries[i][0] == "2")
            {
     
                set<string> s1 = adjlist[arr_queries[i][1]];
                cout << s1.size() << endl;
            }
        }
    }

};

int main()
{
    Graph G;
    int e, n;
    cin >> e >> n;
    G.inputGraph(e);
    G.process(n);
    return 0;
}