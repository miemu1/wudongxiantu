// laodao.c �ϵ�

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("�ϵ�", ({ "lao dao", "dao" }));
	set("long",  "������ȥ�ɷ���ǣ���ò���ס�\n");
	set("gender", "����");
	set("age", 64);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 33);
	set("int", 33);
	set("con", 36);
	set("dex", 32);
	
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2500000);
	set("score", 10000000);

	set_skill("force", 2180);
	set_skill("quanzhen-xinfa", 2280);
	set_skill("xiantian-gong", 2280);
	set_skill("sword", 2260);
	set_skill("quanzhen-jian",2260);
	set_skill("dodge", 2260);
	set_skill("jinyan-gong", 2260);
	set_skill("parry", 2270);
	set_skill("strike", 2270);
	set_skill("chongyang-shenzhang", 2270);
	set_skill("haotian-zhang", 2270);
	set_skill("literate", 1260);
	set_skill("finger", 2250);
	set_skill("taoism", 2300);
	set_skill("finger", 2260);
	set_skill("zhongnan-zhi", 2270);
	set_skill("medical", 2270);
	set_skill("liandan-shu", 2270);

	map_skill("force", "xiantian-gong");
	map_skill("sword", "quanzhen-jian");
	map_skill("dodge", "jinyan-gong");
	map_skill("parry", "quanzhen-jian");
	map_skill("finger", "zhoangnan-zhi");
	map_skill("strike", "haotian-zhang");

	prepare_skill("finger","sun-finger");
	prepare_skill("strike","haotian-zhang");

	create_family("ȫ���", 0, "ǰ��");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.ding" :),
		(: perform_action, "sword.hua" :),
		(: perform_action, "strike.ju" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
