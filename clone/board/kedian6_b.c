// /clone/board/kedian6_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/xiangyang/kedian");
	set("board_id", "kedian6_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

