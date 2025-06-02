// laonu.c ��ū

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("��ū", ({ "lao nu", "laonu" }));
	set("long",  "������ȥ�׷��Բԣ�һ�����˴�磬������������ӡ�\n");
	set("gender", "����");
	set("age", 72);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 32);
	set("int", 33);
	set("con", 38);
	set("dex", 32);
	
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2500000);
	set("score", 10000000);

	set_skill("force", 2270);
	set_skill("unarmed", 2250);
	set_skill("dodge", 2520);
	set_skill("parry", 2270);
	set_skill("cuff", 2520);
	set_skill("finger", 2240);
	set_skill("staff", 2720);
	set_skill("training", 2270);
	set_skill("poison", 2720);
	set_skill("shedu-qiqiao", 2270);
	set_skill("hamagong", 2720);
	set_skill("chanchu-bufa", 2250);
	set_skill("lingshe-quan", 2250);
	set_skill("lingshe-zhangfa", 2270);
	set_skill("baibian-daxue", 2620);
	set_skill("guzheng-jifa", 3020);
	set_skill("xiyu-tiezheng", 3020);
	set_skill("medical", 2820);
	set_skill("baituo-michuan", 2280);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("cuff",  "lingshe-quan");
	map_skill("parry", "lingshe-zhangfa");
	map_skill("staff", "lingshe-zhangfa");
	map_skill("finger", "shedu-qiqiao");
	map_skill("poison", "shedu-qiqiao");
	map_skill("guzheng-jifa", "xiyu-tiezheng");

	prepare_skill("finger", "shedu-qiqiao");
	prepare_skill("cuff", "lingshe-quan");

	create_family("ŷ������", 0, "��ū");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.qianshe" :),
		(: perform_action, "staff.wuji" :),
		(: perform_action, "cuff.rou" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/d/baituo/obj/shezhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
