// /NPC gongzhu.c

#include <ansi.h>

inherit "/inherit/char/punisher";
inherit F_MASTER;
inherit F_QUESTER;
void create()
{
	set_name("邀月", ({ "yao yue", "yao", "yue" }));
	set("long",
	    "她就是「移花宫」的开山祖师.\n"+
	    "她用薄薄的面纱蒙着脸,可是透过那块面纱你仍然依稀可见\n"+
	    "她面色煞白,以不是人间所人看见的,你不由得多看了一眼.\n");
	set("title", "移花宫大宫主");
	set("gender", "女性");
	set("age", 36);
	set("nickname", HIR "杀尽天下负心汉" NOR);
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

	create_family("移花宫",1, "邀月宫主");
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
	carry_object("/d/city/obj/changjian")->wield();
    carry_object("/d/yihua/obj/jinlvyi")->wear();

}