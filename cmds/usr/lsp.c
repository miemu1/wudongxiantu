#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
string status_color(int current, int max);
int potential_lv(int exp);
int main(object me, string arg)
{
object ob;
int craze;
mapping my;
string str,skill_type;
object weapon;
int attack_points, dodge_points, parry_points;
int lv, level, exp, lvl, comexp, i,l, zs,lel;
mixed need;
seteuid(getuid());
if(!arg) ob = me;
else if (wizardp(me))
{
 ob = present(arg, environment(me));
 if (!ob) ob = find_player(arg);
 if (!ob) ob = find_living(arg);
 if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
}
else return notify_fail("ֻ����ʦ�ſ��Բ쿴���˵�״̬��\n");

my = ob->query_entire_dbase();
if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
return notify_fail("��û�г����ţ��쿴ʲô��\n");

if (my["max_jing"] < 1 || my["max_qi"] < 1)
return notify_fail("�޷��쿴" + ob->name(1) + "��״̬��\n");

lv=ob->query("level");
if (lv < 1) lv = 1;
need=(lv+1)*(lv+1)*(lv+1)*10000-ob->query("combat_exp");
if (need < 1) need = 1;

comexp = ob->query("combat_exp");
for(i=0;comexp>(i/10)*i*i;i++)
lvl = i+1;
lel = lv*100;
zs= ob->query("reborn/times");
str = ZJOBLONG;
str += sprintf("������%s ("HIG"%s"NOR") "NOR,ob->name(),capitalize(ob->query("id")));
str += sprintf(HIC"��"HIY"��������������������������������������������"HIC"��"NOR"\n");

str += sprintf(HIR"�������Ѫ����%s%d/%d%s(%d%%)\n"NOR,status_color(my["qi"]/1000,my["eff_qi"]/1000),my["qi"],my["eff_qi"],
status_color(my["eff_qi"]/100,my["max_qi"]/100),my["eff_qi"]*5/(my["max_qi"]/20));

str += sprintf(HIR"�������������%s%d/%d(+%d)"NOR"\n",status_color(my["neili"]/1000, my["max_neili"]/1000), my["neili"], my["max_neili"],my["jiali"]);

str += sprintf(HIR"������񡽣�%s%d/%d%s(%d%%)\n"NOR,status_color(my["jing"]/100,my["eff_jing"]/100),my["jing"],my["eff_jing"],
status_color(my["eff_jing"]/100,my["max_jing"]/100),my["eff_jing"]*5/(my["max_jing"]/20));

str += sprintf(HIR"�����������%s%d/%d(+%d)"NOR"\n",status_color(my["jingli"],my["max_jingli"]),
 my["jingli"],my["max_jingli"],my["jiajing"]);

str += sprintf(HIR"�����������%s%d/%d(+%d)"NOR"\n",status_color(my["mana"],my["max_mana"]),
 my["mana"],my["max_mana"],my["jiamana"]);
str += sprintf(CYN"�����ʳ���%s%d/%d[%d%%]\n"NOR,status_color(my["food"], ob->max_food_capacity()),
my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
str += sprintf(CYN"�������ˮ����%s%d/%d[%d%%]\n"NOR,status_color(my["water"], ob->max_water_capacity()),
my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
str += sprintf(HIC"�������ȼ����ޡ���" NOR + WHT " %-21d""\n", lvl);
str += sprintf(HIC"������书���ޡ���" NOR + WHT " %-21d""\n", lel);
str += sprintf(HIC"�����ȼ�����" NOR + WHT " %-21d""\n", lv);
str += sprintf(HIC"��ת��BUFF����" NOR + WHT " %-21d""\n", zs);
str += sprintf(HIC"����Ϊ���򣩡��� %s%7d/%7d(up)"NOR"\n",HIM,my["combat_exp"] /10000,F_LEVEL->level_max_exp(ob));
str += sprintf(CYN"��Ǳ�ܣ��򣩡���%s%d/%d(max)"NOR"\n",HIY,(int)ob->query("potential") /10000 - (int)ob->query("learned_points") /10000,(int)ob->query_potential_limit() - (int)ob->query("learned_points") /10000);
str += sprintf(HIC"��"HIY"��������������������������������������������"HIC"��"NOR"\n");
str += sprintf(HIC"�������˼�Ҽ����ơ���" NOR + WHT " %-21d""\n", ob->query_skill("martial-cognize"));
str += sprintf(HIC"��������������" NOR + WHT " %-21d""\n", ob->query_skill("sword-cognize"));
str += sprintf(HIC"��������������" NOR + WHT " %-21d""\n", ob->query_skill("martial-cognize"));
str += sprintf( HIY "�����ǵ�����" HIW "%2d |%4d  " HIY "������������" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
ob->query("gift/xisuidan"),
20,
ob->query("gift/shenliwan"),
20);
str += sprintf( HIY "����������" HIW "%2d |%4d  " HIY "�����Ե�����" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
ob->query("gift/unknowdan"),
20,
ob->query("gift/xiandan"),
20);
if (craze = ob->query_craze())
{
if (ob->is_most_craze())
{
str += (HIR"���ߡ�"+HIY"��ŭ"+NOR+HIR"��"+NOR);
str += sprintf("%s", ob->query("character") == "��������" ? MAG"  �������  ( burning ȼ��ŭ�� )"+NOR+"\n"
: HIM"  ŭ������  ( burning ȼ��ŭ�� )"+NOR+"\n");
}
else
{
str += sprintf(HIR "���ߡ���ŭ����%d/%d(+%d)\n",craze, ob->query_max_craze(),
  ob->query("jianu"));
}
}
  else
{
 str += sprintf(MAG "����ƽ���͡��� ����������������������������������\n"+NOR);
}


str += sprintf(MAG "��ʵս��᡿��%s%d/%d\n���ھ����ޣ��򣩡���%s%d/%d\n",
HIM,my["experience"] - my["learned_experience"],me->query_experience_limit() - my["learned_experience"]/10000 ,HIM,ob->query_neili_limit()/10000,ob->query_jingli_limit()/10000);


str += sprintf(HIC"��"HIY"��������������������������������������������"HIC"��"NOR"\n");





str += sprintf(HIG"  ��"HIY"�츳��"NOR":"HIY+chinese_number(ob->query("tianfu_point"))+NOR"\n");
str += sprintf("��   �о������� " HIC "%8d  "NOR" ѧϰ������ "HIC"%8d"NOR"\n", ob->query("research_times"),ob->query("xuexi_times") );
str += sprintf("��   Ѫ�����ޣ� " HIC "%8d  "NOR" �������ޣ� "HIC"%8d"NOR"\n", ob->query("xueliang"),ob->query("jli") );
str += sprintf("��   �������У� " HIC "%8d  "NOR" ��Ĭ������ "HIC"%8d"NOR"\n", ob->query("apply/xuruo_perform"),ob->query("apply/no_perform") );
str += sprintf("��   �����˺��� " HIC "%8d  "NOR" ����æ�ң� "HIC"%8d"NOR"\n", ob->query("reduce_damage"),ob->query("reduce_busy") );
str += sprintf("��   ׷���˺��� " HIC "%8d  "NOR" �����˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_damage"),ob->query("apply/xuruo_damage") );
str += sprintf("��   ս�������� " HIC "%8d  "NOR" ���з����� "HIC"%8d"NOR"\n", ob->query("apply/xuruo_status"),ob->query("apply/perform_dp") );
str += sprintf("��   ׷�ӷ����� " HIC "%8d  "NOR" ��Ϣ���ң� "HIC"%8d"NOR"\n", ob->query("apply/add_armor"),ob->query("apply/no_exert") );
str += sprintf("��   æ�ҵ��ˣ� " HIC "%8d  "NOR" ���мӳɣ� "HIC"%8d"NOR"\n", ob->query("apply/busy_time"),ob->query("apply/attack") );
str += sprintf("��   ����͵ȡ�� " HIC "%8d  "NOR" ����͵ȡ�� "HIC"%8d"NOR"\n", ob->query("apply/leech_qi"),ob->query("apply/leech_neili") );
str += sprintf("��   ˫���˺��� " HIC "%8d  "NOR" ��ת������ "HIC"%8d"NOR"\n", ob->query("apply/double_damage"),ob->query("apply/qi_abs_neili") );
str += sprintf("��   ��͸���ף� " HIC "%8d  "NOR" �����ָ��� "HIC"%8d"NOR"\n", ob->query("apply/through_armor"),ob->query("apply/neili_recover") );
str += sprintf("��   �����ָ��� " HIC "%8d  "NOR" �����ָ��� "HIC"%8d"NOR"\n", ob->query("apply/qi_recover"),ob->query("apply/jing_recover") );
str += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ħ֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_poison"),ob->query("apply/add_magic") );
str += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ľ֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_metal"),ob->query("apply/add_wood") );
str += sprintf("��   ˮ֮�˺��� " HIC "%8d  "NOR" ��֮�˺��� "HIC"%8d"NOR"\n", ob->query("apply/add_water"),ob->query("apply/add_fire") );
str += sprintf("��   ��֮�˺��� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/add_earth"),ob->query("apply/reduce_poison") );
str += sprintf("��   ħ�˿��ԣ� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_magic"),ob->query("apply/reduce_metal") );
str += sprintf("��   ľ�˿��ԣ� " HIC "%8d  "NOR" ˮ�˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_wood"),ob->query("apply/reduce_water") );
str += sprintf("��   ���˿��ԣ� " HIC "%8d  "NOR" ���˿��ԣ� "HIC"%8d"NOR"\n", ob->query("apply/reduce_fire"),ob->query("apply/reduce_earth") );
str += sprintf("��   ���Ӷ��ˣ� " HIC "%8d  "NOR" ��ä���ʣ� "HIC"%8d"NOR"\n", ob->query("apply/avoid_poison"),ob->query("apply/add_blind") );
str += sprintf("��   �������ʣ� " HIC "%8d  "NOR" �������ʣ� "HIC"%8d"NOR"\n", ob->query("apply/add_freeze"),ob->query("apply/add_forget") );
str += sprintf("��   �������ʣ� " HIC "%8d  "NOR" æ�Ҹ��ʣ� "HIC"%8d"NOR"\n", ob->query("apply/add_weak"),ob->query("apply/add_busy") );
str += sprintf("��   ������ä�� " HIC "%8d  "NOR" ���ӱ����� "HIC"%8d"NOR"\n", ob->query("apply/avoid_blind"),ob->query("apply/avoid_freeze") );
str += sprintf("��   ���������� " HIC "%8d  "NOR" ���������� "HIC"%8d"NOR"\n", ob->query("apply/avoid_forget"),ob->query("apply/avoid_weak") );
str += sprintf("��   ����æ�ң� " HIC "%8d  "NOR" ����æ�ң� "HIC"%8d"NOR"\n", ob->query("apply/avoid_busy"),ob->query("apply/reduce_busy") );
str += sprintf("��   ���ӿ־壺 " HIC "%8d  "NOR" ����һ���� "HIC"%8d"NOR"\n", ob->query("apply/avoid_fear"),ob->query("apply/fatal_blow") );
str = replace_string(str,"\n",ZJBR);
if(str[(strlen(str)-4)..(strlen(str)-1)]=="$br#")
str = str[0..(strlen(str)-5)];
str += "\n";
message("vision", str, me);
return 1;
}
string status_color(int current, int max)
{
int percent;
if( max>0 ) percent = current * 100 / max;
else percent = 100;
if( percent > 100 ) return HIC;
if( percent >= 90 ) return HIG;
if( percent >= 60 ) return HIY;
if( percent >= 30 ) return YEL;
if( percent >= 10 ) return HIR;
return RED;
}
int potential_lv(int level)
{
int grade;
grade =level/5+1;
return grade;
}

int help(object me)
{
write(@HELP
ָ���ʽ : hp
   hp <��������>   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�ľ�, ��, ����ֵ��

see also : score
HELP
);
return 1;
}

