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
#ifndef SoftWire_File_hpp
#define SoftWire_File_hpp

#include "Error.hpp"

#include <stdio.h>

#ifdef __unix__
	#include <sys/stat.h>
#else
	#include <io.h>
#endif

namespace SoftWire
{
#ifdef __unix__
	static int _filelength(int handle)
	{
		struct stat statbuf;
		
		if(fstat(handle, &statbuf) != 0)
		{
			throw INTERNAL_ERROR;
		}

		return statbuf.st_size;
	}
#endif
}

#endif   // SoftWire_File_hpp
