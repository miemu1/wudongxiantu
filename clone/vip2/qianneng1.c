#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"修为卡"NOR, ({"potcard1"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "张");
				set("long" ,HIY "这是一张修为卡（无手续费），你可以"ZJURL("cmds:cunn combat_exp")+ZJSIZE(20)+"存修为"NOR"——"ZJURL("cmds:ququ combat_exp")+ZJSIZE(20)+"取修为"NOR"——"ZJURL("cmds:checkqn")+ZJSIZE(20)+"查修为"NOR""HIY"。"HIR"\n"HIY"笑傲祝您使用愉快！mua~"NOR"\n");
                set("no_get", 1);
                set("no_drop", 1);
				set("no_put",1);
                set("no_give", 1);
				set("yuanbao", 2500);
                set("no_sell", 1);
                set("no_steal", 1);
                set("material", "paper");
        }
        setup();
}

void init()
{
	add_action("do_cun","cunn");
	add_action("do_checkqn","checkqn");
	add_action("do_ququ","ququ");
}

int do_cun(string arg)
{
	int qiann = (int)this_player()->query("qiann");
	int cost,qn;
	object me = this_player();
	
	qn = me->query("combat_exp")-me->query("learned_points");
	if(qn<=0)
		return notify_fail(HIR"你没有修为可以存！\n"NOR);

	if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("你想存多少修为？你可以存"HIY+qn+NOR"点修为","cunn $txt#")+"\n");

	if(cost==1)
		return notify_fail("连手续费都不够!\n");

	if(cost<=0)
		return notify_fail(HIR"你在凭空捏造？\n"NOR);

	if( cost > me->query("combat_exp")-me->query("learned_points") )
		return notify_fail("你的修为不足，无法往"HIW"修为卡"NOR"中存入足够的修为！\n");

	me->add("qiann",cost);
	me->add("learned_points", cost);
	tell_object(me,HIC"你向"HIW"修为卡"HIC"内存入了"+cost+"修为。"NOR"\n");	

	return 1;
}

int do_ququ(string arg)
{
	int cost;
	int qn;
	object me = this_player();
	qn = me->query("qiann");
	
	if( me->query("qiann") <= 0 )
		return notify_fail(HIW"修为卡"NOR"中储存的修为已经没有了！\n");

    if( !arg || (!sscanf(arg, "%d", cost)) ) 
		return notify_fail(INPUTTXT("你想取多少修为？你可以取"HIY+qn+NOR"点修为","ququ $txt#")+"\n");

	if(cost<=0)
		return notify_fail(HIR"开玩笑呢你？\n"NOR);
	
	if( cost > me->query("qiann"))
		return notify_fail(HIR"你哪有这么多修为？？？！！\n"NOR);
	
	me->add("qiann",-cost);
	me->add("learned_points", -cost);
	tell_object(me,HIC"你从"HIW"修为卡"HIC"中取出了"+cost+"修为 。"NOR"\n");
		
	return 1;
}

int do_checkqn(string arg)
{
	int qn;
	object me = this_player();
	qn = me->query("qiann");

	if(qn==0)
	{
	write(ZJOBLONG+HIY"温馨提醒您:你没有修为存款(你个穷货！)\n"NOR);
	return 1;
	}

	write(ZJOBLONG+HIW"告诉你:你存有"HIY+qn+HIW"修为。\n"NOR);
	return 1;
}

int query_autoload() { return 1; }