// by jjyy

inherit ROOM;

void create()
{
	set("short", " ����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi14",
		"north" : __DIR__"xijie3",
	]));
	//set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
