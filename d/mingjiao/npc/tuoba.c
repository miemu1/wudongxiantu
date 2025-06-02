// TuoBa.c
// pal 1997.05.14

#include "ansi.h"

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("�ذ�", ({ "tuoba", }));
	set("long",
	"����һλ�������е�ͷ�ӣ���һ���ײ����ۡ�\n"
	"�����Ӳ��ߣ����ܽ�ʵ������ȥ��Ϊ���ӡ��������Ͼ������ֳ���ֵ�Ц�ݣ���\n"
	"����Щ������ͷ�ԡ�\n"
	);

	set("title",HIG "����" NOR "����������");
	set("level",5);

	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 22);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 450);
	set("max_jing", 300);
	set("neili", 600);
	set("max_neili", 600);
	set("jiali", 50);
	set("combat_exp", 50000);
	set("score", 100);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("cuff", 80);
	set_skill("strike", 80);
	set_skill("literate", 100);

	set_skill("shenghuo-xinfa", 80);
	set_skill("lingxu-bu", 80);
	set_skill("shenghuo-quan", 80);
	set_skill("guangming-zhang", 80);
	set_skill("liehuo-jian", 80);

	map_skill("force", "shenghuo-xinfa");
	map_skill("dodge", "lingxu-bu");
	map_skill("strike", "guangming-zhang");
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "shenghuo-quan");

	prepare_skill("cuff", "shenghuo-quan");
	prepare_skill("strike", "guangming-zhang");

	set("inherit_title",HIG"����"NOR"�����Ž���"NOR);
	create_family("����", 38, "����������");
	setup();

	carry_object("/d/mingjiao/obj/baipao")->wear();
}

#include "menzhu.h"
