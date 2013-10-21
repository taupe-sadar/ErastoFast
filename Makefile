FLAGS = -Wall -g -O0

all : test PrimeC.pm

PrimeC.pm : Prime.c writeInlineScript.pl
	perl writeInlineScript.pl Prime.c PrimeC.pm 

Prime.o : Prime.c
	gcc Prime.c -o Prime.o -c $(FLAGS)

test : test.o Prime.o
	gcc Prime.o test.o -o test $(FLAGS)

test.o : test.c Prime.h 
	gcc test.c -o test.o -c $(FLAGS)

clean :
	rm -rf *.o Prime test
