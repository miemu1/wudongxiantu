// /clone/board/baituo_b.c

inherit ITEM;

void create()
{
	set_name("���չ��������԰�", ({ "board" }) );
        set("location", "/d/lingjiu/damen");
	set("board_id", "lingjiu_b");
	set("long", "����һ�������չ����ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
