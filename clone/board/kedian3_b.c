// /clone/board/kedian3_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/city3/kedian");
	set("board_id", "kedian3_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

