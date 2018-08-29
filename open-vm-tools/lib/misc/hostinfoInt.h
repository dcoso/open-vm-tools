/*********************************************************
 * Copyright (C) 2009-2018 VMware, Inc. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation version 2.1 and no later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA.
 *
 *********************************************************/

/*
 * hostinfoInt.h --
 *
 *	lib/misc Hostinfo_* private declarations.
 */

#ifndef _HOSTINFOINT_H_
#define _HOSTINFOINT_H_


#define MAX_OS_NAME_LEN 128
#define MAX_OS_FULLNAME_LEN 512
#define MAX_STRUCTURED_FIELD_LEN 1024

#define STRUCTURED_STRING_DELIMITER " "


/*
 * Global variables
 */

typedef struct {
   char  *name;
   char  value[MAX_STRUCTURED_FIELD_LEN];
} StructuredField;

/* Must be sorted. Keep in same ordering as structuredFields */
typedef enum {
   BITNESS,
   BUILD_NUMBER,
   DISTRO_NAME,
   DISTRO_VERSION,
   FAMILY_NAME,
   KERNEL_VERSION,
   PRETTY_NAME
} StructuredFieldType;

/* Must be sorted. Keep in same ordering as StructuredFieldType. Defined in
 * hostinfoPosix.c */
extern StructuredField structuredFields[];

#define MAX_STRUCTURED_STRING_LEN MAX_STRUCTURED_FIELD_LEN * 10


extern volatile Bool HostinfoOSNameCacheValid;
extern char HostinfoCachedOSName[MAX_OS_NAME_LEN];
extern char HostinfoCachedOSFullName[MAX_OS_FULLNAME_LEN];
extern char HostinfoCachedStructuredString[MAX_STRUCTURED_STRING_LEN];


/*
 * Global functions
 */

extern Bool HostinfoOSData(void);


#endif // ifndef _HOSTINFOINT_H_
