CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic

ifeq ($(OS),Windows_NT)
    EXEEXT := .exe
else
    EXEEXT :=
endif

SRCS := $(wildcard *.cpp)

TARGETS := $(SRCS:%.cpp=%$(EXEEXT))

all: $(TARGETS)

%$(EXEEXT): %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

ASAN_FLAGS:= -fsanitize=address -g

asan: CXXFLAGS += $(ASAN_FLAGS)
asan: clean all

clean:
	rm -f $(TARGETS)
