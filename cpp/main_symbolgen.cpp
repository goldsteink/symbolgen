/*
 * Author: Kevin A. Goldstein (kevin@sendence.com)
 * 
 * PRJ:     SymbolGenerator
 * FILE:		main_symbolgen.cpp
 * DSCRPT:	comment
 */



#include <spdlog/spdlog.h>
#include <memory>
#include <iostream>
#include <cstdlib>

#include "SymbolGenerator.hpp"

using namespace std;




int main (
		int argc_,
			char** argv_ )
{
	SymbolGenerator* sgen = new SymbolGenerator();
	
	return EXIT_SUCCESS;
}
