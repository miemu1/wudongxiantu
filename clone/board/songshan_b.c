// /clone/board/songshan_b.c

inherit ITEM;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/songshan/chanyuan");
	set("board_id", "songshan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

