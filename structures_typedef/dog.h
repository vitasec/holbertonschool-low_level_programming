#ifndef DOG_H
#define DOG_H

/**
* struct dog-melumatlarin saxlayir
*@name: adi
*@age: yasi
*@owner: sahibi
*
*Description: itinin adi,yasi ve sahibi ozunde saxlayan struktur
*/

struct dog
{
char *name;
float age;
char *owner;
};

typedef  struct dog dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);


#endif
