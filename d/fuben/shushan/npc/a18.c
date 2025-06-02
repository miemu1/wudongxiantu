// tufei.c

inherit NPC;
//#include <fb_skill.h>
#include "/d/fuben/npc/fb_skill.h"

void create()
{
	set_name("无名小卒", ({ "wuming", "wuming" }) );
	set("gender", "男性");
	set("age", 30);
	set("long", "这家伙精神抖擞，满怀警惕的盯着靠近大门的陌生人。\n");

	set("combat_exp", 100000+random(300000));
	
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set_basic();
	setup();

	add_money("silver", 50+random(50));
}
void init(object me)
{
	object ob;
	me = this_player();
	ob=this_object();
	::init();
	
	if (userp(me)) {
		command("say 此乃无名山庄，没有请帖不得进入！\n");
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 50);
		if (!random(3))
			ob->do_clone(me, 50);
		//kill_ob(me);
		//me->kill_ob(this_object());
	}
}
void die()
{
        object nvh;
		mapping info;
         object ob =  this_object()->query_last_damage_from();
            object *players,*fubenls;
         int w,x,i;
        ob->start_busy(1); 
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
         x = 2000+random(1190);  
        }
        else
        {   
         x = 2000+random(1190);
         }
         w = sizeof(players);
       for(i = 0; i<sizeof(players); i++)
         {
	     
		 if(players[i]->query("wmszcs")<1){
       tell_object(players[i],HIR"由于你今天副本次数达到上限，你没有获得任何奖励\n"NOR); 
		 }else{
         players[i]->add("potential",x*2);
        players[i]->add("combat_exp", x/10);
        players[i]->add("experience", x/6);
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了无名小卒，你赢得了"+x/10+"修为,"+x*2+"潜能，"+x/6+"实战体会.\n"NOR); 
       }
	   }
           ::die(); 
}