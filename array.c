
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

unsigned int *create_array(FILE *in, unsigned int *size)
{
    fscanf(in, "%u", size);
    return (unsigned int *)malloc(*size * sizeof(unsigned int));
}

unsigned int *free_memory(unsigned int *pointer)
{
    free(pointer);
    return NULL;
}

void read_data(FILE *in, unsigned int *data, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
        fscanf(in, "%u", &data[i]);

    /*get rid of the newline -- the * indicates to ignore this
    field that was read in via fscanf*/
    fscanf(in, "%*c");
}

#define MAX_COLUMNS 10

void display_data(FILE *out, unsigned int count, unsigned int *data)
{

    int num_columns = 0;
    // Need to figure out how many columns to print
    if (count <= MAX_COLUMNS)
    {
        num_columns = count;
    }
    else
    {
        num_columns = MAX_COLUMNS;
    }
    // Printing the data in the correct format
    for (int i = 0; i < num_columns; ++i)
    {
        fprintf(out, " %d ", i);
    }

    int num_rows = 0;
    for (unsigned int i = 0; i < count; ++i)
    {
        if (i % MAX_COLUMNS == 0)
        {
            fprintf(out, "\n %d ", num_rows++);
        }
        fprintf(out, " %d ", data[i]);
    }
}
