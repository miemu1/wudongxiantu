// Room: /d/fuzhou/nanmen.c
inherit ROOM;

void create()
{
	set("short", "�ʹ�");
	set("long", @LONG
���ɱ�, �����·�������ڵ��������Ϊ�˹¶�..�¶�..ֻ��Ϊ������˰ɡ���
LONG );
	set("exits", ([
		"south" : __DIR__"zhongzhou",
		"north" : __DIR__"nanmendou",
	]));
	set("objects", ([
		//	"/kungfu/class/baiyun/ye" : 1,
	]));
set("outdoors", "by");
	setup();
}

