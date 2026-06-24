#include <vector>

using namespace std;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        long long MOD = 1e9 + 7;
        int m = r - l + 1;
        int size = 2 * m;

        vector<vector<long long>> T(size, vector<long long>(size, 0));
        for (int x = 0; x < m; ++x) {

            for (int y = 0; y < x; ++y) {
                T[m + y][x] = 1;
            }

            for (int y = x + 1; y < m; ++y) {
                T[y][m + x] = 1;
            }
        }

        vector<vector<long long>> res(size, vector<long long>(size, 0));
        for (int i = 0; i < size; ++i) res[i][i] = 1;

        long long p = n - 1;
        while (p > 0) {
            if (p & 1) {
                vector<vector<long long>> next_res(size, vector<long long>(size, 0));
                for (int i = 0; i < size; ++i) {
                    for (int k = 0; k < size; ++k) {
                        if (res[i][k] == 0) continue;
                        for (int j = 0; j < size; ++j) {
                            next_res[i][j] = (next_res[i][j] + res[i][k] * T[k][j]) % MOD;
                        }
                    }
                }
                res = next_res;
            }
            
            vector<vector<long long>> next_T(size, vector<long long>(size, 0));
            for (int i = 0; i < size; ++i) {
                for (int k = 0; k < size; ++k) {
                    if (T[i][k] == 0) continue;
                    for (int j = 0; j < size; ++j) {
                        next_T[i][j] = (next_T[i][j] + T[i][k] * T[k][j]) % MOD;
                    }
                }
            }
            T = next_T;
            p >>= 1;
        }

        long long total_valid_arrays = 0;
        for (int start_val = 0; start_val < m; ++start_val) {
            for (int final_state = 0; final_state < size; ++final_state) {
                total_valid_arrays = (total_valid_arrays + res[final_state][start_val]) % MOD;
                total_valid_arrays = (total_valid_arrays + res[final_state][m + start_val]) % MOD;
            }
        }

        return total_valid_arrays;
    }
};