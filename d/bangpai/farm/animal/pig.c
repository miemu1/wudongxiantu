#include "animal.h"

mapping animal_info = ([
    "name" : "��",
    "id" : "pig",
    "time" : 3600,
    "meat" : 5,
    "meat_name" : "zhurou",
]);

void create()
{
    create_animal(animal_info);
}