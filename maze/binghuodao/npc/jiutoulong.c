inherit __DIR__"bhd_npc.c";
#include <ansi.h>

void create()
{
        set_name(HIG "��ͷ����" NOR, ({ "jiutou long", "jiutou", "long" }));
        set("long", HIG "�޴�ķ�������Ȼ���оŸ�ͷ­���������ֲ�����â���ƺ���Ҫ����һ�С�\n" NOR);

        set("age", 99999);
        set("str",500);
        set("dex", 500);
        set("int", 500);
        set("con", 500);
        set("max_qi", 200000000);
        set("max_jing", 100000000);
        set("max_jingli", 100000000);
        set("max_neili", 2500000);
        set("neili", 2500000);
        set("combat_exp", 1000000000);
        set("no_nuoyi", 1);
        set("gift/exp", 3000);
        set("gift/pot", 800);
        set("gift/mar", 40);
        set("oblist", ([
                "/clone/fam/gift/str3" :1,
                "/clone/fam/gift/con3" :1,
                "/clone/fam/gift/dex3" :1,
                "/clone/fam/gift/int3" :1,
        ]));


        set_skill("force", 1500);
        set_skill("dodge", 1500);
        set_skill("unarmed", 1500);
        set_skill("sword", 1500);
        set_skill("parry", 1500);
        set_skill("claw", 1500);

        setup();
        add_money("gold", 3 + random(3));
}

void init()
{
        // ����������
        if (userp(this_player()))
        {
                kill_ob(this_player());
        }
}
