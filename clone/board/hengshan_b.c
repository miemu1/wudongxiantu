// /clone/board/hengshan_b.c

inherit ITEM;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
	set("location", "/d/hengshan/baiyunan");
	set("board_id", "hengshan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	//replace_program(ITEM);
}

