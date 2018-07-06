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
#ifndef __ITEM29_H__
#define __ITEM29_H__

#ifdef _WIN32

//Item29: Strive for exception-safe code.

#include <istream>
#include <fstream>
#include <memory> // std::tr1::shared_ptr

#include "../item14/item14.h"

class Image {
public:
    Image(std::istream &imgsrc, bool exception = true) {
        if (exception) {
            throw std::invalid_argument("invalid argument");
        }
    }
};

class PrettyMenuException {
public:
    PrettyMenuException() : changes_(0) {
        init(&mutex_);
        image_ = new Image(std::istream(NULL), false);
    }
    
    void ChangeBackground(std::istream &imgsrc);

    Image* GetImage() { return image_; }

    int GetChange() { return changes_; }

private:
    Mutex mutex_;
    Image *image_;
    int changes_;
};

//////////////////

class PrettyMenu_Exception_RefactorMutex {
public:
    PrettyMenu_Exception_RefactorMutex() : changes_(0) {
        init(&mutex_);
        image_ = new Image(std::istream(NULL), false);
    }

    Image* GetImage() { return image_; }

    void ChangeBackground(std::istream &imgsrc);

    int GetChange() { return changes_; }

private:
    Mutex mutex_;
    Image *image_;
    int changes_;
};

//////////////////

class PrettyMenu_BasicExceptionSafe_RefactorMutex_SmartPointer {
public:
    PrettyMenu_BasicExceptionSafe_RefactorMutex_SmartPointer() : changes_(0)
        , image_(new Image(std::istream(NULL), false)) {
        init(&mutex_);
    }

    Image* GetImage() { return image_.get(); }

    void ChangeBackground(std::istream &imgsrc, bool exception = true);

    int GetChange() { return changes_; }

private:
    Mutex mutex_;
    std::tr1::shared_ptr<Image> image_;
    int changes_;
};

//////////////////

struct PrettyMenuImpl {
    std::tr1::shared_ptr<Image> image_;
    int changes_;
};

class PrettyMenu_StrongExceptionSafe_RefactorMutex_SmartPointer {
public:
    PrettyMenu_StrongExceptionSafe_RefactorMutex_SmartPointer() {
        init(&mutex_);
        impl_.reset(new PrettyMenuImpl());
        impl_->image_.reset(new Image(std::istream(NULL), false));
    }

    Image* GetImage() { return impl_->image_.get(); }

    int GetChange() { return impl_->changes_; }

    void ChangeBackground(std::istream &imgsrc, bool exception = true);

private:
    Mutex mutex_;
    std::tr1::shared_ptr<PrettyMenuImpl> impl_;
};

#endif // _WIN32

#endif // __ITEM29_H__
