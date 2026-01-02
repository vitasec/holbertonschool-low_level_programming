#include <stdlib.h>
#include "dog.h"

/**
*free_dog - it  ucunu ayrilan yaddasi azad edir
*@d: azad edilecen itin unvani
*
*Description: birinic icindeki elementleri silir
*sonra ozunu silir
*/

void free_dog(dog_t *d)
{
	if (d == NULL)
		return;
	if (d->name != NULL)
		free(d->name);
	if (d->owner != NULL)
		free(d->owner);
	free(d);
}
