#include "Prime.h"
#include "stdio.h"

int main( int  argc, char ** argv )
{
  processSieve(50000);
  printf( "%d\n", getNthPrime( 14 ) );
  printf( "%d\n", getNthPrime( 56 ) );
  printf( "%d\n", getNthPrime( 5000 ) );
  printf( "%d\n", getNthPrime( 200 ) );
  printf( "%d\n", getNthPrime( 4095 ) );
  printf( "%d\n", getNthPrime( 5133 ) );
  
  
  return 0;
}
