// Room: /d/fuzhou/nandajie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǰ��Ƴǵ������ģ�һ���ܿ����Ĺ㳡��������ʯ���棬һƬ������
LONG );
	set("exits", ([
		"south"   : __DIR__"nanmendou",
		"north"   : __DIR__"dongjiekou",
		"east"    : __DIR__"weizhongwei",
		"west"    : __DIR__"yamen",
		"northwest" : __DIR__"jingji/enter",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/bai" : 1,
	]));
	set("outdoors", "by");
	//setup();
}
	
