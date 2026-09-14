BASE = asst1

all: $(BASE)

OS := $(shell uname -s)

HOMEBREW_PREFIX ?= /opt/homebrew
ifeq ($(OS), Linux)
  LIBS += -lGL -lGLU -lGLEW -lglfw
endif

ifeq ($(OS), Darwin)
  CXX = clang++ 
  CPPFLAGS += -D__MAC__ -std=c++11 -stdlib=libc++ 
  CPPFLAGS += -I$(HOMEBREW_PREFIX)/include 
  LDFLAGS += -L$(HOMEBREW_PREFIX)/lib 
  LDFLAGS += -framework OpenGL -framework IOKit -framework Cocoa -framework CoreVideo 
  LIBS += -lglfw -lGLEW 
endif

ifdef OPT
  #turn on optimization
  CXXFLAGS += -O2
else
  #turn on debugging
  CXXFLAGS += -g
endif

OBJ = $(BASE).o ppm.o glsupport.o

$(BASE): $(OBJ)
	$(LINK.cpp) -o $@ $^ $(LIBS)

clean:
	rm -f $(OBJ) $(BASE)
