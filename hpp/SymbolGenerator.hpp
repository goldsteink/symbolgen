/**
 * Kevin A. Goldstein R. (kevgol0@gmail.com)
 *
 * FILE:   SymbolGenerator.hpp
 * DSCRPT: comment
 */

#ifndef __SYMBOLGENERATOR_HPP__
#define __SYMBOLGENERATOR_HPP__

#include <deque>
#include <memory>



class SymbolGenerator
{
	private:
		int _tickerSz; // gives 308,915,776
		
	public:
		SymbolGenerator () = default;
		virtual ~SymbolGenerator () = default;
};

#endif /* __SYMBOLGENERATOR_HPP__ */
