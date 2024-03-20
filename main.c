#include <stdio.h>
#include <stdlib.h>

#include "array.h"
#include "mesa.h"


/**
	argc = number of arguments
	argv = the actual arguments
		argv[0] = the name of your executable
		argv[1] = the first argument to your executable on the command line
		argv[2] = the second argument to your executable
		etc.
*/
int main(int argc, char* argv[])
{
	if ( argc != 3 )
	{
		fprintf( stderr, "Usage: %s <input-file> <output-file>\n", argv[0] );
		exit(1);
	}

	//Opening the files 
	FILE* in = fopen( argv[1], "r" );
	FILE* out = fopen( argv[2], "w" );

	int set = 1;

	while( !feof(in) )
	{

		unsigned int size=0;
		unsigned int* numbers=create_array(in, &size);
		if(size==0){
			break;
		}
		//print header for each Mesa in output file
		fprintf(out,"Set %d\n", set++ );
		for ( int i = 0; i < 55; i++)
			fputs("-", out);
		fputs("\n", out);
		//-----------------------------------------

		


		read_data(in, numbers, size);

		unsigned int length;
		unsigned int height;
		
		struct Mesa m = find_mesa(in, numbers, size, &length, &height);
		fprintf(out,"Min Length: %d  Min Height: %d\n", length, height);
		display_data(out, size, numbers);
		display_mesa(out, m);
		free_memory(numbers);
		

	}

	fclose(in);
	fclose(out);

	return 0;
}
