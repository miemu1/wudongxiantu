// /clone/board/bugs_b.c

inherit ITEM;

void create()
{
        set_name("�������԰�", ({ "board" }) );
        set("location", "/d/city/wumiao");
        set("board_id", "bugs_b");
        set("long", "���԰��ϵ����������棬����������Ϊ�������æ�Ĳ����ֺ���\n" );
        setup();
        set("capacity", 1000);
        replace_program(ITEM);
}
