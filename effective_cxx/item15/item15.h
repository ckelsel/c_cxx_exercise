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
#ifndef __ITEM15_H__
#define __ITEM15_H__

typedef void* FontHandle;

FontHandle GetFont();

void ReleaseFont(FontHandle handle);

class Font {
public:
    explicit Font(FontHandle handle)
        : handle_(handle) {
    }

    ~Font() {
        ReleaseFont(handle_);
    }

    FontHandle Get() const {
        return handle_;
    }

private:
    Font(const Font&);
    Font& operator=(const Font &);

private:
    FontHandle handle_;
};

#endif // __ITEM15_H__