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
#ifndef SoftWire_Token_hpp
#define SoftWire_Token_hpp

namespace SoftWire
{
	class Scanner;

	class Token
	{
	public:
		Token();

		virtual ~Token();

		virtual bool isEndOfLine() const;
		virtual bool isEndOfFile() const;
		virtual bool isIdentifier(const char *compareString = 0) const;
		virtual bool isInteger() const;
		virtual bool isReal() const;
		virtual bool isPunctuator(char c = 0) const;
		virtual bool isLiteral() const;
		virtual bool isConstant() const;

		virtual const char *getString() const;
		virtual char getChar() const;
		virtual int getInteger() const;
		virtual float getReal() const;

		static Token *copy(const Token *token);
	};

	class EndOfLine : public Token
	{
	public:
		EndOfLine(const char *lineStart);

		bool isEndOfLine() const;
		const char *getString() const;

	private:
		const char *lineStart;
	};

	class EndOfFile : public Token
	{
	public:
		EndOfFile(const char *lineStart);

		bool isEndOfFile() const;
		bool isEndOfLine() const;
		const char *getString() const;

	private:
		const char *lineStart;
	};

	class Identifier : public Token
	{
	public:
		Identifier(const char *string);

		~Identifier();

		bool isIdentifier(const char *compareString = 0) const;

		const char *getString() const;

	private:
		char *string;
	};

	class Integer : public Token
	{
	public:
		Integer(int value);

		bool isInteger() const;
		bool isConstant() const;

		int getInteger() const;

	private:
		int value;
	};

	class Real : public Token
	{
	public:
		Real(float value);

		bool isReal() const;
		bool isConstant() const;

		float getReal() const;

	private:
		float value;
	};

	class Punctuator : public Token
	{
	public:
		Punctuator(char c);

		bool isPunctuator(char c = 0) const;

		char getChar() const;

	private:
		char c;
	};

	class Literal : public Token
	{
	public:
		Literal(const char *string);

		~Literal();

		bool isLiteral() const;

		const char *getString() const;

	private:
		char *string;
	};
}

#endif   // SoftWire_Token_hpp
