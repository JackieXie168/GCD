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

#ifndef __DISPATCH_SEMAPHORE_INTERNAL__
#define __DISPATCH_SEMAPHORE_INTERNAL__

struct dispatch_sema_notify_s {
	struct dispatch_sema_notify_s *dsn_next;
	dispatch_queue_t dsn_queue;
	void *dsn_ctxt;
	void (*dsn_func)(void *);
};

struct dispatch_semaphore_s {
	DISPATCH_STRUCT_HEADER(dispatch_semaphore_s, dispatch_semaphore_vtable_s);
	long dsema_value;
	long dsema_orig;
	size_t dsema_sent_ksignals;
#ifdef HAVE_MACH
	semaphore_t dsema_port;
	semaphore_t dsema_waiter_port;
#elif defined(HAVE_SEM_INIT)
	sem_t dsema_sem;
#else
#error "No supported semaphore type"
#endif
	size_t dsema_group_waiters;
	struct dispatch_sema_notify_s *dsema_notify_head;
	struct dispatch_sema_notify_s *dsema_notify_tail;
};

extern const struct dispatch_semaphore_vtable_s _dispatch_semaphore_vtable;

#endif
