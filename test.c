#include "Prime.h"
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
    printf( "%d\n", prime ) ;
    count++;
  }


  freeSieve();
  
  return 0;
}
