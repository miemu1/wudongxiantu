//inventory.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object slnpc,slroom,*slrooms;
	mixed last,now;
	mapping fam;
	int lvl,i;
	string *slnpcs;
	now = localtime(time());
	me = this_player();
	
		if(me->query("combat_exp")<100000)
		{
		tell_object(me,"你的实战修为太低，不能在这里试炼！\n");
		return 1;
	}
		if(me->query("wdtcs")<1)
		{
		tell_object(me,"你今日次数已经用完！\n");
		return 1;
	}
	if(me->query_condition("killer")){
		tell_object(me,"你正在被通缉，不能在这里试炼！\n");
		return 1;
	}
	if (me->over_encumbranced()) 
		return notify_fail("你的负荷过重，动弹不得。\n"); 
	
	if (me->query_encumbrance() < 0) 
		return notify_fail("你的负荷出现故障，动弹不得。\n"); 

	if (me->query_temp("sleeped")) 
		return notify_fail("你现在正躺着呢。\n");
    if (me->query("wudaota")>70) 
		return notify_fail("武道塔目前最高七十层。\n");
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢，你想干什么？！\n");
				
	if (me->is_fighting()) 
		return notify_fail("你现在正在战斗！\n");

	if (me->is_busy() || me->query("doing")) 
		return notify_fail("你的动作还没有完成，不能移动。\n");

	if (me->query_temp("is_flying")) 
		return notify_fail("你现在正在飞行中！\n");
		
			if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
		
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly"))
		return notify_fail("你发现这里有点古怪，你的神雕好象不听你的指挥！\n");	
	slrooms = children("/d/fuben/wudaotai/wudaotai");
	for (i = 0; i < sizeof(slrooms); i++) {
		if(slrooms[i]->query("owner")==me->query("id"))
			slroom = slrooms[i];
	}
	if(!slroom)
	{
		slroom = new("/d/fuben/wudaotai/wudaotai");
		slroom->set("owner",me->query("id"));
		if(!me->query("wudaota")){
			lvl =me->query("wudaota");
			if(lvl<1) lvl = 1;
			me->set("wudaota",1);
			me->set("last_wudaota",time());
		}
		slroom->set("sllv",me->query("wudaota"));
		slnpcs = ({
			"d/fuben/wudaotai/npc/sldz",
		});
		slnpc = new(slnpcs[random(sizeof(slnpcs))]);
		if(me->query("wudaota")<10)
		slnpc->set("name","塔"+chinese_number(me->query("wudaota"))+"守护者");
	    else if(me->query("wudaota")==10)
		slnpc->set("name",HIG"武林高手"NOR"");
	    else if(me->query("wudaota")<30)
		slnpc->set("name",HIC"侠士"+chinese_number(me->query("wudaota"))+""NOR"");
	    else if(me->query("wudaota")==30)
		slnpc->set("name",HIY"绝世高手"NOR);
	    else if(me->query("wudaota")<70)
		slnpc->set("name",HIY"长生者"+chinese_number(me->query("wudaota"))+""NOR"");
	    else if(me->query("wudaota")==70)
		slnpc->set("name",HIC"神"HIG"话"""NOR"");
	}
	this_player()->move(slroom);
	if(objectp(slnpc))
		slnpc->move(slroom);
	return 1;
}

int help (object me)
{

	return 1;
}