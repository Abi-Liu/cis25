#include <limits.h>
#include <iostream>
using namespace std;

int* highestTempArr(int* arr, int n, int k) {
    int* res = new int[n-k+1];
    for(int i = 0; i <= n - k; i++) {
        int max = numeric_limits<int>::min();
        for(int j = i; j < i + k; j++) {
          if(arr[j] > max) {
            max = arr[j];
          }
        }
        res[i] = max;
    }
    return res;
}

void highestTemp(int* arr, vector<int>& res, int n, int k) {
    for(int i = 0; i <= n - k; i++) {
        int max = numeric_limits<int>::min();
        for(int j = i; j < i + k; j++) {
            if(arr[j] > max) {
                max = arr[j];
            }
        }
        res.push_back(max);
    }
}

int main() {
    int* arr = new int[8];
    arr[0] = 20;
    arr[1] = 25;
    arr[2] = 15;
    arr[3] = 10;
    arr[4] = 30;
    arr[5] = 27;
    arr[6] = 35;
    arr[7] = 40;
    int* res = highestTempArr(arr, 8, 3);
    for(int i = 0; i < 6; i++) {
      cout << res[i] << " ";
    }
    cout << endl;

    vector<int> resVec;
    highestTemp(arr, resVec, 8, 3);
    for (int i = 0; i < resVec.size(); i++) {
        cout << resVec[i] << " ";
    }
    cout << endl;

    // free memory
    delete[] arr;
    delete[] res;
}