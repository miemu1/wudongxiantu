// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "fengm tal" }));
        set("title",HIR"��ħ"NOR);
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 500);
        set("per", 500);
        set("con", 500);
        set("cor", 500);
        
	    set("no_suck", 1);
        set("max_qi", 10000000);
        set("max_jing", 10000000);
        set("neili", 10000000);
        set("max_neili", 10000000);
        set("jiali", 1500);
        set("combat_exp", 80000000);
        set("max_neili", 10000000);
        set("neili", 10000000);
        set("max_jingli", 10000000);
        set("jingli", 10000000);
        set("jiali", 1500);

        set_skill("force", 12000);
        set_skill("dodge", 12000);
        set_skill("parry", 12000);
        set_skill("unarmed", 12000);
        set_skill("taiji-shengong", 12000);
        set_skill("zuixian-steps", 12000);
        set_skill("fumozhang",12000);
        map_skill("dodge", "zuixian-steps");
        map_skill("force", "taiji-shengong");
        map_skill("unarmed", "fumozhang");
        set("chat_chance_combat", 30);
/*
        set("chat_msg_combat", ({
                (: cast_spell, "light" :),
                (: cast_spell, "thunder" :),
        }) );
*/
   add_temp("apply/damage", 10000);
   add_temp("apply/armor", 5000);

        setup();
//        carry_object("/d/obj/cloth/jinjinyi")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n�������������ˣ�����ˣ�ס�֣��������������\n", environment());
        message("sound", "\n�����ֵ��������ʵ��������������ͱ�׼������Խ����ˣ���\n", environment());
        message("sound", "\n������ʧ����Ӱ����...\n"NOR, environment());
        }
        destruct(this_object());
}
