// /clone/board/mingjiao_b.c

inherit ITEM;

void create()
{
	set_name("���̽������԰�", ({ "board" }) );
	set("location", "/d/mingjiao/square");
	set("board_id", "mingjiao_b");
	set("long", "����һ�������̽��ڽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
