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

#ifndef __ITEM_5_2_3_H__
#define __ITEM_5_2_3_H__
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class PersonCircleReferenceMisUse : public std::enable_shared_from_this<PersonCircleReferenceMisUse> {
public:
    std::string name_;
    std::shared_ptr<PersonCircleReferenceMisUse> mon_;
    std::shared_ptr<PersonCircleReferenceMisUse> dad_;
    std::vector<std::weak_ptr<PersonCircleReferenceMisUse>> kid_;
    
    PersonCircleReferenceMisUse(const std::string name,
                                std::shared_ptr<PersonCircleReferenceMisUse> mon = nullptr,
                                std::shared_ptr<PersonCircleReferenceMisUse> dad = nullptr) 
                                : name_(name), mon_(mon), dad_(dad) {
    }

    void SetParentsAndTheirKidsError(std::shared_ptr<PersonCircleReferenceMisUse> mon = nullptr,
                                     std::shared_ptr<PersonCircleReferenceMisUse> dad = nullptr) {
        mon_ = mon;
        dad_ = dad;
        if (mon_ != nullptr) {
            // same error
            // int *p = new int;
            // std::shared_ptr<int> ref1(p);
            // std::shared_ptr<int> ref2(p);
            mon_->kid_.push_back(std::shared_ptr<PersonCircleReferenceMisUse>(this));
        }
        if (dad_ != nullptr) {
            dad_->kid_.push_back(std::shared_ptr<PersonCircleReferenceMisUse>(this));
        }
    }

    // 1)
    void SetParentsAndTheirKidsCorrect(std::shared_ptr<PersonCircleReferenceMisUse> kid,
                                       std::shared_ptr<PersonCircleReferenceMisUse> mon = nullptr,
                                       std::shared_ptr<PersonCircleReferenceMisUse> dad = nullptr) {
        mon_ = mon;
        dad_ = dad;
        if (mon_ != nullptr) {
            mon_->kid_.push_back(kid);
        }
        if (dad_ != nullptr) {
            dad_->kid_.push_back(kid);
        }
    }

    void SetParentsAndTheirKidsCorrect2(std::shared_ptr<PersonCircleReferenceMisUse> mon = nullptr,
                                       std::shared_ptr<PersonCircleReferenceMisUse> dad = nullptr) {
        mon_ = mon;
        dad_ = dad;
        if (mon_ != nullptr) {
            mon_->kid_.push_back(shared_from_this());
        }
        if (dad_ != nullptr) {
            dad_->kid_.push_back(shared_from_this());
        }
    }

    ~PersonCircleReferenceMisUse() {
        std::cout << "delete " << name_ << std::endl;
    }
};

#endif // __ITEM_5_2_3_H__