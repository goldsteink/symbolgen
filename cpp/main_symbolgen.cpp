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

#include "hpp/SymbolGenerator.hpp"
#include "hpp/SymbolGenCfg.hpp"

using namespace std;

void printHelp ( char* progName_ );
spdlog::level::level_enum getLogLevel ( const char* lvl_, shared_ptr<spdlog::logger> logger_ );
const char* getAndTestDefaultConfigFile ( const char* progname_, const char* defaultFileName_ );





/**
 * the main thing
 */
int main ( int argc_, char** argv_ )
{
	shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt("console");
	logger->set_level(spdlog::level::trace);


	char c;
	string cfgfile;
	string level = "info";
	while ((c = getopt(argc_, argv_, "c:l:h")) != -1)
	{
		switch (c)
		{
			case 'c':
			cfgfile = optarg;
				break;
			case 'l':
			level = optarg;
			logger->set_level(getLogLevel(level.c_str(), logger));
				break;
			case 'h':
			printHelp(argv_[0]);
			return EXIT_SUCCESS;
			default:
			cerr << "unkown! value: " << optarg;
				break;
		}
	}


	//
	// load my config
	//
	shared_ptr<SymbolGenCfg> cfg;
	if (cfgfile.empty())
	cfg = SymbolGenCfg::getInstance();
	else
	cfg = SymbolGenCfg::getInstance(cfgfile);



	//
	//
	//
	SymbolGenerator* sgen = new SymbolGenerator();
	
	
	delete sgen;
	cfg = nullptr;
	return EXIT_SUCCESS;
}



/***
 * shows how to call 
 */
void printHelp ( char* progName_ )
{
	std::cerr << "usage:" << std::endl;
	std::cerr << "\t" << progName_ << " [-c file] [-h]" << std::endl;
}




/**
 *
 * @param lvl_
 * @return
 */
spdlog::level::level_enum getLogLevel ( const char* lvl_, shared_ptr<spdlog::logger> logger_ )
{
	//
	//
	//
	if (lvl_ == nullptr)
	{
		return spdlog::level::info;
	}





	//
	// set it
	//
	if (string("trace").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to: {}", "TRACE");
		spdlog::set_level(spdlog::level::trace);
		return spdlog::level::trace;
	}
	if (string("debug").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to: {}", "DEBUG");
		spdlog::set_level(spdlog::level::debug);
		return spdlog::level::debug;
	}
	if (string("info").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to:{}", "INFO");
		spdlog::set_level(spdlog::level::info);
		return spdlog::level::info;
	}
	if (string("warn").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to:{}", "WARN");
		spdlog::set_level(spdlog::level::warn);
		return spdlog::level::warn;
	}
	if (string("error").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to:{}", "ERROR");
		spdlog::set_level(spdlog::level::err);
		return spdlog::level::err;
	}
	if (string("critical").compare(lvl_) == 0)
	{
		logger_->info("Setting log level to:{}", "CRITICAL");
		spdlog::set_level(spdlog::level::critical);
		return spdlog::level::critical;
	}




	//
	// don't know
	//
	cerr << "unknown level specified:" << lvl_ << endl;
	return spdlog::level::info;
}


