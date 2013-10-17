// --- TO BE REMOVED BY MAKEFILE ---
#include "stdio.h"
#include "stdlib.h"
#define Newx( x , y , z ) x = malloc( y*sizeof(z))
#define Safefree( x )     free( x )
// --- END OF TO BE REMOVED ---
#define MODULO     30

int offsets[8] = { 1 , 7 , 11 , 13 , 17 ,19 , 23, 29 };

unsigned char maskForCrossing[ MODULO ] = {
  0, 0xfe, 0, 0, 0, 0,
  0, 0xfd, 0, 0, 0, 0xfb,
  0, 0xf7, 0, 0, 0, 0xef,
  0, 0xdf, 0, 0, 0, 0xbf,
  0,    0, 0, 0, 0, 0x7f  
};

typedef struct SieveSegment
{
  unsigned char sieve;
} SieveSegment;

SieveSegment * eratSieveSegment;
int eratSize = 0;

//Array for stocking primes. Must be done dynamically <- TODO
int primeStock[4096] = { 2, 3 , 5 };
int numPrimes = 3;

int sieveCurrentIdx = 0;
int bigPrimeOffset = 0;

int count = 0;

void init_sieve()
{
  int i;
  sieveCurrentIdx = 0;
  bigPrimeOffset = 0;

  eratSieveSegment[ 0 ].sieve = 0xfe; //Considering 1 not as a prime
  for( i = 1; i < eratSize ; i++ ){
    eratSieveSegment[ i ].sieve = 0xff;
  }
}

int primesInNextSegment( int* primes )
{
  unsigned char sieveSeg = eratSieveSegment[ sieveCurrentIdx ].sieve;
  
  int idx = 0;
  int num = 0;
  while( sieveSeg > 0 ) 
  {
    if( sieveSeg & 0x01 )
    {
      primes[ num ++ ] = bigPrimeOffset + offsets[ idx ];
    }
    sieveSeg >>= 1;
    idx++;
  }
  return num;
}

void crossSieve( int prime )
{
  int idxInOffsets = 1;
  int largeModuloOffset = 0;
  int multiple = offsets[ idxInOffsets ]* prime;
  while( multiple < MODULO * eratSize )
  {
    eratSieveSegment[ multiple / MODULO ].sieve &= maskForCrossing[ multiple % MODULO ] ;
    idxInOffsets ++;
    if( idxInOffsets == 8 )
    {
      idxInOffsets = 0; 
      largeModuloOffset += MODULO;
    }
    multiple = prime*( largeModuloOffset +  offsets[ idxInOffsets ] );
  }
}

void processSieve( int sieveSize )
{
  count ++;
  eratSize = ( sieveSize + MODULO - 1 )/MODULO;
  Newx(eratSieveSegment, eratSize , SieveSegment);
  init_sieve();
  printf( "%d\n", 2 );
  printf( "%d\n", 3 );
  printf( "%d\n", 5 );
  while( sieveCurrentIdx < eratSize ) 
  {
    int nextPrimes[8];
    int numPrimes = primesInNextSegment( nextPrimes );
    int i;
    //printf( "-> %02x <-\n", eratSieveSegment[ sieveCurrentIdx ] );
    for( i = 0 ; i < numPrimes; i ++ )
    {
      printf( "%d\n", nextPrimes[ i ] );
      crossSieve( nextPrimes[ i ] );
    }
    
    bigPrimeOffset += MODULO;
    sieveCurrentIdx++;
  }
  printf("%d\n",count);
  Safefree( eratSieveSegment );
}
