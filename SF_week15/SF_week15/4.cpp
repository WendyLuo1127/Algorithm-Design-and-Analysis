#include<iostream>
#include<vector>
#include<string>
using namespace std;

int flag[100] = { 0 };//color(0:unvisited,1:group1,2:group2)


bool binary(const vector<vector<int>>& graph,int cur=0) {
    for (int neighbor : graph[cur]) {
        if (flag[neighbor] == 0) {//unvisited
            flag[neighbor] = 3 - flag[cur];
            if (!binary(graph, neighbor))return false;
        }
        else if (flag[neighbor] == flag[cur])return false;// have same color,not binary graph
    }
    return true;
}

int main() {
	string line;
	getline(cin, line);
	vector<vector<int>>graph;
	vector<int>temp;
    int num = 0;
    bool in_number = false;

    for (char ch : line) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
            in_number = true;
        }
        else {
            if (in_number) {
                temp.push_back(num);
                num = 0;
                in_number = false;
            }
            if (ch == ']') {
                graph.push_back(temp);
                temp.clear();
            }
        }
    }
    bool isBipartite = true;
    for (int i = 0; i < graph.size(); ++i) {
        if (flag[i] == 0) {  // 可能图不连通
            flag[i] = 1;
            if (!binary(graph, i)) {
                isBipartite = false;
                break;
            }
        }
    }

    cout << (isBipartite ? "true" : "false") << endl;
    return 0;
}