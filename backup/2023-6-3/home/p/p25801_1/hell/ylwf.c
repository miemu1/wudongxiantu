//by ΢Ц dudu66's ednpc tools.
// ylwf.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��������");
	set("long","������������������������δ�趨������ϸ������");
	set("owner_build","p25801_1");
	set("exits", ([
		"west" : "/data/hell/7/wulinsan7",
	]));
	set("objects", ([
	]));
	set("close_room", 1);
	set("owner_special", 1);
	setup();
}

