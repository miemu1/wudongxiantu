// /clone/board/emei_b.c

inherit ITEM;

void create()
{
	set_name("���ҵ������԰�", ({ "board" }) );
        set("location", "/d/emei/hcazhengdian");
	set("board_id", "emei_b");
	set("long", "����һ�����������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

