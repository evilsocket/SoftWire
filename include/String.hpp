/***************************************************************************
 *   SoftWire Runtime x86 Assembler Library                                *
 *   Project originally by Nicolas Capens,                                 *
 *   new implementation by Simone Margaritelli <evilsocket@gmail.com>      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#ifndef SoftWire_String_hpp
#define SoftWire_String_hpp

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#ifdef __GNUC__
	#include <sys/types.h>
#endif

namespace SoftWire
{
#ifdef WIN32
	inline int vsnprintf(char *buffer, size_t count, const char *format, va_list argptr)
	{
		return _vsnprintf(buffer, count, format, argptr);
	}

	static int (*snprintf)(char *buffer, size_t count, const char *format, ...) = _snprintf;
#endif

#ifdef __GNUC__
	typedef int64_t __int64;

	inline int stricmp(const char *string1, const char *string2)
	{
		return strcasecmp(string1, string2);
	}

	inline int _getch()
	{
		return getc(stdin);
	}
#endif

#ifndef strlwr
	inline char *strlwr(char *string)
	{
		int n = (int)strlen(string);

		for(int i = 0; i < n; i++)
		{
			string[i] = tolower(string[i]);
		}

		return string;
	}
#endif

	inline char *strdup(const char *string)
	{
		if(!string) return 0;
		char *duplicate = new char[strlen(string) + 1];
		return strcpy(duplicate, string);
	}
}

#endif   // SoftWire_String_hpp
