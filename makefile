headlink_test: headlinklist.h headlinklist.c headlink_test.c
	gcc $^ -o $@ -std=c99

.PHONY: clean

clean: headlink_test
	rm -f $^
