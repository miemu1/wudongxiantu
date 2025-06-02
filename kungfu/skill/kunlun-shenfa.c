// kunlun-shenfa.c (kunlun) ������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit SKILL;

mapping *action = ({
([	"action" : "$nһʽ������ƽɳ�����������٣�������ǰ�߳���������Ȼ�����������ɵ�����һ�ԡ�\n",
	"dodge"  : 15
]),
([	"action" : "$nһʽ���������𡹣������Ծ�������һ��һת����Ʈ��������֮�⡣\n",
	"dodge"  : 25
]),
([	"action" : "$nһʽ���������ڡ���������������������ĥ��������֮��ת��ж����$N��һ�С�\n",
	"dodge"  : 35
]),
([	"action" : "$nһʽ�����ɵ��ҡ���ֻ��$n���Ӻ�����˫��������һ�ţ����ӽ��Ƶ��������$N���Ѵ�$n���š�\n",
	"dodge"  : 45
]),
([	"action" : "$nһʽ����ѩ��̲�����ݸ߷��ͣ���������������Ʈ��������$N������룬ֻ�û������ء�\n",
	"dodge"  : 55
]),
([	"action" : "$nһʽ����˿���꡹��ͻȻ����һ�У���Ȼ�����ܾ��˵Ĵ򷨣���$N��æ���Ұ�ȫ����\n",
	"dodge"  : 65
]),
([	"action" : "$nһʽ��������ѩ�������в��ܣ�ֻ΢΢һ����$N���籩�������Ľ����㼴��ա�\n",
	"dodge"  : 75
]),
([	"action" : "$nһʽ������ǱԾ������Ȼ�����ΰ���ֱ��������ֱ��ӥ��������������ƮƮ������������֮�⡣\n",
	"dodge"  : 85
])
});

mapping query_action(object me, object weapon)
{
	int zhaoshu, level;

	zhaoshu = sizeof(action);
	level   = (int) me->query_skill("kunlun-shenfa");

	if (level < 60 )
		zhaoshu--;

	if (level < 50 )
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;

	return action[random(zhaoshu)];
}

int valid_enable(string usage)
{
	return usage == "dodge" ;
}

int valid_learn(object me)
{

    if (me->query("family/family_name")!="������")
   return notify_fail("�㲻�����ص��ӣ��޷�ѧϰ���ż��ܡ�\n");	
    if ((int)me->query_skill("xuantian-wuji", 1) < 20)		
        return notify_fail("��������޼�������򲻹����޷�ѧϰ���ż��ܡ�\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	object me, ob;
	mapping action;

	me = this_player();
	action = query_action(me, ob);

	return action["action"];
}

int practice_skill(object me)
{
    if (me->query("family/family_name")!="������")
   return notify_fail("�㲻�����ص��ӣ��޷���ϰ���ż��ܡ�\n");	

	if( (int)me->query("jing") < 40 )
		return notify_fail("��ľ���̫���ˣ���������������\n");
	me->receive_damage("jing", 30);
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"kunlun-shenfa/" + action;
}
	//2017.3.25���ɷ��ob_hit��Ч���������˺�Ϊ0�������й�
int ob_hit(object ob, object me, int damage)
{

        int j,ap,dp,neili,neili1;
		ap = me->query_skill("kunlun-shenfa", 1) * me->query("con",1);
		dp = ob->query_skill("dodge", 1) * ob->query("str",1);
        neili = me->query("neili");
        neili1 = ob->query("neili");
	if (damage <10)  damage=10;      	
      if(random(ap) > dp/10
		&& me->query_skill("xuantian-wuji",1) > 100
		&& me->query_skill("kunlun-shenfa", 1) > 200
		&& me->query_skill_mapped("force") == "xuantian-wuji"
        && me->query("neili") > 1000
		&& random(5)==0	)
        { 	
        message_vision(HIB"$N����ͻȻ�θߣ�һ���Ӿͱĵ�����ɽ�У������������ơ�\n"NOR, me, ob); 		
		if (!ob->is_busy()) ob->start_busy(random(2));
		me->add("neili", -100 );
		   if(neili >= random(neili1)+damage)
		   {
              message_vision( HIC"$n����$N����������֮�У��������Կ��壬ֻ�ú��ҹ������У�\n"NOR, me, ob);
              j = -(damage*2+random(damage*2)); 
            }
			else
			{
				j = -(damage+random(damage)); 
			}
           return j;
        }          
}
