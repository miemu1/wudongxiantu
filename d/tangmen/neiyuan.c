//neiyuan.c		�Ĵ����š���Ժ

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long",
"���������Ƹ���Ժ���������򱱾������ŵĺ�������̫̫�����Ҿ���\n"
"����Ҫ��������̫̫�Ʊȵ��컹�ѣ�����������һ��񷿣�������ͨ��\n"
"��Ժ��С·��\n"
);
	set("exits", ([
			"south" : __DIR__"nzlang1",
			"north" : __DIR__"nzlangn1",
	]));
        set("objects", ([
                __DIR__"npc/tangsi" : 1,
        ]));
	set("area", "����");
	setup();
}

int valid_leave(object me, string dir)
{
        if ( (dir == "north") && ( (string)me->query("family/family_name") != "��������") && 
                !wizardp(me) && (objectp( present("tang si", environment(me)) ) ))
		return notify_fail("��˼һ���֣�˵�������㲻���������ˣ���������ǰ���ˣ���\n");
	else
		return ::valid_leave(me, dir);
}
