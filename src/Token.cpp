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
#include "Token.hpp"

#include "String.hpp"
#include "Error.hpp"

#include <stdlib.h>

namespace SoftWire
{
	Token::Token()
	{
	}

	Token::~Token()
	{
	}

	bool Token::isEndOfLine() const
	{
		return false;
	}

	bool Token::isEndOfFile() const
	{
		return false;
	}

	bool Token::isIdentifier(const char *compareString) const
	{
		return false;
	}

	bool Token::isInteger() const
	{
		return false;
	}

	bool Token::isReal() const
	{
		return false;
	}

	bool Token::isPunctuator(char c) const
	{
		return false;
	}

	bool Token::isLiteral() const
	{
		return false;
	}

	bool Token::isConstant() const
	{
		return false;
	}

	const char *Token::getString() const
	{
		return "";
	}

	char Token::getChar() const
	{
		return '\0';
	}

	int Token::getInteger() const
	{
		return 0;
	}

	float Token::getReal() const
	{
		return 0.0f;
	}

	Token *Token::copy(const Token *token)
	{
		if(token->isEndOfFile())	return new EndOfFile(token->getString());
		if(token->isEndOfLine())	return new EndOfLine(token->getString());
		if(token->isIdentifier())	return new Identifier(token->getString());
		if(token->isInteger())		return new Integer(token->getInteger());
		if(token->isLiteral())		return new Literal(token->getString());
		if(token->isPunctuator())	return new Punctuator(token->getChar());
		if(token->isReal())			return new Real(token->getReal());
		else						throw INTERNAL_ERROR;
	}

	EndOfLine::EndOfLine(const char *lineStart)
	{
		this->lineStart = lineStart;
	}

	bool EndOfLine::isEndOfLine() const
	{
		return true;
	}

	const char *EndOfLine::getString() const
	{
		return lineStart;
	}

	EndOfFile::EndOfFile(const char *lineStart)
	{
		this->lineStart = lineStart;
	}

	bool EndOfFile::isEndOfFile() const
	{
		return true;
	}

	bool EndOfFile::isEndOfLine() const
	{
		return true;
	}

	const char *EndOfFile::getString() const
	{
		return lineStart;
	}

	Identifier::Identifier(const char *string)
	{
		this->string = strdup(string);
	}

	Identifier::~Identifier()
	{
		delete[] string;
	}

	bool Identifier::isIdentifier(const char *compareString) const
	{
		if(!compareString)
		{
			return true;
		}
		else
		{
			if(strcmp(this->string, compareString) == 0)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	const char *Identifier::getString() const
	{
		return string;
	}

	Integer::Integer(int value)
	{
		this->value = value;
	}

	bool Integer::isInteger() const
	{
		return true;
	}

	bool Integer::isConstant() const
	{
		return true;
	}

	int Integer::getInteger() const
	{
		return value;
	}

	Real::Real(float value)
	{
		this->value = value;
	}

	bool Real::isReal() const
	{
		return true;
	}

	bool Real::isConstant() const
	{
		return true;
	}

	float Real::getReal() const
	{
		return value;
	}

	Punctuator::Punctuator(char c)
	{
		this->c = c;
	}

	bool Punctuator::isPunctuator(char c) const
	{
		if(c == 0)
		{
			return true;
		}
		else if(this->c == c)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	char Punctuator::getChar() const
	{
		return c;
	}

	Literal::Literal(const char *string)
	{
		this->string = strdup(string);
	}

	Literal::~Literal()
	{
		delete[] string;
	}

	bool Literal::isLiteral() const
	{
		return true;
	}

	const char *Literal::getString() const
	{
		return string;
	}
}
