// Room: /d/fuzhou/dongxiaojie.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "��ǽ");
	set("long", @LONG
�����ǰ��Ƴǵĳ�ǽ����ש��Ѫ�⼣���ۣ���˵�����Ĺ��¡�
LONG );
	set("exits", ([
		//"east"    : __DIR__"dongmen",
		"west"    : __DIR__"dongdajie",
	]));
	set("objects", ([
			"/kungfu/class/baiyun/baixue" : 1,
	]));
set("outdoors", "by");
	setup();
}

