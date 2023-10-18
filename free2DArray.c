#include "shell.h"
/**
 * free2DArray - Deallocate memory used by a 2D array.
 * @array2d: The 2D array to be deallocated.
 */
void free2DArray(char **array2d)
{
	int i;

	if (!array2d)
	return;

	for (i = 0; array2d[i]; i++)
	{
		free(array2d[i]);
		array2d[i] = NULL;
	}
	free(array2d), array2d = NULL;
}
