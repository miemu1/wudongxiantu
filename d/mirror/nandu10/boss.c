// pangu.c �̹�

#include <ansi.h>

inherit NPC;
void do_bite();

void create()
{
	set_name(HIR"boss-��ħ�˻�"NOR, ({ "boss" }));
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


	set("combat_exp", 28000000);
	set("max_qi", 28000000);
	set("max_jing", 28000000);
	set("qi", 28000000);
	set("jing", 28000000);
	set("neili", 28000000);
	set("max_neili", 28000000);
	set("jiali", 2000);
      set("score", 500000);

      set_skill("count", 5000);
	set_skill("kuihua-dafa", 5000);
	set_skill("unarmed", 5000);
	set_skill("dodge", 5000);
	set_skill("force", 5000);
	set_skill("parry", 5000);
      set_skill("martial-cognize",5000);

	
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
						message("channel:chat",HIW HBBLU"��������"+team[i]->query("name")+"С�ӳɹ���ɱ���˵�ʮ��boss��ͨ�������п���\n"NOR,users());

	for(i=0;i<size;i++)
	{

		level = 200000;
		exp = 4000 * size;
        if (exp > 40000) exp=40000;

		if(exp)
		{
			pot = exp*2;
			tell_object(team[i],sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
        obj1 = new("/clone/vip2/putao1");//����
        obj1->move(team[i]);//������Ʒ����ÿ�˶��У��Է�����
		}
	}

        message_vision("\n$Nҡ��һ�Σ���Ϊһ����������ɢ�ˡ�\n", this_object());
	destruct(ob);
}

