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
#ifndef SoftWire_InstructionSet_hpp
#define SoftWire_InstructionSet_hpp

#include "Instruction.hpp"

namespace SoftWire
{
	class TokenList;

	class InstructionSet
	{
	public:
		InstructionSet();

		virtual ~InstructionSet();

		const Instruction *instruction(int i);

	private:
		struct Entry
		{
			~Entry() {delete instruction;};

			const char *mnemonic;

			Instruction *instruction;
		};

		Instruction *intrinsicMap;

		static const Instruction::Syntax instructionSet[];
		static const int numInstructions;

		void generateIntrinsics();

		static int strcmp(const char *string1, const char *string2);
	};
}

#endif   // SoftWire_InstructionSet_hpp
