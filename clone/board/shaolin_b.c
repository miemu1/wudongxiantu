// /clone/board/shaolin_b.c

inherit ITEM;

void create()
{
	set_name("���ֵ������԰�", ({ "board" }) );
	set("location", "/d/shaolin/guangchang1");
	set("board_id", "shaolin_b");
	set("long", "����һ�������ֵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
