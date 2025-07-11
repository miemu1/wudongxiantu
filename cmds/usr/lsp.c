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
 if (!ob) return notify_fail("您要察看谁的状态？\n");
}
else return notify_fail("只有巫师才可以察看别人的状态。\n");

my = ob->query_entire_dbase();
if (userp(ob) && (! stringp(my["born"]) || ! my["born"]))
return notify_fail("还没有出生呐，察看什么？\n");

if (my["max_jing"] < 1 || my["max_qi"] < 1)
return notify_fail("无法察看" + ob->name(1) + "的状态。\n");

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
str += sprintf("姓名：%s ("HIG"%s"NOR") "NOR,ob->name(),capitalize(ob->query("id")));
str += sprintf(HIC"≡"HIY"──────────────────────"HIC"≡"NOR"\n");

str += sprintf(HIR"〖最大气血〗：%s%d/%d%s(%d%%)\n"NOR,status_color(my["qi"]/1000,my["eff_qi"]/1000),my["qi"],my["eff_qi"],
status_color(my["eff_qi"]/100,my["max_qi"]/100),my["eff_qi"]*5/(my["max_qi"]/20));

str += sprintf(HIR"〖最大内力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["neili"]/1000, my["max_neili"]/1000), my["neili"], my["max_neili"],my["jiali"]);

str += sprintf(HIR"〖最大精神〗：%s%d/%d%s(%d%%)\n"NOR,status_color(my["jing"]/100,my["eff_jing"]/100),my["jing"],my["eff_jing"],
status_color(my["eff_jing"]/100,my["max_jing"]/100),my["eff_jing"]*5/(my["max_jing"]/20));

str += sprintf(HIR"〖最大精力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["jingli"],my["max_jingli"]),
 my["jingli"],my["max_jingli"],my["jiajing"]);

str += sprintf(HIR"〖最大法力〗：%s%d/%d(+%d)"NOR"\n",status_color(my["mana"],my["max_mana"]),
 my["mana"],my["max_mana"],my["jiamana"]);
str += sprintf(CYN"〖最大食物〗：%s%d/%d[%d%%]\n"NOR,status_color(my["food"], ob->max_food_capacity()),
my["food"], ob->max_food_capacity(),my["food"]*100/ob->max_food_capacity());
str += sprintf(CYN"〖最大饮水〗：%s%d/%d[%d%%]\n"NOR,status_color(my["water"], ob->max_water_capacity()),
my["water"], ob->max_water_capacity(),my["water"]*100/ob->max_water_capacity());
str += sprintf(HIC"〖功法等级上限〗：" NOR + WHT " %-21d""\n", lvl);
str += sprintf(HIC"〖天魂武功上限〗：" NOR + WHT " %-21d""\n", lel);
str += sprintf(HIC"〖天魂等级〗：" NOR + WHT " %-21d""\n", lv);
str += sprintf(HIC"〖转世BUFF〗：" NOR + WHT " %-21d""\n", zs);
str += sprintf(HIC"〖修为（万）〗： %s%7d/%7d(up)"NOR"\n",HIM,my["combat_exp"] /10000,F_LEVEL->level_max_exp(ob));
str += sprintf(CYN"〖潜能（万）〗：%s%d/%d(max)"NOR"\n",HIY,(int)ob->query("potential") /10000 - (int)ob->query("learned_points") /10000,(int)ob->query_potential_limit() - (int)ob->query("learned_points") /10000);
str += sprintf(HIC"≡"HIY"──────────────────────"HIC"≡"NOR"\n");
str += sprintf(HIC"〖天上人间壹佰零捌〗：" NOR + WHT " %-21d""\n", ob->query_skill("martial-cognize"));
str += sprintf(HIC"〖剑道修养〗：" NOR + WHT " %-21d""\n", ob->query_skill("sword-cognize"));
str += sprintf(HIC"〖剑道修养〗：" NOR + WHT " %-21d""\n", ob->query_skill("martial-cognize"));
str += sprintf( HIY "【根骨丹】：" HIW "%2d |%4d  " HIY "【力量丹】：" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
ob->query("gift/xisuidan"),
20,
ob->query("gift/shenliwan"),
20);
str += sprintf( HIY "【身法丹】：" HIW "%2d |%4d  " HIY "【悟性丹】：" HIW "%2d |%4d" NOR+YEL "  \n" NOR ,
ob->query("gift/unknowdan"),
20,
ob->query("gift/xiandan"),
20);
if (craze = ob->query_craze())
{
if (ob->is_most_craze())
{
str += (HIR"【愤　"+HIY"　怒"+NOR+HIR"】"+NOR);
str += sprintf("%s", ob->query("character") == "光明磊落" ? MAG"  竖发冲冠  ( burning 燃烧怒气 )"+NOR+"\n"
: HIM"  怒火中烧  ( burning 燃烧怒气 )"+NOR+"\n");
}
else
{
str += sprintf(HIR "【愤　　怒】：%d/%d(+%d)\n",craze, ob->query_max_craze(),
  ob->query("jianu"));
}
}
  else
{
 str += sprintf(MAG "【心平气和】： ─────────────────\n"+NOR);
}


str += sprintf(MAG "【实战体会】：%s%d/%d\n【内精极限（万）】：%s%d/%d\n",
HIM,my["experience"] - my["learned_experience"],me->query_experience_limit() - my["learned_experience"]/10000 ,HIM,ob->query_neili_limit()/10000,ob->query_jingli_limit()/10000);


str += sprintf(HIC"≡"HIY"──────────────────────"HIC"≡"NOR"\n");





str += sprintf(HIG"  ★"HIY"天赋点"NOR":"HIY+chinese_number(ob->query("tianfu_point"))+NOR"\n");
str += sprintf("│   研究次数： " HIC "%8d  "NOR" 学习次数： "HIC"%8d"NOR"\n", ob->query("research_times"),ob->query("xuexi_times") );
str += sprintf("│   血量上限： " HIC "%8d  "NOR" 精力上限： "HIC"%8d"NOR"\n", ob->query("xueliang"),ob->query("jli") );
str += sprintf("│   削弱绝招： " HIC "%8d  "NOR" 沉默攻击： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_perform"),ob->query("apply/no_perform") );
str += sprintf("│   化解伤害： " HIC "%8d  "NOR" 化解忙乱： "HIC"%8d"NOR"\n", ob->query("reduce_damage"),ob->query("reduce_busy") );
str += sprintf("│   追加伤害： " HIC "%8d  "NOR" 虚弱伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_damage"),ob->query("apply/xuruo_damage") );
str += sprintf("│   战力削弱： " HIC "%8d  "NOR" 绝招防御： "HIC"%8d"NOR"\n", ob->query("apply/xuruo_status"),ob->query("apply/perform_dp") );
str += sprintf("│   追加防御： " HIC "%8d  "NOR" 内息紊乱： "HIC"%8d"NOR"\n", ob->query("apply/add_armor"),ob->query("apply/no_exert") );
str += sprintf("│   忙乱敌人： " HIC "%8d  "NOR" 命中加成： "HIC"%8d"NOR"\n", ob->query("apply/busy_time"),ob->query("apply/attack") );
str += sprintf("│   生命偷取： " HIC "%8d  "NOR" 内力偷取： "HIC"%8d"NOR"\n", ob->query("apply/leech_qi"),ob->query("apply/leech_neili") );
str += sprintf("│   双倍伤害： " HIC "%8d  "NOR" 伤转内力： "HIC"%8d"NOR"\n", ob->query("apply/double_damage"),ob->query("apply/qi_abs_neili") );
str += sprintf("│   穿透护甲： " HIC "%8d  "NOR" 内力恢复： "HIC"%8d"NOR"\n", ob->query("apply/through_armor"),ob->query("apply/neili_recover") );
str += sprintf("│   生命恢复： " HIC "%8d  "NOR" 精气恢复： "HIC"%8d"NOR"\n", ob->query("apply/qi_recover"),ob->query("apply/jing_recover") );
str += sprintf("│   毒之伤害： " HIC "%8d  "NOR" 魔之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_poison"),ob->query("apply/add_magic") );
str += sprintf("│   金之伤害： " HIC "%8d  "NOR" 木之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_metal"),ob->query("apply/add_wood") );
str += sprintf("│   水之伤害： " HIC "%8d  "NOR" 火之伤害： "HIC"%8d"NOR"\n", ob->query("apply/add_water"),ob->query("apply/add_fire") );
str += sprintf("│   土之伤害： " HIC "%8d  "NOR" 毒伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/add_earth"),ob->query("apply/reduce_poison") );
str += sprintf("│   魔伤抗性： " HIC "%8d  "NOR" 金伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_magic"),ob->query("apply/reduce_metal") );
str += sprintf("│   木伤抗性： " HIC "%8d  "NOR" 水伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_wood"),ob->query("apply/reduce_water") );
str += sprintf("│   火伤抗性： " HIC "%8d  "NOR" 土伤抗性： "HIC"%8d"NOR"\n", ob->query("apply/reduce_fire"),ob->query("apply/reduce_earth") );
str += sprintf("│   忽视毒伤： " HIC "%8d  "NOR" 致盲概率： "HIC"%8d"NOR"\n", ob->query("apply/avoid_poison"),ob->query("apply/add_blind") );
str += sprintf("│   冰冻概率： " HIC "%8d  "NOR" 遗忘概率： "HIC"%8d"NOR"\n", ob->query("apply/add_freeze"),ob->query("apply/add_forget") );
str += sprintf("│   虚弱概率： " HIC "%8d  "NOR" 忙乱概率： "HIC"%8d"NOR"\n", ob->query("apply/add_weak"),ob->query("apply/add_busy") );
str += sprintf("│   忽视致盲： " HIC "%8d  "NOR" 忽视冰冻： "HIC"%8d"NOR"\n", ob->query("apply/avoid_blind"),ob->query("apply/avoid_freeze") );
str += sprintf("│   忽视遗忘： " HIC "%8d  "NOR" 忽视虚弱： "HIC"%8d"NOR"\n", ob->query("apply/avoid_forget"),ob->query("apply/avoid_weak") );
str += sprintf("│   忽视忙乱： " HIC "%8d  "NOR" 化解忙乱： "HIC"%8d"NOR"\n", ob->query("apply/avoid_busy"),ob->query("apply/reduce_busy") );
str += sprintf("│   忽视恐惧： " HIC "%8d  "NOR" 致命一击： "HIC"%8d"NOR"\n", ob->query("apply/avoid_fear"),ob->query("apply/fatal_blow") );
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
指令格式 : hp
   hp <对象名称>   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的精, 气, 神数值。

see also : score
HELP
);
return 1;
}

