

MODULES = oj_ftile
EXTENSION = oj_ftile
DATA = oj_ftile--1.0.sql

subdir = contrib/oj_ftile
top_builddir = ../..
include $(top_builddir)/src/Makefile.global

MODULE_big = oj_ftile
PG_CPPFLAGS = -I$(libpq_srcdir)
OBJS  = ftile.o 
SHLIB_LINK = $(libpq)


include $(top_srcdir)/contrib/contrib-global.mk




