// /clone/board/kedian2_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/beijing/kedian");
	set("board_id", "kedian2_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

