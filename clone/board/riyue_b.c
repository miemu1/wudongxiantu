// /clone/board/riyue_b.c

inherit ITEM;

void create()
{
	set_name("日月神教教众记事板", ({ "board" }) );
	set("location", "/d/heimuya/chengdedian");
	set("board_id", "riyue_b");
	set("long", "这是一个专供日月神教教众在使用的留言板。\n" );
	setup();
	set("capacity", 100);
	replace_program(ITEM);
}

