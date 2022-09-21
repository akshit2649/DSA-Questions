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
#include <map>
#include <iterator>

using namespace std;

bool subArrayExists(int arr[], int n) {
    unordered_map<int, int> m;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (m.find(sum) != m.end() || sum==0) return true;
        else m[sum]++;
    }

    return false;
}

int main() {

    int n = 5;
    int arr[] = {4, 2, 0, 1};

    cout << subArrayExists(arr, n) << endl;
    return 0;
}