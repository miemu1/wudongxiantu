// /clone/board/gaibang_b.c

inherit ITEM;

void create()
{
	set_name("ؤ��������԰�", ({ "board" }) );
	set("location", "/d/city/pomiao");
	set("board_id", "gaibang_b");
	set("long", "����һ����ؤ����ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

