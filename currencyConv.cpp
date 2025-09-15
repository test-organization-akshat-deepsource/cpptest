#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getLeastExchangeCurrencyValue(vector<vector<int>>& graph, int source, int target, int n){
    queue<vector<int>> q;
    q.push({source, 0});

    // find using bfs to find shortest path
    vector<int> v(n, INT_MAX);
    vector<bool> visited(n, false);
    while(!q.empty()){
        auto top = q.front();
        auto node = top[0];
        auto cost = top[1];
        q.pop();

        if(visited[node]) continue;
        visited[node] = true;

        for(int i = 0; i < graph[node].size(); i++){
            int newCost = cost + graph[node][i];
            v[i] = min(newCost, v[i]);
            q.push({i, v[i]});
        }
    }

    return v[target];;
}




int main(){
    cout << "Enter currency exchange values: " << endl;

    vector<string> source;
    vector<string> end;
    vector<int> value;

    while(true){
        cout << "Enter source currency: ";
        string j;
        cin >> j;
        cout << "Enter target currency: ";
        string t;
        cin >> t;
        cout << "Enter value: ";
        int k;
        cin >> k;

        source.push_back(j);
        target.push_back(t);
        value.push_back(k);

        cout << "Continue?(Y/N): ";
        string c;
        cin >> c;

        if(c == "N") break;
    }

    unordered_map<string, int> keys;
    vector<vector<int>> vc;

    int label = 0;
    for(int i = 0; i < source.size(); i++){
        if(keys.find(source[i]) == keys.end()){
            keys[source[i]] = label++;
        }
        if(keys.find(target[i]) == keys.end()){
            keys[target[i]] = label++;
        }
        vc[keys[source[i]]][keys[target[i]]] = value[i];
    }


    string source;
    cout << "Enter source: ";
    cin >> source;
    string target;
    cout << "Enter target: ";
    cin >> target;

    return getLeastExchangeCurrencyValue(vc, keys[source], keys[target]);
}
