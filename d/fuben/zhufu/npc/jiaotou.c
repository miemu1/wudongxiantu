// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

//杀头领可爆出物品列表


void create()
{
	set_name("打手", ({ "dasho", }) );
	set("gender", "男性");
	set("age", 35);
	set("long", "这家伙满脸横肉一付凶神恶煞的模样，令人望而生畏。\n");
    set("twtnpc",1);
	set("combat_exp", 1000000+random(3000000));

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
	ob=this_object();
	::init();

	if (userp(me)) {
		command("say 小子，有点本事啊，我来会会你！\n");
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 40);
		if (!random(3))
			ob->do_clone(me, 40);
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

