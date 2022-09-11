.PHONY: clean

run: lex.yy.c myscanner.c util.c
	gcc myscanner.c -o run

lex.yy.c: mylang.l
	flex mylang.l

clean:
	rm -f run *.o
