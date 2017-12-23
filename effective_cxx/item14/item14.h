/* Copyright 2017 kunming.xie
 *
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
#ifndef __ITEM14_H__
#define __ITEM14_H__
//Item 14: Think carefully about copying behavior in resource-managing classes.

#include <memory>

#include <windows.h>
#define Mutex CRITICAL_SECTION
#define init InitializeCriticalSection
#define lock EnterCriticalSection
#define unlock LeaveCriticalSection

// caller should init mutex
class Lock {
public:
    explicit Lock(Mutex *mutex) : mutex_(mutex) {
        lock(mutex_);
    }
    ~Lock() {
        unlock(mutex_);
    }

private:
    Lock(const Lock &);
    Lock& operator=(const Lock &);

private:
    Mutex *mutex_;
};

class Lock_SmartPointer {
public:
    explicit Lock_SmartPointer(Mutex *mutex) 
        : mutex_(mutex, unlock) {
        lock(mutex_.get());
    }

private:
    Lock_SmartPointer(const Lock_SmartPointer &);
    Lock_SmartPointer& operator=(const Lock_SmartPointer &);

private:
    std::tr1::shared_ptr<Mutex> mutex_;
};

#endif // __ITEM14_H__
