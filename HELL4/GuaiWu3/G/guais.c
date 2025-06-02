#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIM"��ͨ����"NOR, ({"jian jianxiu"}));
	set("nickname", "�߼���");
	set("gender", "����");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 150);
	set("int", 150);
	set("con", 150);
	set("dex", 150);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 1000000);
	set("max_qi", 1000000);
	set("jing", 1000000);
	set("max_jing", 1000000);
	set("neili", 1000000);
	set("max_neili", 1000000);
	set("jiali", 800);
	set("combat_exp", 1000000);
	set("score", 1500);
    set_skill("force", 700+random(150));
    set_skill("unarmed", 700+random(150));
    set_skill("dodge", 700+random(150));
    set_skill("parry", 700+random(150));
    set_skill("sword", 700+random(150));
    set_skill("hand", 700+random(150));
    set_skill("cuff", 700+random(150));
    set_skill("strike", 700+random(150));
    set_skill("finger", 700+random(150));
    set_skill("claw", 700+random(150));
    set_skill("blade", 700+random(150));
    set_skill("staff", 700+random(150));
    set_skill("hammer", 700+random(150));
    set_skill("club", 700+random(150));
    set_skill("whip", 700+random(150));
    
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
    set_skill("wushang-jianjing", 700+random(150));
		
	map_skill("force", "wushang-jianjing");
    map_skill("sword", "wushang-jianjing");
    map_skill("parry", "wushang-jianjing");
    map_skill("unarmed", "wushang-jianjing");
    map_skill("dodge", "wushang-jianjing");
	map_skill("hand", "wushang-jianjing");
    map_skill("cuff", "wushang-jianjing");
    map_skill("strike", "wushang-jianjing");
    map_skill("finger", "wushang-jianjing");
    map_skill("claw", "wushang-jianjing");
	map_skill("blade", "wushang-jianjing");
    map_skill("staff", "wushang-jianjing");
    map_skill("hammer", "wushang-jianjing");
    map_skill("club", "wushang-jianjing");
    map_skill("whip", "wushang-jianjing");

    set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "force.wushangb1" :),
		(: perform_action, "force.wushangb2" :),
		(: perform_action, "force.wushangb3" :),
		(: perform_action, "force.wushangb4" :),
		(: perform_action, "force.wushangb5" :),
		(: perform_action, "force.wushangb6" :),
		(: perform_action, "force.wushangb7" :),
		(: exert_function, "force.wushanga1" :),
	}));
	set_temp("apply/attack", 6000);
	set_temp("apply/defense", 0);
	set_temp("apply/unarmed_damage", 6000);
	set_temp("apply/armor", 0);

    setup();
    carry_object("/HELL4/GuaiWu3/Gzb/wuqi")->wield();
	if (clonep(this_object()))
	{
	set("chat_chance", 150);
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


		exp = 150000;
		pot = 150000;
		me->add("combat_exp",150000);
		me->add("potential",150000);
		me->add("yuanshen/exp",150000);
		me->add("yuanbao",50);
        obj1 = new("/HELL4/BOX/box3");
        obj1->move(env);
		tell_object(me,sprintf(GRN"������%d����Ϊ��%d��Ǳ�ܣ�%d��Ԫ����Ϊ��50ö��ʯ��1�����ޱ��䣬�뼰ʱʰȡ�����ⶪʧ\n"NOR,exp,pot,50000));

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