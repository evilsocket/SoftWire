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
#ifndef SoftWire_Link_hpp
#define SoftWire_Link_hpp

namespace SoftWire
{
	template<class T>
	class Link : public T
	{
	public:
		Link();
		
		~Link();

		Link *append(const T &t);
		Link *next() const;
		Link *tail() const;

	private:
		Link *n;   // Next
		Link *t;   // Tail
	};
}

namespace SoftWire
{
	template<class T>
	Link<T>::Link()
	{
		n = 0;
		t = 0;
	}

	template<class T>
	Link<T>::~Link()
	{
		// Avoid call stack overflow
		while(n)
		{
			Link *nextNext = n->n;
			n->n = 0;
			delete n;
			n = nextNext;
		}

		t = 0;
	}

	template<class T>
	Link<T> *Link<T>::append(const T &e)
	{
		if(t == 0)   // Empty chain
		{
			*(T*)this = e;
			t = this;
		}
		else if(t != this)
		{
			t = t->append(e);
		}
		else
		{
			t = n = new Link();
			*(T*)t = e;
			t->t = t;
		}

		return t;
	}

	template<class T>
	Link<T> *Link<T>::next() const
	{
		return n;
	}

	template<class T>
	Link<T> *Link<T>::tail() const
	{
		return t;
	}
}

#endif   // SoftWire_Link_hpp
