// by jjyy

inherit ROOM;

void create()
{
	set("short", "��ռ�һ��");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinyi6",
		"south" : __DIR__"wulinyi8",
	]));
	set("objects", (["/SJSSS4/GW1/G/guais" : 3,"/SJSSS4/GW1/G/guais1" : 5,]));
	setup();
}
