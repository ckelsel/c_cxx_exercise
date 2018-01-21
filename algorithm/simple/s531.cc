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
#include "s531.h"
#include <map>
#include <algorithm>

namespace S531 {
// 4 2 3
// 2 4 3
// 2 3 4
// the biggest one to the end
void SmallBubbleSort(int *value, int length) {
    // 跟SmallBubbleSort_3相比，
    // i < length, i_max = length - 1
    // j < length - i - 1 = length - (length - 1) - 1 = 0
    // 导致j未无效循环
    // 解决上述问题
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (value[j] > value[j+1]) {
                int tmp = value[j+1];
                value[j+1] = value[j];
                value[j] = tmp;
            }
        }
    }
}

void SmallBubbleSort_3(int *value, int length) {
    for (int i = 0; i < length; i++) {
        // 跟SmallBubbleSort_2相比，
        // length - i - 1, 已经排序过的不再排序
        for (int j = 0; j < length - i - 1; j++) {
            if (value[j] > value[j+1]) {
                int tmp = value[j+1];
                value[j+1] = value[j];
                value[j] = tmp;
            }
        }
    }
}

void SmallBubbleSort_2(int *value, int length) {
    // 循环length次
    for (int i = 0; i < length; i++) {
        // 每次从第一个开始，排序length-1次。
        // 缺点，因为最后面已经排序过，但是每次循环又排序了一遍
        for (int j = 0; j < length - 1; j++) {
            if (value[j] > value[j+1]) {
                int tmp = value[j+1];
                value[j+1] = value[j];
                value[j] = tmp;
            }
        }
    }
}


void BigBubbleSort(int *value, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (value[j] < value[j+1]) {
                int tmp = value[j];
                value[j] = value[j+1];
                value[j+1] = tmp;
            }
        }
    }
}


struct Cmp {
    bool operator()(const Result &m, const Result &n) const {
        if (m.size() == n.size()) {
            for (unsigned int i = 0; i < m.size(); i++) {
                if (m[i] != n[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};

int ToInt(Result value) {
    int rv = 0;
    int size = value.size();
    for (int i = 0; i < size; ++i) {
        rv += value[i] * pow(10, size - i - 1);
    }
    return rv;
}

Result ToResult(int value) {
    Result rv;
    do {
        int remain = value % 10;
        value /= 10;

        rv.push_back(remain);
    } while (value != 0);
    std::reverse(rv.begin(), rv.end());

    return rv;
}

int flag[9999] = {0};
void Answer(Result &in, Result &result) {
    result.push_back(ToInt(in));
    flag[ToInt(in)] = true;

    Result max = in;
    Result min = in;
    for(;;) {
        SmallBubbleSort(&min[0], min.size());
        BigBubbleSort(&max[0], max.size());

        Result out = [max, min]() -> Result {
            return ToResult(ToInt(max) - ToInt(min));
        }();

        int outvalue = ToInt(out);
        result.push_back(outvalue);
        if (flag[outvalue]) {
            break;
        }

        flag[outvalue] = true;
        max = out;
        min = out;
    }
}

}