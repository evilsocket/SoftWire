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
#ifndef SoftWire_Scanner_hpp
#define SoftWire_Scanner_hpp

#include "TokenList.hpp"

#include "Link.hpp"

namespace SoftWire
{
	class Scanner : public TokenList
	{
	public:
		Scanner();
		Scanner(const char *fileName, bool doPreprocessing = true);

		~Scanner();

		void scanFile(const char *fileName, bool doPreprocessing = true);
		void scanString(const char *sourceString, bool doPreprocessing = true);

		static void defineSymbol(int value, const char *name);
		static void clearSymbols();

	private:
		struct Symbol
		{
			Symbol(int value = 0, const char *name = 0) : value(value), name(name) {};

			int value;
			const char *name;
		};

		char *source;

		enum {tokenMax = 256};   // Maximum token length

		typedef Link<Symbol> SymbolTable;
		static SymbolTable *symbols;

		void scanBuffer(char *source, bool doPreprocessing);
		void preprocess();
		void includeFiles();
		void substituteSymbols();
		void expandMacros();
		void conditionalCompilation();

		int conditionTrue();
		void evaluateUnary();
		void evaluateMultiplicative();
		void evaluateAdditive();
		void evaluateRelational();
		void evaluateEquality();
		void evaluateBitwiseAND();
		void evaluateBitwiseOR();
		void evaluateLogicalAND();
		void evaluateLogicalOR();
		void processDirectives();

		bool cleanupParenthesis();

		void includeFile(const char *fileName);
	};
}

#endif   // SoftWire_Scanner_hpp
