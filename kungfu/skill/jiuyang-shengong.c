#include <ansi.h>

inherit FORCE;

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("jiuyang-shengong", 1);
        return lvl / 10 * lvl / 10 * 15 * 28 / 10 / 20;
}

mapping *actionf = ({
([      "action": "$N����һԾ��������Ȼ�ӿ죬����$n$l���ٹ�����ʮȭ",
        "force" : 510,
        "attack": 190,
        "dodge" : 100,
        "parry" : 90,
        "damage": 180,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N����������һȭ����$n��ɲ�Ǽ䣬$Nȫ�����ֳ�һ�����",
        "force" : 510,
        "attack": 185,
        "dodge" : 90,
        "parry" : 120,
        "damage": 175,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N���������˾��ڱۣ�һ�������ն����������һ�����ȵĻ�â",
        "force" : 530,
        "attack": 175,
        "dodge" : 90,
        "parry" : 110,
        "damage": 200,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N�粽��ǰ������΢΢һչ��˫�ƶ�׼$n$lһ������",
        "force" : 525,
        "attack": 185,
        "dodge" : 85,
        "parry" : 115,
        "damage": 185,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$N���߾������ھ����͵�һȭ�ں�Х���ж�Ȼ�ӻ�����",
        "force" : 530,
        "attack": 165,
        "dodge" : 90,
        "parry" : 115,
        "damage": 200,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
([      "action": "$Nһ�����ȣ�ʮָĺ���ſ���һ���ۺ���ھ����ȶ���",
        "force" : 540,
        "attack": 200,
        "dodge" : 115,
        "parry" : 120,
        "damage": 180,
        "weapon": HIR "�����޼���" NOR,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action" : "$N���ƺ��������裬$w�仯�޳���׽��������$n������ȥ",
        "force" : 330,
        "attack": 140,
        "dodge" : 35,
        "parry" : 85,
        "damage": 325,
        "damage_type": "����"
]),
([      "action":"$N���е�$wͻ������ɭ�ϣ�����ǧ�������۶�����$w����һ����â����$n",
        "force" : 310,
        "attack": 120,
        "dodge" : 25,
        "parry" : 25,
        "damage": 310,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w����ʱ��â���ǣ����罾���һ�ֱ����$n��ȥ",
        "force" : 340,
        "attack": 115,
        "dodge" : 20,
        "parry" : 25,
        "damage": 365,
        "damage_type": "����"
]),
([      "action":"$N����$w�û���һ��һ��ԲȦ����ʱ������Ȧ��$n���Ű�Χ",
        "force" : 285,
        "attack": 110,
        "dodge" : 25,
        "parry" : 25,
        "damage": 390,
        "damage_type": "����"
]),
([      "action":"$N��ת$wңָ$n����ʱ$w���˶�ʱ͸��һ�����²����Ļ�⣬�������",
        "force" : 330,
        "attack": 118,
        "dodge" : 10,
        "parry" : 20,
        "damage": 420,
        "damage_type": "����"
]),
});

string main_skill() { return "jiuyang-shengong"; }

int get_ready(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        object me = this_player();

        if (! me->query("can_skill/jiuyang-shengong"))
                return usage == "force";
        else
                return usage == "force" || usage == "unarmed" || usage =="parry";
}

int valid_force(string force) { return 1; }

int double_attack() { return 1; }

mapping query_action(object me, object weapon)
{
        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

int valid_learn(object me)
{
        int level;
        int i;
/*
        if ((int)me->query_skill("yinyang-shiertian", 1))
                return notify_fail("���ѽ��������ڻ��ͨ���ϳ�������֮����"
                                   "ǿ���书�������ٷֿ�ѧϰ�ˡ�\n");
*/
	
    //    if( (!me->query("family/family_name") ||
    //            me->query("family/family_name") != "����") && me->query("reborn/family_name") != "����" )
    //            return notify_fail("��û�о����Ž�����ָ�㣬������⡣\n");

	if (me->query("gender") == "����" && (int)me->query_skill("jiuyang-shengong", 1) > 49)
		return notify_fail("���޸����ԣ���������������������ľ����񹦡�\n");

	if (me->query("int") < 25)
		return notify_fail("����þ����񹦹��ڼ��������⡣\n");

	if (me->query("con") < 29)
		return notify_fail("��ĸ��ǲ��ã�������ת�����񹦡�\n");

        if ((int)me->query("max_neili") < 3500)
            return notify_fail("���������Ϊ̫ǳ���޷���ת�����񹦡�\n");

        level = me->query_skill("jiuyang-shengong", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 100)
                return notify_fail("����þ����񹦹�����£����Լ�����ѧ����"
                                   "ȫȻ�޷����ס�\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬������ת�����񹦡�\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "����ľ����񹦡�\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "����ľ����񹦡�\n");
/*
        if (me->query("can_learn/jiuyang-shengong/enable_weapon") &&
            me->query_skill("sword", 1) < level &&
            me->query_skill("blade", 1) < level)
                return notify_fail("��Ե����������⻹�������޷���������"
                                   "����ľ����񹦡�\n");

        if (! me->query("can_learn/jiuyang-shengong/enable_weapon"))
        {
                write(HIG "��ѧ�������þ����񹦼���������\n");
                me->set("can_learn/jiuyang-shengong/enable_weapon", 1);
        }
*/
        return 1;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;

        if ((int)me->query_skill("jiuyang-shengong", 1) < 150
           || me->query_skill_mapped("parry") != "jiuyang-shengong"
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
           || (int)me->query("neili") < 500
           || ob->query_temp("weapon")
           || ! living(me))
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili") + ob->query_skill("count", 1) * 6;
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "Ĭ��������ܾ�������"
                                            "�ھ�������$N" + HIR "��һ�У�$N" HIR
                                            "ֻ������ʯ���󺣣�˿���������á�\n"
                                            NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$N" HIR "һ�л���$n" HIR "����"
                                            "����ȴ��������޻���һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "����$n" HIR "΢΢һЦ����������"
                                            "�Ľ�����$N" HIR "��һ�У�ȴû���ܵ�"
                                            "����˺���\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("jiuyang-shengong", 1);

        if (damage_bonus < 150
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "jiuyang-shengong"
           || me->query_skill_mapped("unarmed") != "jiuyang-shengong"
           || me->query_skill_prepared("unarmed") != "jiuyang-shengong")
		return 0;
		if (userp(me) && (! me->query("can_skill/jiuyang-shengong") || me->query("family/family_name") != "����")) {
			if (damage_bonus > 300)
				damage_bonus = 300;
		}
        if (damage_bonus / 5 > victim->query_con())
        {
	        me->add("neili", -50);
                victim->receive_wound("qi", (damage_bonus - 80) / 2, me);
                return random(2) ? HIR "ֻ��$N" HIR "�����ھ������ڱŷ�����������ʽ"
                                   "���������ݻ���$n" HIR "����Ԫ��\n" NOR:

                                   HIR "$N" HIR "�����񹦵�Ǳ�������˳�����ͻȻ��$n"
                                   HIR "ֻ�к���һ�����һ����Ѫ��\n" NOR;
        }
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("jiuyang-shengong", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 100;
}

int practice_skill(object me)
{
        return notify_fail("������ֻ��ͨ��������о������������ȡ�\n");
}

int difficult_level()
{
        return 700;
}

string perform_action_file(string action)
{
        return __DIR__"jiuyang-shengong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"jiuyang-shengong/exert/" + action;
}
