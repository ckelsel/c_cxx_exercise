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
#include <algorithm>
#include "poj1163.h"

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

int MaxSum(int r, int j) {
    if (r == n) {
        return data[r][j];
    } else {
        return std::max(MaxSum(r + 1, j), MaxSum(r + 1, j + 1)) + data[r][j];
    }
}

void ReadData(const char *filename) {
    std::ifstream file;

    file.open(filename);
    if (file) {
        file >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                file >> data[i][j];
            }
        }
        file.close();
    }
}
