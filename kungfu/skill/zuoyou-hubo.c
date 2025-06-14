// zuoyou-hubo.c 左右互博
// by Doing Lu

inherit SKILL;

#include <ansi.h>

#define LEVEL_PER_LAYER	 30
#define MAX_LAYER	       12

string type() { return "special"; }

int valid_learn(object me)
{
	int layer;
	int lvl;

	lvl = me->query_skill("zuoyou-hubo", 1);
	
	if (me->query("gender") == "无性" && lvl >= 50)
		return notify_fail("你默默凝神，试图分心二用，可是却觉得阴阳失调，心浮气躁。\n");

	if (lvl >= MAX_LAYER * LEVEL_PER_LAYER)
		return notify_fail("你的左右互博之术已经修炼的炉火纯青，再难进步了。\n");

	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;

	return 1;
}
int valid_research(object me)
{
	return notify_fail("左右互博只能通过学习不断提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("左右互博只能通过学习不断提高。\n");
}

void skill_improved(object me)
{
	int lvl;
	int layer;

	lvl = me->query_skill("zuoyou-hubo", 1);
	layer = lvl / LEVEL_PER_LAYER;
	if (layer > MAX_LAYER) layer = MAX_LAYER;
	
	if (! layer)
	{
		tell_object(me, HIM "你潜心领悟左右互"
				"博，若有所悟。"NOR"\n");
	} else
	if ((lvl % LEVEL_PER_LAYER) == 0)
	{
		tell_object(me, HIM "你领悟了第" + chinese_number(layer) +
			    "层境界的左右互博的奥妙。"NOR"\n");
	} else
		tell_object(me, HIM "你对第" + chinese_number(layer) +
			    "层境界的左右互博又加深了一点了解。"NOR"\n");
}
