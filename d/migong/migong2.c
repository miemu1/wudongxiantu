#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "������ɽ·");
	set("long", @LONG
 ����һ���˼�������ɽ�ȣ�Զ����Լ�ܿ������͵�ɽ�£�һ��
��ȥ���ܶ���ãã���������ұ���һ������С��ֱ���ֺ�֮�С�
LONG );
	set("exits", ([
		"east" : __DIR__"migong1",
		"west" : __DIR__"migong3",
                           	]));
                set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
