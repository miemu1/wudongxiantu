// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͽռ�һ��");
	set("long", "����һ���ռ�ش���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", (["/SJSSS4/GW1/G/guais" : 3,"/SJSSS4/GW1/G/guais1" : 5,
	]));
	setup();
}