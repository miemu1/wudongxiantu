// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if(!arg)
{
	str = ZJOBLONG"请选择操作：\n";
	str += ZJOBACTS2+ZJMENUF(1,1,9,29);
	str += WHT"[无限灵石]"NOR"["+((me->query("GM/GMma3")>=999999)?HIG"已领取"NOR:HIR"无限领取"NOR)+"]:GMma3"ZJSEP;
    str += WHT"[无限天机]"NOR"["+((me->query("GM/GMma4")>=999999)?HIG"已领取"NOR:HIR"无限领取"NOR)+"]:GMma4"ZJSEP;
    str += WHT"[无限点券]"NOR"["+((me->query("GM/GMma5")>=999999)?HIG"已领取"NOR:HIR"无限领取"NOR)+"]:GMma5"ZJSEP;
}
	
	message("vision", str+"\n", me);
	return 1;
}

int help(object me)
{
     write(@HELP
指令格式: uplv [-s]

这个指令让你消耗修为提升等级。

HELP
    );
    return 1;
}
