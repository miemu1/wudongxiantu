// /clone/board/quanzhen_b.c

inherit ITEM;

void create()
{
	set_name("ȫ���ɵ������԰�", ({ "board" }) );
        set("location", "/d/quanzhen/damen");
	set("board_id", "quanzhen_b");
	set("long", "����һ����ȫ�������½��������԰塣\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

