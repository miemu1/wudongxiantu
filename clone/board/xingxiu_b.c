// /clone/board/wudang_b.c

inherit ITEM;

void create()
{
	set_name("�����ɵ������԰�",({"board"}));
        set("location", "/d/xingxiu/xxh1");
	set("board_id", "xingxiu_b");
	set("long", "���ǹ������������Եİ���.\n");
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

