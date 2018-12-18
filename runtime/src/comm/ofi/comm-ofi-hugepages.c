/*
 * Copyright 2004-2019 Cray Inc.
 * Other additional copyright holders may be indicated within.
 * 
 * The entirety of this work is licensed under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License.
 * 
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
// Interface to hugepages for the OFI-based Chapel comm layer.
//

#include "chplrt.h"

#include "comm-ofi-internal.h"

#include <stdint.h>
#include <sys/types.h>
#include <hugetlbfs.h>  // <sys/types.h> must come first


void* chpl_comm_ofi_hp_get_huge_pages(size_t size) {
  return get_huge_pages(size, GHP_DEFAULT);
}


size_t chpl_comm_ofi_hp_gethugepagesize(void) {
  return gethugepagesize();
}
