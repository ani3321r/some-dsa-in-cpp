#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int w, Item arr[], int n) {
    sort(arr, arr + n, cmp);
    int i = 0;
    int w_left = w;
    double ret = 0.0;
    while (i < n && w_left > 0) {
        if (arr[i].weight <= w_left) {
            ret += arr[i].value;
            w_left -= arr[i].weight;
        } else {
            ret += (double)arr[i].value * w_left / arr[i].weight;
            w_left = 0;
        }
        i++;
    }
    return ret;
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, weight;
    cin >> n >> weight;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    cout << fixed << setprecision(2) << fractionalKnapsack(weight, items.data(), n) << endl;
    return 0;
}