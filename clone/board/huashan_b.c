// /clone/board/huashan_b.c

inherit ITEM;

void create()
{
	set_name("��ɽ�������԰�", ({ "board" }) );
        set("location", "/d/huashan/laojun");
	set("board_id", "huashan_b");
	set("long", "����һ������ɽ���½��������԰塣\n" );
	setup();
	set("capacity", 100);
	//replace_program(ITEM);
}

