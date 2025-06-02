#include <ansi.h>
inherit FORCE;

string *dodge_msg = ({
        HIW "$n" HIW "��ǰһ���������������뽣���Ϊһ�壬$N" HIW "Ŀ�ɿڴ���һʱ�����ҳ����������\n" NOR,
        HIW "ֻ��$n" HIW "����������������������ʱ��������Ӱ��$N" HIW "�ۻ����ң��޴ӹ�����\n" NOR,
        HIW "$n" HIW "�����ڹ��������ɽ�����������������է�ֽ���$N" HIW "����Χס�����ﻹ�л��ṥ����\n" NOR,
});

string *parry_msg = ({
        HIG "$N" HIG "һ�й�����$n" HIG "���˲��ܣ�������â��������������о������������Ρ�\n" NOR,
        HIG "$n" HIG "��¶΢Ц��������Ȼ��û�Ϊһ����������$N" HIG "�����������޷���֮���塣\n" NOR,
        HIG "$n" HIG "���Ų�æ�����н�������ǰ����һ�������Ļ��ߣ�����$N" HIG "����ȫ�����⡣\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("liujiu-xinjing", 1);
        return lvl * lvl / 100 * 15 * 38  / 200;
}

int query_jingli_improve(object me)
{
        int lvl;
        
        lvl = (int)me->query_skill("liujiu-xinjing", 1);
        
        if (me->query_skill_mapped("force") == "liujiu-xinjing")
                return lvl * 14 / 10;

        return 0;
}

mapping *action = ({
([      "action": HIW "$N" HIW "ʹ�������־������˽��������У���������Ǻӣ�����������䣬����$n" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,
        "skill_name" : "���־�",
        "damage_type": "����"
]),
([      "action": HIM "$N����$w" HIM "���������Ǻӣ�����һ��΢����һʽ�����ľ���ʹ������ʱ��$n" HIM "�ش�" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,        
        "skill_name" : "���ľ�",
        "damage_type": "����"
]),
([      "action": HIG "$N" HIG"һ�����϶��£������־���ʹ���������޴����ڣ�����$n" HIG "�������޷��мܡ�" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 450,    
        "skill_name" : "���־�",
        "damage_type": "����"
]),
([      "action": HIR "$N" HIR "������ԣ�һʽ�����ľ�����һ�ɽ�����$w" HIR "���Ķ������������У��޷�ƥ�У��ޱ߽�������$n" NOR,
        "force" : 600,
        "attack": 650,
        "dodge" : 110,
        "parry" : 450,
        "damage": 550,
        "lvl"   : 300,        
        "skill_name" : "���ľ�",
        "damage_type": "����"
]),

});

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "parry" || usage == "dodge" || usage == "unarmed" || usage == "force";
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}



int get_ready(object me)
{
        return 1;
}



int valid_learn(object me)
{
        int level;
        level = me->query_skill("liujiu-xinjing", 1);
		
		if( me->query("zhuanshi")<5 && me->query("chongxiu")<1 )
                return notify_fail("������������㡣\n");

        if( me->query("str")<150 )
                return notify_fail("������������㡣\n");

        if( me->query("int")<150 )
                return notify_fail("���������Բ��㡣\n");

        if( me->query("dex")<150 )
                return notify_fail("�����������㡣\n");
                
        if( me->query("con")<150 )
                return notify_fail("��������ǲ��㡣\n");                        
                
        if( me->query("max_neili")<100000 )
                return notify_fail("���������Ϊ����������������ʮ���ľ���\n");
                                            
        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ʮ���ľ���\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷������������ʮ���ľ���\n");
                
if (me->query_skill("martial-cognize", 1) < level &&
            me->query_skill("martial-cognize", 1) < 600)
                                return notify_fail("����ѧ�����������޷�����������\n");              

        if ((int)me->query_skill("dodge", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷������������ʮ���ľ���\n"); 

        if ((int)me->query_skill("force", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷������������ʮ���ľ���\n"); 
                                                
        if ((int)me->query_skill("parry", 1) < (int)me->query_skill("liujiu-xinjing", 1))
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷������������ʮ���ľ���\n"); 
                                                                
        return 1;
}

string query_skill_name(int level)
{
        int i;
        for (i = sizeof(action) - 1; i >= 0; i--)
                if (level >= action[i]["lvl"])
                        return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return notify_fail("��ʮ���ľ�������޷��򵥵�ͨ����ϰ������\n");
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("liujiu-xinjing", 1);
        if (lvl < 200) return 70;
        if (lvl < 250) return 80;
        if (lvl < 350) return 120;
        return 150;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("liujiu-xinjing", 1);
        if (lvl < 200) return 200;
        if (lvl < 250) return 300;
        if (lvl < 350) return 400;
        return 500;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{

        string *desc;
        object weapon;
        
        weapon=me->query_temp("weapon");
        
        if (! objectp(weapon))return damage_bonus;
        
        desc = ({
                HIY "$N" HIY "΢΢��������" + weapon->name() + HIY "ֻ��ɲ�ǽ�����$n" HIY "��\n" NOR,
                HIG "$N" HIG "�����������������ɶ��죬������ʮ�ŵ�������$n" HIG "���֡�\n" NOR,
                HIR "$N" HIR "��������" + weapon->name() + HIR "��˲��������󣬷��Ʊ�ã�$n" HIR "û��˿������֮����\n" NOR,
        });
        
        if (me->is_busy() 
           || ! living(victim) 
           || damage_bonus < 120 
           || me->query("neili")<500
           || me->query_skill("liujiu-xinjing", 1) < 300) 
                return 0; 

        // ׷����Ч
        victim->receive_wound("qi", damage_bonus , me);
        // 500������׷��50%�˺�
        if (me->query_skill("liujiu-xinjing", 1) >= 500)
                victim->receive_wound("qi", damage_bonus / 2, me);
        
        if (random(3) == 1)victim->start_busy(3 + random(3));
        
        if( random(10) == 1)victim->add("neili", -1*me->query_skill("liujiu-xinjing",1)*2);
        
        return desc[random(sizeof(desc))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("liujiu-xinjing", 1) < 350
           || me->query_skill_mapped("parry") != "liujiu-xinjing"
           || me->query("neili")<200
           || ! living(me))
                return;

        
        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("liujiu-xinjing", 1) * 6 + me->query_skill("martial-cognize", 1);

        if( ob->query("reborn/times") < 4 )dp+=1000;
        
        if (dp + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(3))
                {
                case 0:
                        result += (["msg" : HIG "$n" HIW "����һ�٣����������⣬ת˲���š�\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIM "$n" HIW "���Ž��⣬���˷���������$N" HIW "�����������¡�\n" NOR]);
                        break;
                default:
                        result += (["msg" : MAG "$n" HIW "��������������鲼������û��һ�п���ͻ���������\n" NOR]);
                        break;
                }
                return result;
        }
}
string perform_action_file(string action)
{
        return __DIR__"liujiu-xinjing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"liujiu-xinjing/exert/" + action;
}

int difficult_level()
{
        return 25000;
}