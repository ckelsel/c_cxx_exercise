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

#ifndef __ITEM_5_2_5_H__
#define __ITEM_5_2_5_H__
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <functional>

inline void sink(std::unique_ptr<std::string, std::function<void(std::string *p)>> ref) {

}

inline std::unique_ptr<std::string, std::function<void(std::string *p)>> source(int &val) {
    std::unique_ptr<std::string, std::function<void(std::string *p)>> ref(new std::string("source"),
        [&val](std::string *p) {
            std::cout << "delete " << *p << std::endl;
            val = 2;
        });
    return ref;
}


class Member {
public:
    Member() : val_(new int) {
    }

private:
    Member(const Member &);
    void operator=(const Member &);

    std::unique_ptr<int> val_;
};

#endif // __ITEM_5_2_5_H__