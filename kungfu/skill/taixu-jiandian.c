#include <ansi.h>

inherit FORCE;
string *dodge_msg = ({
        "$N���μ��٣����Ų�ƣ�����$n������Χ�ȹ�������ȴ�����ڼ䲻�ݷ��Ŀ�϶�ܹ�\n",
        "$N���п���ת�ۣ���$nÿ�ι���ǰ��ٿ����ʧ��һ���Ӿ��ѳ�$n�Ĺ�����Χ\n",        
        "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ������������\n", 
        "$Nƾ������������$n�Ĺ�����Χ�ڽ������ܣ���������һ����һ���Ĺ���\n",
        "$N��Ų���٣���Ȼ�ڿ����γ���Ӱ������������$Nһ��Ų��\n",
        "$n��ǰ��Ȼһ������ǰ$N����Ӱ�ƺ���Щ������������һ��$N������������ǰ����һ�ߵĽ���\n",
});
int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taixu-jiandian", 1);
        return lvl / 10 * lvl / 10 * 15 * 25 / 10 / 20;
}

mapping *actionf = ({
([      "action": "$N����һԾ��������Ȼ�ӿ죬����$n$l���ٹ�����ʮȭ",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "������" NOR,
        "damage_type":  "����"
]),
([      "action": "$N����������һȭ����$n��ɲ�Ǽ䣬$Nȫ�����ֳ�һ�����",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "������" NOR,
        "damage_type":  "����"
]),
([      "action": "$N��̫�齣���˾��ڱۣ�һ�������ն����������һ�����ȵĻ�â",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "������" NOR,
        "damage_type":  "����"
]),
([      "action": "$N�粽��ǰ������΢΢һչ��˫�ƶ�׼$n$lһ������",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "����ʽ" NOR,
        "damage_type":  "����"
]),
([      "action": "$N����̫�齣���ھ����͵�һȭ�ں�Х���ж�Ȼ�ӻ�����",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "�ؽ���" NOR,
        "damage_type":  "����"
]),
([      "action": "$Nһ�����ȣ�ʮָĺ���ſ���һ���ۺ���ھ����ȶ���",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "weapon": HIC "�۽�ʽ" NOR,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action" : "$N���ƺ��������裬$w�仯�޳���׽��������$n������ȥ",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "����"
]),
([      "action":"$N���е�$wͻ������ɭ�ϣ�����ǧ�������۶�����$w����һ����â����$n",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w����ʱ��â���ǣ����罾���һ�ֱ����$n��ȥ",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "����"
]),
([      "action":"$N����$w�û���һ��һ��ԲȦ����ʱ������Ȧ��$n���Ű�Χ",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "����"
]),
([      "action":"$N��ת$wңָ$n����ʱ$w���˶�ʱ͸��һ�����²����Ļ�⣬�������",
        "force" : 500,
        "attack": 500,
        "dodge" : 500,
        "parry" : 500,
        "damage": 500,
        "damage_type": "����"
]),
});

string main_skill() { return "taixu-jiandian"; }

int get_ready(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        object me = this_player();

                return usage == "force" || usage == "unarmed" || usage =="parry"|| usage == "sword"|| usage == "dodge";
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

	if (me->query("gender") == "����" && (int)me->query_skill("taixu-jiandian", 1) > 49)
		return notify_fail("���޸����ԣ����������������������̫�齣�䡣\n");

	if (me->query("int") < 50)
		return notify_fail("�����̫�齣�����ڼ��������⡣\n");

	if (me->query("con") < 50)
		return notify_fail("��ĸ��ǲ��ã�������ת̫�齣����\n");
	if (me->query("str") < 50)
		return notify_fail("�����̫�齣�����ڼ��������⡣\n");

	if (me->query("dex") < 50)
		return notify_fail("��ĸ��ǲ��ã�������ת̫�齣����\n");

        if ((int)me->query("max_neili") < 50000)
            return notify_fail("���������Ϊ̫ǳ���޷���ת̫�齣����\n");

        level = me->query_skill("taixu-jiandian", 1);

        if ((int)me->query_skill("martial-cognize", 1) < 300)
                return notify_fail("�����̫�齣�������£����Լ�����ѧ����"
                                   "ȫȻ�޷����ס�\n");

        if ((int)me->query_skill("force", 1) < 300)
                return notify_fail("��Ļ����ڹ���Ϊ���㣬������ת̫�齣�䡣\n");

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "�����̫�齣����\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "�����̫�齣����\n");
		if (me->query_skill("dodge", 1) < level)
                return notify_fail("��Ի����Ṧ����⻹�������޷���������"
                                   "�����̫�齣����\n");

        if (me->query_skill("sword", 1) < level)
                return notify_fail("��Ի�����������⻹�������޷���������"
                                   "�����̫�齣����\n");

        return 1;
}

