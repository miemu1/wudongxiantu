// ���µ�һ.c ̫ʼ�۾�
// ��ʮ��֮ǰͨ�������񹦡������񹦡���ڤ�񹦡��貨΢����Ǭ
// ����Ų�ơ�����ʮ���ƺ������񽣣�����Ϊһ������S+++����ѧ��
// ̫ʼ�۾����Լ���Ϊ�������е��书��

#include <ansi.h>

inherit FORCE;

string *xue_name = ({
"�����쾭��", "С���쾭��", });

string *attack_name = ({"���ɷ��Ԫ��" });

string *dodge_msg = ({
        HIW "$n" HIW "�������һ�Σ�$N" HIW "��Ȼ�޷�������ֻ���Ա���\n" NOR,
        HIW "ֻ��$n" HIW "��������ζ���$N" HIW "��ǰ��ʱ������������$n" HIW
        "�Ļ�Ӱ����$N" HIW "��ȫ�޷������ʵ��\n" NOR,
        HIW "$n" HIW "���Ա�����бб������һ����ȴǡ����$N" HIW "�Ĺ���ʧ֮"
        "���塣\n" NOR,
        HIW "$N" HIW "��һ�����ĺÿ죬Ȼ��$n" HIW "һ�����ƺ����Ѱ��������"
        "ȴ��$N" HIW "��һ�иպñܿ���\n" NOR,
        HIW "����$n" HIW "����һԾ���Ѳ�������Ӱ��$N" HIW "���д󺧣�ȴ�ּ�"
        "$n" HIW "���籼��������֮���ɣ���������˼�����ǡ�\n" NOR,
});

string *parry_msg = ({
        HIW "$n����һ����$N" HIW "�����Լ������ػ��������ŵ������˼�����\n" NOR,
        HIW "$n�ֱۻ�ת����$N" HIW "����������һ�ƣ�$N" HIW "������ա�\n" NOR,
        HIW "$n�����������$N" HIW "����������һ����$N" HIW "���Ʋ�ס��ֱ��ǰ��ȥ��\n" NOR,
        HIW "$n���β�����$N" HIW "һ�л��£�����ʯ���󺣣�������ס�ˡ�\n" NOR,
        HIW "$n��ǣ������$N" HIW "��������������ת�˺ü���Ȧ��\n" NOR,
        HIW "$n˫�ֻ�Ȧ��$N" HIW "ֻ����ǰ�������һ��ǽ����Ҳ������ȥ��\n" NOR,
        HIW "$n����һת��$N" HIW "һ�л��ڵ��ϣ�ֻ��ó������\n" NOR,
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("wudi", 1);
        return lvl /10 * lvl /10 * 15 * 80 / 10 / 20;
}

int query_jingli_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("wudi", 1);

        if (me->query_skill_mapped("force") == "wudi")
                return lvl * 14 / 3;

        return 0;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "������ָһ���������ɷ��Ԫ������ǰ�̳��������ĵ�����"
                  "Ȼ���죬��������ֱָ$n" HIW,
        "force" : 999999999,
        "attack": 999999999,
        "dodge" : 999999999,
        "parry" : 999999999,
        "damage": 999999999,
        "lvl": 999999999,
        "weapon": HIW "���ɷ��Ԫ��" NOR,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
                  HIY "������ȥ",
        "force" : 999999999,
        "attack": 999999999,
        "dodge" : 999999999,
        "parry" : 999999999,
        "damage": 999999999,
        "lvl": 999999999,
        "damage_type": "����"
]),
});

string main_skill()
{
        return "wudi";
}

mapping sub_skills = ([
        ]);

int get_ready(object me)
{
        return 1;
}

int get_finish(object me)
{
        object ob;

        if( me->query("int")<150 )
        {
                tell_object(me, "��������ϣ�ֻ��˼�����ң�������������ԣ���"
                                "�������һ��\n");
                return 0;
        }
        if( me->query("con")<150 )
        {
                tell_object(me, "��������ϣ�ֻ��ȫ�������Ҵܣ���ð���ǣ�������������"
                                "�����ײſ���������\n");
                return 0;
        }
        if( me->query("str")<150 )
        {
                tell_object(me, "��������ϣ�ֻ��˫�����ۣ�ȫ����\n");
                return 0;
        }
        if( me->query("dex")<150 )
        {
                tell_object(me, "��������ϣ��������������ʱ���޷������ڻ��ͨ��\n");
                return 0;
        }

        if( me->query("age") >= 18 )
        {
                                tell_object(me, "���Ѵ�����������ʱ�̣��������ڴ˸�����ѧ��Ե��\n");
                return 0;
        }

        if (random(300) != 1 && ! wizardp(me))
        {
                tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ�����������ǧ��\n");
                return 0;
        }

        tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
                        "�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
                        "��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "������"HIY"�����ǧ"HIM"��\n");
        return 1;
}

mapping query_sub_skills()
{
        return sub_skills;
}
string *usage_skills = ({ "unarmed", "strike", "claw", "hand", "cuff", "finger", "sword", "blade", "hammer", "club", "whip","staff", "dodge", "dagger", "parry", "force" });

int valid_enable(string usage)
{
        return (member_array(usage, usage_skills) != -1);
}

