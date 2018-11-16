link_test: linklist.h linklist.c link_test.c
	gcc $^ -o $@ -std=c99

.PHONY: clean

clean: link_test
	rm -f $^
