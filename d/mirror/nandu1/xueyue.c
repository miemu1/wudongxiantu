// pangu.c �̹�

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIW"Ѫ�»�"NOR, ({ "xue yue" }));
	set("gender", "����");
      set("title",HIR "BOSS" NOR);
      set("age", 29);
	set("attitude", "friendly");
      
 

	set("str", 300);
	set("dex", 300);
	set("con", 300);
	set("int", 300);
      set("per", 30);
	set("shen_type", -1);


	set("combat_exp", 2000000);
	set("max_qi", 2000000);
	set("max_jing", 2000000);
	set("qi", 2000000);
	set("jing", 2000000);
	set("neili", 2000000);
	set("max_neili", 2000000);
	set("jiali", 2000);
      set("score", 500000);

      set_skill("count", 400);
	set_skill("kuihua-dafa", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 400);
	set_skill("force", 400);
	set_skill("parry", 400);
      set_skill("martial-cognize",400);

	
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
		exp = 2000 * size;
        if (exp > 20000) exp=20000;

		if(exp)
		{
			pot = exp*2;
			tell_object(team[i],sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
        obj1 = new("/clone/spec/putao");//����
        obj1->move(team[i]);//������Ʒ����ÿ�˶��У��Է�����
		}
	}

	destruct(ob);
}

