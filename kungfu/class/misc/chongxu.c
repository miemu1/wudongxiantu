// chongxu.c ����

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("����", ({ "chong xu", "xu" }));
	set("long",  "�������䵱�ɵĸ��ֳ����������ò��Ȼ��ƮƮ���ɡ�\n");
	set("gender", "����");
	set("age", 55);
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

	set_skill("force", 2280);
	set_skill("wudang-xinfa", 2280);
	set_skill("taiji-shengong", 2280);
	set_skill("dodge", 2250);
	set_skill("tiyunzong", 2250);
	set_skill("unarmed", 2270);
	set_skill("taiji-quan", 2270);
	set_skill("strike", 2270);
	set_skill("wudang-zhang", 2270);
	set_skill("hand", 2270);
	set_skill("paiyun-shou", 2270);
	set_skill("parry", 2270);
	set_skill("sword", 2270);
	set_skill("wudang-jian", 2270);
	set_skill("taiji-jian", 2270);
  	set_skill("taoism", 2250);
	set_skill("literate", 1200);
	set_skill("medical", 2260);
	set_skill("liandan-shu", 2260);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
	map_skill("strike", "wudang-zhang");

	prepare_skill("unarmed", "taiji-quan");
	prepare_skill("strike", "wudang-zhang");

	create_family("�䵱��", 0, "����");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "sword.chan" :),
		(: perform_action, "sword.lian" :),
		(: perform_action, "sword.sui" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/whiterobe")->wear();
}
