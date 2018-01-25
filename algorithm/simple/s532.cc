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
#include "s532.h"
#include "utils/utils.h"
#include <map>
#include <algorithm>
#include <vector>
#include <assert.h>
#include <string>

namespace S532 {

std::vector<std::string> data;

std::vector<std::string> data_test;


void ReadData(const char *file) {
    data.clear();

    std::string filepath = GetFileOfCurrentDir(file);
    FILE *fp = fopen(filepath.c_str(), "rb");
    if (fp) {
        char buf[100];
        do {
            fscanf(fp, "%s", buf);
            if (std::string(buf) == "******") {
                break;
            }
            data.push_back(buf);
        } while ( true );

        do {
            fscanf(fp, "%s", buf);
            data_test.push_back(buf);
            if (feof(fp)) {
                break;
            }
        } while ( true );

        fclose(fp);
    }
}

void Answer(const char *file) {
    std::string filepath = GetFileOfCurrentDir(file);
    FILE *fp = fopen(filepath.c_str(), "wb");
    if (!fp) {
        assert(false);
        return;
    }

    std::multimap<std::string, std::string> dict;
    for (std::string s : data) {
        std::string key(s);
        std::sort(key.begin(), key.end());
        dict.emplace(key, s);
    }

    typedef std::multimap<std::string, std::string>::iterator DictIter;
    std::pair<DictIter, DictIter> result;

    for (std::string s : data_test) {
        std::sort(s.begin(), s.end());
        result = dict.equal_range(s);
        std::string value;
        for (DictIter it = result.first; it != result.second; it++) {
            if (!value.empty()) {
                value += " ";
            }
            value += it->second;
        }
        fprintf(fp, "%s\n", value.c_str());
    }
    fclose(fp);
}

}