// /clone/board/shuyuan_b.c

inherit ITEM;

void create()
{
        set_name("���͵Ĵ�˵", ({ "board" }) );
        set("location", "/d/city/shuyuan2");
        set("board_id", "shuyuan_b");
        set("long", "���͵Ľ������꣬��˵���¡�\n" );
        setup();
        set("capacity", 100);
        replace_program(ITEM);
}
