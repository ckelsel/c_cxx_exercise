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
#ifndef __ITEM43_H__
#define __ITEM43_H__
//Item 43: Know how to access names in templatized base classes
#include <string>

class CompanyA {
public:
    void sendClearText(const std::string &msg){
    }

    void sendEncryped(const std::string &msg){
    }
};

class CompanyB {
public:
    void sendClearText(const std::string &msg){
    }

    void sendEncryped(const std::string &msg){
    }
};

class CompanyZ {
public:
    void sendEncryped(const std::string &msg){
    }
};


class MsgInfo {
};


template<typename Company>
class MsgSender {
public:
    void sendClear(const MsgInfo &info) {
        Company company;
        company.sendClearText(std::string());
    }

    void sendSecrte(const MsgInfo &info) {
        Company company;
        company.sendEncryped(std::string());
    }
};

// *Must declare after*
// template<typename Company>
// class MsgSender {
template<>
class MsgSender<CompanyZ> {
public:
    void sendSecrte(const MsgInfo &info) {
        CompanyZ company;
        company.sendEncryped(std::string());
    }
};


template<typename Company>
class LoggingMsgSender : public MsgSender<Company> {
public:
    void sendClearMsg(const MsgInfo &info) {
        MsgSender<Company>::sendClear(info);
    }

    void sendSecrteMsg(const MsgInfo &info) {
        sendSecrte(info);
    }
};

#endif // __ITEM43_H__