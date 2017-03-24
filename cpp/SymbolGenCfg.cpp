/*
 * Author: Kevin A. Goldstein (kevin@sendence.com)
 * 
 * PRJ:     SymbolGenerator
 * FILE:		SymbolGenCfg.cpp
 * DSCRPT:	comment
 */




#include "hpp/SymbolGenCfg.hpp"
#include "hpp/stdinc.hpp"

#include <spdlog/spdlog.h>
#include <exception>

using namespace std;
using namespace libconfig;

SymbolGenCfg* SymbolGenCfg::_instance = nullptr;





/**
 * 
 */
SymbolGenCfg::SymbolGenCfg ( string fname_ ) :
			_version(""),
			_tickerLength(5)
{
	Config cfg;
	_logger = getLogger();
	IFTRACE(_logger->level())
	traceLogLoc(spdlog::get(LOGNAME));

	//
	// open the file
	// 
	try
	{
		IFDEBUG(_logger->level())
		_logger->info("CfgFile:{}", fname_);
		cfg.readFile(fname_.c_str());
	}
	catch (std::exception& ex_)
	{
		_logger->error("Unable to open:{}", fname_);
		string err = "unable to open file:";
		err += fname_;
		err += ", Error:";
		err += ex_.what();
		throw runtime_error(err);
	}



	//
	// general
	//
	_version = getValue<string>(cfg, "version");
	_tickerLength = getValue<int>(cfg, "ticker_length");



	//
	// output file stuff
	//
	_outputFileName = getValue<string>(cfg, "output_file_name");
	_outputFieldDelim = getValue<string>(cfg, "output_field_delimiter");
	_outputFileOverwrite = getValue<bool>(cfg, "output_file_overwrite");



	//
	// some debugging
	//
	IFINFO(_logger->level())
	_logger->info("version:{}", getVersion());

	IFDEBUG(_logger->level())
	{
		_logger->debug("TickeLength:{}", getNumberOfCharsInTicker());
		_logger->debug("OutputFileName:{}", getOutputFileName());
		_logger->debug("OutputFileDelim:{}", getOutputFileDelim());
	}

}





/**
 * 
 */
SymbolGenCfg::~SymbolGenCfg ()
{
}





/**
 * 
 */
shared_ptr<SymbolGenCfg> SymbolGenCfg::getInstance ( string cfgFile_ )
{
	if (_instance == nullptr)
	{
		_instance = new SymbolGenCfg(cfgFile_);
	}
	return make_shared<SymbolGenCfg>(*_instance);
}


