// jinsha.c

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "草民丹" NOR, ({ "caomin dan" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一粒晶莹剔透的丹药，由太上老君秘制而成，服了之后使人强行散去本门武功，从而重新拜师学艺,不清除当前所学技能。使用前请先卸下自身title\n");
		set("unit", "粒");
		set("value", 50000);
				set("no_give",1);
				set("no_drop",1);
				set("no_get",1);
				set("no_sell",1);
                set("no_put", 1);
		set("tianji1", 1500);
		set("only_do_effect", 1);
		set("weight", 1);
	}
	setup();
}

int do_effect(object me)
{
	string family,*skills;
	int i;
	mapping all_fam = ([
		"武当派":({
				
			}),
		"少林派":({
				
//以下为少林藏经阁特有武功
				
			}),
		"天龙寺":({
			}),
		"华山派":({
			}),
		"华山剑宗":({
				
			}),
		"峨嵋派":({
				
			}),
		"桃花岛":({
				
			}),
		"神龙教":({
				
			}),
		"丐帮":({
				
				
			}),
		"古墓派":({
				
			}),
		"全真教":({
				
			}),
		"星宿派":({
				
			}),
		"逍遥派":({
			}),
		"雪山寺":({
				
			}),
		"血刀门":({
			}),

		"灵鹫宫":({
				
			}),
		"慕容世家":({
			}),
		"欧阳世家":({
				
			}),
		"关外胡家":({
			
			}),
		"段氏皇族":({
				
			}),
	]);


	if(!me->query("family"))
	{
		tell_object(me,"你还没有师门吧，无需使用"+query("name")+"。\n");
		return 1;
	}
	message_vision(CYN "$N" CYN "小心的服下了一"+query("unit")+"" + name() + CYN "，决定重新做人。"NOR"\n", me);

	family = me->query("family/family_name");

	
	CHANNEL_D->do_channel( this_object(), "rumor","据说"+me->query("name")+"服用了一粒"+this_object()->query("name")+""HIM"，获得了一次重新选择师门的机会！");
	me->delete("family");
	me->delete("title");
	me->delete("class");
	destruct(this_object());

	return 1;
}
int query_autoload() { return 1; }