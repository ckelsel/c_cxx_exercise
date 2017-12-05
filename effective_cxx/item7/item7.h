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
#ifndef __ITEM7_H__
#define __ITEM7_H__

extern int TimeKeeperReference;

void ResetTimeKeeperReference();

class TimeKeeperNonVirtual {
public:
    TimeKeeperNonVirtual();
    ~TimeKeeperNonVirtual();
};

class TimeKeeperVirtual {
public:
    TimeKeeperVirtual();
    virtual ~TimeKeeperVirtual();
};

class WaterWatch : public TimeKeeperNonVirtual {
public:
    WaterWatch();
    ~WaterWatch();
};

class AtomicWatch : public TimeKeeperVirtual {
public:
    AtomicWatch();
    ~AtomicWatch();
};

TimeKeeperNonVirtual *getTimeKeeper();

TimeKeeperVirtual *getTimeKeeper2();

#endif // __ITEM7_H__