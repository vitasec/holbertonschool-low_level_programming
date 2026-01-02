#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - stringin uzunlugunu heasb edir
 *
 *@s: string
 * Return: uzunluq
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - stringi kopyalayır
 * @dest: hədəf
 * @src: mənbə
 * Return: hədəf pointeri
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - yeni it yaradır
 * @name: itin adı
 * @age: itin yaşı
 * @owner: sahibinin adı
 * Return: yeni it strukturunun ünvanı, yoxsa NULL
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int name_l, owner_l;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_l = _strlen(name);
	owner_l = _strlen(owner);

	d->name = malloc(sizeof(char) * (name_l + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(sizeof(char) * (owner_l + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
