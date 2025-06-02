// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tangmen-throwing.c

#include <ansi.h>

inherit SKILL;

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});
mapping *action = ({
([	"action":		"$N˫���������裬һ��"+(order[random(13)])+"�������롹"NOR"��$wֱ��$n���ظ�Ҫ��",
	"dodge":		200,
        "force":		200,
	"damage":		60,
	"poison": 30,
	"lvl" : 0,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���λζ���һ��"+(order[random(13)])+"�������롹"NOR"������$w��һ�����ߣ���$n�ʺ��ȥ",
	"dodge":		200,
	"force":		200,
	"damage":		80,
	"poison": 40,
	"lvl" : 60,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��ָ΢�ţ�һ��"+(order[random(13)])+"����Ѫ�롹"NOR"������$w���ð���$nȫ��ȥ",
	"dodge":		200,
	"force":		200,
	"damage":		180,
	"poison": 50,
 	"lvl" : 90,
	"skill_name" : "��Ѫ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N���һ����һ��"+(order[random(13)])+"������롹"NOR"��$w�û�����Ŀ����������$n",
	"dodge":		290,
	"force":		200,
	"damage":		140,
	"poison": 60,
	"lvl" : 100,
	"skill_name" : "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N��һԾ��һ��"+(order[random(13)])+"�������롹"NOR"��$w�����������磬����$nȫ��",
	"dodge":		270,
	"force":		200,
	"damage":		160,
	"poison": 70,
 	"lvl" : 110,
	"skill_name" : "������",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N˫Ŀ��â������һ��"+(order[random(13)])+"������롹"NOR"������$wȫ�����ַɳ�����ɽ���������$nȫ��",
	"dodge":		290,
	"force":		200,
	"damage":		180,
	"poison": 80,
	"lvl" : 120,
	"skill_name":  "�����",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N������Х��һ��"+(order[random(13)])+"����ħ�롹"NOR"��$w��Ȼ����һ��ǿ�Ҿ��磬ɨ��$n",
	"dodge":		207,
	"force":		200,
	"damage":		180,
	"poison": 90,
	"lvl" : 130,
	"skill_name" : "��ħ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
([	"action":		"$N����ɱ��ͻȻ��ʢ��һ��"+(order[random(13)])+"����ɷ�롹"NOR"��$w�ɻȰ����$nȫ��",
	"dodge":		290,
        "force":		200,
	"damage":		180,
	"poison": 100,
	"lvl" : 200,
	"skill_name" : "��ɷ��",
	"post_action":  (: call_other, WEAPON_D, "throw_weapon" :),
	"damage_type":	"����"
]),
});

int valid_enable(string usage) { return (usage == "throwing") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query_skill("force") < 60)
                return notify_fail("����ڹ��ķ���򲻹����޷�ѧ���Ű�����\n");

        if ((int)me->query_skill("dodge") < 60)
                return notify_fail("����Ṧ��򲻹����޷��������Ű�����\n");

        if ((int)me->query("dex") < 30)
                return notify_fail("������������ɣ��޷�ѧϰ���Ű�����\n");

        if ((int)me->query("int") < 25)
                return notify_fail("������Բ������޷�ѧϰ���Ű�����\n");

        if ((int)me->query_skill("throwing", 1) < (int)me->query_skill("tangmen-throwing", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ�����������������Ű�����\n");

        return 1;
}

int practice_skill(object me)
{
        //object weapon;

        if ((int)me->query("qi") < 60)
                return notify_fail("�������̫���ˡ�\n");

        if ((int)me->query("neili") < 60)
                return notify_fail("����������������Ű�����\n");

        me->receive_damage("qi", 50);
        me->add("neili", -50);
        return 1;
}

string perform_action_file(string action)
{
        return __DIR__"tangmen-throwing/" + action;
}

