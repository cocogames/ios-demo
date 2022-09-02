// Tencent is pleased to support the open source community by making Mars available.
// Copyright (C) 2016 THL A29 Limited, a Tencent company. All rights reserved.

// Licensed under the MIT License (the "License"); you may not use this file except in 
// compliance with the License. You may obtain a copy of the License at
// http://opensource.org/licenses/MIT

// Unless required by applicable law or agreed to in writing, software distributed under the License is
// distributed on an "AS IS" basis, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
// either express or implied. See the License for the specific language governing permissions and
// limitations under the License.


/*
 * scope_recursion_limit.h
 *
 *  Created on: Mar 12, 2014
 *      Author: yanguoyue
 */

#ifndef BU_ALOG_SCOPERECURSIONLIMIT_H_
#define BU_ALOG_SCOPERECURSIONLIMIT_H_

#include "BUTss.h"

class BUScopeRecursionLimit {
  public:
    BUScopeRecursionLimit(BUTss* _tss): tss_(_tss) {
        tss_->set((void*)((intptr_t)tss_->get() + 1));
    }

    ~BUScopeRecursionLimit() {
        tss_->set((void*)((intptr_t)tss_->get() - 1));
    }

    /**
     * return
     *     true-limit
     *     false-pass
     */
    bool CheckLimit(int _maxRecursionNum = 1) {
        return (intptr_t)tss_->get() > _maxRecursionNum;
    }

    intptr_t Get() const {
        return (intptr_t)tss_->get();
    }

  private:
    BUScopeRecursionLimit(const BUScopeRecursionLimit&);
    BUScopeRecursionLimit& operator=(const BUScopeRecursionLimit&);

  private:
    BUTss* tss_;
};

#ifndef __CONCAT__
#define __CONCAT_IMPL(x, y)    x##y
#define __CONCAT__(x, y)    __CONCAT_IMPL(x, y)
#endif

#define    DEFINE_BUSCOPERECURSIONLIMIT(classname)\
    static BUTss __CONCAT__(tss, __LINE__)(NULL);\
    BUScopeRecursionLimit classname(&__CONCAT__(tss, __LINE__))


#endif /* COMM_SCOPERECURSIONLIMIT_H_ */
