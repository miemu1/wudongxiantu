// daojian-guizhen.c ��������
// Edit By Vin 11/2/2001

#include <ansi.h>
inherit SKILL;

int difficult_level() { return 2500; }

mapping *action = ({
([      "action" : "$N����$w�������ƶ������������ʩһ�С�" HIW "�Ʋ���"
                   "��" NOR "��������ͬʱ��ʩչ\n����" HIY "ϴ�����б���"
                   NOR "������������ͬʱ����$n$l��ȥ",
        "force" : 350,
        "attack": 350,
        "dodge" :	350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�" HIY "����ת������" NOR "������$n���̳���"
                   "������Ȼ���ֱ���Ϊ��" HIW "ɳŸ�Ӳ�" NOR "����\n����"
                   "���ϻ������뻡�ε�â��������â��$w����һ���׹�����$n",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "$N��ɫ΢�䣬һ�С�" HIY "���ﳯ��" NOR "������ʽ"
                   "��ʱ��������ޱȣ�����ʹһ�С�" HIW "��������" NOR
                   "����\n��$w���������һ��ѹ��$n",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "$Nʹһ�к��ҵ����ġ�" HIW "��������" NOR "����$w��"
                   "������Ļ���б����ն��������\n��;��ɲ�Ǽ��Ȼֻ����"
                   "��һ��������$N��һ����ҽ���֮��" HIY "ӭ���ȷ�����"
                   "ɽ" NOR "����\nȴ��$w��â��˸�������Ѿ���������",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "$N�ͺ�һ����һ�к��ҵ�����" HIW "��´���" NOR "��"
                   "����ҽ�����" HIY "������´���" NOR "��������\n$w��"
                   "�ּ�������������ת��Ծ��һ���׹�����$n���ؿ�",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$N����$w���͡���һ��б������գ��漴�����¡��"
                   "ৡ����£����Һ�\nն��������ʱ�ó�һ��������ʮ�֣���"
                   "$nӿ�������Ǻ��ҵ����С�" HIW "�׺����" NOR "��\n��"
                   "����ҽ����С�" HIY "���ý��׺����" NOR "���ľ���",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "$Nһ�С�" HIY "�ϲ��Ʊ�ժ��" NOR "��������Ծ�𣬲�"
                   "����Ӱ����Ȼ��ȴ��$w�Ӱ���д���\n���С�" HIW "��"
                   "����ů" NOR "�������Ծ����أ�$w˳����ǰ����Х����"
                   "��$n��$l",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
([      "action" : "ֻ��$Nһ�С�" HIY "���������ر���" NOR "����������"
                   "��������$w�͵����·�����ɲʱ\n�ֳ�ɱ�š�" HIW "�˷�"
                   "�ص���" NOR "������ʱ���������������䵶��������˷�"
                   "ӿ��$nȫ��",
        "force" : 350,
        "attack": 350,
        "dodge" :350,
        "parry" :350,
        "damage": 350,
        "damage_type" : "����",
]),
});

string main_skill() { return "daojian-guizhen"; }

mapping sub_skills = ([
        "miaojia-jian" : 1200,
        "hujia-daofa"  : 1200,
]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword"
            && ob->query("skill_type") != "blade" )
        {
                tell_object(me, "��������˰��죬���ֲ��ðѵ����ǽ�ʵ��"
                                "����������\n");
                return 0;
        }
		
		if (me->query("zhuanshi") < 3)
        {
                tell_object(me, "��������ϣ���������ת�����᲻�ܽ�������������\n");
                return 0;
        }
		
        if( me->query("character") != "��������" && me->query("character") != "��ʿ��˫")
        {
                tell_object(me, "�������˰��죬���а�����ʲô������һ��"
                                "�������������������ƭ�˵İ��ˡ�\n");
                return 0;
        }

        if( me->query("int")<32 )
        {
                tell_object(me, "��������ϣ�ֻ�н����͵�������ǣ������"
                                "����������ԣ��޷������һ��\n");
                return 0;
        }

        if( me->query("dex")<26 )
        {
                tell_object(me, "��������ϣ�ֻ�����Լ������鶯�ԣ���"
                                "���޷������ߺ�һ��\n");
                return 0;
        }

        if( me->query("con")<32 )
        {
                tell_object(me, "��������ϣ�ֻ�����Լ��ĸ��ǲ��㣬��"
                                "���޷������ߺ�һ��\n");
                return 0;
        }

        if( me->query("str")<31 )
        {
                tell_object(me, "��������ϣ�ֻ�����Լ��ı������㣬��"
                                "���޷������ߺ�һ��\n");
                return 0;
        }

        if (me->query_skill("literate", 1) < 200)
        {
                tell_object(me, "�������ҽ����ͺ��ҵ�����������£���"
                                "�����о�һ��ѧ�ʿ��ܸ��а�����\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 200)
        {
                tell_object(me, "��������ϣ������Լ�����ѧ�����д����"
                                "�������޷������ߺ�һ��\n");
                return 0;
        }


        if( me->query("max_neili")<4500 )
        {
                tell_object(me, "������Լ��������̣��޷�����ҽ����ͺ�"
                                "�ҵ������ߺ�һ��\n");
                return 0;
        }

        if (random(30) < 27)
        {
                tell_object(me, "������������򣬻���������һ�ξ����ڻ�"
                                "��ͨ�������ߺ�һ��\n");
                return 0;
        }
		if( me->query("family/family_name") != "�������" )
                return notify_fail("�㲻�Ǻ��ҵ��Ӳ���������\n");

        tell_object(me, HIY "\nһ�󷲳�����ӿ����ͷ���㼸��������̾����"
                        "�Ǽ䣬��ҽ����ͺ��ҵ��������Ų�����\n���Ժ���"
                        "���֣������ڻ��ͨ���϶�Ϊһ��������ͨ���˵���"
                        "����ľ��ϡ�\n" NOR);
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}

int valid_enable(string usage)
{
        return usage == "sword" || usage == "blade" || usage == "parry";
}

int valid_learn(object me)
{
        object ob;
        int lvls, lvlb, lvld;

        lvls = me->query_skill("sword", 1);
        lvlb = me->query_skill("blade", 1);
        lvld = me->query_skill("daojian-guizhen", 1);

        if( !(ob=me->query_temp("weapon") )
            || ob->query("skill_type") != "sword"
            && ob->query("skill_type") != "blade" )
                return notify_fail("���������һ������һ�������ܹ���ϰ��\n");

        if( me->query("character") != "��������" && me->query("character") != "��ʿ��˫" )
                return notify_fail("����ϰ�˰��죬���а�����ʲô������"
                                   "һ��������������ⶫ������Ҳ�ա�\n");
								   
		if (me->query("zhuanshi") < 3)
        {
                tell_object(me, "��������ϣ���������ת�����᲻�ܽ�������������\n");
                return 0;
        }

        if( me->query("int")<32 )
                return notify_fail("���о��˰��죬ȴֻ�н����͵�������"
                                   "ǣ�����������Լ����ʲ��㡣\n");

        if( me->query("dex")<26 )
                return notify_fail("���о��˰��죬ֻ�����Լ������鶯"
                                   "�ԣ������޷���ϰ�����书��\n");

        if( me->query("con")<32 )
        {
                tell_object(me, "��������ϣ�ֻ�����Լ��ĸ��ǲ��㣬��"
                                "���޷���ϰ�����书��\n");
                return 0;
        }

        if( me->query("str")<31 )
        {
                tell_object(me, "��������ϣ�ֻ�����Լ��ı������㣬��"
                                "���޷���ϰ�����书��\n");
                return 0;
        }

        if (me->query_skill("martial-cognize", 1) < 250)
                return notify_fail("�������ҽ����ͺ��ҵ������������"
                                   "�������Լ���ѧ����������⡣\n");

        if( me->query("max_neili")<4500 )
                return notify_fail("�������̫�����޷�����ҽ����ͺ���"
                                   "�������ߺ�һѧϰ��\n");
		if( me->query_skill("lengyue-shengong")<450)
                return notify_fail("����ڹ�̫�����޷���ϰ�������档\n");

        if (lvls < 250 || lvlb < 250)
                return notify_fail("��ĵ�����������㣬������������"
                                   "���档\n");

        // �����ͽ��������ڵ�������
        if (lvls < lvld && lvlb < lvld)
                return notify_fail("��ĵ�����������㣬�޷�������"
                                   "��ĵ������档\n");

        // �����ͽ�������һ���ڵ�������
        if (lvls < lvld || lvlb < lvld)
        {
                // ����������Ϊ��ѧ����ʦ���һ��������������ȼ���
                // ���� 320 ������ֻ��Ҫ����֮һ֧�ּ���
                if (! ultrap(me) || lvls < 320 || lvlb < 320)
                        return notify_fail("��ĵ����򽣷�����㣬��"
                                           "����������ĵ������档\n");
        }
        return 1;
}

int practice_skill(object me)
{
        if( me->query("qi")<100 )
                return notify_fail("��������������������档\n");

        if( me->query("neili")<100 )
                return notify_fail("��������������������档\n");

        me->receive_damage("qi", 85);
        me->add("neili", -85);
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

/*
void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);

        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames[i]);
}
*/

void skill_improved(object me)
{
        int lvl;

        lvl = me->query_skill("daojian-guizhen", 1);

        if( lvl >= 200 &&
            !me->query("can_perform/daojian-guizhen/ben") )
        {
                tell_object(me, HIC "��ͨ���˵������桸" HIR "������" HIC "���İ��ء�\n" NOR);
                me->set("can_perform/daojian-guizhen/ben", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 300 &&
            !me->query("can_perform/daojian-guizhen/po") )
        {
                tell_object(me, HIC "��ͨ���˵������桸" HIR "�ƶ���ɽ" HIC "���İ��ء�\n" NOR);
                me->set("can_perform/daojian-guizhen/po", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 250 &&
            !me->query("can_perform/daojian-guizhen/tian") )
        {
                tell_object(me, HIC "��ͨ���˵������桸" HIR "����������" HIC "���İ��ء�\n" NOR);
                me->set("can_perform/daojian-guizhen/tian", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }

        if( lvl >= 280 &&
            !me->query("can_perform/daojian-guizhen/xue") )
        {
                tell_object(me, HIC "��ͨ���˵������桸" HIR "������Ѫ" HIC "���İ��ء�\n" NOR);
                me->set("can_perform/daojian-guizhen/xue", 1);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
                me->improve_skill("martial-cognize", 1500000);
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        if (damage_bonus < 100)
                return 0;

        if (damage_bonus < victim->query_int())
                return 0;

        // if (me->query_temp("daojian-guizhen/max_pfm"))
        {
                victim->receive_damage("qi", damage_bonus, me);
                victim->receive_wound("qi", damage_bonus / 2, me);
                return random(2) ? HIR "ֻ�������͡�һ����һ����Ѫ��$n"
                                   HIR "��ǰ�����\n" NOR:

                                   HIR "��ʱֻ������һ����һ����Ѫ��$n"
                                   HIR "��ǰ�����\n" NOR;
        }
}

string perform_action_file(string action)
{
        return __DIR__"daojian-guizhen/" + action;
}

int query_effect_parry(object attacker, object me)
{
        int lvl;
        if( !objectp(me->query_temp("weapon")) )
                return 0;

        lvl = me->query_skill("daojian-guizhen", 1);
        if (lvl < 80)  return 0;
        if (lvl < 200) return 50;
        if (lvl < 280) return 80;
        if (lvl < 350) return 100;
        return 120;
}



mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mixed result;
        int ap, dp, mp, level;

        if ((level = (int)me->query_skill("daojian-guizhen", 1)) < 100 ||
            !objectp(me->query_temp("weapon")) )
                return;

        mp = ob->query_skill("count", 1);
        ap = ob->query_skill("force") + mp;
        dp = me->query_skill("parry", 1) / 2 +
             me->query_skill("daojian-guizhen", 1) + me->query_skill("hujia-daofa", 1);

        if (ap / 2 + random(ap) < dp)
        {
                result = ([ "damage": -damage ]);

                result += (["msg" : HIC "$n" HIC "ͻȻʹ��һ�С���ѩ�׷ס��������򳤰�â���������䣬ֱ����$N"
                            "������Ϊ���ƣ���$N����������\n" NOR]);
                COMBAT_D->do_attack(me,ob,me->query_temp("weapon"));
                return result;
        }
}
