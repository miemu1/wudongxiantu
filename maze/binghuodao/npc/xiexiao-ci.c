#include <ansi.h>

inherit NPC;

int move_bhd();

void create()
{
        set_name(HIM "л����" NOR, ({ "xiexiao ci", "xiexiao", "ci" }));
        set("title", HIW "��" HIR "��" HIC "ʹ��");
        set("long", "���Ǹ�������ҵ���ԭ������ʹ�ߡ�\n");
        set("gender", "Ů��");
        set("age", 20);
        set("max_qi", 99999);
        set("qi", 99999);
        set("max_jingli", 99999);
        set("max_jing", 99999);
        set("max_neili", 99999);
        set("jing", 99999);
        set("jingli", 99999);
        set("neili", 99999);

        set("per", 25);
        set("con", 88);
        set("int", 88);
        set("dex", 88);
        set("str", 88);

        set("inquiry", ([
                "��ԭ" : (: move_bhd :),
        ]));
        set("combat_exp", 10000000);
        set("shen_type", 1);
        setup();
        carry_object("/d/city/npc/cloth/feature")->wear();      
}

int move_bhd()
{
        object me = this_player();

        command("wave");
        command("say ��ӭ�ٻص����𵺣�");

        me->move("/d/quanzhou/yongninggang");
        return 1;
}
