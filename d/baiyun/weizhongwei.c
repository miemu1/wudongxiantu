// jiulou.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������ʯ��ֵ���������ͷ���졣
LONG);
	set("exits", ([
	    //"west"  : __DIR__"nandajie",
	    //"north"  : __DIR__"chufang",
		"east"    : __DIR__"dongdajie",
		"west"    : __DIR__"nandajie",
	]));
	set("objects", ([
	   // __DIR__"npc/xiaoer3" : 1,
	]));
	set("item_desc", ([
	   // "�����ӡ�" : "
//����ǽ(Fotiaoqiang)   ����������
//�����Ͼ�(Jiuping)     ����������\n",
	]));
	set("outdoors", "by");
	setup();
}

