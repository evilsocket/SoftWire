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
#ifndef SoftWire_Loader_hpp
#define SoftWire_Loader_hpp

#include "Link.hpp"

namespace SoftWire
{
	class Linker;
	class Encoding;

	class Loader
	{
	public:
		Loader(const Linker &linker, bool x64);

		virtual ~Loader();

		void (*callable(const char *entryLabel = 0))();
		void (*finalize(const char *entryLabel = 0))();
		void *acquire();

		Encoding *appendEncoding(const Encoding &encoding);

		const char *getListing();
		void clearListing();
		void reset();
		int instructionCount();

	private:
		const Linker &linker;

		typedef Link<Encoding> Instruction;
		Instruction *instructions;
		unsigned char *machineCode;
		char *listing;

		const bool x64;   // Long mode
		bool possession;
		bool finalized;

		void loadCode(const char *entryLabel = 0);
		const unsigned char *resolveReference(const char *name, const Instruction *position) const;
		const unsigned char *resolveLocal(const char *name, const Instruction *position) const;
		const unsigned char *resolveExternal(const char *name) const;
		int codeLength() const;
	};
}

#endif   // SoftWire_Loader_hpp
