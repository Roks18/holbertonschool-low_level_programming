
#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to the new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *dog;
    unsigned int i, j;

    if (name == NULL || owner == NULL)
        return (NULL);

    dog = malloc(sizeof(dog_t));
    if (dog == NULL)
        return (NULL);

    i = 0;
    while (name[i] != '\0')
        i++;

    dog->name = malloc(sizeof(char) * (i + 1));
    if (dog->name == NULL)
    {
        free(dog);
        return (NULL);
    }

    for (i = 0; name[i] != '\0'; i++)
        dog->name[i] = name[i];
    dog->name[i] = '\0';

    j = 0;
    while (owner[j] != '\0')
        j++;

    dog->owner = malloc(sizeof(char) * (j + 1));
    if (dog->owner == NULL)
    {
        free(dog->name);
        free(dog);
        return (NULL);
    }

    for (j = 0; owner[j] != '\0'; j++)
        dog->owner[j] = owner[j];
    dog->owner[j] = '\0';

    dog->age = age;

    return (dog);
}

