// yinyang-shiertian.c �����淨
// �����淨���Լ���Ϊ�������е��书��

#include <ansi.h>

inherit FORCE;

object me=this_player();
//int sh=random((me->query_skill("force") * 2 /5));
int sh=0;

string *xue_name = ({
"�����", "ľ���", "ˮ���", "�����", "�����", "�����", "�����", "�����", "�����",
"�����", "�����", "�ռ����", "�������", "�ڰ����", "�ռ����", "�����", "�����", "�����", });

string *attack_name = ({
"����籩", "����׽�", "�������", "ɭ������", "��ʱ�վ�ɱ","������Ĩ��" });

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

lvl = (int)me->query_skill("xiuxian-gongfas", 1);
return lvl /120 * lvl /42 * 23 * 12 / 5 / 1;
}

int query_jingli_improve(object me)
{
int lvl;

lvl = (int)me->query_skill("xiuxian-gongfas", 1);

if (me->query_skill_mapped("force") == "xiuxian-gongfas")
return lvl * 16 / 9;

return 0;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "������ָһ����������籩����ǰ�̳�����"
  "Ȼ���죬$n��������������ɣ�����" HIW,
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": HIW "����籩" NOR,
"damage_type":  "����"
]),
([      "action": HIR "$N" HIR "������ǰ��ѹ����պ�¡¡�ı�����׵磬"
  "ֻ��һ˲�䣬�׵縲��$n" HIR "ȫ�����������",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": HIR "����׽�" NOR,
"damage_type":  "����"
]),
([      "action": HIY "$N" HIY "����һת������Я�ż��������ӳ���ֻ��һ˲�䣬"
  "�ͽ�$n���⣡����" HIY,
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": HIY "�������" NOR,
"damage_type":  "����"
]),
([      "action": WHT "$N" WHT "˫�ƻ�����£����ɫ���صĻ���ʩ����ɭ�����󡹣�"
  "ֻ��һ˲�䣬���˺�ѣ�������ľ��Χ��ѹ��$n" WHT "ȫ�����������",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": WHT "ɭ������" NOR,
"damage_type": "ѹ��"
]),
([      "action": HIW "$N" HIW "���ֽ�ָ������ǰ���ڵ�����ռ�"
  "����ɱ����$n��Χ�Ŀռ�˲�����齫������˺�ѣ�����" HIW,
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": HIW "��ռ��ɱ" NOR,
"damage_type":  "����"
]),
([      "action": WHT "$N" WHT "˫�ƺ�£�����һ�����������������˫��"
  "����$n" WHT "����˲�仯���ҳ������ɢ������",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"weapon": WHT "������ĥ��" NOR,
"damage_type": "����"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
  HIY "������ȥ",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "���е�$w" HIY "ͻ������ɭ����ǧ�������۶�"
  "������ͬ����һ���ɨ$n" HIY,
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "�������е�$w" HIY "����������һ�����$n" HIY "��"
  "�����ң�û�а���·�",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "����$w" HIY "�û���һ��һ��ԲȦ���ƺ�Ҫ��$n" HIY
  "���Ű�Χ",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "��Ц��ת$w" HIY "������һָ��"
  "��$n" HIY "ȫ��",
"force" : 1000 + sh,
"attack": 1000 + sh,
"dodge" : 1000 + sh,
"parry" : 1000 + sh,
"damage": 5000 + sh,
"damage_type": "����"
]),
});

string main_skill()
{
return "xiuxian-gongfas";
}

mapping sub_skills = ([
"taiyan-dijing": 999999,
"wushang-jianjing": 999999,
"douzhan-shengjing": 999999,
"shanggu-mijing": 999999,
"lianyu-mojing": 99999,
]);

int get_ready(object me)
{
return 1;
}

int get_finish(object me)
{
object ob;
ob = environment(me);

if (random(30) != 1 && ! wizardp(me))
{
tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ�����������淨��\n");
return 0;
}

tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
"�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
"��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);

CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "������"HIY"�����淨"HIM"��\n");
return 1;
}

mapping query_sub_skills()
{
return sub_skills;
}

string *usage_skills = ({ "unarmed", "strike", "claw", "hand", "cuff", "finger",
  "sword", "blade", "hammer", "throwing", "club", "whip",
  "staff", "dodge", "dagger", "parry", "force" });

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

int difficult_level()
{
return 300000;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
string name1, name2, weapon;
name1 = xue_name[random(sizeof(xue_name))];
name2 = attack_name[random(sizeof(attack_name))];

victim->receive_wound("qi", damage_bonus * 8, me);
me->add("neili", me->query("jiali") * 11 / 3);

if (victim->query("neili") < 500)
victim->set("neili", 0);
else
victim->add("neili", -500);

return NOR + HIR "$n" HIR "����$N" HIR "һ�У�" + name2 + "��ʱ�����"
       "�룬ȫ��������" + name1 + "��к������\n" NOR;
}

mixed valid_damage(object ob, object me, int damage, object weapon)
{
mapping result;
int ap, dp;

ap = ob->query_skill("parry");
dp = me->query_skill("xiuxian-gongfas", 1);

if (random(ap * 5 / 3) < dp * 5 / 2)
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

int query_effect_parry(object attacker, object me)
{
int lvl;

lvl = me->query_skill("xiuxian-gongfas", 1);
if (lvl < 200) return 100;
if (lvl < 250) return 150;
if (lvl < 350) return 180;
return 200;
}

int query_effect_dodge(object attacker, object me)
{
int lvl;

lvl = me->query_skill("xiuxian-gongfas", 1);
if (lvl < 200) return 100;
if (lvl < 250) return 150;
if (lvl < 350) return 180;
return 200;
}

string perform_action_file(string action)
{
return __DIR__"xiuxian-gongfas/perform/" + action;
}

string exert_function_file(string action)
{
return __DIR__"xiuxian-gongfas/exert/" + action;
}

void skill_improved(object me)
{
int i;
string *sub_skillnames;

sub_skillnames = keys(sub_skills);
for (i = 0; i < sizeof(sub_skillnames); i++)
me->delete_skill(sub_skillnames);
}