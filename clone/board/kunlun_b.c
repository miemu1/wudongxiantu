// /clone/board/kunlun_b.c

inherit ITEM;

void create()
{
        set_name("���ص������԰�", ({ "board" }) );
        set("location", "/d/kunlun/sanshengtang");
        set("board_id", "kunlun_b");
        set("long", "����һ���������ɵ��ӽ��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(ITEM);
}

