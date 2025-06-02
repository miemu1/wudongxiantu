// chuniang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;
#include <chaocai.h>

void create()
{
	set_name("����", ({"chu niang", "chu", "niang"}));
	set("long", "����һ������ȥ����ͨͨ�ĳ���������µ��ڳ����ղ�������һ˫"
			"�ֲڵĴ��֣������Χȹ��ò�����ˣ����������ķ������ȴ�Ǵ���"
			"һ����Ϊ���ƺ�ʮ�ְ�������������һ������" );
	set("gender", "Ů��");
	set("age", 35);
	set("no_get", 1);
	set("attitude", "friendly");

	set("inquiry",([
		"����" : (: ask_job :),
	]));

	set("age", 30);

	set("str", 21);
	set("skill_chuniang", 1);
	set("max_exp", 2500000);//������Ϊ����
	set("int", 22);
	set("con", 30);
	set("dex", 21);

	set("max_qi", 450);
	set("max_jing", 200);
	set("neili", 350);
	set("max_neili", 350);
	set("jiali", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("dodge", 50);
	set_skill("cooking", 200);
	set_skill("chuancai-jiyi", 200);
	set_skill("unarmed", 50);

	set("vendor_goods", ({
		"/clone/misc/cailiao",
	}));

	setup();
}

void init()
{
	add_action("do_cook", "cook");
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

