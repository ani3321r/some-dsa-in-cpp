#include<bits/stdc++.h>
using namespace std;

class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;
    
    public:
        LFUCache(int capacity){
            this->capacity = capacity;
            minFreq = 0;
        }

        int get(int key) {
            if (keyVal.find(key) == keyVal.end()) {
                return -1; 
            }
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();

            if (freqList[minFreq].empty()) {
                minFreq++;
            }
            return keyVal[key].first;
        }

        void put(int key, int value) {
        if(!capacity) return;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty()) minFreq++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }    
};
int main(){
    LFUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;
    cache.put(3, 3);
    cout << cache.get(2) << endl;
    cout << cache.get(3) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}