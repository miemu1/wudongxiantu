#include "food.h"

mapping food_info = ([
	"name" : "С����",
	"id" : "ksbc",
	"need" : (["zhurou" : 2, "xiaomai" : 5, ]),
	"time" : 300,
	"unit" : "��",
	]);

void create()
{
    set("no_buff", 1);
	create_food(food_info);
}