inherit __DIR__"bhd_npc.c";
#include <ansi.h>

void create()
{
        set_name(HIR "��ѪҰ��" NOR, ({ "shixue yeren", "shixue", "yeren" }));
        set("long", HIR "���������ڱ����ϵ�Ұ�ˣ��ƺ��볣�����в�ͬ��\n" NOR);

        set("age", 300);
        set("str",121);
        set("dex", 80);
        set("int", 80);
        set("con", 80);
        set("max_qi", 32000000);
        set("max_jing", 8500000);
        set("max_jingli", 8500000);
        set("max_neili", 2500000);
        set("neili", 2500000);
        set("combat_exp", 100000000);
        set("no_nuoyi", 1);
        set("gift/exp", 1500);
        set("gift/pot", 565);
        set("gift/mar", 30);
        set("oblist", ([
                "/clone/fam/gift/str3" :1,
                "/clone/fam/gift/con3" :1,
                "/clone/fam/gift/dex3" :1,
                "/clone/fam/gift/int3" :1,
        ]));


        set_skill("force", 1200);
        set_skill("dodge", 1200);
        set_skill("unarmed", 1200);
        set_skill("sword", 1200);
        set_skill("parry", 1200);
        set_skill("claw", 1200);

        setup();
        add_money("gold", 1 + random(3));
}

void init()
{
        // ����������
        if (userp(this_player()) && random(2) == 1)
        {
                kill_ob(this_player());
        }
}
