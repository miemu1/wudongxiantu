// migong lev12  xuantie-jian

#include <ansi.h>
inherit NPC;
#include "/clone/tongren/tongren.h"
int big_blowing();
int hurting();

void create()
{

    set_name("�´��ҿ�", ({ "dechuan jiakang"}));

	set("gender", "����" );
	set("long","ս������������Ļ����һ�����Ĵ󽫾���\n");
	set("attitude", "aggressive");
	set("vendetta/authority",1);

	set("max_qi",10000+random(30000));
	set("eff_qi",60000+random(30000));
	set("qi",6000000+random(3000000));
	set("max_jing",6000000+random(3000000));
	set("eff_jing",6000000+random(3000000));
	set("jing",600000+random(300000));
	set("max_neili",600000+random(300000));
	set("eff_neili",600000+random(300000));
	set("neili",600000+random(300000));
	set("per", 10);
	set("age", 43);

	set("int", 200);
	set("str", 200);
	set("con", 200);
	set("dex", 200);
	set("jiali" , 200);
	set("shen", -1000000);
	set("intellgent",1);
	set("pursuer",1);
	set("combat_exp", 80000000+random(1000000));
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
				(: big_blowing :)
        }));
	set("chat_chance", 60);
	set("chat_msg", ({
                (: random_move :),
        }) );
	set_skill("unarmed", 50+random(300));
	set_skill("force", 50+random(300));
	set_skill("parry", 50+random(300));
	set_skill("dodge", 50+random(300));
	set_skill("cuff",50+random(300));
	set_skill("blade", 50+random(300));
	set_skill("literate", 50+random(300));
	//set_skill("xuanhualiu-quanfa", 550+random(300));
	//set_skill("feitian-yujianliu",550+random(300));
	//set_skill("wuxing-dun", 550+random(300));
	//set_skill("shayi-xinfa", 550+random(300));
	set_skill("shayi", 50+random(300));

	map_skill("force", "shayi-xinfa");
	//map_skill("parry", "feitian-yujianliu");
	//map_skill("blade", "feitian-yujianliu");
	//map_skill("dodge", "wuxing-dun");
	//map_skill("unarmed", "xuanhualiu-quanfa");
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 100);
	set_temp("apply/damage", 200);
	set_temp("apply/attack", 300);


	setup();

	carry_object("/d/migong/obj/cloth")->wear();

	carry_object("/d/migong/obj/blade")->wield();
}

void init( )
{
	object ob;
	remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
		ob->start_busy(1);
        call_out("hunting",0);
	}
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}


int big_blowing()
{
        remove_call_out("hurting");
        hurting();
        start_busy(3+random(2));
}
int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n�´��ҿ����һ�������d�⡱��\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
                dam = 20+random(1000);
                inv[i]->receive_wound("max_qi",dam, this_object());
                inv[i]->receive_wound("max_jing",dam/2, this_object());

                tell_object(inv[i], HIG "������塣\n");
                COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}


void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void unconcious()
{
    die();
}
void die()
{
	object me,ob,memory,item;
	mapping team;
	string location;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();
	me = ob->query_temp("last_damage_from");
	team = me->query_team();


	size = sizeof(team);
	for(i=0;i<size;i++)
	{

		level = 2000+random(2000);
		exp = 1000 * size + random(10000);

		if(exp)
		{
			pot = exp/2;
			tell_object(team[i],sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
			team[i]->add("combat_exp",exp);
			team[i]->add("potential",pot);
			if(team[i]->query("zhuanshen"))
			{
				team[i]->add("yuanshen/exp",level);
				tell_object(team[i],sprintf("���������%d��Ԫ����Ϊ��\n",level));
			}
		}
	}/*
	if(random(10000) < 5)
	{
		if(random(2)==1)
		{
			corpse=new("/clone/1000y/cloth/blggold-cloth");
			command("rumor "+me->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
			corpse->move(me);
		}else
		{
			corpse=new("/clone/1000y/cloth/blmgold-cloth");
			command("rumor "+me->query("name")+"�õ�һ��"+corpse->query("name")+"!"NOR"��\n");
			corpse->move(me);
		}
	}*/
	if(random(100) < 10)
	{
		item = new(GIFT_DIR + GF_LIST[random(sizeof(GF_LIST))]);
		if(item)
		{
			item->move(environment(ob));
		}
    }
	destruct(ob);
}
