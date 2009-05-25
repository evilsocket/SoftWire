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
#ifndef SoftWire_Parser_hpp
#define SoftWire_Parser_hpp

#include "InstructionSet.hpp"

namespace SoftWire
{
	class TokenList;
	class Instruction;
	class Token;
	class Synthesizer;
	class InstructionSet;

	class Parser
	{
	public:
		Parser(TokenList &tokenList, Synthesizer &synthesizer, const InstructionSet &instructionSet);

		~Parser();

		const Encoding &parseLine();
		const char *skipLine() const;

	private:
		TokenList &tokenList;
		Synthesizer &synthesizer;
		const InstructionSet &instructionSet;

		Instruction *instruction;

		void parseLabel();
		void parseMnemonic();
		void parseSpecifier();

		void parseFirstOperand();
		void parseSecondOperand();
		void parseThirdOperand();

		OperandIMM parseImmediate();
		OperandSTR parseLiteral();
		OperandREG parseRegister();
		OperandMEM parseMemoryReference();
	};
}

#endif   // SoftWire_Parser_hpp
