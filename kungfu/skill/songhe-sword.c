// xuedao-daofa.c Ѫ��
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N��������,����$w���գ���$n��ȥ�������ƿ�ɽ��һ�㣬��һ�����ۺ��"HIC"������ӭ�͡�"NOR"",

"ֻ��$N���ָ�����������轣������$w��$n��ȫ��ȥ\n"
"����һ��"HIR"���ƹȺ׷塹"NOR"��",

"$N������ǰ������$w���裬һ��"HIM"����ɽ������"NOR"�ó����Ž�â����$n������������",

"$N���˷��������һ����Х������$w������$n��$l��ȥ������ɽ����Х���"HIG"���׺�����"NOR"��ȫ��$n������",

"ֻ��$N������أ�ʹ��һ��"HIW"��Я�����ơ�"NOR"������$w���ٷɽ���������㽣����ֱ��$n��$l��ȥ",

"$N����ǰ����һʽ"HIB"���������硹"NOR"�����潣����$nȫ���������â������������������$n�������ܵù�",

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{ int level;
        if( me->query("int")<30 )
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if( me->query("dex")<30 )
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        if( me->query("con")<30 )
                return notify_fail("���о��˰��죬ֻ���ø�����Щ���ʽʼ���޷�����ʩչ��\n");

        if( me->query("str")<30 )
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

level = me->query_skill("songhe-sword", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("��Ļ���������򲻹����޷�ѧϰ�ɺ׽�����\n");

       if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������ɺ׽�����\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("xiangsi");
	if( !me->query("xiangsi") ) 
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 400 + random(400), 
                "attack": 200 + random(100),
                "dodge" : 200 + random(100),
                "parry" : 200 + random(100),
                "damage_type": "����", 
        ]);
}
int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("songhe-sword");

	if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
	if ((int)me->query("qi") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ���ɺ׽����к����档\n");
	if ((int)me->query("neili") < 5.)
		return notify_fail("���������㣬ǿ���ɺ׽������߻���ħ��Σ�ա�\n");
	me->receive_damage("qi", 30);
	me->add("neili", -5.);
	message_vision("$NĬĬ������һ�����Ȼ������һ���ɺ׽�����\n", me);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"songhe-sword/" + action;
}

