CC=g++
CPPFLAGS+=-std=c++11 -Wall -Wextra -Werror -lm

.PHONY: all
all: main
main: main.cpp Teacher.cpp Student.cpp Book.cpp

.PHONY: clean
clean:
	rm -f main
