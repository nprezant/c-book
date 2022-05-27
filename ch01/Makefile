
SOURCES := hello.c

BINS := $(SOURCES:.c=.out)

.PHONY: all
all: $(BINS)

%.out: %.c
	cc $< -o $@

.PHONY: clean
clean:
	rm -f *.out
