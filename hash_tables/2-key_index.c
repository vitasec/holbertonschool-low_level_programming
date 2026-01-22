#include "hash_tables.h"

/**
 * key_index - Gives the index of a key in the hash table array.
 * @key: The key (string) to get the index for.
 * @size: The size of the array of the hash table.
 *
 * Return: The index at which the key/value pair should be stored.
 * Description: Uses the djb2 algorithm to calculate the hash and
 * then calculates the index using modulo operation.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash;

	/* 1. djb2 funksiyasını çağıraraq böyük heş rəqəmini alırıq */
	hash = hash_djb2(key);

	/* 2. Həmin rəqəmi massivin ölçüsünə bölüb qalığı qaytarırıq */
	/* Bu qalıq həmişə 0 və (size - 1) arasında olacaq */
	return (hash % size);
}
