// /clone/board/murong_b.c

inherit ITEM;

void create()
{
	set_name("Ľ�ݼҵ������԰�", ({ "board" }) );
        set("location", "/d/yanziwu/qinyun");
	set("board_id", "murong_b");
	set("long", "����һ����Ľ�ݼҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

