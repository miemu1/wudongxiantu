inherit BULLETIN_BOARD;

void create()
{
        set_name("����Ħ��", ({ "board" }) );
        set("location", "/data/room/redl/woshi");
        set("board_id", "redl_b");
        set("long", "����Redl�ıʼǱ���\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}


