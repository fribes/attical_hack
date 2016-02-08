
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void process(char *buffer, int length);

void process(char *buffer, int length)
{
  unsigned int key;
  int i;

  key = length & 0xff;

  for(i = 0; i < length; i++) {

      buffer[i] ^= key;
      key -= buffer[i];
  }

}

void main(int argc, char* argv[])
{
	char buf[2];
	int i,j,k;

	for ( i='A'; i<='z'; i++)
	{

		for ( j='A'; j<='z'; j++)
		{

			for ( k='A'; k<='z'; k++)
			{

				buf[0] = i;
				buf[1] = j;
				buf[2] = k;

				process(buf, 3);

				if (buf[2] == 0)
					printf ("=> %c%c%c <= \n", i, j,k);

			}
		}

	}
}
