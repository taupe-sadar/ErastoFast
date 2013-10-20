#include "Prime.h"
#include "stdio.h"

int main( int  argc, char ** argv )
{
  int i = 0; 
  processSieve( 12000 );
  processSieve( 3000 );
  printf( "-----------------\n" );
  for( ; i < 100; i++ )
  {
    printf( "%d\n", getNthPrime( i ) );
  }
  
  
  return 0;
}