int valid_force(string force)
{
        return 1;
}

int double_attack()
{
        return 1;
}

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int valid_learn(object me)
{
        int level;
        int i;
       
        if( me->query("str")<150 )
                return notify_fail("������������㡣\n");

        if( me->query("int")<150 )
                return notify_fail("���������Բ��㡣\n");

        if( me->query("dex")<150 )
                return notify_fail("�����������㡣\n");
                
        if( me->query("con")<150 )
                return notify_fail("��������ǲ��㡣\n");    

       if( me->query("gender") == "����" &&
            (int)me->query_skill("wudi", 1) > 49)
                return notify_fail("���޸����ԣ�������������������������µ�һ��\n");
                
        if( me->query("max_neili")<5000 )
                return notify_fail("���������Ϊ�����������������µ�һ��\n");

        if ((int)me->query_skill("force", 1) < 500)
                return notify_fail("����ڹ����̫ǳ�������������µ�һ��\n");

        if ((int)me->query_skill("dodge", 1) < 500)
                return notify_fail("����Ṧ�������㣬�����������µ�һ��\n");

        if ((int)me->query_skill("unarmed", 1) < 500)
                return notify_fail("���ȭ�Ÿ������㣬�����������µ�һ��\n");

        if ((int)me->query_skill("parry", 1) < 500)
                return notify_fail("����мܸ������㣬�����������µ�һ��\n");
    
        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����ѧ�������㣬�����������µ�һ��\n");
                    
        if ((int)me->query_skill("buddhism", 1) < 800)
                return notify_fail("��������ķ���Ϊ���㣬�����������µ�һ��\n");

        if ((int)me->query_skill("lamaism", 1) < 800)
                return notify_fail("��������ķ���Ϊ���㣬�����������µ�һ��\n");

        if ((int)me->query_skill("taoism", 1) < 800)
                return notify_fail("��ĵ�ѧ�ķ���Ϊ���㣬�����������µ�һ��\n");

         level = me->query_skill("wudi", 1);

        if (me->query_skill("dodge", 1) < level)
                return notify_fail("��Ļ����Ṧˮƽ���ޣ��޷�������������µ�һ��\n"); 

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ļ����ڹ�ˮƽ���ޣ��޷�������������µ�һ��\n"); 
                   
        if (me->query_skill("parry", 1) < level)
                return notify_fail("��Ļ����м�ˮƽ���ޣ��޷�������������µ�һ��\n"); 

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ļ���ȭ��ˮƽ���ޣ��޷�������������µ�һ��\n"); 

        if (me->query_skill("blade", 1) < level)
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������µ�һ��\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�������������µ�һ��\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("���µ�һ������޷��򵥵�ͨ����ϰ������\n");
}

int difficult_level()
{
        return 30000;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        string name1, name2, weapon;
        name1 = xue_name[random(sizeof(xue_name))];
        name2 = attack_name[random(sizeof(attack_name))];

        victim->receive_wound("qi", damage_bonus * 40000, me);
        me->add("neili", me->query("jiali") * 30000);

        if (victim->query("neili") < 500)
                victim->set("neili", 0);
        else
                victim->add("neili", -300);

        return NOR + HIR "$n" HIR "����$N" HIR "һ�У�" + name2 + "��ʱ��" + name1 + "��ӿ���롣\n" NOR;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp, cost;

        if ((int)me->query_skill("wudi", 1) < 350
           || me->query_skill_mapped("parry") != "wudi"
           || me->query("neili")<200
           || ! living(me))
                return;

        
        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force", 1) * 4 + ob->query_skill("martial-cognize", 1);
        dp = me->query_skill("wudi", 1) * 60 + me->query_skill("martial-cognize", 1);

        if( ob->query("reborn/times") < 4 )dp+=1000;
        
        if (dp + random(dp / 2) >= ap)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);


                switch (random(4))
                {
                case 0:
                        result += (["msg" : HIW "$n" HIW "�溬΢Ц������һ���ѽ���"
                                            "�����н�������ȫ��������\n" NOR]);
                        break;
                case 1:
                        result += (["msg" : HIW "$n" HIW "üͷ΢΢һ�壬��Ҳ��������"
                                            "$N" HIW "��һ�ߡ�\n" NOR]);
                        break;
                case 2:
                        result += (["msg" : HIW "$n" HIW "����΢΢һ�����ѽ�$N" HIW
                                            "�����������⡣\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIW "$n" HIW "һ����ߣ�����΢΢һ������"
                                            "ƮȻԶȥ��ʹ$N" HIW "�Ľ���ȫ���ô���\n" NOR]);
                        break;
                }
                return result;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wudi", 1);
        if (lvl < 200) return 200;
        if (lvl < 250) return 300;
        if (lvl < 350) return 400;
        return 200;
}

int query_effect_dodge(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("wudi", 1);
        if (lvl < 200) return 100;
        if (lvl < 250) return 150;
        if (lvl < 350) return 180;
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"wudi/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"wudi/exert/" + action;
}

void skill_improved(object me)
{
        int i;
        string *sub_skillnames;

        sub_skillnames = keys(sub_skills);
        for (i = 0; i < sizeof(sub_skillnames); i++)
                me->delete_skill(sub_skillnames);
}