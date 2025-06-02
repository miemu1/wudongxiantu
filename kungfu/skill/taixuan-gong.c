#include <ansi.h> 
inherit FORCE;

string *dodge_msg = ({
        "$n����̫�������ŷ�������$n�����ĳ������絽������$N��һ�ߡ�\n",
        "$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������\n",
        "$nĬ��̫���ھ���������ţ���Ծ��������������ʮ�����⡣\n",
        "$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�\n",
});

int query_neili_improve(object me)
{
        int lvl;

        lvl = (int)me->query_skill("taixuan-gong", 1);
          return lvl * lvl * 20 * 15 / 100 / 200;
}

mapping *actionf = ({
([      "action":"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���",
        "force" : 450,
        "attack": 150,
        "dodge" : 70,
        "parry" : 80,
        "damage": 95,
        "damage_type":  "����"
]),
([      "action":"$N�����������ʱһ�������������Ϯ��$n",    
        "force" : 470,
        "attack": 140,
        "dodge" : 60,
        "parry" : 90,
        "damage": 110,
        "damage_type":  "����"
]),
([      "action":"$N���һ��������һ������ʱһ��������$n����ӿȥ",
        "force" : 440,
        "attack": 135,
        "dodge" : 55,
        "parry" : 85,
        "damage": 100,
        "damage_type":  "����"
]),
([      "action":"$N�����ϣ�ȫ������������˫���͵�����$n",
        "force" : 480,
        "attack": 170,
        "dodge" : 100,
        "parry" : 75,
        "damage": 95,
        "damage_type":  "����"
]),
([      "action":"$N�����죬������֣�ͻȻ��$N˫�������ĳ�������̫���ھ�������$n",
        "force" : 470,
        "attack": 175,
        "dodge" : 80,
        "parry" : 65,
        "damage": 110,
        "damage_type":  "����"
]),
([      "action":"$NͻȻ������һ�࣬��ס$n��·������������ӿ����",
        "force" : 460,
        "attack": 160,
        "dodge" : 75,
        "parry" : 85,
        "damage": 100,
        "damage_type":  "����"
]),
});

mapping *actionw = ({
([      "action" : "$N������磬���ƷǷ���$w�������֣�׽��������$n������ȥ",
        "force" : 410,
        "attack": 80,
        "dodge" : 75,
        "parry" : 85,
        "damage": 95,
        "damage_type": "����"
]),
([      "action":"$N���е�$w�������������糤��������������$n����",
        "force" : 410,
        "attack": 88,
        "dodge" : 72,
        "parry" : 85,
        "damage": 110,
        "damage_type": "����"
]),
([      "action":"$N�������е�$w�����緭������ֱ����$n��ȥ",
        "force" : 432,
        "attack": 125,
        "dodge" : 100,
        "parry" : 82,
        "damage": 95,
        "damage_type": "����"
]),
([      "action":"$N����$w�ó�һ�����⻷����ʱ��$n���Ű�Χ",
        "force" : 465,
        "attack": 110,
        "dodge" : 105,
        "parry" : 105,
        "damage": 120,
        "damage_type": "����"
]),
([      "action":"$N�����������$w����������ؾ���$n",
        "force" : 455,
        "attack": 118,
        "dodge" : 100,
        "parry" : 100,
        "damage": 120,
        "damage_type": "����"
]),
});

mapping *actionbad = ({
([      "action" : "$N����ʩ�У�ȴ��ͻȻ���ú�����������ʽ��ֻ�ú���ʹ����",
        "force" : 10,
        "attack": 10,
        "dodge" : 10,
        "parry" : 10,
        "damage": 10,
        "damage_type": "����"
]),
});

int valid_enable(string usage)
{ 
        object me = this_player();

       // if (me->query_skill("taixuan-gong", 1)<180 && me->query_skill("literate", 1))
        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//��Ϊ�������ж��鼼�ܳ���ת�� by luoyun 2018.5.12
                return usage == 0;

        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage == "parry";
        else
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage == "parry";
 
        else 
        if (me->query_skill("sword", 1) < me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) > me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="blade" || usage == "parry";

        else
        if (me->query_skill("sword", 1) > me->query_skill("taixuan-gong", 1)
            && me->query_skill("blade", 1) < me->query_skill("taixuan-gong", 1))
                return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="sword" || usage == "parry";

        else        
            return usage == "force" || usage == "unarmed" || usage == "dodge" || usage =="blade" || usage == "parry" || usage == "sword";
       
}

