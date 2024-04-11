#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Graph {
public:
    vector<string> names;
    map<string, map<string, int>> adjlist;

    void inputGraph(int e) {
        string u, i;
        int x;
        for (int k = 0; k < e; k++) {
            cin >> u >> i >> x;
            adjlist[u][i] = x;
        }
    }

    void process(int n) 
    {
        string chuoi;
        getline(cin, chuoi); 
        for (int i = 0; i < n; i++)
        {
            getline(cin, chuoi);
            stringstream ss(chuoi);
            string token;
            vector<string> ket_qua;

            while (ss >> token) {
                if (token != ".") {
                    ket_qua.push_back(token);
                }
            }
            int len = ket_qua.size();
            int tong = 0;
            for (int j = 0; j < len - 1; j++) {
                int s = adjlist[ket_qua[j]][ket_qua[j + 1]];
                if (s == 0) 
                {
                    tong = 0;
                    break;
                }
                else {
                    tong += s;
                }
            }

            if (tong!=0) 
            {
                cout << tong << endl;
            }
            else {
                cout << "FALSE" << endl;
            }
        }
    }
};

int main() {
    Graph G;
    int e, n;
    cin >> e >> n;
    G.inputGraph(e);
    G.process(n);
    return 0;
}
