// anyezangdi-jing.c ��ҹ�ᾭ
//�˵۾�Ϊ��۳ɵۺ�����������������һ����ѧ���˹����ɼ�������������ѧ
//��������������ڹ���ָ�����ַ���������������ǹ�����޷���������������ȭ�ŵ���ѧ
#include <ansi.h> 
inherit FORCE;

//����
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
//��
string *parry_msg = ({
        HIW "$N" HIW "һ�л���$n" HIW "���ϣ�ȴ��$n" HIW "����Ǭ����Ų���ھ�"
        "������������������¡�\n" NOR,
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

        lvl = (int)me->query_skill("anyezangdi-jing", 1);
        return lvl * lvl * 999 * 999 / 100 / 200;
}

//��ʽ
mapping *action = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
                  HIY "������ȥ",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "���е�$w" HIY "ͻ������ɭ�ϣ�����ǧ�������۶�"
                  "������ͬ����һ���ɨ$n" HIY,
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "�������е�$w" HIY "����������һ�����$n" HIY "��"
                  "�����ң�û�а���·�",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "����$w" HIY "�û���һ��һ��ԲȦ���ƺ�Ҫ��$n" HIY
                  "���Ű�Χ",
        "force" : 600,
        "attack": 300,
        "dodge" : 300,
        "parry" : 300,
        "damage": 400,
        "damage_type": "����"
]),
([      "action": HIY "$N" HIY "��Ц��ת$w" HIY "������һָ���ĵ��黨ָ֮�⣬��"
                  "��$n" HIY "ȫ��",
        "force" : 6000,
        "attack": 3000,
        "dodge" : 3000,
        "parry" : 3000,
        "damage": 4000,
        "damage_type": "����"
]),
});
//������ѧ
string *usage_skills = ({ "axe", "blade","unarmed", "strike", "claw", "hand",  "finger",
                          "sword", "hammer", "throwing", "club", "claw", "whip", "stick",
                          "staff", "dodge", "dagger", "parry", "force" ,"spear", });
						  
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
        return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        string msg;
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("anyezangdi-jing", 1);

        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "anyezangdi-jing")
                return 0;

        // δѧ���������
        if (! me->query("can_learned/anyezangdi-jing/enable_weapon"))
        {
             if (me->query_skill_prepared("unarmed") != "anyezangdi-jing")
                      return 0;
        }

        // �Ѿ����������
        if (me->query("can_learned/anyezangdi-jing/enable_weapon"))
        {             
             if (! objectp(weapon))
                  if (me->query_skill_prepared("unarmed") != "anyezangdi-jing")           
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") != "sword" 
                 && weapon->query("skill_type") != "blade"
				 && weapon->query("skill_type") != "axe"
				 && weapon->query("skill_type") != "club"
				 && weapon->query("skill_type") != "hammer"
				 && weapon->query("skill_type") != "staff"
				 && weapon->query("skill_type") != "spear"
				 && weapon->query("skill_type") != "whip")
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "anyezangdi-jing")
                         return 0;
            
             if (objectp(weapon) && weapon->query("skill_type") == "blade"
                 && me->query_skill_mapped("blade") != "anyezangdi-jing")
                         return 0; 

             if (objectp(weapon) && weapon->query("skill_type") == "axe"
                 && me->query_skill_mapped("axe") != "anyezangdi-jing")
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") == "club"
                 && me->query_skill_mapped("club") != "anyezangdi-jing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "hammer"
                 && me->query_skill_mapped("hammer") != "anyezangdi-jing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "staff"
                 && me->query_skill_mapped("staff") != "anyezangdi-jing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "spear"
                 && me->query_skill_mapped("spear") != "anyezangdi-jing")
                         return 0;	

             if (objectp(weapon) && weapon->query("skill_type") == "whip"
                 && me->query_skill_mapped("whip") != "anyezangdi-jing")
                         return 0;						 
        }

        if (random(damage_bonus) / 2 > victim->query_con() && random(2))
        {
                me->add("neili", -100);
                result = ([ "damage" : (damage_bonus - 80)/3 ]);

                if (me->query("can_learned/anyezangdi-jing/enable_weapon") && objectp(weapon))
                {
                        msg = random(2) ? HIM "$N" HIM "һ�й�����������ǧ�����ˣ�����ھ�"
                                           "��ʱԴԴ����͸��" + weapon->name() + HIM "ӿ��$n" HIM "��"
                                           "�ڣ�\n" NOR:
                                           HIM "$N" HIM "����ھ��ŷ���$n" HIM "ֻ��ȫ��һ�𣬵�ʱһ"
                                           "������֮��͸�ض�����" + weapon->name() + HIM "��Ѫ���죡\n" NOR;
                } else
                {
                        msg = random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�����ھ�"
                                           "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                           HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                           "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
                }
                result += ([ "msg" : msg ]);
                return result;
        }
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;

        ap = ob->query_skill("parry");
        dp = me->query_skill("anyezangdi-jing", 1);

        if (random(ap / 6) < dp * 3 / 2)
        {
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

int practice_skill(object me)
{
	return notify_fail("��ҹ�ᾭֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

string perform_action_file(string action)
{
        return __DIR__"anyezangdi-jing/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"anyezangdi-jing/exert/" + action;
}

void skill_improved()
{
	this_player()->add("exception/anye-count",
			   (int)this_player()->query_skill("anyezangdi-jing", 1) + 1);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
        return 200;
}