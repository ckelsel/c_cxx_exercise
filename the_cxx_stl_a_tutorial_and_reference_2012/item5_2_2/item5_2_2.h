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

#ifndef __ITEM_5_2_2_H__
#define __ITEM_5_2_2_H__
// 5.2.2 std::weak_ptr

#include <memory>
#include <string>
#include <vector>
#include <iostream>

class CircleReferenceB;
class CircleReferenceA {
public:
    std::shared_ptr<CircleReferenceB> b_;

    ~CircleReferenceA() {
        std::cout << "delete CircleReferenceA" << std::endl;
    }
};

class CircleReferenceB {
public:
    std::shared_ptr<CircleReferenceA> a_;

    ~CircleReferenceB() {
        std::cout << "delete CircleReferenceB" << std::endl;
    }
};

class CircleReference {
public:
    std::shared_ptr<CircleReference> m_;
    std::shared_ptr<CircleReference> n_;

    CircleReference() {
    }

    ~CircleReference() {
        std::cout << "delete CircleReference" << std::endl;
    }
};

class PersonCircleReference {
public:
    std::string name_;
    std::shared_ptr<PersonCircleReference> mon_;
    std::shared_ptr<PersonCircleReference> dad_;
    std::vector<std::shared_ptr<PersonCircleReference>> kid_;
    
    PersonCircleReference(const std::string name,
           std::shared_ptr<PersonCircleReference> mon = nullptr,
           std::shared_ptr<PersonCircleReference> dad = nullptr) 
           : name_(name), mon_(mon), dad_(dad) {
    }

    ~PersonCircleReference() {
        std::cout << "delete " << name_ << std::endl;
    }
};

inline std::shared_ptr<PersonCircleReference> initFamily(const std::string &name) {
    std::shared_ptr<PersonCircleReference> mon(new PersonCircleReference(name + "'s mon"));
    std::shared_ptr<PersonCircleReference> dad(new PersonCircleReference(name + "'s dad"));
    std::shared_ptr<PersonCircleReference> kid(new PersonCircleReference(name, mon, dad));

    mon->kid_.push_back(kid);
    dad->kid_.push_back(kid);

    return kid;
}

class PersonCircleReferenceWeakPtr {
public:
    std::string name_;
    std::shared_ptr<PersonCircleReferenceWeakPtr> mon_;
    std::shared_ptr<PersonCircleReferenceWeakPtr> dad_;
    std::vector<std::weak_ptr<PersonCircleReferenceWeakPtr>> kid_;
    
    PersonCircleReferenceWeakPtr(const std::string name,
           std::shared_ptr<PersonCircleReferenceWeakPtr> mon = nullptr,
           std::shared_ptr<PersonCircleReferenceWeakPtr> dad = nullptr) 
           : name_(name), mon_(mon), dad_(dad) {
    }

    ~PersonCircleReferenceWeakPtr() {
        std::cout << "delete " << name_ << std::endl;
    }
};

inline std::shared_ptr<PersonCircleReferenceWeakPtr> initFamilyWeakPtr(const std::string &name) {
    std::shared_ptr<PersonCircleReferenceWeakPtr> mon(new PersonCircleReferenceWeakPtr(name + "'s mon"));
    std::shared_ptr<PersonCircleReferenceWeakPtr> dad(new PersonCircleReferenceWeakPtr(name + ", dad"));
    std::shared_ptr<PersonCircleReferenceWeakPtr> kid(new PersonCircleReferenceWeakPtr(name, mon, dad));

    mon->kid_.push_back(kid);
    dad->kid_.push_back(kid);

    return kid;
}
#endif // __ITEM_5_2_2_H__