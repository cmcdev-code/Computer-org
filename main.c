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

	//open input and output files here
	

	//-------------------------------

	//get data from input file in a format you can use it for the first set
	//HINT: what functions are you creating in other files?
	

	//--------------------------------
	

	int set = 1;

	while( !feof(in) )
	{
		//print header for each Mesa in output file
		fprintf(out,"Set %d\n", set );
		for ( int i = 0; i < 55; i++)
			fputs("-", out);
		fputs("\n", out);
		//-----------------------------------------

		
		//find the largest Mesa
		

		//------------------------
		
		//print all necessary information about the minimum length and height of the Mesas
		//print the largest Mesa if there is a valid one
		//otherwise, print that there is no valid Mesa
		//(see the examples in the assignment spec)


		//------------------------
		

		//clean up any memory used for the first iteration

		//------------------------

		
		//get data from input file in a format you can use it for the next set
		//HINT: what functions are you creating in other files?
	

		//------------------------
	}

	//clean up memory for the last iteration
	
	//-----------------------


	//close input and output files here
	

	//-----------------------

	return 0;
}
