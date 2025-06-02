// huanong.c

#include <ansi.h>
#include <command.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��ũ", ({ "lao nong", "nong" }));
	set("nickname","��ʵ��"); 

	set("gender", "����");
	set("long",
		"һλ������˪����ѡ�ֲ��ֶ������ĵõ���ũ��\n");
	set("str", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 15);

	set("combat_exp", 800000);
	set("attitude", "friendly");

	set("vendor_goods", ([
		"/clone/wine/yuanliao/yumizhong": 10000,//5
		"/clone/wine/yuanliao/xiaomaizhong": 10000,//5
		"/clone/wine/yuanliao/putaozhong": 1000,//10
		"/clone/wine/yuanliao/nuomizhong": 2000,//10
		"/clone/wine/yuanliao/lvdouzhong": 5000,//5
		"/clone/wine/yuanliao/lihuazhong": 5000,//5
		"/clone/wine/yuanliao/gaoliangzhong": 1000,//10
		"/clone/wine/yuanliao/damizhong": 2000,//10							
	]));

	setup();
	set("chat_chance", 5);
	set("chat_msg", ({
		"��ũʮ�ֳϿҵ�˵���������յ��磬���κ�������˭֪���вͣ����������ࡣ��\n",
		"��ũ̾�˿���˵��������һ���ڣ���������ӡ��ĺ������ũ���̶�������\n",
	}));

	carry_object("/clone/cloth/cloth")->wear();
	set_max_encumbrance(100000000);
}

void init()
{
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}