string query_dodge_msg(string limb)
		{    return dodge_msg[random(sizeof(dodge_msg))];}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp,cp,kp;
        int cost;

        if ((int)me->query_skill("taixu-jiandian", 1) < 250
           || me->query_skill_mapped("parry") != "taixu-jiandian"
           || me->query_skill_mapped("force") != "taixu-jiandian"
           || me->query_skill_mapped("unarmed") != "taixu-jiandian"
           || (int)me->query("neili") < 500
           || ob->query_temp("weapon")
           || ! living(me))
                return;

        cost = damage / 2;
        if (cost > 100) cost = 100;

        ap = ob->query_skill("force") * 12 + ob->query("neili");
        dp = me->query_skill("force") * 12 + me->query("max_neili");
		cp = me->query_skill("dodge") * 12 + me->query("max_neili");
		kp = ob->query_skill("dodge") * 12 + me->query("neili");
        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "Ĭ��̫�齣���ܾ�������"
                                            "�ھ�������$N" + HIC "��һ�У�$N" HIC
                                            "ֻ������ʯ���󺣣�˿���������á�" +
                                            COMBAT_D->do_respond(me, ob, damage, 50, HIR "$Pֻ��һ�ɰ�����ӿ���������ɼ��Ļ����Լ���"NOR"\n")]);
                        break;
                case 1:
                        result += (["msg" : HIC "$N" HIC "һ�л���$n" HIC "����"
                                            "����ȴ��������޻���һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�"+
											COMBAT_D->do_respond(me, ob, damage, (me->query("int"))*6, HIR "$Pֻ��һ�ɰ���������������ʱһ����Ѫ��ӿ��"NOR"\n")]);
                        break;
                default:
                        result += (["msg" : HIC "����$n" HIC "΢΢һЦ����������"
                                            "�Ľ�����$N" HIC "��һ�У�ȴû���ܵ�"
                                            "����˺���" +
											COMBAT_D->do_respond(me, ob, damage, 50, HIR "$Pֻ��һ�ɰ�����ӿ���������ɼ��Ļ����Լ���"NOR"\n")]);
                        break;
                }
                return result;
        }
		else if (kp / 2 + random(kp) < cp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIC "$n" HIC "Ĭ��̫�齣���ܾ�������"
                                            "�ھ�������$N" + HIC "��һ�У�$N" HIC
                                            "ֻ������ʯ���󺣣�˿���������á�" +
                                            COMBAT_D->do_respond(me, ob, damage, 50, HIR "$Pֻ��һ�ɰ�����ӿ���������ɼ��Ļ����Լ���"NOR"\n")]);
                        break;
                case 1:
                        result += (["msg" : HIC "$N" HIC "һ�л���$n" HIC "����"
                                            "����ȴ��������޻���һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�"+
											COMBAT_D->do_respond(me, ob, damage, (me->query("int"))*6, HIR "$Pֻ��һ�ɰ���������������ʱһ����Ѫ��ӿ��"NOR"\n")]);
                        break;
                default:
                        result += (["msg" : HIC "����$n" HIC "΢΢һЦ����������"
                                            "�Ľ�����$N" HIC "��һ�У�ȴû���ܵ�"
                                            "����˺���" +
											COMBAT_D->do_respond(me, ob, damage, 50, HIR "$Pֻ��һ�ɰ�����ӿ���������ɼ��Ļ����Լ���"NOR"\n")]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int lvl;

        lvl = me->query_skill("taixu-jiandian", 1);

        if (damage_bonus < 150
           || lvl < 150
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "taixu-jiandian"
           || me->query_skill_mapped("unarmed") != "taixu-jiandian"
           || me->query_skill_prepared("unarmed") != "taixu-jiandian")
		return 0;
		if (userp(me) && (me->query("family/family_name") != "̫��ɽ")) {
			if (damage_bonus > 1000)
				damage_bonus = 1000;
		}
        if (damage_bonus / 5 > victim->query_con())
        {
	        me->add("neili", -50);
                victim->receive_wound("qi",damage_bonus, me);
                return random(2) ? HIC "ֻ��$N" HIC "̫�齣�������ڱŷ�����������ʽ"
                                   "���������ݻ���$n" HIC "����Ԫ��\n" NOR:

                                   HIC "$N" HIC "̫�齣�������������˳�����ͻȻ��$n"
                                   HIC "ֻ�к���һ�����һ����Ѫ��\n" NOR;
        }
		else if (damage_bonus / 5 > victim->query_con() &&
	    victim->affect_by("taixu",
			      ([ "level" : damage_bonus + random(damage_bonus),
				 "id"    : me->query("id"),
				 "duration" : lvl / 50 + random(lvl / 20) ])))
	{
		return HIR "$n" HIR "һ���ҽУ�ֻ�����ϱ�������Ű������\n";
	}
}

int query_effect_parry(object attacker, object me)
{
        int lvl;

        lvl = me->query_skill("taixu-jiandian", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 500;
}

int query_effect_dodge(object attacker, object me) 
{ 
	int lvl; 
      
	lvl = me->query_skill("taixu-jiandian", 1);
        if (lvl < 150) return 0;
        if (lvl < 200) return 50;
        if (lvl < 250) return 60;
        if (lvl < 300) return 70;
        if (lvl < 350) return 80;
        if (lvl < 400) return 90;
        return 500;
} 

int practice_skill(object me)
{
        return notify_fail("̫�齣��ֻ��ͨ��������о������������ȡ�\n");
}

int difficult_level()
{
        return 5;
}

string perform_action_file(string action)
{
        return __DIR__"taixu-jiandian/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"taixu-jiandian/exert/" + action;
}
