#define the C compiler to use
GXX = g++

# define any compile-time flags
CFLAGS = -std=c++11 -Wall -g `pkg-config --cflags opencv`

# define any directories containing header files other than /usr/include
#
INCLUDES = -I/usr/local/include  -I../include

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LDFLAGS = -L/usr/local/lib  -L../lib

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option:
LIBS = `pkg-config --libs opencv`

# define the CXX source files
SRCS = face.cpp

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file 
TARGET = face

#
# The following part of the makefile is generic; it can be used to 
# build any executable.
#

.PHONY: clean

all:    $(TARGET)
	@/bin/true

$(TARGET): $(OBJS)
	$(GXX) -std=c++11 -o $@ $^ $(LDFLAGS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
		$(GXX) $(CFLAGS) $(INCLUDES) -cpp $<  o $@

clean:
		rm $(TARGET)
