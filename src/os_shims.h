/*
 * Copyright (c) 2008-2009 Apple Inc. All rights reserved.
 *
 * @APPLE_APACHE_LICENSE_HEADER_START@
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 * @APPLE_APACHE_LICENSE_HEADER_END@
 */

/*
 * IMPORTANT: This header file describes INTERNAL interfaces to libdispatch
 * which are subject to change in future releases of Mac OS X. Any applications
 * relying on these interfaces WILL break.
 */

#ifndef __DISPATCH_OS_SHIMS__
#define __DISPATCH_OS_SHIMS__

#include <pthread.h>
#ifdef HAVE_PTHREAD_MACHDEP_H
#include <pthread_machdep.h>
#endif
#ifdef HAVE_PTHREAD_WORKQUEUES
#include <pthread_workqueue.h>
#endif
#ifdef HAVE_PTHREAD_NP_H
#include <pthread_np.h>
#endif

#if USE_APPLE_CRASHREPORTER_INFO
__private_extern__ const char *__crashreporter_info__;
#endif

#if !HAVE_DECL_FD_COPY
#define	FD_COPY(f, t)	(void)(*(t) = *(f))
#endif

#include "shims/malloc_zone.h"
#include "shims/tsd.h"
#include "shims/perfmon.h"
#include "shims/time.h"

#endif
