#include <iostream>

class animals
{
    enum Diet_preference
    {
        Herbivore,
        Carnivore,
        Omnivore
    };

    float avg_sleep;
    int limbs;
};

class amphibians : protected animals
{
};

class mammal : protected animals
{
};

class reptile : protected animals
{
};
