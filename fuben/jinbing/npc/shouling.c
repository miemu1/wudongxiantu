//by ���� ranger's ednpc tools.
// shanzei1.c

#include <ansi.h>
inherit NPC;

string *random_ob = ({
"/HCSP/sp25",
"/HCSP/sp26",
"/HCSP/sp27",
"/HCSP/sp28",
"/HCSP/sp29",
"/HCSP/sp30",
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box3",
"/fuben/box/box4",
"/fuben/box/box4",
"/HCSP/jyzbSP/sp1",
"/HCSP/jyzbSP/sp2",
"/HCSP/jyzbSP/sp3",
"/HCSP/jyzbSP/sp4",
"/HCSP/jyzbSP/sp5",
"/HCSP/jyzbSP/sp6",
"/HCSP/jyzbSP/sp7",
"/HCSP/jyzbSP/sp8",
"/HCSP/jyzbSP/sp9",
"/HCSP/jyzbSP/sp1",
"/HCSP/jyzbSP/sp2",
"/HCSP/jyzbSP/sp3",
"/HCSP/jyzbSP/sp4",
"/HCSP/jyzbSP/sp5",
"/HCSP/jyzbSP/sp6",
"/HCSP/jyzbSP/sp7",
"/HCSP/jyzbSP/sp8",
"/HCSP/jyzbSP/sp9",
"/HCSP/jyzbSP/sp1",
"/HCSP/jyzbSP/sp2",
"/HCSP/jyzbSP/sp3",
"/HCSP/jyzbSP/sp4",
"/HCSP/jyzbSP/sp5",
"/HCSP/jyzbSP/sp6",
"/HCSP/jyzbSP/sp7",
"/HCSP/jyzbSP/sp8",
"/HCSP/jyzbSP/sp9",
});

void create()
{
object ob = this_player();
int lvl = ob->query("qi");
int sklv;
sklv = to_int(pow(to_float(ob->query("combat_exp")*10),0.333333333)+random(15));
if (ob->query("combat_exp")<100000){
sklv = 100;
}
if (lvl > 7000){
lvl = 7000;
}
	set_name(HIR"���֮��"NOR,({"shouling"}));
	set("gender", "����");
	set("per",20);
	set("age", 30);
	set("combat_exp", 9999999+random(3000000));
	set("str", 300);
	set("int", 300);
	set("con", 300);
	set("dex", 100);
	set("chat_chance", 1);
    set("quest2/kuihua/pass", 1);

	set("qi", 10000000);
	set("max_qi", 10000000);
	set("jing", 100000);
	set("max_jing", 100000);
	set("neili", 100000);
	set("max_neili", 100000);
	set("jiali", 4000);
	set("combat_exp", 5000000);
	set("score", 4000);
    set_skill("force", 4000+random(4000));
    set_skill("unarmed", 4000+random(4000));
    set_skill("dodge", 4000+random(4000));
    set_skill("parry", 4000+random(4000));
    set_skill("sword", 4000+random(4000));
    set_skill("hand", 4000+random(4000));
    set_skill("cuff", 4000+random(4000));
    set_skill("strike", 4000+random(4000));
    set_skill("finger", 4000+random(4000));
    set_skill("claw", 4000+random(4000));
    set_skill("blade", 4000+random(4000));
    set_skill("staff", 4000+random(4000));
    set_skill("hammer", 4000+random(4000));
    set_skill("club", 4000+random(4000));
    set_skill("whip", 4000+random(4000));
    
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
    set_skill("wushang-jianjing", 4000+random(4000));
		
	map_skill("force", "wushang-jianjing");
    map_skill("sword", "wushang-jianjing");
    map_skill("parry", "wushang-jianjing");
    map_skill("unarmed", "wushang-jianjing");
    map_skill("dodge", "wushang-jianjing");
	map_skill("hand", "wushang-jianjing");
    map_skill("cuff", "wushang-jianjing");
    map_skill("strike", "wushang-jianjing");
    map_skill("finger", "wushang-jianjingsA");
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
	set_temp("apply/attack", 15000);
	set_temp("apply/defense", 2000);
	set_temp("apply/unarmed_damage", 15000);
	set_temp("apply/armor", 2000);

    setup();
}

void die()
{
	string id = random_ob[random(sizeof(random_ob))];//�����Ʒ
	object killer,ob;
	int exp;

	if (objectp(killer = query_last_damage_from()))
	{
		killer->add("combat_exp",500000);
		tell_object(killer,"��ɱ��"+name()+"�����50�����Ϊ��\n");
		if(killer->query("zhanling/s2") < 1000)
		{
		killer->add("zhanling/a2",100);
		killer->add("zhanling/s2",100);
		tell_object(killer,"��ɱ��"+name()+"�����100ս����Ϊ��\n");
		}
	}
	
	switch (random(11))
	{
		case 0 : 
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 5 :
			new(id)->move(killer);
			new(id)->move(killer);
		break;

		case 9 :
			new(id)->move(killer);
			new(id)->move(killer);

//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"�ڷ�����������л����"+id->short()+"��");
		break;
//CHANNEL_D->do_channel(this_object(),"rumor", killer->query("name")+"�ڷ�����������л����"+id->short()+"��");
message("channel:chat",HIW"�������"HIR"��"+killer->query("name")+"���ܵо�"+id->short()+"\n"NOR,users());											
		break;
	}
	::die();
}

void unconcious()
{
	die();
}