#include "mesa.h"
#include "array.h"

// Helper function that checks if the mesa is valid in the range both inclusive returns an int 0 if not valid 1 if valid
static int check_valid_mesa_in_range(unsigned int const *numbers, unsigned int start, unsigned int end, unsigned int min_height)
{
    // Early escape other condition ensures that if it passes through that it is a valid mesa
    if (numbers[start] < min_height)
    {
        return 0;
    }
    for (unsigned int i = start; i < end; ++i)
    {

        if (numbers[i] != numbers[i + 1])
        {
            return 0;
        }
    }
    return 1;
}

static unsigned int find_max_mesa_weight_index(unsigned int const *numbers, unsigned int const *start_index, unsigned int const *end_index, unsigned int count)
{
    if (count == 1)
    {
        return 0;
    }
    unsigned int max_weight = numbers[start_index[0]] * (end_index[0] - start_index[0] + 1);
    unsigned int max_weight_index = 0;

    for (unsigned int i = 1; i < count; ++i)
    {

        if (numbers[start_index[i]] * (end_index[i] - start_index[i] + 1) > max_weight)
        {

            max_weight = numbers[start_index[i]] * (end_index[i] - start_index[i] + 1);
            max_weight_index = i;
        }
    }
    return max_weight_index;
}

struct Mesa find_mesa(FILE *in, unsigned int *numbers, unsigned int count, unsigned int *length, unsigned int *height)
{

    struct Mesa m;
    // Reading in the minimum length and height of mesa
    fscanf(in, "%u %u", length, height);

    // If length > count then there can't possibly be any valid mesa so early return
    if (*length > count)
    {
        m.valid = false;
        return m;
    }
    // Create two arrays that have all possible maximum mesa based on validity of length
    // note that 'worst' case scenario is that length is 1 hence any 'singleton' is a valid mesa so
    // creating two arrays with length count will always suffice
    unsigned int *start_array = (unsigned int *)malloc(count * sizeof(unsigned int));
    unsigned int *end_array = (unsigned int *)malloc(count * sizeof(unsigned int));
    unsigned int num_mesa = 0;

    for (unsigned int i = 0; i < count - *length + 1; ++i)
    {
        unsigned int delta = 0;
        while (check_valid_mesa_in_range(numbers, i, i + *length + delta - 1, *height))
        {
            delta++;
        }
        if (delta > 0)
        {
            start_array[num_mesa] = i;
            end_array[num_mesa] = i + *length + delta - 2;
            num_mesa++;
            i = i + *length + delta - 2;
        }
    }
    if (num_mesa == 0)
    {
        m.valid = false;
        return m;
    }

  
    unsigned int max_weight_index = find_max_mesa_weight_index(numbers, start_array, end_array, num_mesa);
    m.start = start_array[max_weight_index];
    m.end = end_array[max_weight_index];
    m.height = numbers[start_array[max_weight_index]];
    m.weight = numbers[start_array[max_weight_index]] * (end_array[max_weight_index] - start_array[max_weight_index] + 1);
    m.valid = true;
    free(start_array);
    free(end_array);
    return m;
}

void display_mesa(FILE *out, struct Mesa m)
{
    if (m.valid)
    {
        fprintf(out, "\nStart End Height Weight\n %d %d %d %d \n \n", m.start, m.end, m.height, m.weight);
    }
    else
    {
        fprintf(out, "\nNo valid mesa found\n\n");
    }
}
