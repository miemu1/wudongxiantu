// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
object obj,ob;
int count,mengxin;
string a;
me = this_player();
me->add("max_neili",250);
me->add("max_jingli",250);
me->add("max_jing",250);
me->add("max_qi",500);
me->add("gain/damage",35);
me->add("gain/2ap",25);
me->add("gain/2dp",25);
me->add("gain/break",25);
me->add("gain/armor",25);
write("激活码正确，恭喜你成功激活GM特权!\n");
tell_object(me,HIW"你获得了：\n" +
250 + "内力上限。\n"+
250 + "精力上限。\n"+
250 + "精神上限。\n"+
500 + "气血上限。\n"+
35 + "基础伤害。\n"+
25 + "暴击值。\n"+
25 + "抗暴值。\n"+
25 + "护甲值。\n"+
25 + "破甲值。\n"+
NOR);
return 1;
}
int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
