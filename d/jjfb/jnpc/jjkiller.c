

#include <ansi.h>

inherit CLASS_D("generate") + "/chineses";
#include "/clone/good/spl.h"
#include "/clone/tongren/tongren.h"
int  accept_object(object who, object ob);
void random_move();
int  leave();
int  is_stay_in_room()	{ return 1; }

void create()
{
	::create();
	set("gender", "����" );
	set("age", 30 + random(30));
        if (arrayp(query("from")) && sizeof(query("from")))
                set("long",query("from")[random(sizeof(query("form")))] + "\n");
        else
                set("long","");
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("no_update", 1);
	set("chat_chance", 30);
	set("chat_msg", ({ (: random_move :) }));
	set("chat_chance_combat", 120);
	set("scale", 150);
	set("no_get", 1);

	set_temp("apply/armor", 1500);
	set_temp("apply/damage", 500);

	add_money("silver", 15 + random(15));

	keep_heart_beat();

	//if (clonep()) keep_heart_beat();
}

void set_from_me(object me)
{
	int exp;
	mapping my;

	NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me));
	my = query_entire_dbase();

	if (my["max_qi"] > 30000)
		my["max_qi"] = 30000;

	if (my["max_jing"] < my["max_qi"] / 2)
		my["max_jing"] = my["max_qi"] / 2;

	if (my["max_jing"] > 30000)
		my["max_jing"] = 30000;

	my["eff_jing"] = my["max_jing"];
	my["jing"] = my["max_jing"];
	my["eff_qi"] = my["max_qi"];
	my["qi"] = my["max_qi"];
	my["quest_count"] = me->query("quest_count");

	exp = me->query("combat_exp") * 11 / 10;
	if (exp > query("combat_exp"))
		set("combat_exp", exp);


	if (my["combat_exp"] > 800000){
		my["jiali"] = query_skill("force") / 5;
	}
	else{
		my["jiali"] = query_skill("force") / 10;
	}

}

void init()
{

	call_out("findPlayer",5); //Ѱ��
}

void unconcious()
{
        die();
}
void die()
{
	object me,ob,jjmem,item;
	mapping jj;
	int i,size,level,exp,rand,pot,x;
	string location;
	string file;

	ob = this_object();                                //��ñ����
	me = ob->query_temp("last_damage_from");           //���ɱ���������ID
	jjmem = (object)me->query_temp("jjfb/jjfb_jjmem"); //���������ϵ��ڴ�

	if(!clonep(jjmem) || !me || !userp(me))
	{
		destruct(ob);
		return;
	}

	jjmem->add("make_jboss",1);
	i = 10000+random(100);
	exp = 30000 +  random(5000) ;
	if ( me->query("zhuanshen"))
	{
		tell_object(me,sprintf("���������%d��Ԫ����Ϊ��\n",i));
		me->add("yuanshen/exp",i);
	}
	if(exp)
	{
		pot = exp/2;
		tell_object(me,sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
		me->add("combat_exp",exp);
		me->add("potential",pot);
	}

	destruct(ob);
}

//������Ѱ��
void findPlayer()
{
	object map,*players,ob;
	int i,size,rand;

	ob = this_object();
	map = environment(ob);
	players = all_inventory(map);

	size = sizeof(players);
	rand = random(size);
	if(userp(players[rand])) ob->kill_ob(players[rand]);
	call_out("findPlayer",1+random(5));
}
