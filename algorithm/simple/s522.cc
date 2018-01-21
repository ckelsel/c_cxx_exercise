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
#include "s522.h"

#include <string>

namespace S522 {

/// ans [0] [1] [2]
///      1   10  100
void Answer(int n, Result &ans) {
    int carry = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            ans.push_back(1);
            continue;
        } else {
            for (int j = 0; j < ans.size(); j++) {
                int tmp = ans[j] * i + carry;
                if (tmp > 9) {
                    ans.resize(ans.size() + 1);
                }
                carry = tmp / 10;
                ans[j] = tmp % 10;
            }
        }
    }
}

std::string AnswerToString(Result &ans) {
    bool find = false;
    int size = ans.size();
    std::string result;
    for (int i = size - 1; i >= 0; i--) {
        if (ans[i] != 0) {
            find = true;
        }
        if (!find) {
            continue;
        }
        result += std::to_string(ans[i]);
    }
    return result;
}

}