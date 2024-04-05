#include<iostream>
#include<vector>
using namespace std;
void inputGraph(vector<vector<int>>& G, int v, int e) {
    G = vector<vector<int>>(v, vector<int>(v, 0));
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        G[a - 1][b - 1] = 1;
    }
}

void process(const vector<vector<int>>& G, int v, int n) {
    vector<vector<int>> arr_queries(n, vector<int>(3, 0));

    for (int i = 0; i < n; i++) {
        cin >> arr_queries[i][0];
        if (arr_queries[i][0] == 1) {
            cin >> arr_queries[i][1] >> arr_queries[i][2];
        } else if (arr_queries[i][0] == 2) {
            cin >> arr_queries[i][1];
        }
    }
    for (int i = 0; i < n; i++) {
        int count = 0;
        if (arr_queries[i][0] == 1) {
            if (G[arr_queries[i][1] - 1][arr_queries[i][2] - 1] == 1)
                cout << "TRUE" << endl;
            else
                cout << "FALSE" << endl;
        } else if (arr_queries[i][0] == 2) {
            for (int j = 0; j < v; j++) {
                if (G[arr_queries[i][1] - 1][j] == 1) {
                    cout << j + 1 << " ";
                    count++;
                }
            }
            if (count == 0)
                cout << "NONE";
            cout << endl;
        }
    }
}
int main()
{

	int v, e, n;
	cin >> v >> e >> n; 
	vector<vector<int> > G;

	inputGraph(G,v,e);
    process(G,v,n);

	return 0;
}
