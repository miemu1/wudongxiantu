#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "zombie" }));
        set("long", "����һ�����ġ�\n");
        set("title", HIB "(����)" NOR);

        set("str", 50);
        set("con", 120);
        set("dex", 22);
        set("int", 50);
        set("max_jing", 5000);
        set("max_neili", 50000);
        set("max_jingli", 50000);
        set("chat_chance_combat", 80);
        set("combat_exp", 100000000);
        set("bellicosity", 5 );

        setup();
}

void die()
{
        object ob,obj,env;
        env = environment(this_object());
        obj = new("/clone/vip/vip2/putao");
        obj->move(env, 1);
        message_vision("\n$N����һ̲��Ѫ����ʧ�ˡ�\n", this_object());
        ::die();
} 