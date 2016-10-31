use PrimeC;
use ChinoisC;
use warnings;
use Data::Dumper;

PrimeC::processSieve(50000);
print( PrimeC::getNthPrime( 14 )."\n" );
print( PrimeC::getNthPrime( 56 )."\n" );
print( PrimeC::getNthPrime( 5000 )."\n" );
print( PrimeC::getNthPrime( 200 )."\n" );
print( PrimeC::getNthPrime( 4095 )."\n" );
print( PrimeC::getNthPrime( 5133 )."\n" );

my(%primes)=();
my($i)=0;
my($p)=0;
do
{
  $p=PrimeC::getNthPrime( $i++ );
  $primes{$p}=1;
}
while( $p < 45000 );

for( my($i)=3; $i<= 45000; $i+=2 )
{ 
  my($i1,$i2)=($i>>32,$i&0xffffffff);
  my($t)=ChinoisC::longChinoisTest( $i1, $i2 );
  if( $t==1 )
  {
    print "$i : Case Chinois test fails ... \n" if( !exists($primes{$i}));
  }
  else
  {
    print "$i : Bug in Chinois test \n" if( exists($primes{$i}));
  }
}

