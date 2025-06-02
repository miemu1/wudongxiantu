// person used in quest

// ���µ����ݣ�
// void die()   - ���� npc ����ʱ���������׼��Զ������

#include <ansi.h>

inherit CLASS_D("generate") + "/chinese";
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
	set("attitude", "friendly");
	set("chat_chance", 30);
	set("chat_msg", ({ (: random_move :) }));
	set("chat_chance_combat", 120);
	set("scale", 150);
	set("no_get", 1);

	set_temp("apply/armor", 100);
	set_temp("apply/damage", 5);
	set_temp("born_time", time());
	set_temp("dest_time", 900 + time());

	add_money("silver", 15 + random(15));

	keep_heart_beat();

	//if (clonep()) keep_heart_beat();
}

void set_from_me(object me, int scale)
{
        int exp;
        mapping my;

        NPC_D->init_npc_skill(this_object(), NPC_D->check_level(me) - 2);
        my = query_entire_dbase();

        if (my["max_qi"] > 60000)
                my["max_qi"] = 60000;

        if (my["max_jing"] < my["max_qi"] / 2)
                my["max_jing"] = my["max_qi"] / 2;

        if (my["max_jing"] > 30000)
                my["max_jing"] = 30000;

        my["eff_jing"] = my["max_jing"];
        my["jing"] = my["max_jing"];
        my["eff_qi"] = my["max_qi"];
        my["qi"] = my["max_qi"];

        my["quest_count"]=me->query("quest_count");

        // �����޸�
        exp=me->query("combat_exp")*12/10;
        if (exp > query("combat_exp"))
                set("combat_exp", exp);

}

void die()
{
	object me,ob,jjmem,item;
	mapping jj;
	int i,size,level,exp,rand,pot;
	string file;

	ob = this_object();                                //��ñ����
	me = ob->query_temp("last_damage_from");           //���ɱ���������ID
	jjmem = (object)me->query_temp("jjfb/jjfb_jjmem"); //���������ϵ��ڴ�

	if(!clonep(jjmem) || !me || !userp(me))
	{
		tell_room(environment(ob),HIM"���������ˡ�\n"NOR);
		destruct(ob);
		return;
	}

	jjmem->add("make_jboss",1);
	tell_room(environment(ob),HIM"��~~~~��\n������ʧ�ˡ�\n"NOR);

	exp = 100*(3+random(5));

	if(exp)
	{
		pot = exp/2;
		tell_object(me,sprintf("������%d����Ϊ��%d��Ǳ�ܡ�\n",exp,pot));
		me->add("combat_exp",exp);
		me->add("potential",pot);
	}

	rand = 1000;
	if(random(rand)<10)
	{
		item = new("d/jjfb/jobj/powerwan");
		item->move(me);
	}

	destruct(ob);
}
