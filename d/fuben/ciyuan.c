// Room: /city/beidajie1.c
#include <room.h>
inherit ROOM;
void create()
{

	set("short", "���Ԫ");
	set("long", @LONG
�������Ԫ����Χ�кܶ�ʱ���ѷ죬һ��С�ľͻ����ȥ��
LONG
	);
	set("exits", ([
		//"east"  : "/d/fuben/longzu/longzu",
		"south" : "/d/zhenhun/enter",
		"north"  : "/d/sishenfuben/jinrufuben",
		"west"  : "/d/fuben/qianchipu/qianchipu",
		//"out"  : "/d/gaoli/baodian",
		
	]));

	setup();
}



