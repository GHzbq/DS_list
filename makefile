dseq_test: dseqlist.h dseqlist.c dseq_test.c
	gcc $^ -o $@ -std=c99

.PHONY: clean

clean: dseq_test
	rm -f $^
