// xuedao-daofa.c Ѫ��
// updated by lwx 

inherit SKILL;
#include <ansi.h> 

string *action_msg = ({
        "$N������ת�����ֽ�ָ������ǰ��һ�紦�̴ٶ�������\n"
    "һ��"HIR"���������ܡ�"NOR"������$w���������һ�����϶�������$n��",

        "$N���β�������ǰ�������������ϱ���һ��"HIR"�������֡�"NOR"��\n"
    "����$w��ǰ�·��̣�һ��ָ��$n",

        "$N�����ǰ���ŵ���������$wͻ��ǰ�̣���ת�����\n"
    "ʹ��һʽ"HIR"����ҹ���"NOR"��������ƥ����й��$n",

        "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������$wʹ��һʽ"HIR"������δ��Ե��"NOR"��"
    "����������ת�������಻������$n",

        "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������$wʹ��\n"
    "һʽ"HIR"����˿�Ѷϡ�"NOR"����$n",

        "$N���ϲ����������أ�����$wһʽ"HIR"�����Ѹ���"NOR"��"
    "����Բ�󣬴���$n",

        "$N�����˲������ֽ�ָ��ת������$wһ��"HIR"���̽�������"NOR"��"

        "$N�鲽�������ὣ�ؽ��������ϱ���һ��"HIR"������Զ��"NOR"ֱȡ$n",

HIG"\n��һ���������ɵ������ɣ��������һ�������������϶��£�"NOR,
HIG"\n�ڶ���������������Բȱ��������ңĪ���У����������ң�"NOR,
HIG"\n����������������ʶ��Ů��ͬ������Ѱ��;��������ת������"NOR,

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

level = me->query_skill("canxin-jian", 1);

   if ((int)me->query_skill("sword", 1) < 180)
               return notify_fail("��Ļ���������򲻹����޷�ѧϰ���Ľ���\n");

       if ((int)me->query_skill("sword", 1) < level)
               return notify_fail("��Ļ�������ˮƽ���ޣ��޷���������Ĳ��Ľ���\n");

        return 1;
}

mapping query_action(object me, object weapon)
{
	int i;
	i=me->query("xiangsi");
	if( !me->query("xiangsi") ) 
        return ([ 
                "action": action_msg[random(sizeof(action_msg))], 
                "damage": 200 + random(400), 
                "attack": 100 + random(100),
                "dodge" : 100 + random(100),
                "parry" : 100 + random(100),
                "damage_type": "����", 
        ]);
}
int practice_skill(object me)
{
	if( (int)me->query("qi") < 30
	||	(int)me->query("neili") < 30 )
		return notify_fail("�����������������û�а취��ϰ���Ľ���\n");
	me->add("qi", -30);
	me->add("neili", -30);
	write(HIC"�������������ϣ������޺��³�Բ��\n"NOR,me);
	return 1;
}
string perform_action_file(string action)
{
        return __DIR__"canxin-jian/" + action;
}

