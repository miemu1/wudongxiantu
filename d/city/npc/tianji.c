// chen.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
string do_answer();
void create()
{
	set_name(HIM"�������"NOR, ({ "master tianji" }));
	set("long", HIG"�������ϯԪ�ϣ��������û��������ĺ���\n"NOR);
	set("gender", "����");
	set("age", 45);
	set("icon","00723");
		set("str", 20000);
	set("int", 20000);
	set("dex", 20000);
	set("int", 20000);
	set("qi", 100000000);
	set("max_qi", 100000000);
	set("jing", 100000000);
	set("max_jing", 100000000);
	set("neili", 100000000);
	set("max_neili", 100000000);
	set("jiali", 1000);
	set("combat_exp", 2500000);
	set("score", 50000);
	set_skill("cuff", 2000);
	set_skill("dodge", 20000);
	set_skill("force", 20000);
	set_skill("parry", 20000);
	set_skill("claw", 20000);
	set_skill("hand", 20000);
	set_skill("strike", 20000);
	set_skill("finger", 20000);
	set_skill("cuff", 20000);
	set_skill("blade", 20000);
	set_skill("club", 20000);
	set_skill("staff", 20000);
	set_skill("sword", 20000);
	set_skill("throwing", 20000);
	set_temp("apply/attack", 20000);
	set_temp("apply/defense", 20000);
	set_temp("apply/damage", 20000);

	set("combat_exp", 400000);
	set("shen_type", 1);
	 set("inquiry", ([
		"����̳�" : (: do_answer :),
	      
			]));
	{
		set("chat_chance", 30);
		set("chat_msg", ({ (: random_move :) }));
		set("born_time", time());
		keep_heart_beat();
	}
	
	setup();
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


int do_answer()
{
  string str="";  
object me;
me=this_player();

	tell_object(me,HIM + ZJSIZE(20)"������������Ҷ������ղص������Ʒ����ֻ��ͣ��12Сʱ����úð��ա�\n"NOR);
	write(ZJFORCECMD("myshopp4"));

		return 1;

}

void random_move()
{
	if (time() - query("born_time") > 43200)
	{
		message_vision("$N����ææ�����ˡ�\n", this_object());
		CHANNEL_D->do_channel(this_object(), "rumor",
			"��˵" + name() + HIM "���˼�ͣ������"
			"���������ĺ�ȥ�ˡ�" NOR);
		destruct(this_object());
		return;
	}
}