ACLOCAL_AMFLAGS = -I m4


bin_PROGRAMS = symbolgen
symbolgen_SOURCES = \
	hpp/SymbolGenerator.hpp \
	hpp/SymbolGenCfg.hpp \
	cpp/SymbolGenerator.cpp \
	cpp/SymbolGenCfg.cpp \
	cpp/main_symbolgen.cpp


symbolgen_LDFLAGS = \
	$(LIBCONFIGXX_LIBS) \
	$(SPDLOG_LIBS) \
	-lpthread

	
if DEBUG
AM_CFLAGS = -g3 -O0 -I$(top_srcdir)/hpp
AM_CXXFLAGS = -g3 -O0 -I$(top_srcdir)/hpp
else
AM_CFLAGS = -O2 -I$(top_srcdir)/hpp
AM_CXXFLAGS = -O2 -I$(top_srcdir)/hpp
endif