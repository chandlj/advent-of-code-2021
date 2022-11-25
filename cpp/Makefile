CXX := clang++
RM := rm -f

COMMONFLAGS := -Wall -Werror -Wextra -Wno-sign-compare
CPPFLAGS := $(COMMONFLAGS) -std=c++17 -stdlib=libc++ -g
LDFLAGS := $(COMMONFLAGS) -std=c++17 -lm

SRCS := $(wildcard day*.cpp)
TARGETS := $(SRCS:%.cpp=bin/%)

.PHONY: all clean

all: $(TARGETS)

bin/%: %.cpp utils.cpp utils.hh
	$(CXX) $(CPPFLAGS) utils.cpp $< -o $@

clean:
	$(RM) -R $(TARGETS)
