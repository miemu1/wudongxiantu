//2020.6.9改bagua，改者name
//QQ:3468713544
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(HIY"自动师门（非消耗品）"NOR, ({"quest sss"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 10);
	   	//set("no_put", 1);
		set("no_get", 1);
		set("no_give", 1);
		set("no_drop", 1);
		set("no_sell", 1);
		set("no_steal", 1);
		set("no_beg", 1);
		set("jifeng",100);
		set("unit", "个");
		set("long","能顺境移动到当前师门任务npc的位置！使用说明：use quest sss;accept quest;后面跟技能\n");
		set("only_do_effect", 1);
	}
	setup();
}


int do_effect(object me)
{
	object ob;
	mapping q;
	string area;
	
	
	if (base_name(environment(me)) == "/d/city/wumiao")
			return notify_fail("武庙设下了禁制。\n");
	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
	if(!mapp(q=me->query("quest")))
	{
      		return notify_fail("你现在没有任务，使用自动师门干什么?\n");  
	}

	if(q["type"]!="kill")
	{
      		return notify_fail("你现在没有师门杀人任务，无需使用。\n");  
	}
	 if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n");
	if(ob=find_living(q["id"]))
	{
		sscanf(base_name(environment(ob)),"/d/%s/%*s",area);
               message_vision(HIC"。。。。。。。。。。。。。\n" , me);
		tell_object(me,HIR+q["name"]+NOR"（"+q["id"]+"）目前正在"HIW+MAP_D->query_map_short(area)+NOR"的"HIW+environment(ob)->query("short")+NOR"活动。\n");
me->move(environment(ob));
me->force_me("kill " + me->query("quest/id"));
	}
	else
		tell_object(me,"无法自动到目标人物，可能是目标人物已被杀死或者消失了。\n");

	//add_amount(-1);
	return 1;
}
