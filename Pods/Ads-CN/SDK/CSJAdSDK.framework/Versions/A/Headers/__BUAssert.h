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
 * assert.h
 *
 *  Created on: 2012-8-6
 *      Author: yerungui
 */

#ifndef BU_ALOG_ASSERT_H_
#define BU_ALOG_ASSERT_H_

#include <sys/cdefs.h>
#include <stdarg.h>

# if (!__ISO_C_VISIBLE >= 1999)
#error "C Version < C99"
# endif

#  define    BUASSERT(e)                 ((e) ? (void)0 : __BUASSERT(__FILE__, __LINE__, __func__, #e))

__BEGIN_DECLS
int IS_BUASSERT_ENABLE();

__attribute__((__nonnull__(1, 3, 4)))
void __BUASSERT(const char*, int, const char*, const char*);
__END_DECLS

#endif /* COMM_COMM_ASSERT_H_ */
