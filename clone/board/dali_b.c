// /clone/board/dali_b.c

inherit ITEM;

void create()
{
	set_name("����θ����԰�", ({ "board" }) );
	set("location", "/d/dali/wangfugate");
	set("board_id", "dali_b");
	set("long", "����һ��������θ����½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

