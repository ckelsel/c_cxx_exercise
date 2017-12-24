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
#ifndef __ITEM39_H__
#define __ITEM39_H__
//Item 39: Use private inheritance judiciously

class Person39 {
};

class Student39 : private Person39 {
};

void eat(const Person39 &person);
void study(const Student39 &student);

//////////////////////////////

class Timer39 {
public:
    virtual void onTick() const;
};

class WidgetPrivateTimer39 {
public:
    virtual void onTick() const;
};

//////////////////////////////


class WidgetCompositionTimer39 {
private:
    class WidgetTimer39 : public Timer39 {
    public:
        virtual void onTick() const;
    };

    WidgetTimer39 timer_;
};

#endif // __ITEM39_H__