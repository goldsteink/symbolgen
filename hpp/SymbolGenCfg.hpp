/**
 * Kevin A. Goldstein R. (kevgol0@gmail.com)
 *
 * FILE:   SymbolGen.hpp
 * DSCRPT: comment
 */

#ifndef __SYMBOLGEN_HPP__
#define __SYMBOLGEN_HPP__

#include <string>
#include <libconfig.h++>

#include <memory>
#include <spdlog/spdlog.h>

#include "hpp/stdinc.hpp"

using namespace std;
using namespace spdlog;
using namespace libconfig;



class SymbolGenCfg
{
	private:
		static SymbolGenCfg* _instance;


		shared_ptr<logger> _logger;

		string _version;
		string _outputFileName;
		string _outputFieldDelim;
		bool _outputFileOverwrite;
		int _tickerLength;


	private:
		SymbolGenCfg ( string cfgfile_ );

	public:
		virtual ~SymbolGenCfg ();
		static shared_ptr<SymbolGenCfg> getInstance ( string cfgFile_ = "./etc/symbolgen.cfg" );

	public:
		inline int getNumberOfCharsInTicker ();
		inline bool getOutputFileOverwrite ();

		inline string getVersion ();
		inline string getOutputFileName ();
		inline string getOutputFileDelim ();


	public:
		template<class T>
			T getValue ( Config& cfg_, string key_ )
			{
				try
				{
					T rv = cfg_.lookup(key_);
					return rv;
				}
				catch (libconfig::SettingNotFoundException& snf_)
				{
					getLogger()->error("Key:{}, Error:{}", key_, snf_.what());
					throw invalid_argument(key_);
				}
				catch (libconfig::ParseException& pex_)
				{
					getLogger()->error("Key:{}, Error:{}", key_, pex_.what());
					throw invalid_argument(key_);
				}
				catch (libconfig::SettingTypeException& ste_)
				{
					getLogger()->error("Key:{}, Error:{}", key_, ste_.what());
					throw invalid_argument(key_);
				}
				catch (libconfig::ConfigException& cex_)
				{
					getLogger()->error("Key:{}, Error:{}", key_, cex_.what());
					throw invalid_argument(key_);
				}
				catch (std::exception& ex_)
				{
					getLogger()->error("Key:{}, Error:{}", key_, ex_.what());
					throw invalid_argument(key_);
				}
			}
};





/////////////////////////////////////////////////////
//
/////////////////////////////////////////////////////
inline bool SymbolGenCfg::getOutputFileOverwrite ()
{
	return _outputFileOverwrite;
}

string SymbolGenCfg::getVersion ()
{
	return _version;
}

inline int SymbolGenCfg::getNumberOfCharsInTicker ()
{
	return _tickerLength;
}

inline string SymbolGenCfg::getOutputFileName ()
{
	return _outputFileName;
}

inline string SymbolGenCfg::getOutputFileDelim ()
{
	return _outputFieldDelim;
}

#endif /* __SYMBOLGEN_HPP__ */

