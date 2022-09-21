#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <string>
#include <numeric>
#include <functional>

using namespace std;

int kthSmallest(int arr[], int l, int r, int k) {

        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int> pq;

        for (int i = 0; i <= r; i++) {
                pq.push(arr[i]);
                if (pq.size() > k) {
                        pq.pop();
                }
        }
        return pq.top();
}

int main() {

        int arr[] = {7, 10, 4, 3, 20, 15};
        int n = sizeof(arr) / sizeof(arr[0]);

        cout << kthSmallest(arr, 0, n - 1, 3)<<endl;

        return 0;
}