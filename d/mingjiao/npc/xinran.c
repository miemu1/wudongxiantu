// XinRan.c
// pal 1997.05.11

#include "ansi.h"

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("��Ȼ", ({ "xin ran", "xin", "ran", }));
	set("long",
	"����һλ�ߴ��ΰ���������ӣ���һ���ײ����ۡ�\n"
	"���������������е���ͷ����������򲻵�֮�£�����һ���������ݵĺ��ӡ�\n"
	);

	set("title", HIG "����" HIR "�һ���" NOR "����ʹ");
	set("level",7);

	set("gender", "����");
	set("attitude", "friendly");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_qi", 1000);
	set("max_jing", 1000);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 100);
	set("combat_exp", 100000);
	set("score", 5000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 120);
	set_skill("cuff", 120);
	set_skill("strike", 120);
	set_skill("throwing", 200);
	set_skill("literate", 100);

	set_skill("shenghuo-xinfa", 120);
	set_skill("lingxu-bu", 120);
	set_skill("shenghuo-quan", 120);
	set_skill("guangming-zhang", 120);
	set_skill("liehuo-jian", 120);
	set_skill("wuxing-jueji", 200);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "shenghuo-quan");
	map_skill("throwing", "wuxing-jueji");

	prepare_skill("cuff", "shenghuo-quan");
	prepare_skill("strike", "guangming-zhang");
	create_family("����", 37, "�һ�������ʹ");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "zhangqishi.h"
