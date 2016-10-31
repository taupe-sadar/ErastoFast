#include "Prime.h"
#include "Chinois.h"
#include "stdio.h"

static int index = 0;
int crible_size = 30;
int next_prime()
{
  while( index >=  getNumCalculatedPrimes()  )
  {
    crible_size*=2;
    processSieve( crible_size );
  }
  
  int p = getNthPrime( index );
  
  index ++;
  return p;
  
};

int main( int  argc, char ** argv )
{
  
  int count =0;
  int number = 10001;
  
  while(count<number)
  {
    int prime = next_prime();
    //printf( "%d\n", prime ) ;
    
    count++;
    if( !longChinoisTest( 0,prime ) && prime !=2 )
    {
      printf( "Chinois bug 'not prime' : for %d\n", prime ) ;
    }
  }
  freeSieve();
  
  int i;
  for( i = 3; i < 200; i+=2 )
  {
    if( !longChinoisTest( 0,i ) )
      printf( "Chinois not prime : %d\n", i ) ;
  }

  return 0;
}
