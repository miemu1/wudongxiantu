// by jjyy

inherit ROOM;

void create()
{
	set("short", " ����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi3",
		"south" : __DIR__"wulinyi5",
	]));
	//set("objects", (["/HELL3/GuaiWu5/G/guais1" : 4,"/HELL3/GuaiWu5/G/guais" : 1,]));
	setup();
}
