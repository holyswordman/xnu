/*
 * Copyright (c) 2000-2004 Apple Computer, Inc. All rights reserved.
 *
 * @APPLE_LICENSE_OSREFERENCE_HEADER_START@
 * 
 * This file contains Original Code and/or Modifications of Original Code 
 * as defined in and that are subject to the Apple Public Source License 
 * Version 2.0 (the 'License'). You may not use this file except in 
 * compliance with the License.  The rights granted to you under the 
 * License may not be used to create, or enable the creation or 
 * redistribution of, unlawful or unlicensed copies of an Apple operating 
 * system, or to circumvent, violate, or enable the circumvention or 
 * violation of, any terms of an Apple operating system software license 
 * agreement.
 *
 * Please obtain a copy of the License at 
 * http://www.opensource.apple.com/apsl/ and read it before using this 
 * file.
 *
 * The Original Code and all software distributed under the License are 
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER 
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES, 
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY, 
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT. 
 * Please see the License for the specific language governing rights and 
 * limitations under the License.
 *
 * @APPLE_LICENSE_OSREFERENCE_HEADER_END@
 */
/*
 * Copyright 1995 NeXT Computer, Inc. All rights reserved.
 */
#ifndef _BSD_MACHINE_EXEC_H_
#define _BSD_MACHINE_EXEC_H_

#include <sys/param.h>

struct exec_archhandler {
	char path[MAXPATHLEN];
	uint32_t fsid;
	long fileid;
};

extern struct exec_archhandler exec_archhandler_ppc;
extern int set_archhandler(struct proc *p, int arch);
extern int grade_binary(cpu_type_t exectype, cpu_subtype_t execsubtype);

#if defined (__ppc__) || defined (__ppc64__)
#include "ppc/exec.h"
#elif defined (__i386__) || defined(__x86_64__)
#include "i386/exec.h"
#else
#error architecture not supported
#endif


#endif /* _BSD_MACHINE_EXEC_H_ */
