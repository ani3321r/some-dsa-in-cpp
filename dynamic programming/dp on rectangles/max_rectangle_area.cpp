#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    stack<int> st;
    vector<int> leftSmall(n), rightSmall(n);
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
    if(st.empty()) leftSmall[i] = 0;
    else leftSmall[i] = st.top()+1;
    st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
        if(st.empty()) rightSmall[i] = n-1;
        else rightSmall[i] = st.top() - 1;
        st.push(i);
    }
    int maxA = 0;
    for(int i=0; i<n; i++){
        maxA = max(maxA, heights[i] * (rightSmall[i] - leftSmall[i] + 1));
    }    
    return maxA;
}

int minArea(vector<vector<int>> &mat, int n, int m){
    int maxArea = 0;
    vector<int> height(m, 0);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int result = minArea(mat, n, m);
    cout << "The largest rectangle area is: " << result << endl;

    return 0;
}