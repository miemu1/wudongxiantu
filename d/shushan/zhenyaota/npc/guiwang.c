// modified by vikee 2000.11
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����", ({ "gui wang", "wang" }));
        set("title",HIR"����"NOR);
        set("age", 300);
        set("attitude", "aggressive");
        set("str", 40);
        set("per", 20);
        set("con", 30);
        set("cor", 30);
        
	 set("no_suck", 1);
        set("max_qi", 60000);
        set("max_jing", 60000);
        set("neili", 3000000);
        set("max_neili", 20000);
        set("jiali", 600);
        set("combat_exp", 80000000);
        set("max_neili", 100000);
        set("neili", 100000);
        set("max_jingli", 100000);
        set("jingli", 100000);
        set("jiali", 10000);

        set_skill("force", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
        set_skill("unarmed", 220);
        set_skill("taiji-shengong", 220);
        set_skill("zuixian-steps", 220);
        set_skill("fumozhang",220);
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
   add_temp("apply/damage", 20);
   add_temp("apply/armor", 20);

        setup();
//        carry_object("/d/obj/cloth/jinjinyi")->wear();

}

void die()
{
        if( environment() ) {
        message("sound", CYN"\n����ǵ�������ԭ���ң���Ϊ�������������ΪֻҪ�ܳԾŰپ�ʮ�Ÿ�����\n����һ�ٸ�����Ϳ��Գ�ȥ������...��\n", environment());
        message("sound", "\n������ֵ������������ϣ��ҷ�����ϣ����ϣ�����ܹ��������뿪�����...ǰ��������鷳�Ļ����������ң���\n", environment());
        message("sound", "\n�������ʧ����Ӱ����...\n"NOR, environment());
        }
        destruct(this_object());
}
