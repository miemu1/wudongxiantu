// yinyang-shiertian.c ���Ͻ���
// ��ʮ��֮ǰͨ�������񹦡������񹦡���ڤ�񹦡��貨΢����Ǭ
// ����Ų�ơ�����ʮ���ƺ������񽣣�����Ϊһ������S+++����ѧ��
// ���Ͻ������Լ���Ϊ�������е��书��

#include <ansi.h>

inherit FORCE;

object me=this_player();
//int sh=random((me->query_skill("force") * 2 /5));
int sh=0;

string *xue_name = ({
"�͹�Ѩ", "����Ѩ", "����Ѩ", "��ԪѨ", "����Ѩ", "�м�Ѩ", "�н�Ѩ", "��ͻѨ", "�ٻ�Ѩ",
"����Ѩ", "����Ѩ", "���Ѩ", "�Ϲ�Ѩ", "��ԨѨ", "�쾮Ѩ", "��ȪѨ", "����Ѩ", "����Ѩ", });

string *attack_name = ({
"��ɽ����", "ɭ�޽���", "�򺣽���", "��������", "��ս���","��������" });

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

lvl = (int)me->query_skill("wushang-jianjing", 1);
return lvl /12 * lvl /13 * 14 * 35 / 12 / 23;
}

int query_jingli_improve(object me)
{
int lvl;

lvl = (int)me->query_skill("wushang-jianjing", 1);

if (me->query_skill_mapped("sword") == "wushang-jianjing")
return lvl * 18 / 9;

return 0;
}

mapping *actionf = ({
([      "action": HIW "$N" HIW "������ָһ���������Ͻ�������ǰ�̳��������ĵ�����"
  "Ȼ���죬���ν���ֱָ$n" HIW,
"force" : 200 + sh,
"attack": 200 + sh,
"dodge" : 200 + sh,
"parry" : 200 + sh,
"damage": 750 + sh,
"weapon": HIW "��ɽ����" NOR,
"damage_type":  "����"
]),
([      "action": HIR "$N" HIR "����һ�࣬һ�����������һ�ɳ����ޱȵ�������ʱ��"
  "��ӿ��$n" HIR "ȫ�����",
"force" : 250 + sh,
"attack": 250 + sh,
"dodge" : 250 + sh,
"parry" : 250 + sh,
"damage": 800 + sh,
"weapon": HIR "ɭ�ֽ���" NOR,
"damage_type":  "����"
]),
([      "action": HIY "$N" HIY "����һת��ȭͷЯ�ż�����ת�������ӳ����������磬"
  "��������������$n" HIY,
"force" : 300 + sh,
"attack": 300 + sh,
"dodge" : 300 + sh,
"parry" : 300 + sh,
"damage": 850 + sh,
"weapon": HIY "�򺣽���" NOR,
"damage_type":  "����"
]),
([      "action": WHT "$N" WHT "˫��ƽƽ�ᵽ��ǰ����ɫ���صĻ���ʩ��������ʮ����"
  "������$n" WHT "ȫ�����",
"force" : 350 + sh,
"attack": 350 + sh,
"dodge" : 350 + sh,
"parry" : 350 + sh,
"damage": 900 + sh,
"weapon": WHT "��������" NOR,
"damage_type": "����"
]),
([      "action": HIW "$N" HIW "˫��ʮָ���죬��ʮ���������ٳ�Ѩ�м������������"
  "���񽣡�������磬ָ��$n" HIW,
"force" : 400 + sh,
"attack": 400 + sh,
"dodge" : 400 + sh,
"parry" : 400 + sh,
"damage": 950 + sh,
"weapon": HIW "��ս���" NOR,
"damage_type":  "����"
]),
([      "action": WHT "$N" WHT "ͻȻ���η���˫�ƾӸ�����һ�С�����ʮ���ơ��ں�"
  "Х����Ѹ���ޱȵ�����$n" WHT "ȫ�����",
"force" : 450 + sh,
"attack": 450 + sh,
"dodge" : 450 + sh,
"parry" : 450 + sh,
"damage": 1000 + sh,
"weapon": WHT "��������" NOR,
"damage_type": "����"
]),
});

