// tufei.c

inherit NPC;
#include <ansi.h>
#include "/d/fuben/npc/fb_skill.h"

mixed ask_yinguo();

//可爆出物品列表
string *random_ob = ({
    "/clone/vip/putao",
    "/clone/money/gold",
});

void create()
{
	set_name(HIY"无"HIW"名"HIY"氏"NOR, ({ "wuming"}) );
	set("gender", "男性");
	set("age", 45);
	set("long", "这就是无名山庄的主人。\n");

	set("combat_exp", 1000000+random(3000000));

	set("attitude", "peaceful");
	set("str", 130);
	set("int", 130);
	set("con", 130);
	set("dex", 130);
	

	set_basic();
	setup();

	add_money("gold", 1+random(10));
}

void init(object me)
{
	object ob;
	me = this_player();
	ob = this_object();
	::init();

	if (userp(me)&&!me->query_temp("zxt_again")) {
		
		//npc难度是采用根据玩家最高可学技能等级生成
		if (!this_object()->query_temp("do_clone"))
			ob->do_clone(me, 200);
		if (!random(3))
			ob->do_clone(me, 200);
		command("say 今天是无名山庄开山之日？老夫不想打开杀戒！！\n");
		kill_ob(me);
		me->kill_ob(this_object());
	}
}

void die()
{
        object nvh;
         object ob =  this_object()->query_last_damage_from();
            object *players;
         int w,x,i;
        ob->start_busy(1); 
        if (sizeof(ob->query_team()) > 1)
        {
        players = ob->query_team();
         x = 5000+random(5000);
        }
        else
        {   
         x = 5000+random(5000);
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
       tell_object(players[i],HIR"由于"+ob->query("name")+"击败了无名氏，你赢得了"+x/10+"修为,"+x*2+"潜能，"+x/6+"实战体会.\n"NOR); 
            message("channel:chat",HIY"无名山庄"HIR"："+ob->query("name")+"神功盖世，成功击杀了"MAG"无名氏"HIG"，带领着他的队伍杀出了无名山庄!\n"NOR,users());
				  
       }
	   }
           ::die(); 
}