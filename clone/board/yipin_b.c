// /clone/board/yipin_b.c

inherit ITEM;

void create()
{
	set_name("һƷ�����԰�", ({ "board" }) );
	set("location", "/d/lingzhou/yipindayuan");
	set("board_id", "yipin_b");
	set("long", "����һ����һƷ�ý��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

