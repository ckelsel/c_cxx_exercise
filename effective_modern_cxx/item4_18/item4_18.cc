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

#include "item4_18.h"

std::unique_ptr<Investment> makeInvestment(Investment::TYPE type) {
    std::unique_ptr<Investment> val(nullptr);

    if (type == Investment::TYPE::BOND) {
        val.reset(new Bond);
    } else if (type == Investment::TYPE::REAL_ESTATE) {
        val.reset(new RealEstate);
    } else if (type == Investment::TYPE::STOCK) {
        val.reset(new Stock);
    }

    return val;
}