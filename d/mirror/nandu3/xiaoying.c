// pangu.c 盘古

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIW"小影"NOR, ({ "xiaoying" }));
	set("gender", "男性");
      set("age", 29);
	set("attitude", "friendly");
      
 

	set("str", 300);
	set("dex", 300);
	set("con", 300);
	set("int", 300);
      set("per", 30);
	set("shen_type", -1);


	set("combat_exp", 6000000);
	set("max_qi", 6000000);
	set("max_jing", 6000000);
	set("qi", 6000000);
	set("jing", 6000000);
	set("neili", 6000000);
	set("max_neili", 6000000);
	set("jiali", 2000);
      set("score", 500000);

      set_skill("count", 1200);
	set_skill("kuihua-dafa", 1200);
	set_skill("unarmed", 1200);
	set_skill("dodge", 1200);
	set_skill("force", 1200);
	set_skill("parry", 1200);
      set_skill("martial-cognize",1200);

	
	map_skill("dodge", "kuihua-dafa");
	map_skill("force", "kuihua-dafa");
      map_skill("parry", "kuihua-dafa");
      map_skill("unarmed", "kuihua-dafa");
		
			set("chat_chance", 60);
	set("chat_msg", ({
                (: random_move :),
        }) );
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
	object me,ob,memory,item,env,obj,obj1;
	mapping team;
	string location;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me  = ob->query_last_damage_from();
	team = me->query_team();

        env = environment(this_object());
	size = sizeof(team);
	for(i=0;i<size;i++)
	{

		level = 200000;
		exp = 2400 * size;
        if (exp > 24000) exp=24000;

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

	destruct(ob);
}

