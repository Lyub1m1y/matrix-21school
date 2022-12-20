.SUFFIXES:

UNAME:=$(shell uname -s)

CC=@gcc
CFLAGS=-std=c11 -Wall -Werror -Wextra

OBJ_DIR=obj/
RECURSIVE_C=/*.c /*/*.c /*/*/*.c /*/*/*/*.c

IGNORE_ERRORS=-Wno-format \
	-Wno-unused-but-set-parameter \
	-Wno-unused-but-set-variable \
	-Wno-unused-parameter \
	-Wno-unused-function \
	-Wno-unused-variable \
	-Wno-return-type

# C to Objects

$(OBJ_DIR)%.o: %.c
	@mkdir -p -- "$(dir $@)"
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

# Library source code

SRC=$(wildcard *.c \
	$(addprefix cs, $(RECURSIVE_C)) \
	$(addprefix internal, $(RECURSIVE_C)) \
	$(addprefix io, $(RECURSIVE_C)) \
	$(addprefix matrix, $(RECURSIVE_C)))

OBJ=$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

# Test source code

SRC_TEST=$(wildcard $(addprefix tests, $(RECURSIVE_C)))

OBJ_TEST=$(addprefix $(OBJ_DIR), $(SRC_TEST:.c=.o))

# Standard targets

all: s21_matrix.a
rebuild: clean all
clean:
	@rm -f -- s21_matrix.a libs21_matrix.a test *.o $(OBJ) $(OBJ_TEST)
	@rm -rf -- gcov_report $(OBJ_DIR) $(wildcard *.dSYM *.gcno)

# Library target

s21_matrix.a: CFLAGS += -fPIC
s21_matrix.a: $(OBJ)
	@ar rcs $@ $^
	@cp $@ lib$@

# Test target

build_test: CFLAGS += -D_GNU_SOURCE -ggdb3 -fsanitize=address -g
build_test: $(OBJ_TEST) s21_matrix.a
ifeq ($(UNAME), Linux)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -lcheck -lpthread -lsubunit -lrt -lm -o test
else
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -lcheck -o test
endif

test: build_test
	@./test

# Gcov target

build_gcov_report: CFLAGS += -DUNIT_TESTING -ggdb3 -fPIC -O0 --coverage
build_gcov_report: $(OBJ_TEST) s21_matrix.a
	@mkdir -p -- gcov_report
ifeq ($(UNAME), Linux)
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -lcheck -lpthread -lsubunit -lrt -lm -o gcov_report/test
else
	$(CC) $^ $(CFLAGS) $(CPPFLAGS) -lcheck -o gcov_report/test
endif
	@./gcov_report/test
	lcov -c -b . -t gcov_report/test -o gcov_report/report.info -d $(OBJ_DIR) --rc lcov_branch_coverage=1
	genhtml -o gcov_report/ gcov_report/report.info

gcov_report: build_gcov_report
	open gcov_report/index.html

# Tools

build_dev: CFLAGS += -ggdb3 -DUNIT_TESTING $(IGNORE_ERRORS)
build_dev: clean build_test

dev: clean build_dev
	@./test

check_style:
	clang-format -style=Google -n **/*.c **/*.h
