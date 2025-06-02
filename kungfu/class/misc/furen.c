// furen.c �Ϸ���

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("�Ϸ���", ({ "lao furen", "furen" }));
	set("long",  "������ȥ����Ѿ���С�ˣ�������ü������Ȼ�ɿ�������ķ��ˡ�\n");
	set("gender", "Ů��");
	set("age", 69);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 37);
	set("int", 32);
	set("con", 35);
	set("dex", 36);
	
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2500000);
	set("score", 10000000);

	set_skill("force", 2270);
	set_skill("literate", 2820);
	set_skill("unarmed", 2860);
	set_skill("cuff", 2870);
	set_skill("finger", 2870);
	set_skill("strike", 2860);
	set_skill("hand", 2860);
	set_skill("claw", 2860);
	set_skill("club", 2860);
	set_skill("sword", 2870);
	set_skill("blade", 2860);
	set_skill("staff", 2860);
	set_skill("dodge", 2860);
	set_skill("parry", 8270);
	set_skill("zihui-xinfa", 2870);
	set_skill("douzhuan-xingyi", 2870);
	set_skill("beidou-xianzong", 2870);
	set_skill("canhe-zhi", 2870);
	set_skill("qixing-quan", 2870);
	set_skill("murong-sword", 2870);

	map_skill("force", "zihui-xinfa");
	map_skill("dodge", "beidou-xianzong");
	map_skill("cuff",  "qixing-quan");
	map_skill("parry", "douzhuan-xingyi");
	map_skill("finger", "canhe-zhi");
	map_skill("sword", "murong-sword");

	prepare_skill("finger", "canhe-zhi");
	prepare_skill("cuff", "qixing-quan");

	create_family("Ľ������", 0, "����");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.qixing" :),
		(: perform_action, "finger.ci" :),
		(: perform_action, "finger.lan" :),
		(: perform_action, "finger.zhi" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
