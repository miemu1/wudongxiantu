inherit ITEM;

void create()
{
        set_name("���������", ({ "board" }) );
        set("location", "/d/city/advice/advice");
        set("board_id", "game_advice");
        set("long", "���õĻ���������˵���ҹ�ˮɱ���⡣\n" );
        setup();
        set("capacity", 100000);
        replace_program(ITEM);
}



