

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("ʪ����", ({ "shi yongxing", "yongxing", "shi"}));
        set("age", 50);
        set("gender", "����");
        set("long", "����һ��������Ϻ��С�\n");
        set("attitude", "peaceful");
        set("str", 100);
        set("dex", 100);
        set("combat_exp", 800000000000);
        set("shen_type", 1);

        setup();
}

void init()
{
        object ob;

        ::init();
        if (interactive(ob = this_player()) && ! is_fighting())
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (! ob || environment(ob) != environment())
                return;

        say(CYN "��λʩ��������Ҫ������\n" NOR);
}

int accept_object(object who, object ob)
{
        if( query("money_id", ob) )
        {
                message_vision(CYN "$N" CYN "��$n" CYN "˵�������뿪��" NOR +
                               HIY "(goto)" NOR + CYN "ʲô��λ���ȸ����������ٸ�"
                               "ǮҲ���١�\n" NOR, this_object(), who);
                return 0;
        }

        return 0;
}

