#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
    int n = details.size();
    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;
    for(int i=0; i<n; i++){
        for(int j=1; j<details[i].size(); j++){
            string mail = details[i][j];
            if(mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            }
            else{
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }
    vector<string> mergeMail[n];
    for(auto it : mapMailNode){
        string mail = it.first;
        int node = ds.findUPar(it.second);
        mergedMail[node].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i=0; i<n; i++){
        if(mergedMail[i].size() == 0) continue;
        sort(mergedMail[i].begin(), mergedMail[i].end());
        vector<string> temp;
        temp.push_back(details[i][0]);
        for(auto it : mergedMail[i]){
            temp.push_back(it);
        }
        ans.push_back(temp);
    }
    return ans;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    
    string input;
    cout << "Enter the accounts in the format: [[\"Name\",\"email1@example.com\",\"email2@example.com\"], ...]\n";
    getline(cin, input);

    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    input = input.substr(1, input.length() - 2);

    vector<vector<string>> accounts;
    size_t pos = 0;
    while (pos < input.length()) {
        vector<string> account;
        size_t end = input.find(']', pos);
        string accountStr = input.substr(pos + 1, end - pos - 1);
        
        size_t commaPos = 0;
        while (commaPos < accountStr.length()) {
            size_t nextComma = accountStr.find(',', commaPos);
            if (nextComma == string::npos) nextComma = accountStr.length();
            string item = accountStr.substr(commaPos, nextComma - commaPos);
            item = item.substr(1, item.length() - 2);
            account.push_back(item);
            commaPos = nextComma + 1;
        }
        
        accounts.push_back(account);
        pos = end + 2;
    }

    vector<vector<string>> mergedAccounts = mergeDetails(accounts);
    
    cout << "\nMerged Accounts:\n";
    for (const auto& account : mergedAccounts) {
        cout << "[";
        for (size_t i = 0; i < account.size(); ++i) {
            cout << "\"" << account[i] << "\"";
            if (i < account.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    
    return 0;
}