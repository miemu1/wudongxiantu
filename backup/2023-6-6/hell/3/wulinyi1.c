// by jjyy

inherit ROOM;

void create()
{
	set("short", " ����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"beijie3",
		"east" : __DIR__"wulinyi2",
	]));
	//set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
