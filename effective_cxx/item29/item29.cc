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
#ifdef _WIN32

#include <istream>
#include <algorithm>
#include "item29.h"

void PrettyMenuException::ChangeBackground(std::istream &imgsrc)
{
    lock(&mutex_);

    delete image_;
    image_ = NULL;
    image_ = new Image(imgsrc);
    ++changes_;

    unlock(&mutex_);
}

void PrettyMenu_Exception_RefactorMutex::ChangeBackground(std::istream &imgsrc)
{
    Lock lock(&mutex_);

    delete image_;
    image_ = NULL;
    image_ = new Image(imgsrc);
    ++changes_;
}

void PrettyMenu_BasicExceptionSafe_RefactorMutex_SmartPointer::ChangeBackground(std::istream &imgsrc, bool exception)
{
    Lock lock(&mutex_);

    image_.reset(new Image(imgsrc, exception));

    ++changes_;
}

void PrettyMenu_StrongExceptionSafe_RefactorMutex_SmartPointer::ChangeBackground(std::istream &imgsrc, bool exception)
{
    Lock lock(&mutex_);

    std::tr1::shared_ptr<PrettyMenuImpl> newimg(new PrettyMenuImpl(*impl_));
    newimg->image_.reset(new Image(imgsrc, exception));
    newimg->changes_++;

    std::swap(impl_, newimg);
}

#endif // _WIN32
