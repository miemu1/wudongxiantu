// /clone/board/baituo_b.c

inherit ITEM;

void create()
{
	set_name("ŷ���������԰�", ({ "board" }) );
        set("location", "/d/baituo/damen");
	set("board_id", "baituo_b");
	set("long", "����һ����ŷ�����ҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
