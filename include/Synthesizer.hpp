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
#ifndef SoftWire_Synthesizer_hpp
#define SoftWire_Synthesizer_hpp

#include "Encoding.hpp"
#include "Operand.hpp"

namespace SoftWire
{
	class Instruction;

	class Synthesizer
	{
	public:
		Synthesizer(bool x64);

		virtual ~Synthesizer();

		void reset();

		void defineLabel(const char *label);

		void encodeFirstOperand(const Operand &firstOperand);
		void encodeSecondOperand(const Operand &secondOperand);
		void encodeThirdOperand(const Operand &thirdOperand);

		void encodeImmediate(int i);
		void encodeLiteral(const char *string);

		const Encoding &encodeInstruction(const Instruction *instruction);

	private:
		const bool x64;

		Encoding encoding;

		Operand::Type firstType;
		Operand::Type secondType;

		int firstReg;
		int secondReg;
		int baseReg;
		int indexReg;

		int scale;

		void encodeBase(const Operand &base);
		void encodeIndex(const Operand &index);

		void setScale(int scale);
		void setDisplacement(int displacement);

		void referenceLabel(const char *label);

		void encodeRexByte(const Instruction *instruction);
		void encodeModField();
		void encodeR_MField(const Instruction *instruction);
		void encodeRegField(const Instruction *instruction);
		void encodeSibByte(const Instruction *instruction);
	};
}

#endif   // SoftWire_Synthesizer_hpp
