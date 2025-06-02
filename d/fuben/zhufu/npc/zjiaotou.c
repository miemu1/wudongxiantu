// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name(HIR"王管家"NOR, ({ "wangguanjia", }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "他是朱府的管家，如今看你就像看一个死人一般。\n");

	set("combat_exp", 1000000+random(3000000));
    set("twtnpc",1);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set_basic();
	setup();

}
void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)) {
		command("say 小子，有点本事啊，我来会会你！！\n");
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 80);
		if (!random(3))
			ob->do_clone(me, 80);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

