// youji.c ����

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "you ji", "you", "ji" }) );
        set("gender", "����");
        set("nickname",HIW"����˫��"NOR);
        set("title","����ׯ��ׯ��");
        set("age", 40);
        set("long","�����Ǿ���ׯ�Ĵ�ׯ��������\n");
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "peaceful");
        set("unique", 1);

        set("str", 28);
        set("con", 26);
        set("int", 20);
        set("dex", 24);
        set("per", 13);

        set("max_qi", 90000);
        set("max_jing", 60000);
        set("neili", 90000);
        set("eff_jingli", 60000);
        set("max_neili", 90000);

        set_skill("force", 1000);
        set_skill("yijin-jing", 1000);
        set_skill("sword", 1000);
        set_skill("dodge", 1000);
        set_skill("strike", 1000);
        set_skill("cuff", 1000);
        set_skill("weituo-zhang", 1000);
        set_skill("parry", 1000);
        set_skill("luohan-quan", 1000);
        set_skill("shaolin-shenfa", 1000);
        map_skill("parry", "luohan-quan");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "luohan-quan");
        map_skill("force","yijin-jing");
        map_skill("strike", "weituo-zhang");
        prepare_skill("strike", "weituo-zhang");
        prepare_skill("cuff", "luohan-quan");

        set("auto_perform", 1);
        setup();
        carry_object("/clone/cloth/jinduan")->wear();
}
