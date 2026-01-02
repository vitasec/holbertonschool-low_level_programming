#include "dog.h"
#include <stddef.h>

/**
 * init_dog - struct dog tipində dəyişəni başladır
 * @d: Başladılacaq itin ünvanı
 * @name: İtin adı
 * @age: İtin yaşı
 * @owner: İtin sahibi
 *
 * Description: Bu funksiya d pointeri vasitəsilə it info yazir.
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
