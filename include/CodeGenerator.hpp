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
#ifndef SoftWire_CodeGenerator_hpp
#define SoftWire_CodeGenerator_hpp

#include "Emulator.hpp"

namespace SoftWire
{
	class CodeGenerator : public Emulator
	{
		class Variable
		{
		public:
			virtual ~Variable();

			void free();

		protected:
			Variable(int size);

			int ref() const;

			const int size;

		private:
			int reference;
			int previous;
		};

	public:
		class Byte : public Variable
		{
		public:
			Byte();

			operator OperandREG8() const;
		};

		class Char : public Byte
		{
		public:
			Char();
			Char(unsigned char c);
			Char(const Char &c);

			Char &operator=(const Char &c);

			Char &operator+=(const Char &c);
			Char &operator-=(const Char &c);
			Char &operator*=(const Char &c);
			Char &operator/=(const Char &c);
			Char &operator%=(const Char &c);
			Char &operator<<=(const Char &c);
			Char &operator>>=(const Char &c);
			Char &operator&=(const Char &c);
			Char &operator^=(const Char &c);
			Char &operator|=(const Char &c);

			Char operator+(const Char &c);
			Char operator-(const Char &c);
			Char operator*(const Char &c);
			Char operator/(const Char &c);
			Char operator%(const Char &c);
			Char operator<<(const Char &c);
			Char operator>>(const Char &c);
			Char operator&(const Char &c);
			Char operator^(const Char &c);
			Char operator|(const Char &c);

			Char &operator+=(unsigned char c);
			Char &operator-=(unsigned char c);
			Char &operator*=(unsigned char c);
			Char &operator/=(unsigned char c);
			Char &operator%=(unsigned char c);
			Char &operator<<=(unsigned char c);
			Char &operator>>=(unsigned char c);
			Char &operator&=(unsigned char c);
			Char &operator^=(unsigned char c);
			Char &operator|=(unsigned char c);

			Char operator+(unsigned char c);
			Char operator-(unsigned char c);
			Char operator*(unsigned char c);
			Char operator/(unsigned char c);
			Char operator%(unsigned char c);
			Char operator<<(unsigned char c);
			Char operator>>(unsigned char c);
			Char operator&(unsigned char c);
			Char operator^(unsigned char c);
			Char operator|(unsigned char c);
		};

		class Word : public Variable
		{
		public:
			Word();

			operator OperandREG16() const;
		};

		class Short : public Word
		{
		public:
			Short();
			Short(unsigned short s);
			Short(const Short &s);

			Short &operator=(const Short &s);

			Short &operator+=(const Short &s);
			Short &operator-=(const Short &s);
			Short &operator*=(const Short &s);
			Short &operator/=(const Short &s);
			Short &operator%=(const Short &s);
			Short &operator<<=(const Short &s);
			Short &operator>>=(const Short &s);
			Short &operator&=(const Short &s);
			Short &operator^=(const Short &s);
			Short &operator|=(const Short &s);

			Short operator+(const Short &s);
			Short operator-(const Short &s);
			Short operator*(const Short &s);
			Short operator/(const Short &s);
			Short operator%(const Short &s);
			Short operator<<(const Short &s);
			Short operator>>(const Short &s);
			Short operator&(const Short &s);
			Short operator^(const Short &s);
			Short operator|(const Short &s);

			Short &operator+=(unsigned short s);
			Short &operator-=(unsigned short s);
			Short &operator*=(unsigned short s);
			Short &operator/=(unsigned short s);
			Short &operator%=(unsigned short s);
			Short &operator<<=(unsigned short s);
			Short &operator>>=(unsigned short s);
			Short &operator&=(unsigned short s);
			Short &operator^=(unsigned short s);
			Short &operator|=(unsigned short s);

