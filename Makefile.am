bin_PROGRAMS=sybmolgen
sybmolgen_SOURCES=\
	hpp/SymbolGenerator.hpp \
	cpp/SymbolGenerator.cpp \
	cpp/main_symbolgen.cpp

if DEBUG
CFLAGS = -O0
AM_CFLAGS = -g3 -O0 -pg
AM_CXXFLAGS = -g3 -O0 -pg
endif


AM_CXXFLAGS = -I$(top_srcdir)/hpp 