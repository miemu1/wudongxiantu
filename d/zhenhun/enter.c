#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{	set("outdoors","zhenhun");
	set("short", "��������");
	set("long","�����ǻ���һ����ѹĹ�صĵط���\n"
	"����ѡ���������");
	set("exits", ([
		"north" : "d/zhenhun/chuji/chuji",
	]));
	setup();
}