// pangu.c 盘古

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIW"boss-气仙"NOR, ({ "qixian" }));
	set("gender", "女性");
      set("title",HIR "BOSS" NOR);
      set("age", 29);
	set("attitude", "friendly");
      
 

	set("str", 300);
	set("dex", 300);
	set("con", 300);
	set("int", 300);
      set("per", 30);
	set("shen_type", -1);


	set("combat_exp", 4000000);
	set("max_qi", 4000000);
	set("max_jing", 4000000);
	set("qi", 4000000);
	set("jing", 4000000);
	set("neili", 4000000);
	set("max_neili", 4000000);
	set("jiali", 2000);
      set("score", 500000);

      set_skill("count", 800);
	set_skill("kuihua-dafa", 800);
	set_skill("unarmed", 800);
	set_skill("dodge", 800);
	set_skill("force", 800);
	set_skill("parry", 800);
      set_skill("martial-cognize",800);

	
	map_skill("dodge", "kuihua-dafa");
	map_skill("force", "kuihua-dafa");
      map_skill("parry", "kuihua-dafa");
      map_skill("unarmed", "kuihua-dafa");
		
	
	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
            (: perform_action, "parry.klyh" :),
            (: perform_action, "parry.rzwh" :),
            (: perform_action, "parry.wcs" :),
            (: perform_action, "parry.ws" :),
		(: exert_function, "recover" :),
            (: exert_function, "bszs" :),
            (: exert_function, "powerup" :),
            (: exert_function, "gbhy" :),
            (: exert_function, "lqhs" :),
            (: exert_function, "lyhx" :),
            (: exert_function, "ldxr" :),
           	}));

		set("chat_chance", 60);
	set("chat_msg", ({
                (: random_move :),
        }) );

	setup();
	set_temp("apply/attack", 2500);
	set_temp("apply/defense", 2500);
	set_temp("apply/unarmed_damage", 2500);
	set_temp("apply/armor", 2500);

	setup();

         }

void unconcious()
{
    die();
}
void die()
{
	object me,ob,memory,item,env,obj,obj1,rand_map;
	mapping team;
	string location;
	int i,size,level,exp,rand,pot;
	string file;
	mapping maps;

	ob = this_object();
	me  = ob->query_last_damage_from();
	team = me->query_team();

        env = environment(this_object());
	size = sizeof(team);
						message("channel:chat",HIW HBBLU"【除暴】"+team[i]->query("name")+"小队成功地杀死了第二波boss，通过了二层考验\n"NOR,users());

	for(i=0;i<size;i++)
	{

		level = 200000;
		exp = 2200 * size;
        if (exp > 22000) exp=22000;

		if(exp)
		{
			pot = exp*2;
			tell_object(team[i],sprintf("你获得了%d点修为，%d点潜能。\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
        obj1 = new("/clone/spec/putao");//葡萄
        obj1->move(team[i]);//奖励物品队伍每人都有，以防报错
		}
	}

        message_vision("\n$N摇身一晃，华为一缕缕青烟消散了。\n", this_object());
        obj1 = new("/d/mirror/nandu3/xiaoying");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu3/haoran");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu3/duqing");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu3/yunv");
        obj1->move(environment(ob));
	destruct(ob);
}

