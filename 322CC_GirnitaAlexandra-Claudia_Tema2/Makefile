# Exemplu de Makefile pentru soluții scrise în C++.

CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: p1 p2 p3 p4

# Nu compilați aici, nici măcar ca dependențe de reguli.
run-p1:
	./p1
run-p2:
	./p2
run-p3:
	./p3
run-p4:
	./p4

# Schimbați numele surselor (și, eventual, ale executabilelor - peste tot).
p1: supercomputer.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: ferate.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: teleportare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: magazin.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f p1 p2 p3 p4

