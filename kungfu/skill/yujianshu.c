// xuedao-daofa.c Ѫ��
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N˫��һ�٣���ֱԾ������$w��ͣ�ز����ţ�\n"
"����ס$nȫ������"HIC"���������硹"NOR"��Ȼ���޿ײ���",
"$n���˰벽,���е�$W���ٻӶ�,������$N�Ĺ��ơ�\n",


        "$N����$w�����㺮�⣬ָ��$nǰ��Ѩ����$n��ר����־�ضԸ��Ž��У�\n"
"����$N������������$n��$l������"HIR"��������硹"NOR"������ã�ʵ���ѷ�",
"$n�з�ͻ��,���е�$Wֱ��$N,�Ƶ�$Nֻ���ջ���ʽ��\n",


"$N��$n�������ߣ�һ��"HIY"[��������]"NOR",����$wȥ��Ʈ��������ֻ����$n�ۻ����ҡ�\n"
"�ô�������$N������������һ��$w����$n��$l����",
"$n��������,����$W��ǰ�մ�����������������$N�Ĺ��ơ�\n",

"$N��������$w��������㺮�⣬��ס$n���ظ���ֻ��$n��������\n"
"����"HIM"�������пա�"NOR"ֱ��ϸ�����ܣ�$nʵ�ڲ�֪$w��Ҫָ���Լ����Ϻδ�",

"$N����$w�й�ֱ�������ٴ���$n��ǰ�ġ�\n"
"����"HIG"��������Ӱ��"NOR"���˶�Ŀһ�¡�$nֻ������һ����$w�Ѵ̵���$l",

"$N����$w��$n�����ּ��̣�������$nҪ�м�ʱ��\n"
"$wȴͻȻת����$n�����㣡����"HIB"���������ڡ�"NOR"ȷʵ���Ī��",
"$n�������������е�$W��������$N���ⱳˮһս֮�ƹ�Ȼ��Ч����$N���˻�ȥ��\��\n",

});

int valid_enable(string usage) { return usage == "sword" || usage == "parry"; }

int valid_learn(object me)
{ int level;
        if( me->query("int")<35 )
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if( me->query("dex")<35 )
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");

        if( me->query("con")<35 )
                return notify_fail("���о��˰��죬ֻ���ø�����Щ���ʽʼ���޷�����ʩչ��\n");

        if( me->query("str")<35 )
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

level = me->query_skill("yujianshu", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("��Ļ���������򲻹����޷�ѧϰ��������\n");

   if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������������\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 600 + random(100), 
                "attack": 100 + random(100),
                "dodge" : 100 + random(100),
                "parry" : 100 + random(100),
                 "damage_type" : random(2) ? "����" : "����",
        ]);
}

int practice_skill(object me)
{
         
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("yujianshu");
            if (dod<swo/2)
		return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
       if ((int)me->query("qi") < 3000)
		return notify_fail("������Ƿ�ѣ�ǿ���������к����档\n");
	if ((int)me->query("neili") < 500)
		return notify_fail("���������㣬ǿ�����������߻���ħ��Σ�ա�\n");
	me->receive_damage("qi", 3000);
	me->add("neili", -500);
	message_vision("$NĬĬ������һ�����Ȼ������һ����������\n", me);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"yujianshu/" + action;
}

