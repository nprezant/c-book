
SOURCES := $(shell find . -name "*.c")

BINS := $(SOURCES:.c=.out)

.PHONY: all
all: $(BINS)

%.out: %.c
	cc -g $< -o $@

.PHONY: clean
clean:
	rm -f *.out

.PHONY: perf-test
perf-test: all
	perf stat -d -r 10 ./3-01_binsearch.out kr
	perf stat -d -r 10 ./3-01_binsearch.out np