mapping query_action(object me, object weapon)
{
        if ( !me->query("relife/zhuanshi"))//��Ϊ�������ж��鼼�ܳ���ת�� by luoyun 2018.5.12
               return actionbad[0];

        return weapon ? actionw[random(sizeof(actionw))] :
                        actionf[random(sizeof(actionw))];
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
        mapping result;
        int ap, dp;
        int cost;  

        if ( !me->query("relife/zhuanshi"))//��Ϊ�������ж��鼼�ܳ���ת�� by luoyun 2018.5.12
               return;

        cost = damage / 4;

        if ((int)me->query_skill("taixuan-gong", 1) < 150
		   || !me->query_temp("parry_valid_damage")
           || me->query_skill_mapped("parry") != "taixuan-gong"
           || me->query_skill_mapped("force") != "taixuan-gong"
           || me->query_skill_mapped("unarmed") != "taixuan-gong"
           || (int)me->query("neili") < (int)me->query("max_neili")/3
           || (int)me->query("neili") < cost
           || ! living(me))
                return;

        ap = ob->query_skill("force") * 12 + ob->query("max_neili");
        dp = me->query_skill("force") * 12 + me->query("neili");

        if (ap / 2 + random(ap) < dp)
        {
                me->add("neili", -cost);
                result = ([ "damage": -damage ]);

                switch (random(2))
                {
                case 0:
                        result += (["msg" : HIR "$n" HIR "Ĭ��̫�����ھ���̫����"
                                            "�������ȫ��$N" HIR "ֻ�����й���"
                                            "$n" HIR "���ϣ���������ͭǽ����һ�㣬"
                                            "˿���������á�\n"NOR]);
                        break;
                case 1:
                        result += (["msg" : HIR "$N" HIR "һ�л���$n" HIR "����"
                                            "����ȴ�������ͭǽ������һ�㣬������ʱ"
                                            "��ʧ����Ӱ���١�\n" NOR]);
                        break;
                default:
                        result += (["msg" : HIR "����$n" HIR "һ����Х����������"
                                            "�Ľ�����$N" HIR "��һ�У�ȴû���ܵ�"
                                            "����˺���\n" NOR]);
                        break;
                }
                return result;
        }
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        mixed result;
        string msg;
        int lvl;
        object weapon = me->query_temp("weapon");

        lvl = me->query_skill("taixuan-gong", 1);

        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//��Ϊ�������ж��鼼�ܳ���ת�� by luoyun 2018.5.12
               return 0;

        if (damage_bonus < 150
           || lvl < 140
           || me->query("neili") < 300
           || me->query_skill_mapped("force") != "taixuan-gong")
                return 0;

        // δѧ���������
        if (! me->query("can_learned/taixuan-gong/enable_weapon"))
        {
             if (me->query_skill_prepared("unarmed") != "taixuan-gong")
                      return 0;
        }

        // �Ѿ����������
        if (me->query("can_learned/taixuan-gong/enable_weapon"))
        {             
             if (! objectp(weapon))
                  if (me->query_skill_prepared("unarmed") != "taixuan-gong")           
                         return 0;

             if (objectp(weapon) && weapon->query("skill_type") != "sword" 
                 && weapon->query("skill_type") != "blade")
                         return 0;
           
             if (objectp(weapon) && weapon->query("skill_type") == "sword"
                 && me->query_skill_mapped("sword") != "taixuan-gong")
                         return 0;
            
             if (objectp(weapon) && weapon->query("skill_type") == "blade"
                 && me->query_skill_mapped("blade") != "taixuan-gong")
                         return 0;                                   
        }

        if (random(damage_bonus) / 2 > victim->query_con() && random(2))
        {
                me->add("neili", -100);
                result = ([ "damage" : (damage_bonus - 80)/3 ]);

                if (me->query("can_learned/taixuan-gong/enable_weapon") && objectp(weapon))
                {
                        msg = random(2) ? HIM "$N" HIM "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                           "��ʱԴԴ����͸��" + weapon->name() + HIM "ӿ��$n" HIM "��"
                                           "�ڣ�\n" NOR:
                                           HIM "$N" HIM "̫���ھ��ŷ���$n" HIM "ֻ��ȫ��һ�𣬵�ʱһ"
                                           "������֮��͸�ض�����" + weapon->name() + HIM "��Ѫ���죡\n" NOR;
                } else
                {
                        msg = random(2) ? HIW "$N" HIW "һ�й�����������ǧ�����ˣ�̫���ھ�"
                                           "��ʱԴԴ����ӿ��$n" HIW "���ڣ�\n" NOR:
                                           HIW "$N" HIW "̫���ھ��ŷ���$n" HIW "ֻ��ȫ��һ"
                                           "�𣬵�ʱ�������������������߹ǣ�\n" NOR;
                }
                result += ([ "msg" : msg ]);
                return result;
        }
}

int practice_skill(object me)
{
        return notify_fail("̫����ֻ����ѧ(learn)�������������ȡ�\n");
}

int valid_learn(object me)
{
        int level;
 
        if ( !me->query("relife/zhuanshi") && me->query_skill("literate", 1))//��Ϊ�������ж��鼼�ܳ���ת�� by luoyun 2018.5.12
                return notify_fail("�����̫�������֮����һʱ��������ᡣ\n");

        if (me->query("gender") == "����")
                return notify_fail("���޸����ԣ����������������������̫������\n");

        if ((int)me->query("int") < 18)
                return notify_fail("����������Ȼ�������е㲻���ס�\n");

        if ((int)me->query("dex") < 25)
                return notify_fail("���о��˰��죬ֻ����ʽʼ���޷�����ʩչ��\n");
        
        if ((int)me->query("con") < 25)
                return notify_fail("���о��˰��죬ֻ���ø�����Щ���ʽʼ���޷�����ʩչ��\n");
        
        if ((int)me->query("str") < 25)
                return notify_fail("���о��˰��죬�о�������Щ�ͣ�ʼ���޷�����ʩչ��\n");

        level = me->query_skill("taixuan-gong", 1);

        if (me->query_skill("force", 1) < level)
                return notify_fail("��Ի����ڹ�����⻹�������޷���������"
                                   "�����̫������\n");

        if (me->query_skill("unarmed", 1) < level)
                return notify_fail("��Ի���ȭ�ŵ���⻹�������޷���������"
                                   "�����̫������\n");

        return ::valid_learn(me);
}

int get_ready(object me)
{
        return 1;
}

int difficult_level()
{
        return 200;
}

string perform_action_file(string action)
{
        return __DIR__"taixuan-gong/perform/" + action;
}

string exert_function_file(string action)
{
        return __DIR__"taixuan-gong/exert/" + action;
}
