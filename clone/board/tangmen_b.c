// /clone/board/huashan_b.c

inherit ITEM;

void create()
{
        set_name("�����������԰�", ({ "board" }) );
        set("location", "/d/tangmen/chashi");
        set("board_id", "tangmen_b");
        set("long", "����һ���������������½��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(ITEM);
}

