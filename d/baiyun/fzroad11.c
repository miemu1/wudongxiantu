// Room: /d/fuzhou/fzroad11.c
inherit ROOM;

void create()
{
	set("short", "��ѩ��");
	set("long", @LONG
���������ɭ��Դͷ��ԭ�������������������ޱȵ��䡣�¶�����ϸһ��ԭ���Ǹ���Ӱ��ȴ��֪����������!
LONG );
	set("exits", ([
		"north"   : __DIR__"ximen",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/ximen" : 1,
	]));

	setup();
}

