PREFIX = ../build/out
CC = gcc
CC_FLAGS = -Wall -I${PREFIX}/include -L${PREFIX}/lib -ldill -o

install: 
	@cd ../build && $(MAKE) && $(MAKE) install

out: install ${test_file}
	${CC} ${test_file} ${CC_FLAGS} $@

run: out
	@echo "\n------running-------\n"
	LD_LIBRARY_PATH=${PREFIX}/lib ./$^
