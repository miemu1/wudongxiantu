#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

 int lvl = (int)me->query_skill("huaxue-dafa", 1);
        if( me->query("gender") == "无性" && lvl>49 )
                return notify_fail("你无根无性，阴阳不调，难以领会高深的化血大法。\n");

        if( me->query("class") == "bonze" )
                return notify_fail("血河派武功精要皆在一个“杀”字，有违佛家六根清净之意，"
                        + RANK_D->query_respect(me) + "欲修此功，已是罪过。\n");

        if( lvl>10 && me->query("shen")> -lvl*500)
		return notify_fail("血河派武功精要皆在一个“杀”字，你的杀气太低了。\n");


/*
        if (( (int)me->query("shen") < -10000) && me->query_skill("huaxue-dafa",1)>30)
		return notify_fail("血河派武功精要皆在一个“杀”字，你的杀气太低了。\n");
*/
	if ( (int)me->query_skill("force", 1) < 400)
                return notify_fail("你的基本内功火候还不够，无法领会化血大法。\n");
	return 1;
}
int practice_skill(object me)
{
        return notify_fail("化血大法只能用学(learn)的来增加熟练度。\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

