 /*
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cassert>
#include "poj1163.h"
#include "utils/utils.h"

#if 0
5
7
3   8
8   1   0
2   7   4   4
4   5   2   6   5

在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径。 
三角形的行数大于1小于等于100，数字为 0 - 99
#endif

#define LINE 101
int data[LINE][LINE];
int n;
int maxsum[LINE][LINE];

int MaxSum(int i, int j) {
    if (i == n) {
        return data[i][j];
    } else {
        return std::max(MaxSum(i + 1, j), MaxSum(i + 1, j + 1)) + data[i][j];
    }
}

int MaxSum_2(int i, int j) {
    if (maxsum[i][j] != -1) {
        return maxsum[i][j];
    }

    if (i == n) {
        maxsum[i][j] = data[i][j];
    } else {
        maxsum[i][j] = std::max(MaxSum_2(i + 1, j), MaxSum_2(i + 1, j + 1)) + data[i][j];
    }

    return maxsum[i][j];
}

int MaxSum_3(int i, int j) {
    int sum[LINE][LINE];
    memset(sum, -1, sizeof(sum));

    // last line
    for (int i = 0; i <= n; i++) {
        sum[n][i] = data[n][i];
    }

    // from second last
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            sum[i][j] = std::max(sum[i+1][j], sum[i+1][j+1]) + data[i][j];
        }
    }

    return sum[i][j];
}


void ReadData(const char *filename) {
    std::ifstream file;

    file.open(GetFileOfCurrentDir(filename));
    assert(file.is_open());
    if (file) {
        file >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                file >> data[i][j];
                maxsum[i][j] = -1;
            }
        }
        file.close();
    }
}
