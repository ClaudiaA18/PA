CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: p1 p2 p3 p4

run-p1:
	./p1
run-p2:
	./p2
run-p3:
	./p3
run-p4:
	./p4

# Nu uitați să modificați numele surselor și, eventual, ale executabilelor.
p1: feribot.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: nostory.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: sushi.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: semnale.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

# Vom șterge executabilele.
clean:
	rm -f p1 p2 p3 p4
