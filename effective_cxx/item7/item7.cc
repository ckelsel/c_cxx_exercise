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

#include "item7.h"
#include <iostream>

int TimeKeeperReference = 0;

void ResetTimeKeeperReference()
{
    TimeKeeperReference = 0;
}

TimeKeeperNonVirtual::TimeKeeperNonVirtual()
{
    TimeKeeperReference++;
}

TimeKeeperNonVirtual::~TimeKeeperNonVirtual()
{
    TimeKeeperReference--;
}

////////////////////


TimeKeeperVirtual::TimeKeeperVirtual()
{
    TimeKeeperReference++;
}

TimeKeeperVirtual::~TimeKeeperVirtual()
{
    TimeKeeperReference--;
}

/////////////////////

WaterWatch::WaterWatch()
{
    TimeKeeperReference++;
}

WaterWatch::~WaterWatch()
{
    TimeKeeperReference--;
}

//////////////////////


AtomicWatch::AtomicWatch()
{
    TimeKeeperReference++;
}

AtomicWatch::~AtomicWatch()
{
    TimeKeeperReference--;
}

/////////////////////

TimeKeeperNonVirtual *getTimeKeeper()
{
    return new WaterWatch();
}

TimeKeeperVirtual *getTimeKeeper2()
{
    return new AtomicWatch();
}