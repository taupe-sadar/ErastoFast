FLAGS = -Wall -g -O0

all : test PrimeC.pm ChinoisC.pm

PrimeC.pm : Prime.c writeInlineScript.pl
	perl writeInlineScript.pl Prime.c PrimeC.pm PrimeC

ChinoisC.pm : Chinois.c writeInlineScript.pl
	perl writeInlineScript.pl Chinois.c ChinoisC.pm ChinoisC
  
Chinois.o : Chinois.c
	gcc Chinois.c -o Chinois.o -c $(FLAGS)

Prime.o : Prime.c
	gcc Prime.c -o Prime.o -c $(FLAGS)

test : test.o Prime.o Chinois.o
	gcc Prime.o test.o Chinois.o -o test $(FLAGS)

test.o : test.c Prime.h 
	gcc test.c -o test.o -c $(FLAGS)

clean :
	rm -rf *.o Prime test PrimeC.pm
