use PrimeC;
use warnings;
use Data::Dumper;

PrimeC::processSieve(50000);
printf( "%d\n", PrimeC::getNthPrime( 14 ) );
printf( "%d\n", PrimeC::getNthPrime( 56 ) );
printf( "%d\n", PrimeC::getNthPrime( 5000 ) );
printf( "%d\n", PrimeC::getNthPrime( 200 ) );
printf( "%d\n", PrimeC::getNthPrime( 4095 ) );
printf( "%d\n", PrimeC::getNthPrime( 5133 ) );
