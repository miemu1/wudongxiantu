// /clone/board/hu.c

inherit ITEM;

void create()
{
	set_name("���ҵ������԰�", ({ "board" }) );
        set("location", "/d/guanwai/xiaoyuan");
	set("board_id", "hu_b");
	set("long", "����һ�������ҵ��ӽ��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