			Short operator+(unsigned short s);
			Short operator-(unsigned short s);
			Short operator*(unsigned short s);
			Short operator/(unsigned short s);
			Short operator%(unsigned short s);
			Short operator<<(unsigned short s);
			Short operator>>(unsigned short s);
			Short operator&(unsigned short s);
			Short operator^(unsigned short s);
			Short operator|(unsigned short s);
		};

		class Dword : public Variable
		{
		public:
			Dword();

			operator OperandREG32() const;
		};

		class Int : public Dword
		{
		public:
			Int();
			Int(unsigned int i);
			Int(const Int &i);

			Int &operator=(const Int &i);

			Int &operator+=(const Int &i);
			Int &operator-=(const Int &i);
			Int &operator*=(const Int &i);
			Int &operator/=(const Int &i);
			Int &operator%=(const Int &i);
			Int &operator<<=(const Int &i);
			Int &operator>>=(const Int &i);
			Int &operator&=(const Int &i);
			Int &operator^=(const Int &i);
			Int &operator|=(const Int &i);

			Int operator+(const Int &i);
			Int operator-(const Int &i);
			Int operator*(const Int &i);
			Int operator/(const Int &i);
			Int operator%(const Int &i);
			Int operator<<(const Int &i);
			Int operator>>(const Int &i);
			Int operator&(const Int &i);
			Int operator^(const Int &i);
			Int operator|(const Int &i);

			Int &operator+=(unsigned int i);
			Int &operator-=(unsigned int i);
			Int &operator*=(unsigned int i);
			Int &operator/=(unsigned int i);
			Int &operator%=(unsigned int i);
			Int &operator<<=(unsigned int i);
			Int &operator>>=(unsigned int i);
			Int &operator&=(unsigned int i);
			Int &operator^=(unsigned int i);
			Int &operator|=(unsigned int i);

			Int operator+(unsigned int i);
			Int operator-(unsigned int i);
			Int operator*(unsigned int i);
			Int operator/(unsigned int i);
			Int operator%(unsigned int i);
			Int operator<<(unsigned int i);
			Int operator>>(unsigned int i);
			Int operator&(unsigned int i);
			Int operator^(unsigned int i);
			Int operator|(unsigned int i);
		};

		class Word4;
		class Dword2;

		class Qword : public Variable
		{
			friend class Word4;
			friend class Dword2;

		public:
			Qword();
			Qword(const Qword &qword);

			operator OperandMMREG() const;

			Qword &operator=(const Qword &qword);

			Qword &operator+=(const Qword &qword);
			Qword &operator-=(const Qword &qword);
			Qword &operator<<=(const Qword &qword);
			Qword &operator&=(const Qword &qword);
			Qword &operator^=(const Qword &qword);
			Qword &operator|=(const Qword &qword);

			Qword operator+(const Qword &qword);
			Qword operator-(const Qword &qword);
			Qword operator<<(const Qword &qword);
			Qword operator&(const Qword &qword);
			Qword operator^(const Qword &qword);
			Qword operator|(const Qword &qword);

			Qword &operator<<=(char imm);
			Qword operator<<(char imm);
		};

		class Word4 : public Qword
		{
		public:
			Word4();
			Word4(const Word4 &word4);

			operator OperandMMREG() const;

			Word4 &operator=(const Word4 &word4);

			Word4 &operator+=(const Word4 &word4);
			Word4 &operator-=(const Word4 &word4);
			Word4 &operator<<=(const Qword &qword);
			Word4 &operator>>=(const Qword &qword);
			Word4 &operator&=(const Word4 &word4);
			Word4 &operator^=(const Word4 &word4);
			Word4 &operator|=(const Word4 &word4);

			Word4 operator+(const Word4 &word4);
			Word4 operator-(const Word4 &word4);
			Word4 operator<<(const Qword &qword);
			Word4 operator>>(const Qword &qword);
			Word4 operator&(const Word4 &word4);
			Word4 operator^(const Word4 &word4);
			Word4 operator|(const Word4 &word4);

			Word4 &operator<<=(char imm);
			Word4 &operator>>=(char imm);

