// by jjyy

inherit ROOM;

void create()
{
	set("short", "�Ͻ�һ��");
	set("long", "����һ����������ʯ�ֵ���");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"guangchang",
		"south" : __DIR__"nanjie2",
	]));
	set("objects", (["/HELL1/GuaiWu5/G/guais" : 10,"/HELL1/GuaiWu1/G/guais" : 5,]));
	setup();
}