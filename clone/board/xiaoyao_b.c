// /clone/board/wudang_b.c

inherit ITEM;

void create()
{
	set_name("��ң�ɵ������԰�",({"board"}));
        set("location","/d/xiaoyao/xiaodao4");
	set("board_id", "xiaoy_b");
	set("long", "���ǹ���ң���������Եİ���.\n");
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