			Word4 operator<<(char imm);
			Word4 operator>>(char imm);
		};

		typedef Word4 Short4;

		class Dword2 : public Qword
		{
		public:
			Dword2();
			Dword2(const Dword2 &dword2);

			operator OperandMMREG() const;

			Dword2 &operator=(const Dword2 &dword2);

			Dword2 &operator+=(const Dword2 &dword2);
			Dword2 &operator-=(const Dword2 &dword2);
			Dword2 &operator<<=(const Qword &qword);
			Dword2 &operator>>=(const Qword &qword);
			Dword2 &operator&=(const Dword2 &dword2);
			Dword2 &operator^=(const Dword2 &dword2);
			Dword2 &operator|=(const Dword2 &dword2);

			Dword2 operator+(const Dword2 &dword2);
			Dword2 operator-(const Dword2 &dword2);
			Dword2 operator<<(const Qword &qword);
			Dword2 operator>>(const Qword &qword);
			Dword2 operator&(const Dword2 &dword2);
			Dword2 operator^(const Dword2 &dword2);
			Dword2 operator|(const Dword2 &dword2);

			Dword2 &operator<<=(char imm);
			Dword2 &operator>>=(char imm);

			Dword2 operator<<(char imm);
			Dword2 operator>>(char imm);
		};

		typedef Dword2 Int2;

		class Float : public Variable
		{
		public:
			Float();
			Float(const Float &f);

			operator OperandXMMREG() const;

			Float &operator=(const Float &f);

			Float &operator+=(const Float &f);
			Float &operator-=(const Float &f);
			Float &operator*=(const Float &f);
			Float &operator/=(const Float &f);
		//	Float &operator&=(const Float &f);   // NOTE: No andss instruction, andps gives trouble
		//	Float &operator^=(const Float &f);
		//	Float &operator|=(const Float &f);

			Float operator+(const Float &f);
			Float operator-(const Float &f);
			Float operator*(const Float &f);
			Float operator/(const Float &f);
		//	Float operator&(const Float &f);
		//	Float operator^(const Float &f);
		//	Float operator|(const Float &f);
		};

		class Xword : public Variable
		{
		public:
			Xword();

			operator OperandXMMREG() const;
		};

		class Float4 : public Xword
		{
		public:
			Float4();
			Float4(const Float4 &float4);
			Float4(const Float &f);

			Float4 &operator=(const Float4 &float4);

			Float4 &operator+=(const Float4 &float4);
			Float4 &operator-=(const Float4 &float4);
			Float4 &operator*=(const Float4 &float4);
			Float4 &operator/=(const Float4 &float4);
			Float4 &operator&=(const Float4 &float4);
			Float4 &operator^=(const Float4 &float4);
			Float4 &operator|=(const Float4 &float4);

			Float4 operator+(const Float4 &float4);
			Float4 operator-(const Float4 &float4);
			Float4 operator*(const Float4 &float4);
			Float4 operator/(const Float4 &float4);
			Float4 operator&(const Float4 &float4);
			Float4 operator^(const Float4 &float4);
			Float4 operator|(const Float4 &float4);
		};

		CodeGenerator(bool x64);

		virtual ~CodeGenerator();

		void prologue(int functionArguments);
		void epilogue();
		OperandMEM32 argument(int i);

		using Emulator::free;
		void free(Variable &var1);
		void free(Variable &var1, Variable &var2);
		void free(Variable &var1, Variable &var2, Variable &var3);
		void free(Variable &var1, Variable &var2, Variable &var3, Variable &var4);
		void free(Variable &var1, Variable &var2, Variable &var3, Variable &var4, Variable &var5);

	private:
		Dword arg;

		static int stack;
		static int stackTop;
		static Encoding *stackUpdate;

		// Active code generator
		static CodeGenerator *cg;
	};
}

#endif   // SoftWire_CodeGenerator_hpp
