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
#include "s513.h"
#include <string>

/// keyword : %
/// abcabcabc
/// data[3 % 3] = data[0];
/// data[4 % 3] = data[1];
/// data[5 % 3] = data[2];
/// data[6 % 3] = data[0];
int GetMinCycle(const char *data) {
    int len = strlen(data);

    for (int i = 1; i < len; i++) {
        // it's a cycle string, so `len % cycle == 0`
        if (len % i == 0) {
            int ok = 1;
            for (int j = i; j < len; j++) {
                // data[j % i]
                if (data[j] != data[j % i]) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                return i;
            }
        }
    }

    return 0;
}