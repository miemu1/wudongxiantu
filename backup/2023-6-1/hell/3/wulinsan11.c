

inherit ROOM;

void create()
{
	set("short", " ��������");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan10",
		"south" : __DIR__"wulinsan12",
	]));
	set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
