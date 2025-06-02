// hongri.c ���շ���

#include <ansi.h>

inherit "/inherit/char/punisher";

void create()
{
	set_name("���շ���", ({ "hongri fawang", "fawang" }));
	set("long",  "������ȥ��һ����ɮ����ǰ����һ������̫����\n");
	set("gender", "����");
	set("age", 62);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 33);
	set("int", 36);
	set("con", 34);
	set("dex", 33);
	
	set("max_qi", 6000);
	set("max_jing", 3000);
	set("neili", 7500);
	set("max_neili", 7500);
	set("jiali", 150);
	set("combat_exp", 2500000);
	set("score", 10000000);

	set_skill("lamaism", 2820);
	set_skill("literate", 8000);
	set_skill("force", 2830);
	set_skill("parry", 2820);
	set_skill("blade", 2825);
	set_skill("xue-dao", 2825);
	set_skill("sword", 1880);
	set_skill("mingwang-jian", 1880);
	set_skill("dodge", 2180);
	set_skill("mizong-neigong", 2830);
	set_skill("xuehai-mogong", 2830);
	set_skill("shenkong-xing", 2810);
	set_skill("hand", 8200);
	set_skill("dashou-yin", 2800);
	set_skill("cuff", 2800);
	set_skill("yujiamu-quan", 2800);

	map_skill("force", "xuehai-mogong");
	map_skill("dodge", "shenkong-xing");
	map_skill("hand", "dashou-yin");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "xue-dao");
	map_skill("blade", "xue-dao");
	map_skill("sword", "mingwang-jian");

	prepare_skill("cuff", "yujiamu-quan");
	prepare_skill("hand", "dashou-yin");

	create_family("Ѫ����", 0, "����");
	set("class", "bonze");

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: perform_action, "blade.shendao" :),
		(: perform_action, "blade.xueyu" :),
		(: perform_action, "hand.jingang" :),
		(: perform_action, "cuff.chen" :),
		(: exert_function, "recover" :),
	}));

	setup();
	carry_object("/d/xueshan/obj/y-jiasha")->wear();
	carry_object("/d/xuedao/obj/xblade")->wield();
}
