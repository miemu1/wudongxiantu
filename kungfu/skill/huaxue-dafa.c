#include <ansi.h>
inherit FORCE;
int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{

 int lvl = (int)me->query_skill("huaxue-dafa", 1);
        if( me->query("gender") == "����" && lvl>49 )
                return notify_fail("���޸����ԣ���������������������Ļ�Ѫ�󷨡�\n");

        if( me->query("class") == "bonze" )
                return notify_fail("Ѫ�����书��Ҫ����һ����ɱ���֣���Υ��������徻֮�⣬"
                        + RANK_D->query_respect(me) + "���޴˹������������\n");

        if( lvl>10 && me->query("shen")> -lvl*500)
		return notify_fail("Ѫ�����书��Ҫ����һ����ɱ���֣����ɱ��̫���ˡ�\n");


/*
        if (( (int)me->query("shen") < -10000) && me->query_skill("huaxue-dafa",1)>30)
		return notify_fail("Ѫ�����书��Ҫ����һ����ɱ���֣����ɱ��̫���ˡ�\n");
*/
	if ( (int)me->query_skill("force", 1) < 400)
                return notify_fail("��Ļ����ڹ���򻹲������޷���ữѪ�󷨡�\n");
	return 1;
}
int practice_skill(object me)
{
        return notify_fail("��Ѫ��ֻ����ѧ(learn)�������������ȡ�\n");
}
string exert_function_file(string func)
{
        return __DIR__"huaxue-dafa/" + func;
}

