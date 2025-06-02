// chongxu.c ����

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("����ѩ", ({ "su zhenxue", "xue" }));
	set("long",  "�����ǰ��Ƴ����ذ�ɱ��֯��һ�ˣ�ƮƮ���ɡ�\n");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 32);
	set("int", 33);
	set("con", 32);
	set("dex", 31);
	
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2500000);
	set("score", 10000000);

	set_skill("force", 1000);
	set_skill("dodge", 1000);
	set_skill("unarmed", 1000);
	set_skill("feixian-sword", 1000);
	set_skill("parry", 1000);
	set_skill("sword", 1000);
	set_skill("literate", 1000);

	map_skill("parry", "feixian-sword");
	map_skill("sword", "feixian-sword");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("���Ƴ�", 0, "��ɱ��֯");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.bai" :),
		(: perform_action, "sword.luo" :),
		(: perform_action, "sword.se" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
}
