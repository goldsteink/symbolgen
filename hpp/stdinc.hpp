/**
 * Kevin A. Goldstein R. (kevgol0@gmail.com)
 *
 * FILE:   stdinc.hpp
 * DSCRPT: comment
 */

#ifndef __STDINC_HPP__
#define __STDINC_HPP__

#define LOGNAME "console"

#include <string>
using namespace std;


#include <spdlog/spdlog.h>
#define getLogger() (spdlog::get(LOGNAME))
#define traceLogLoc(a) (a->debug("{}:{}", __PRETTY_FUNCTION__, __LINE__))

#define IFTRACE(lvl) if (lvl<=spdlog::level::trace)
#define IFDEBUG(lvl) if (lvl<=spdlog::level::debug)
#define IFINFO(lvl) if (lvl<=spdlog::level::info)
#define IFWARN(lvl) if (lvl<=spdlog::level::warn)


#endif /* __STDINC_HPP__ */
