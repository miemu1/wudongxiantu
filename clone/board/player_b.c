// /clone/board/player_b.c

inherit ITEM;

void create()
{
	set_name("������Թ���԰�", ({ "board" }) );
	set("location", "/d/city/chaguan");
	set("board_id", "player_b");
	set("long", "����һ������ҷ�й������Թ�����԰塣л������������\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

