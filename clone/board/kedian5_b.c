// /clone/board/kedian5_b.c

inherit ITEM;

void create()
{
	set_name("�͵����԰�", ({ "board" }) );
	set("location", "/d/fuzhou/rongcheng");
	set("board_id", "kedian5_b");
	set("long", "�����õĻ���������˵���ҹ�ˮɱ���⡣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

