

inherit ROOM;

void create()
{
	set("short", " ��������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"wulinsan4",
		"south" : __DIR__"wulinsan6",
	]));
	set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
