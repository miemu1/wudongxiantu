// /clone/board/kedian4_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/suzhou/kedian");
	set("board_id", "kedian4_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

