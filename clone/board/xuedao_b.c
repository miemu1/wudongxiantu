// /clone/board/xuedao_b.c

inherit ITEM;

void create()
{
	set_name("血刀门弟子留言板",({ "board" }) );
        set("location", "/d/xuedao/shandong2");
	set("board_id", "xuedao_b");
        set("long","这是供血刀门弟子传递信息用的留言板\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}
