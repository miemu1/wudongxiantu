// /clone/board/bocai_b.c
// jeeny 2001.5
inherit ITEM;

void create()
{
        set_name("�������Բ�", ({ "board" }));
        set("location", "/d/city/bocai");
        set("board_id", "bocai_b");
        set("long", "����һ��ר������ʹ�õ����԰塣\n" );
        setup();
        set("capacity", 1000);
        replace_program(ITEM);
}

int do_discard(object me, string arg)
{
        me = this_player();

        if (wiz_level(me) < 1)
                return notify_fail("�㲻����ʦ���޷�ɾ�����ԡ�\n");
        else
                return ::do_discard(me, arg);
}
