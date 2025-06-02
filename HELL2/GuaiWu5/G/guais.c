#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIM"�粼��"NOR, ({"gebu lin"}));
	set("nickname", "�����");
	set("gender", "����");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 500000);
	set("max_qi", 500000);
	set("jing", 500000);
	set("max_jing", 500000);
	set("neili", 500000);
	set("max_neili", 500000);
	set("jiali", 350);
	set("combat_exp", 500000);
	set("score", 100);
    set_skill("force", 450+random(100));
    set_skill("unarmed", 450+random(100));
    set_skill("dodge", 450+random(100));
    set_skill("parry", 450+random(100));
    set_skill("sword", 450+random(100));
    set_skill("hand", 450+random(100));
    set_skill("cuff", 450+random(100));
    set_skill("strike", 450+random(100));
    set_skill("finger", 450+random(100));
    set_skill("claw", 450+random(100));
    set_skill("blade", 450+random(100));
    set_skill("staff", 450+random(100));
    set_skill("hammer", 450+random(100));
    set_skill("club", 450+random(100));
    set_skill("whip", 450+random(100));
    
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
    set_skill("shanggu-mijing", 450+random(100));
		
	map_skill("force", "shanggu-mijings");
    map_skill("sword", "shanggu-mijings");
    map_skill("parry", "shanggu-mijings");
    map_skill("unarmed", "shanggu-mijings");
    map_skill("dodge", "shanggu-mijings");
	map_skill("hand", "shanggu-mijings");
    map_skill("cuff", "shanggu-mijings");
    map_skill("strike", "shanggu-mijings");
    map_skill("finger", "shanggu-mijings");
    map_skill("claw", "shanggu-mijings");
	map_skill("blade", "shanggu-mijings");
    map_skill("staff", "shanggu-mijings");
    map_skill("hammer", "shanggu-mijings");
    map_skill("club", "shanggu-mijings");
    map_skill("whip", "shanggu-mijings");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "perform force.shanggub1" :),
		(: perform_action, "perform force.shanggub2" :),
		(: perform_action, "perform force.shanggub3" :),
		(: perform_action, "perform force.shanggub4" :),
		(: exert_function, "exert force.shanggua1" :),
		(: exert_function, "exert force.shanggua2" :),
		(: exert_function, "exert force.shanggua3" :),
		(: exert_function, "exert force.shanggua4" :),
	}));
	set_temp("apply/attack", 3500);
	set_temp("apply/defense", 100);
	set_temp("apply/unarmed_damage", 3500);
	set_temp("apply/armor", 100);

    setup();
    carry_object("/HELL2/GuaiWu5/Gzb/wuqi")->wield();
	if (clonep(this_object()))
	{
	set("chat_chance", 100);
	set("chat_msg", ({ (: random_move :) }));
	set("born_time", time());
	keep_heart_beat();
	}
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
	int i,level,exp,rand,pot;
	string file;

	ob = this_object();
	me  = ob->query_last_damage_from();


        env = environment(this_object());
//	CHANNEL_D->do_channel(this_object(), "chat", HIR"��������ȥҲ��"NOR"");


		exp = 200000;
		pot = 200000;
		me->add("combat_exp",200000);
		me->add("potential",200000);
		me->add("yuanshen/exp",1000);
		me->add("yuanbao",2);
		tell_object(me,sprintf(GRN"������%d����Ϊ��%d��Ǳ�ܣ�%d��Ԫ����Ϊ��2��ʯ��\n"NOR,exp,pot,50000));

	destruct(ob);
}

void random_move()
{
	if (time() - query("born_time") > 1800)
	{
		message_vision("$N����ææ�����ˡ�\n", this_object());

		destruct(this_object());
		return;
	}
}