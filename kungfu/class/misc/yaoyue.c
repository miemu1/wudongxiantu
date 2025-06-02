// /NPC gongzhu.c

#include <ansi.h>

inherit "/inherit/char/punisher";
inherit F_MASTER;
inherit F_QUESTER;
void create()
{
	set_name("����", ({ "yao yue", "yao", "yue" }));
	set("long",
	    "�����ǡ��ƻ������Ŀ�ɽ��ʦ.\n"+
	    "���ñ�������ɴ������,����͸���ǿ���ɴ����Ȼ��ϡ�ɼ�\n"+
	    "����ɫɷ��,�Բ����˼����˿�����,�㲻�ɵö࿴��һ��.\n");
	set("title", "�ƻ�������");
	set("gender", "Ů��");
	set("age", 36);
	set("nickname", HIR "ɱ�����¸��ĺ�" NOR);
      set("shen_type",-500);
	set("attitude", "peaceful");

    set("str", 1550);
	set("int", 350);
	set("con", 400);
	set("dex", 250);

    set("max_qi", 5000000);
	set("jing", 14000);
    set("max_jing", 3000000);
    set("neili", 4500000);
     set("max_neili", 4000000);
      set("jiali", 800);
	set("no_suck",1);

      set("combat_exp", 600000000);
	set("score", 2000000);
        set_skill("force", 3000);
        set_skill("strike", 3000);
        set_skill("dodge", 3000);
        set_skill("parry", 3000);
        set_skill("sword",3000);
        set_skill("literate",3000);

        set_skill("jueqing-zhang",3000);
        set_skill("mingyu-shengong",3000);
        set_skill("yifeng-jian",3000);
        set_skill("yihua-jiemu",3000);
         set_skill("yifeng-dodge",3000);



	map_skill("force", "mingyu-shengong");
	map_skill("strike", "jueqing-zhang");
		map_skill("dodge", "yihua-jiemu");
	map_skill("parry", "yihua-jiemu");
         map_skill("dodge","yifeng-dodge");
        map_skill("sword","yifeng-jian");

	create_family("�ƻ���",1, "���¹���");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
	carry_object("/d/city/obj/changjian")->wield();
    carry_object("/d/yihua/obj/jinlvyi")->wear();

}