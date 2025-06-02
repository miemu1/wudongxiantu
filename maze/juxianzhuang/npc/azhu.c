// Written by Lonely@nitan.org
// azhu.c ����

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "a zhu", "a", "zhu" }));
        set("gender", "Ů��");
        set("age", 17);
        set("long", "����һλ�����ɴ����Ů�ɣ�Ҳ��ӯӯʮ������ͣ��쵰��������\n"
                    "�鶯��һ��������Ƥ��������������ɫ�Ұ����������ƺ����˼�Ϊ��\n"
                    "�ص����ˡ�\n");

        set("str", 20);
        set("int", 30);
        set("con", 20);
        set("dex", 20);
        set("per", 23);
        set("combat_exp", 14000);
        set("shen_type", 0);
        set("attitude", "peaceful");
        set("max_qi",1000);
        set("eff_qi", 10);
        set("max_jing",1000);
        set("eff_jing", 100);
        set("neili",1000);
        set("max_neili",1000);

        set_skill("cuff", 80);
        set_skill("parry",80);
        set_skill("beidou-xianzong",80);
        set_skill("dodge", 80);
        set_skill("force",80);
        set_skill("douzhuan-xingyi",80);

        map_skill("force","douzhuan-xingyi");
        map_skill("dodge","beidou-xianzong");

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);

        setup();

        carry_object("/d/yanziwu/npc/obj/goldring")->wear();
        carry_object("/d/yanziwu/npc/obj/necklace")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/yanziwu/npc/obj/pink_cloth")->wear();
        carry_object("/d/yanziwu/npc/obj/flower_shoe")->wear();
}
