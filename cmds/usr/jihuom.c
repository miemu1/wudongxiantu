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
	str += WHT"[萌新大礼包]"NOR"["+((me->query("jihuom/s1")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo1"ZJSEP;
	str += WHT"[中秋节礼包]"NOR"["+((me->query("jihuom/s2")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo2"ZJSEP;
	str += WHT"[国庆节礼包]"NOR"["+((me->query("jihuom/s4")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo4"ZJSEP;
	str += WHT"[替身使者]"NOR"["+((me->query("jihuom/s10")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo10"ZJSEP;
    str += WHT"[更新补偿 A]"NOR"["+((me->query("jihuom/s5")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo5"ZJSEP;
    str += WHT"[更新补偿 B]"NOR"["+((me->query("jihuom/s6")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo6"ZJSEP;
    str += WHT"[更新补偿 C]"NOR"["+((me->query("jihuom/s3")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo3"ZJSEP;
    str += WHT"[更新补偿 D]"NOR"["+((me->query("jihuom/s7")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo7"ZJSEP;
    str += WHT"[萌新开荒]"NOR"["+((me->query("jihuom/s8")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo8"ZJSEP;
    str += WHT"[删档补偿 A]"NOR"["+((me->query("jihuom/s999")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo999"ZJSEP;
    str += WHT"[删档补偿 B]"NOR"["+((me->query("jihuom/s9")>=1)?HIG"已领取"NOR:HIR"未领取"NOR)+"]:jihuo9"ZJSEP;
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
