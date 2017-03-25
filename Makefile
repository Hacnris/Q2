TEST = test.c levenshtein.c table.c engine.c
SUGGEST = suggest.c levenshtein.c table.c engine.c
OBJ_TEST = $(TEST:.c=.o)
OBJ_SUGGEST = $(SUGGEST:.c=.o)

CFLAGS = -g -Wall

LFLAGS = -Wall -Wno-format-y2k -W -Wstrict-prototypes \
    -Wpointer-arith -Wreturn-type -Wcast-qual -Wwrite-strings -Wswitch \
    -Wshadow -Wcast-align -Wbad-function-cast -Wchar-subscripts -Winline \
    -Wnested-externs -Wredundant-decls

COVFLAGS = -Wall -fprofile-arcs -ftest-coverage

test: $(OBJ_TEST)
	$(CC) $(OBJ_TEST) -o $@

suggest: $(OBJ_SUGGEST)
	$(CC) $(OBJ_SUGGEST) -o $@

coverage: $(OBJ_TEST)
	gcc $(COVFLAGS) $(TEST) -o $@

.SUFFIXES: .c .o
.c.o:
	$(CC) $< $(CFLAGS) -c -o $@

run-coverage: coverage
	./coverage && gcov levenshtein

run-test: test
	./test

run-suggest: suggest
	./suggest sitting kitten

clean:
	rm -f coverage test suggest $(OBJ_TEST) $(OBJ_EXAMPLE) *.gc{ov,da,no}

.PHONY: clean run-coverage run-test
