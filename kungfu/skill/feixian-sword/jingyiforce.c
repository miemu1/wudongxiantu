// fonxanforce.c

inherit FORCE;

void remove_effect(object me, int amount);

string query_name() { return "净衣"ZJBR"心法"; }

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return 
notify_fail("净衣心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"jingyiforce/" + func;
}
 
int effective_level() { return 10;}

int learn_bonus()
{
	return 10;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return 20;
}

