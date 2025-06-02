#include <ansi.h>

#define LVYU_ZHANG    "/clone/weapon/green_stick"

inherit NPC;

int try_to_learn_ds();
int try_to_learn_db();
mixed ask_me();
mixed ask_bang();

void create()
{
	set_name(HIG"�Խ�ū"NOR, ({"jian shinu"}));
	set("nickname", "������");
	set("gender", "����");
	set("age", 9999);
	set("nolook", 1);
	set("attitude", "peaceful");
	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 200000);
	set("max_qi", 200000);
	set("jing", 200000);
	set("max_jing", 200000);
	set("neili", 200000);
	set("max_neili", 200000);
	set("jiali", 500);
	set("combat_exp", 200000);
	set("score", 500);
    set_skill("force", 500+random(50));
    set_skill("unarmed", 500+random(50));
    set_skill("dodge", 500+random(50));
    set_skill("parry", 500+random(50));
    set_skill("sword", 500+random(50));
    set_skill("hand", 500+random(50));
    set_skill("cuff", 500+random(50));
    set_skill("strike", 500+random(50));
    set_skill("finger", 500+random(50));
    set_skill("claw", 500+random(50));
    set_skill("blade", 500+random(50));
    set_skill("staff", 500+random(50));
    set_skill("hammer", 500+random(50));
    set_skill("club", 500+random(50));
    set_skill("whip", 500+random(50));
    
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
    set_skill("wushang-jianjing", 500+random(50));
		
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
	set_temp("apply/attack", 5000);
	set_temp("apply/defense", 500);
	set_temp("apply/unarmed_damage", 5000);
	set_temp("apply/armor", 500);

    setup();
    carry_object("/HELL4/GuaiWu1/Gzb/wuqi")->wield();
	if (clonep(this_object()))
	{
	set("chat_chance", 50);
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


		exp = 50000;
		pot = 50000;
		me->add("combat_exp",50000);
		me->add("potential",50000);
		me->add("yuanshen/exp",50000);
		me->add("yuanbao",50);
        obj1 = new("/HELL4/BOX/box1");
        obj1->move(env);
		tell_object(me,sprintf(GRN"������%d����Ϊ��%d��Ǳ�ܣ�%d��Ԫ����Ϊ��500ö��ʯ��1����ū���䣬�뼰ʱʰȡ�����ⶪʧ\n"NOR,exp,pot,50000));

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