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
#ifndef SoftWire_Error_hpp
#define SoftWire_Error_hpp

namespace SoftWire
{
	class Error
	{
	public:
		Error(const char *format, ...);

		const char *getString() const;

		Error &operator<<(const Error &error);
		Error &operator>>(const Error &error);

	private:
		char string[256];
	};

	#ifndef __FUNCSIG__
		#define	__FUNCSIG__ "<function signature unavailable>"
	#endif

	#ifndef NDEBUG
		#define INTERNAL_ERROR Error("%s(%d):\n\tInternal error in '%s'", __FILE__, __LINE__, __FUNCSIG__)
		#define EXCEPTION      Error("%s(%d):\n\t", __FILE__, __LINE__) << Error
	#else
		#define INTERNAL_ERROR Error("Internal error in '%s'", __FUNCSIG__)
		#define EXCEPTION      Error	
	#endif
}

#endif   // SoftWire_Error_hpp