mapping *actionw = ({
([      "action": HIY "$N" HIY "���ƺ��������裬$w" HIY "�仯�޳���׽��������$n"
  HIY "������ȥ",
"force" : 300 + sh,
"attack": 300 + sh,
"dodge" : 300 + sh,
"parry" : 300 + sh,
"damage": 850 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "���е�$w" HIY "ͻ������ɭ�ϣ�����ǧ�������۶�"
  "������ͬ����һ���ɨ$n" HIY,
"force" : 350 + sh,
"attack": 350 + sh,
"dodge" : 350 + sh,
"parry" : 350 + sh,
"damage": 900 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "�������е�$w" HIY "����������һ�����$n" HIY "��"
  "�����ң�û�а���·�",
"force" : 400 + sh,
"attack": 400 + sh,
"dodge" : 400 + sh,
"parry" : 400 + sh,
"damage": 950 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "����$w" HIY "�û���һ��һ��ԲȦ���ƺ�Ҫ��$n" HIY
  "���Ű�Χ",
"force" : 450 + sh,
"attack": 450 + sh,
"dodge" : 450 + sh,
"parry" : 450 + sh,
"damage": 1000 + sh,
"damage_type": "����"
]),
([      "action": HIY "$N" HIY "��Ц��ת$w" HIY "����ǰһ�̣��ĵ��黨ָ֮�⣬��"
  "��$n" HIY "ȫ��",
"force" : 500 + sh,
"attack": 500 + sh,
"dodge" : 500 + sh,
"parry" : 500 + sh,
"damage": 1500 + sh,
"damage_type": "����"
]),
});

string main_skill()
{
return "wushang-jianjing";
}

mapping sub_skills = ([
"jiuyin-shengong"  : 999999,
"jiuyang-shengong" : 999999,
"six-finger"       : 999999,
"dragon-strike"    : 999999,
"taixuan-gong"     : 999999,
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
tell_object(me, "������������򣬻���������һ�ξ����ڻ��ͨ���������Ͻ�����\n");
return 0;
}

tell_object(me, HIW "һ�󷲳�����ӿ����ͷ���㼸��������̾�����Ǽ䣬����ۻ��ף�����һ��Ī��\n"
"�ı�������ʦ̩�����ָ߳���ʤ������̩ɽ��С����֮����Ȼ��������ֻ������\n����"
"��ѧ���ڿ����Ƕ�ô����С��Ц��\n" NOR);

CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + me->name() + "������"HIY"���Ͻ���"HIM"��\n");
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

victim->receive_wound("qi", damage_bonus * 3, me);
me->add("neili", me->query("jiali") / 3);

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
dp = me->query_skill("wushang-jianjing", 1);

if (random(ap * 2 / 3) < dp * 3 / 2)
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

lvl = me->query_skill("wushang-jianjing", 1);
if (lvl < 200) return 100;
if (lvl < 250) return 150;
if (lvl < 350) return 180;
return 200;
}

int query_effect_dodge(object attacker, object me)
{
int lvl;

lvl = me->query_skill("wushang-jianjing", 1);
if (lvl < 200) return 100;
if (lvl < 250) return 150;
if (lvl < 350) return 180;
return 200;
}

string perform_action_file(string action)
{
return __DIR__"wushang-jianjing/perform/" + action;
}

string exert_function_file(string action)
{
return __DIR__"wushang-jianjing/exert/" + action;
}

void skill_improved(object me)
{
int i;
string *sub_skillnames;

sub_skillnames = keys(sub_skills);
for (i = 0; i < sizeof(sub_skillnames); i++)
me->delete_skill(sub_skillnames);
}