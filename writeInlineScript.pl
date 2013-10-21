use warnings;
use Data::Dumper;

$#ARGV == 1 or die "Usage : $0 inputFile outputFile\n";
open( CFILE, $ARGV[0] ) or die "Cannot open $ARGV[0]";
open( PERLFILE, "> $ARGV[1]" ) or die "Cannot open $ARGV[1]";

print PERLFILE startOfPerlFile();

my($line);
my($mode_skip)=0;
while( defined( $line = <CFILE> ) )
{
  chomp($line);
  if( $line eq "// --- TO BE REMOVED BY MAKEFILE ---")
  {
    $mode_skip = 1;
  }
  elsif( $line eq "// --- END OF TO BE REMOVED ---")
  {
    $mode_skip = 0;
  }
  elsif( $mode_skip == 0 )
  {
    print PERLFILE "$line\n";
  }
}

print PERLFILE "END_C\n";
print PERLFILE "1;\n";

close( PERLFILE );
close( CFILE);

sub startOfPerlFile
{
  return 'package PrimeC;
use warnings;
use strict;

use Inline C => <<\'END_C\';

';
}
