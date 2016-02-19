#!/usr/bin/env perl


sub login {
  $username = $_[0];
  $password = $_[1];

  $username =~ tr/a-z/A-Z/; # conver to uppercase
  $username =~ s/\s.*//;        # strip everything after a space

  @output = `egrep "^$username" userdb.txt 2>&1`;
  foreach $line (@output) {
      ($usr, $pw) = split(/:/, $line);
  
      print('inner loop');
      if($pw =~ $password) {
          return 1;
      }
  }

  return 0;
}

login($ARGV[0], $ARGV[1]);
