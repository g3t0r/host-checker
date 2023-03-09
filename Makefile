CC := gcc

default: clean build

.PHONY: clean
clean:
	rm -rf host-checker

.PHONY: build
build:
	$(CC) src/*.c -o host-checker
