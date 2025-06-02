//tianmo-gun.c ������ħ��
//By haiyan

inherit SKILL; 

mapping *action = ({
([      "action":"$N�������ˣ�����$wӭ��һ����һ�С��ºڷ�ߡ�������$n��ͷ�������ҽ�������",
        "force" :20,
        "attack":20,
        "dodge" :5,
        "parry" :10,
        "damage":20,
        "lvl"   :0,
        "skill_name" :"�ºڷ��",
        "damage_type":"����"
]),
([      "action":"$N�����ɫ������$w��һ�С���糤�š������������$n��$l����ɨȥ��",
        "force" :50,
        "attack":30,
        "dodge" :10,
        "parry" :25,
        "damage":30,
        "lvl"   :20,
        "skill_name" :"��糤��",
        "damage_type":"����"
]),
([      "action":"$N����һת������$w����һ�ϣ������⽫��δ��֮�ʣ�һ�С����·ת������$n��ͷ���¡�",
        "force" :80,
        "attack":40,
        "dodge" :20,
        "parry" :40,
        "damage":48,
        "lvl"   :50,
        "skill_name" :"���·ת",
        "damage_type":"����"
]),
([      "action":"$N����һת��һ�С��������⡹$w�ó������Ӱ������ʵʵ��Ϯ��$n��$l��",
        "force" :110,
        "attack":50,
        "dodge" :40,
        "parry" :55,
        "damage":65,
        "lvl"   :80,
        "skill_name" :"��������",
        "damage_type":"����"
]),
([      "action":"$N����ʱ���������죬$w�䴦������ϼǧ�ƣ�һʽ���������桹������������ȫȻ����$n���С�",
        "force" :140,
        "attack":60,
        "dodge" :60,
        "parry" :70,
        "damage":75,
        "lvl"   :120,
        "skill_name" :"��������",
        "damage_type":"����"
]),
([      "action":"$n��Ȼ����$N����һ̧ͷֻ��$Nһʽ�����R�L��������������һ�㾶ֱɨ��$n$l��",
        "force" :170,
        "attack":70,
        "dodge" :80,
        "parry" :85,
        "damage":80,
        "lvl"   :150,
        "skill_name" :"���R�L��",
        "damage_type":"����"
]),
});

int valid_enable(string usage) { return usage == "club" || usage == "parry"; }

int valid_learn(object me)
{

     if ((int)me->query_skill("riyue-xinfa", 1) < 80)
         return notify_fail("����ڹ��ķ����̫ǳ������ѧ������ħ����\n");

     if ((int)me->query_skill("club", 1) < 80)
         return notify_fail("��Ļ���������򲻹���\n");

     if ((int)me->query("max_neili") < 350)
         return notify_fail("�������̫�ͣ��޷�ѧ������ħ����\n");

     if ((int)me->query_skill("club", 1) < (int)me->query_skill("tianmo-gun", 1))
         return notify_fail("��Ļ�������ˮƽ���ޣ��޷����������������ħ����\n");

     return 1;
}

string query_skill_name(int level)
{
     int i;
     for(i = sizeof(action)-1; i >= 0; i--)
     if(level >= action[i]["lvl"])
            return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
     int i, level;
     level = (int) me->query_skill("tianmo-gun", 1);
     for(i = sizeof(action); i > 0; i--)
         if(level > action[i-1]["lvl"])
              return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
     object weapon;

     if (! objectp(weapon = me->query_temp("weapon")) ||
        (string)weapon->query("skill_type") != "club")
            return notify_fail("��ʹ�õ��������ԡ�\n");

     if ((int)me->query("qi") < 70)
            return notify_fail("�������������������ħ����\n");

     if ((int)me->query("neili") < 80)
            return notify_fail("�������������������ħ����\n");

     me->receive_damage("qi", 65);
     me->add("neili", -68);
     return 1;
}

string perform_action_file(string action)
{
     return __DIR__"tianmo-gun/" + action;
}

