inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wuliner2",
		"east" : __DIR__"wuliner4",
	]));
	set("objects", ([
		"/d/publicnpc/killplayer" : 5,
	]));
	setup();
}
