// fangsheng.c

inherit "/inherit/char/punisher";

void create()
{
	set_name("����", ({ "fang sheng", "fang" }));
	set("long", "����Ŀ�Ⱥͣ���Ȼ��һ�õ���ɮ��\n");

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 35);
	set("int", 31);
	set("con", 37);
	set("dex", 32);
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2450000);
	set("score", 10000000);

	set_skill("force", 2270);
	set_skill("hunyuan-yiqi", 2070);
	set_skill("dodge", 2060);
	set_skill("shaolin-shenfa", 2060);
	set_skill("finger", 2070);
	set_skill("strike", 2070);
	set_skill("hand", 2860);
	set_skill("claw", 2860);
	set_skill("parry", 260);
	set_skill("nianhua-zhi", 2070);
	set_skill("sanhua-zhang", 2870);
	set_skill("fengyun-shou", 28860);
	set_skill("longzhua-gong", 2860);
	set_skill("buddhism", 2860);
	set_skill("literate", 1820);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("finger", "nianhua-zhi");
	map_skill("strike", "sanhua-zhang");
	map_skill("hand", "fengyun-shou");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "nianhua-zhi");

	prepare_skill("finger", "nianhua-zhi");
	prepare_skill("strike", "sanhua-zhang");

	create_family("������", 0, "��ɮ");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "strike.san" :),
		(: perform_action, "hand.qinna" :),
		(: perform_action, "claw.zhua" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
