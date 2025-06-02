// huanong.c

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("�һ�ʹ��", ({ "duihuan shizhe"}));
	set("nickname","��������"); 

	set("gender", "����");
	set("long",
		"һλ�ǳ�ţ�ƵĶһ�ʹ�ߡ�\n");
	set("str", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
		"/clone/tingyuge"    : 100000,//3						
	]));

	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"�źöӣ�һ��һ������\n",
	}));

	carry_object("/clone/cloth/cloth")->wear();
	set_max_encumbrance(100000000);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
