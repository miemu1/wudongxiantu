// Room: /d/fuzhou/yamen.c
// Date: may 12. 1998 Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������ʯ��ֵ���������ͷ���졣��������������ڣ�����ϡ�٣������ĵغ������塣
LONG );
	set("exits", ([
		"east" : __DIR__"nandajie",
		"west"    : __DIR__"xidajie",
	]));
	set("objects", ([
	
	]));
	set("no_fight", 1);
	set("outdoors", "by");
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;

	if (objectp(ob = present("ge shiha", environment(me))) &&
	    dir != "east" && living(ob))
		return notify_fail("��ʲ���ȵ�����ʩ������ȥУ���ı��������θɣ���\n");

	return ::valid_leave(me, dir);
}
