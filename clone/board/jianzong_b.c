// /clone/board/jianzong_b.c

inherit ITEM;

void create()
{
	set_name("��ɽ���ڵ������԰�", ({ "board" }) );
	set("location", "/d/huashan/xiaowu");
	set("board_id", "jianzong_b");
	set("long", "����һ������ɽ�������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	//replace_program(ITEM);
}

