// by jjyy

inherit ROOM;

void create()
{
	set("short", "����һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi7",
		"west" : __DIR__"wulinyi9",
	]));
	//set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}
