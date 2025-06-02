// pangu.c �̹�

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIW"boss-��Ů"NOR, ({ "yunv" }));
	set("gender", "Ů��");
      set("title",HIR "BOSS" NOR);
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
						message("channel:chat",HIW HBBLU"��������"+team[i]->query("name")+"С�ӳɹ���ɱ���˵�����boss��ͨ�������㿼��\n"NOR,users());

	for(i=0;i<size;i++)
	{

		level = 200000;
		exp = 2400 * size;
        if (exp > 24000) exp=24000;

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

        message_vision("\n$Nҡ��һ�Σ���Ϊһ����������ɢ�ˡ�\n", this_object());
        obj1 = new("/d/mirror/nandu4/1");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu4/2");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu4/3");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu4/4");
        obj1->move(environment(ob));
        obj1 = new("/d/mirror/nandu4/boss");
        obj1->move(environment(ob));
	destruct(ob);
}

