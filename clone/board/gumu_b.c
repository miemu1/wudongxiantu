// /clone/board/gumu_b.c

inherit ITEM;

void create()
{
	set_name("��Ĺ�ɵ������԰�", ({ "board" }) );
	set("location", "/d/gumu/zhengting");
	set("board_id", "gumu_b");
	set("long", "����һ������Ĺ�����½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

