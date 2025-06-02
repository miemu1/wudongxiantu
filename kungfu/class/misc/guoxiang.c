// guoxiang.c

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("����", ({ "guo xiang", "guo" }));
	set("long", "���Ƕ����ɵĿ�ɽ��ʦ��\n");
	set("nickname", HIM "С��а" NOR);
	set("gender", "Ů��");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.mie" :),
		(: perform_action, "strike.bashi" :),
		(: exert_function, "recover" :),
	}));

	set("str", 29);
	set("int", 39);
	set("con", 37);
	set("dex", 37);

	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7000);
	set("max_neili", 7000);
	set("jingli", 150);

	set("combat_exp", 2400000);
	set("score", 10000000);

	set_skill("force", 2870);
	set_skill("dodge", 2870);
	set_skill("finger", 2870);
	set_skill("parry", 2870);
	set_skill("strike", 2870);
	set_skill("sword", 2870);
	set_skill("literate", 2850);
	set_skill("mahayana", 2850);
	set_skill("buddhism", 2850);
	set_skill("jinding-zhang", 2870);
	set_skill("tiangang-zhi", 2870);
	set_skill("huifeng-jian", 2870);
	set_skill("zhutian-bu", 2870);
	set_skill("emei-xinfa", 2870);
	set_skill("linji-zhuang", 2870);

	map_skill("force","linji-zhuang");
	map_skill("finger","tiangang-zhi");
	map_skill("dodge","zhutian-bu");
	map_skill("strike","jinding-zhang");
	map_skill("sword","huifeng-jian");
	map_skill("parry","huifeng-jian");

	create_family("������", 1, "��ɽ��ʦ");

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/city/obj/cloth.c")->wear();
}
