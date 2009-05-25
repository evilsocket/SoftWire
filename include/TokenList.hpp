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
#ifndef SoftWire_TokenList_hpp
#define SoftWire_TokenList_hpp

namespace SoftWire
{
	class Macro;
	class Token;

	class TokenList
	{
	public:
		TokenList();

		~TokenList();
		
		// Properties of current token (pointer)
		bool isEndOfFile() const;
		bool isEndOfLine() const;
		bool isIdentifier(const char *compareString = 0) const;
		bool isInteger() const;
		bool isReal() const;
		bool isPunctuator(char c = 0) const;
		bool isLiteral() const;
		bool isConstant() const;

		const char *getString() const;
		char getChar() const;
		int getInteger() const;
		float getReal() const;

		const Token &current() const;
		const Token &lookAhead(int n = 1) const;
		const Token &advance(int n = 1);
		
		void append(const Token &token);
		void erase(int n = 1);
		void overwrite(const Token &token);
		void insertBefore(const Token &token);
		void insertAfter(const Token &token);

		void paste(TokenList &tokenList);
		void expand(Macro &macro);

		void rewind();
		bool isEmpty() const;

	private:
		class TokenLink
		{
		public:
			TokenLink();

			~TokenLink();

			Token *token;
			TokenLink *next;
		};

		TokenLink *head;
		TokenLink *tail;
		TokenLink *pointer;
	};
}

#endif   // SoftWire_TokenList_hpp
